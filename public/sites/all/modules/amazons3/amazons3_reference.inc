<?php
/**
 * @file
 * A FileField extension to allow referencing of existing files.
 *
 * The "hooks" in this file are not true hooks, they're called individually
 * from the main filefield_sources.module in the corresponding hook by the
 * same name. Any of these hooks could be broken out into a separate module.
 */
define('AMAZONS3_REFERENCED_HINT_TEXT', 'Object.mp3');

/**
 * Implements hook_filefield_sources_info().
 */
function amazons3_filefield_sources_info() {
  $source = array();

  $source['amazons3_referenced'] = array(
    'name' => t('S3 Autocomplete reference'),
    'label' => t('S3 Reference'),
    'description' => t('Reuse an existing file by entering its file name.'),
    'process' => 'amazons3_referenced_process',
    'value' => 'amazons3_referenced_value',
    'weight' => 1,
  );
  return $source;
}

/**
 * Implements hook_theme().
 */
function amazons3_theme() {
  return array(
    'amazons3_referenced_element' => array(
      'render element' => 'element',
      'file' => 'amazons3_reference.inc',
    ),
    'amazons3_referenced_autocomplete_item' => array(
      'variables' => array('file' => NULL),
      'file' => 'amazons3_reference.inc',
    ),
  );
}

/**
 * Implements hook_filefield_sources_widgets().
 */
function amazons3_filefield_sources_widgets() {
  // Add any widgets that your module supports here.
  return array('file', 'commerce_file_generic');
}

/**
 * Implements hook_filefield_source_settings().
 */
function filefield_source_amazons3_settings($op, $instance) {
  $return = array();

  if ($op == 'form') {
    $settings = $instance['widget']['settings']['filefield_sources'];

    $return['amazons3_referenced'] = array(
      '#title' => t('S3 Autocomplete reference options'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $return['amazons3_referenced']['autocomplete'] = array(
      '#title' => t('Match file name'),
      '#options' => array(
        '0' => t('Starts with string'),
        '1' => t('Contains string'),
      ),
      '#type' => 'radios',
      '#default_value' => isset($settings['amazons3_referenced']['autocomplete']) ? $settings['amazons3_referenced']['autocomplete'] : '0',
    );
  }
  elseif ($op == 'save') {
    $return['amazons3_referenced']['autocomplete'] = '0';
  }

  return $return;
}

/**
 * A #process callback to extend the filefield_widget element type.
 */
function amazons3_referenced_process($element, &$form_state, $form) {

  $element['amazons3_referenced'] = array(
    '#weight' => 100.5,
    '#theme' => 'amazons3_referenced_element',
    '#filefield_source' => TRUE, // Required for proper theming.
    '#filefield_sources_hint_text' => AMAZONS3_REFERENCED_HINT_TEXT,
  );

  $element['amazons3_referenced']['autocomplete'] = array(
    '#type' => 'textfield',
    '#autocomplete_path' => 'amazons3/reference/' . $element['#entity_type'] . '/' . $element['#bundle'] . '/' . $element['#field_name'],
    '#description' => t('Choose a file from your S3 bucket.'),
  );

  $element['amazons3_referenced']['select'] = array(
    '#name' => implode('_', $element['#array_parents']) . '_autocomplete_select',
    '#type' => 'submit',
    '#value' => t('Select'),
    '#validate' => array(),
    '#submit' => array('filefield_sources_field_submit'),
    '#name' => $element['#name'] . '[amazons3_referenced][button]',
    '#limit_validation_errors' => array($element['#parents']),
    '#ajax' => array(
      'path' => 'file/ajax/' . implode('/', $element['#array_parents']) . '/' . $form['form_build_id']['#value'],
      'wrapper' => $element['#id'] . '-ajax-wrapper',
      'effect' => 'fade',
    ),
  );

  return $element;
}

function amazons3_referenced_field_validate(&$form, &$form_state) {
/*

  $parents = array_slice($form_state['triggering_element']['#parents'], 0, -1);
  //drupal_array_set_nested_value($form_state['input'], $parents, NULL);

  // @todo: There has to be a "Drupal Way" of doing this.
  if (!empty($form_state['values'][$parents[0]][$parents[1]][$parents[2]][$parents[3]]['autocomplete'])) {
    $filename = $form_state['values'][$parents[0]][$parents[1]][$parents[2]][$parents[3]]['autocomplete'];

    $frecord = amazons3_reference_create_file_record($filename);

    if($frecord){
      $form_state['values'][$parents[0]][$parents[1]][$parents[2]][$parents[3]]['fid'] = $frecord["fid"];
    }else{
      form_set_error($form, 'Please, check the file name');
    }
  }
*/
}


function amazons3_reference_create_file_record($filename) {

  libraries_load('awssdk');

  $wrapper = new AmazonS3StreamWrapper();
  $bucket = variable_get('amazons3_bucket', '');

  $response = $wrapper->_amazons3_get_object($filename);
  $metadata = $wrapper->getS3()->get_object_metadata($bucket, $filename);

  if ($response) {
    global $user;
    $result = db_select('file_managed', 'fm')
      ->fields('fm')
      ->condition('uri', "s3://" . $filename)
      ->execute()
      ->fetchAssoc();

    if ($result){
      return $result;
    }

    $record = array(
      "uid" => $user->uid,
      "filename" => $filename,
      "uri" => "s3://" . $filename,
      "filemime" => $wrapper->getMimeType($filename),
      "filesize" => $metadata["Size"],
      "status" => '1',
      "timestamp" => time(),
      "type" => 'video',
      "origname" => $filename,
    );
    drupal_write_record('file_managed', $record);



    return $record;
  }
  return FALSE;
}

/**
 * A #filefield_value_callback function.
 */
function amazons3_referenced_value($element, &$item) {
  if (isset($item['amazons3_referenced']['autocomplete']) && strlen($item['amazons3_referenced']['autocomplete']) > 0 && $item['amazons3_referenced']['autocomplete'] != AMAZONS3_REFERENCED_HINT_TEXT) {
    $filename = $item['amazons3_referenced']['autocomplete'];
    $record = amazons3_reference_create_file_record($filename);
    $field = field_info_instance($element['#entity_type'], $element['#field_name'], $element['#bundle']);

    if ($record) {
      $fid = db_query('SELECT fid FROM {file_managed} WHERE uri = :filename', array(':filename' =>  "s3://". $filename))->fetchField();

      if ($file = file_load($fid)) {
        // Now tell Drupal that our node is using the file.
        file_usage_add($file, 'amazons3', 'preexisting', $file->fid);

        // Below is commented out because this is not a local file.
        if (filefield_sources_element_validate($element, (object) $file)) {
          //$filename = filefield_sources_clean_filename($filename, $field['settings']['file_extensions']);
          //$filepath = file_create_filename($filename, 's3://');

          //if ($file = filefield_sources_save_file($filepath, $element['#upload_validators'], $element['#upload_location'])) {
            $item = array_merge($item, (array) $file);
          //}
        }
      }
      else {
        form_error($element, t('The referenced file could not be used because the file does not exist in the database.'));
      }
    }
  }
    // No matter what happens, clear the value from the autocomplete.
    $item['amazons3_referenced']['autocomplete'] = '';
}

/**
 * Menu callback; autocomplete.js callback to return a list of files.
 */
function amazons3_referenced_autocomplete($entity_type, $bundle_name, $field_name, $filename) {
  $field = field_info_instance($entity_type, $field_name, $bundle_name);

  $items = array();
  if (!empty($field)) {
    $files = amazons3_referenced_get_files($filename, $field);
    foreach ($files as $file) {
      $items[$file] = theme('amazons3_referenced_autocomplete_item', array('file' => $file));
    }
  }

  drupal_json_output($items);
}

/**
 * Theme the output of a single item in the autocomplete list.
 */
function theme_amazons3_referenced_autocomplete_item($variables) {
  $file = $variables['file'];

  $output = '';
  $output .= '<div class="filefield-source-amazons3-reference-item">';
  $output .= '<span class="filename">' . $file . '</span>';
  $output .= '</div>';
  return $output;
}

/**
 * Theme the output of the autocomplete field.
 */
function theme_amazons3_referenced_element($variables) {
  $element = $variables['element'];
  $element['autocomplete']['#field_suffix'] = drupal_render($element['select']);
  return '<div class="filefield-source filefield-source-amazons3 clear-block">' . drupal_render($element['autocomplete']) . '</div>';
}

/**
 * Get all the files used within a particular field (or all fields).
 *
 * @param $file_name
 *   The partial name of the file to retrieve.
 * @param $instance
 *   Optional. A CCK field array for which to filter returned files.
 */
function amazons3_referenced_get_files($filename, $instance = NULL) {
  $instances = array();
  if (!isset($instance)) {
    foreach (field_info_fields() as $instance) {
      if ($instance['type'] == 'file' || $instance['type'] == 'image') {
        $instances[] = $instance;
      }
    }
  }
  else {
    $instances = array($instance);
  }

  $files = array();
  foreach ($instances as $instance) {
    $field = field_info_field($instance['field_name']);

    if (!isset($field['storage']['details']['sql']['FIELD_LOAD_CURRENT'])) {
      continue;
    }

    $like = empty($instance['widget']['settings']['filefield_sources']['amazons3_referenced']['autocomplete']) ? ($filename . '%') : ('%' . $filename . '%');

    $table = 'amazons3_file';
    $query = db_select($table, 'af');
    $query->fields('af', array('uri'));
    $query->condition('af.uri', $like, 'LIKE');
    $result = $query->execute();

    if ($result) {
      foreach ($result as $file) {
        $files[$file->uri] = $file->uri;
      }
    }
  }

  return $files;
}
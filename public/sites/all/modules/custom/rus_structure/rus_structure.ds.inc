<?php
/**
 * @file
 * rus_structure.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function rus_structure_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|scoreboard|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'scoreboard';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'scoreboard_item_score' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'scoreboard_item_terms' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|scoreboard|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|scoreboard|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'scoreboard';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'scoreboard_item_terms' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'scoreboard_item_score' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
      ),
    ),
  );
  $export['node|scoreboard|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function rus_structure_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'scoreboard_item_score';
  $ds_field->label = 'Scoreboard Item Score';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php 
  $wrapper = entity_metadata_wrapper(\'node\', $entity, array(\'bundle\' => \'scoreboard\'));
  
  //Get the wrappers for each term reference field
  $wrapper_term_team_home  = $wrapper->field_term_team_home;
  $wrapper_term_team_away  = $wrapper->field_term_team_away;
  $wrapper_score_home  = $wrapper->field_score_home;
  $wrapper_score_away  = $wrapper->field_score_away;     
  
  //Extract the data if available
  $team_home  = ($wrapper_term_team_home->value() == "") ? "" : $wrapper_term_team_home->name->value();
  $team_away  = ($wrapper_term_team_away->value() == "") ? "" : $wrapper_term_team_away->name->value();  
  $score_home = $wrapper_score_home->value();
  $score_away = $wrapper_score_away->value();  
  
  $html = "";
  if($team_away != "" && $team_home != "") {
    $html = "@" . $team_home . " " . $score_home . ", " . $team_away . " " . $score_away;
  }
  echo $html;
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['scoreboard_item_score'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'scoreboard_item_terms';
  $ds_field->label = 'Scoreboard Item Terms';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
  $wrapper = entity_metadata_wrapper(\'node\', $entity, array(\'bundle\' => \'scoreboard\'));

  //Get the wrappers for each term reference field
  $wrapper_term_sport  = $wrapper->field_term_sport;
  $wrapper_term_level  = $wrapper->field_term_level;
  $wrapper_term_gender = $wrapper->field_term_gender;

  //Convert any arrays into a single item wrappers
  $wrapper_term_sport_item  = (get_class($wrapper_term_sport)  == "EntityListWrapper") ? $wrapper_term_sport->get(0)  : $wrapper_term_sport;
  $wrapper_term_level_item  = (get_class($wrapper_term_level)  == "EntityListWrapper") ? $wrapper_term_level->get(0)  : $wrapper_term_level;
  $wrapper_term_gender_item = (get_class($wrapper_term_gender) == "EntityListWrapper") ? $wrapper_term_gender->get(0) : $wrapper_term_gender;
  
  //Extract the data if available
  $sport  = ($wrapper_term_sport_item->value() == "") ? "" : $wrapper_term_sport_item->name->value();
  $level  = ($wrapper_term_level_item->value() == "") ? "" : $wrapper_term_level_item->name->value();
  $gender = ($wrapper_term_gender_item->value() == "") ? "" : $wrapper_term_gender_item->name->value();
  $html = $gender . " " . $level . " " . $sport;
  
  echo $html;
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['scoreboard_item_terms'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function rus_structure_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|scoreboard|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'scoreboard';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_datetime',
        1 => 'scoreboard_item_terms',
        2 => 'scoreboard_item_score',
        3 => 'body',
      ),
    ),
    'fields' => array(
      'field_datetime' => 'ds_content',
      'scoreboard_item_terms' => 'ds_content',
      'scoreboard_item_score' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|scoreboard|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|scoreboard|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'scoreboard';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_3col_equal_width';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'field_datetime',
        2 => 'scoreboard_item_score',
        3 => 'scoreboard_item_terms',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_datetime' => 'left',
      'scoreboard_item_score' => 'left',
      'scoreboard_item_terms' => 'left',
    ),
    'classes' => array(),
  );
  $export['node|scoreboard|teaser'] = $ds_layout;

  return $export;
}

<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */
 

function omega_rus_init() {

}
 
function omega_rus_preprocess_page(){  
  //Add in default javascript
  drupal_add_js(path_to_theme() . '/js/omega_rus.js');
  
  //Add in school specific CSS
  if(module_exists('less')) {
    $school_submission = check_plain(variable_get('omega_rus_school_css', 'default'));
    $school_css = ($school_submission == "") ? "default" : $school_submission;
    drupal_add_css(path_to_theme() . '/css/schools/'.$school_css.'.less', 
      array(
        'weight' => 9
      )
    );
  }
}
 
function omega_rus_form_alter(&$form, &$form_state, $form_id){
  //dpm($form);
  //dpm($form_state);
  if($form['form_id']['#value'] == 'views_exposed_form'){
    if(isset($form['field_term_sport_tid'])){$form['field_term_sport_tid']['#options']['All'] = "All";}
    if(isset($form['field_term_level_tid'])){$form['field_term_level_tid']['#options']['All'] = "All";}
    if(isset($form['field_term_gender_tid'])){$form['field_term_gender_tid']['#options']['All'] = "All";}
    if(isset($form['field_term_categories_tid'])){$form['field_term_categories_tid']['#options']['All'] = "All";}
  }
}

function omega_rus_form_search_block_form_alter(&$form, &$form_state){
  $form['actions']['submit'] = array(
    '#type' => 'image_button', 
    '#src' => base_path() . path_to_theme() . '/image/search-hourglass2.png',
  );  
}

/**
 * Implements hook_form_system_theme_settings_alter()
 */
function omega_rus_form_system_theme_settings_alter(&$form, &$form_state){
  //dpm($form);
  //dpm($form_state);
  
  $form['omega_rus_settings'] = array(
    '#type' => 'fieldset',
    '#title' => 'School Specific Settings',
    '#description' => 'Here you can adjust the school specific settings for the theme, most notably the color.',
  );
  
  $options = array();
  $results = file_scan_directory(getcwd().'/'.drupal_get_path('theme', 'omega_rus').'/css/schools', '/.less/');
  foreach($results as $item) {
    if($item->name != "common_selectors"){
      $options[$item->name] = $item->name;
    }
  }
  
  $form['omega_rus_settings']['omega_rus_school_css'] = array(
    '#type' => 'select',
    '#title' => 'School Theme File',
    '#options' => $options,
    '#default_value' => variable_get('omega_rus_school_css', 'default'),
  );
  
  $form['#submit'][] = 'omega_rus_theme_settings_form_submit';
}

/**
 * Clears the cache for the theme settings upon form submission.
 */
function omega_rus_theme_settings_form_submit($form, &$form_state) {
  variable_set('omega_rus_school_css', $form_state['values']['omega_rus_school_css']);
}



  
  
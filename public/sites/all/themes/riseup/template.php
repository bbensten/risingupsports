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

/**
 * Implements hook_form_system_theme_settings_alter()
 */
// function riseup_form_system_theme_settings_alter(&$form, &$form_state){
//   $form['riseup_settings'] = array(
//     '#type' => 'fieldset',
//     '#title' => 'School Specific Settings',
//     '#description' => 'Here you can adjust the school specific settings for the theme, most notably the color.',
//   );

//   $options = array();
//   $results = file_scan_directory(getcwd().'/'.drupal_get_path('theme', 'omega_rus').'/css/schools', '/.less/');
//   foreach($results as $item) {
//     if($item->name != "common_selectors"){
//       $options[$item->name] = $item->name;
//     }
//   }

//   $form['riseup_settings']['riseup_school_css'] = array(
//     '#type' => 'select',
//     '#title' => 'School Theme File',
//     '#options' => $options,
//     '#default_value' => variable_get('riseup_school_css', 'default'),
//   );

//   $form['#submit'][] = 'riseup_theme_settings_form_submit';
// }

// /**
//  * Clears the cache for the theme settings upon form submission.
//  */
// function riseup_theme_settings_form_submit($form, &$form_state) {
//   variable_set('riseup_school_css', $form_state['values']['riseup_school_css']);
// }

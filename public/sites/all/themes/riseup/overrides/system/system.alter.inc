<?php

/**
 * Implements hook_css_alter().
 */
function riseup_css_alter(&$css) {
  // Nuke some modules styles that get in the way.
  $remove = array(
    drupal_get_path('module', 'rus_helper') . '/skins/rus-scoreboard/jcarousel-rus-scoreboard.css',
    drupal_get_path('module', 'rus_helper') . '/skins/rus-scoreboard/jcarousel-rus-scoreboard-filter.css',
  );
  foreach ($remove as $styles) {
    if ($css[$styles]) {
      unset($css[$styles]);
    }
  }
}

/**
 * Implments hook_form_alter().
 */
function riseup_form_alter(&$form, &$form_state, $form_id){
  if($form['form_id']['#value'] == 'views_exposed_form'){
    if(isset($form['field_term_sport_tid'])){$form['field_term_sport_tid']['#options']['All'] = "All";}
    if(isset($form['field_term_level_tid'])){$form['field_term_level_tid']['#options']['All'] = "All";}
    if(isset($form['field_term_gender_tid'])){$form['field_term_gender_tid']['#options']['All'] = "All";}
    if(isset($form['field_term_categories_tid'])){$form['field_term_categories_tid']['#options']['All'] = "All";}
  }
}

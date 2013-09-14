<?php
/**
 * @file
 * rus_node_generic.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function rus_node_generic_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'feature_small';
  $ds_view_mode->label = 'Small feature';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['feature_small'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'medium_teaser';
  $ds_view_mode->label = 'Medium teaser';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['medium_teaser'] = $ds_view_mode;

  return $export;
}

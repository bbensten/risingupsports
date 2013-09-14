<?php
/**
 * @file
 * rus_structure.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function rus_structure_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "dfp" && $api == "default_dfp_tags") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function rus_structure_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function rus_structure_node_info() {
  $items = array(
    'block_ad' => array(
      'name' => t('Block Ad'),
      'base' => 'node_content',
      'description' => t('These are square image ads that will appear at the bottom of the site in a grid fashion.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'crew' => array(
      'name' => t('Crew'),
      'base' => 'node_content',
      'description' => t('These are the students, faculty, and volunteers that are assisting in all aspects of the network for each school.'),
      'has_title' => '1',
      'title_label' => t('Full Name'),
      'help' => '',
    ),
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('A live streaming event.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'scoreboard' => array(
      'name' => t('Scoreboard Item'),
      'base' => 'node_content',
      'description' => t('This is a video-less scoreboard entry.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

<?php
/**
 * @file
 * rus_blog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function rus_blog_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function rus_blog_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function rus_blog_node_info() {
  $items = array(
    'blog' => array(
      'name' => t('Blog post'),
      'base' => 'node_content',
      'description' => t(' Update readers on the latest news.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

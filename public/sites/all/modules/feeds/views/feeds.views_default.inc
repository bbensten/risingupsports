<?php

/**
 * @file
 * Default view definitions for Feeds.
 */

/**
 * Implementation of hook_views_default_views().
 */
function feeds_views_default_views() {
  $views = array();

  $view = new view;
  $view->name = 'feeds_log';
  $view->description = 'Feeds log displays for overview, standalone importers and feed nodes.';
  $view->tag = 'Feeds';
  $view->base_table = 'feeds_log';
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer feeds';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'log_time' => 'log_time',
    'request_time' => 'request_time',
    'message' => 'message',
    'severity' => 'severity',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'log_time' => array(
      'sortable' => 0,
      'align' => '',
      'separator' => '',
    ),
    'request_time' => array(
      'sortable' => 0,
      'align' => '',
      'separator' => '',
    ),
    'message' => array(
      'align' => '',
      'separator' => '',
    ),
    'severity' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  /* Empty text: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no log messages.';
  $handler->display->display_options['empty']['area']['format'] = '1';
  /* Field: Feeds log: Log time */
  $handler->display->display_options['fields']['log_time']['id'] = 'log_time';
  $handler->display->display_options['fields']['log_time']['table'] = 'feeds_log';
  $handler->display->display_options['fields']['log_time']['field'] = 'log_time';
  $handler->display->display_options['fields']['log_time']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['log_time']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['log_time']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['log_time']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['log_time']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['log_time']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['log_time']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['log_time']['alter']['html'] = 0;
  $handler->display->display_options['fields']['log_time']['hide_empty'] = 0;
  $handler->display->display_options['fields']['log_time']['empty_zero'] = 0;
  $handler->display->display_options['fields']['log_time']['date_format'] = 'custom';
  $handler->display->display_options['fields']['log_time']['custom_date_format'] = 'Y-m-d H:i:s';
  /* Field: Feeds log: Request time */
  $handler->display->display_options['fields']['request_time']['id'] = 'request_time';
  $handler->display->display_options['fields']['request_time']['table'] = 'feeds_log';
  $handler->display->display_options['fields']['request_time']['field'] = 'request_time';
  $handler->display->display_options['fields']['request_time']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['request_time']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['request_time']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['request_time']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['request_time']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['request_time']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['request_time']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['request_time']['alter']['html'] = 0;
  $handler->display->display_options['fields']['request_time']['hide_empty'] = 0;
  $handler->display->display_options['fields']['request_time']['empty_zero'] = 0;
  $handler->display->display_options['fields']['request_time']['date_format'] = 'custom';
  $handler->display->display_options['fields']['request_time']['custom_date_format'] = 'Y-m-d H:i:s';
  /* Field: Feeds log: Log message */
  $handler->display->display_options['fields']['message']['id'] = 'message';
  $handler->display->display_options['fields']['message']['table'] = 'feeds_log';
  $handler->display->display_options['fields']['message']['field'] = 'message';
  $handler->display->display_options['fields']['message']['label'] = 'Message';
  $handler->display->display_options['fields']['message']['hide_empty'] = 0;
  $handler->display->display_options['fields']['message']['empty_zero'] = 0;
  /* Field: Feeds log: Severity */
  $handler->display->display_options['fields']['severity']['id'] = 'severity';
  $handler->display->display_options['fields']['severity']['table'] = 'feeds_log';
  $handler->display->display_options['fields']['severity']['field'] = 'severity';
  $handler->display->display_options['fields']['severity']['hide_empty'] = 0;
  $handler->display->display_options['fields']['severity']['empty_zero'] = 0;
  /* Sort criterion: Feeds log: Log time */
  $handler->display->display_options['sorts']['log_time']['id'] = 'log_time';
  $handler->display->display_options['sorts']['log_time']['table'] = 'feeds_log';
  $handler->display->display_options['sorts']['log_time']['field'] = 'log_time';
  $handler->display->display_options['sorts']['log_time']['order'] = 'DESC';
  /* Argument: Feeds log: Importer id */
  $handler->display->display_options['arguments']['id']['id'] = 'id';
  $handler->display->display_options['arguments']['id']['table'] = 'feeds_log';
  $handler->display->display_options['arguments']['id']['field'] = 'id';
  $handler->display->display_options['arguments']['id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['id']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['id']['validate_fail'] = 'empty';
  $handler->display->display_options['arguments']['id']['glossary'] = 0;
  $handler->display->display_options['arguments']['id']['limit'] = '0';
  $handler->display->display_options['arguments']['id']['transform_dash'] = 0;
  /* Filter: Feeds log: Feed node id */
  $handler->display->display_options['filters']['feed_nid']['id'] = 'feed_nid';
  $handler->display->display_options['filters']['feed_nid']['table'] = 'feeds_log';
  $handler->display->display_options['filters']['feed_nid']['field'] = 'feed_nid';
  $handler->display->display_options['filters']['feed_nid']['value']['value'] = '0';
  /* Filter: Feeds log: Severity */
  $handler->display->display_options['filters']['severity']['id'] = 'severity';
  $handler->display->display_options['filters']['severity']['table'] = 'feeds_log';
  $handler->display->display_options['filters']['severity']['field'] = 'severity';
  $handler->display->display_options['filters']['severity']['exposed'] = TRUE;
  $handler->display->display_options['filters']['severity']['expose']['operator'] = 'severity_op';
  $handler->display->display_options['filters']['severity']['expose']['label'] = 'Severity';
  $handler->display->display_options['filters']['severity']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['severity']['expose']['identifier'] = 'severity';
  $handler->display->display_options['filters']['severity']['expose']['reduce'] = 0;

  /* Display: Standalone importer page */
  $handler = $view->new_display('page', 'Standalone importer page', 'page_1');
  $handler->display->display_options['path'] = 'import/%/log';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Log';
  $handler->display->display_options['menu']['weight'] = '0';

  /* Display: Feed node page */
  $handler = $view->new_display('page', 'Feed node page', 'page_2');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: Feeds log: Feed node id */
  $handler->display->display_options['arguments']['feed_nid']['id'] = 'feed_nid';
  $handler->display->display_options['arguments']['feed_nid']['table'] = 'feeds_log';
  $handler->display->display_options['arguments']['feed_nid']['field'] = 'feed_nid';
  $handler->display->display_options['arguments']['feed_nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['feed_nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['feed_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['feed_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['feed_nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter: Feeds log: Severity */
  $handler->display->display_options['filters']['severity']['id'] = 'severity';
  $handler->display->display_options['filters']['severity']['table'] = 'feeds_log';
  $handler->display->display_options['filters']['severity']['field'] = 'severity';
  $handler->display->display_options['filters']['severity']['exposed'] = TRUE;
  $handler->display->display_options['filters']['severity']['expose']['operator'] = 'severity_op';
  $handler->display->display_options['filters']['severity']['expose']['label'] = 'Severity';
  $handler->display->display_options['filters']['severity']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['severity']['expose']['identifier'] = 'severity';
  $handler->display->display_options['filters']['severity']['expose']['reduce'] = 0;
  $handler->display->display_options['path'] = 'node/%/log';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Log';
  $handler->display->display_options['menu']['weight'] = '12';

  /* Display: All entries */
  $handler = $view->new_display('page', 'All entries', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Feeds log';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Feeds log: Feed node */
  $handler->display->display_options['relationships']['feed_nid']['id'] = 'feed_nid';
  $handler->display->display_options['relationships']['feed_nid']['table'] = 'feeds_log';
  $handler->display->display_options['relationships']['feed_nid']['field'] = 'feed_nid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Feeds log: Log time */
  $handler->display->display_options['fields']['log_time']['id'] = 'log_time';
  $handler->display->display_options['fields']['log_time']['table'] = 'feeds_log';
  $handler->display->display_options['fields']['log_time']['field'] = 'log_time';
  $handler->display->display_options['fields']['log_time']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['log_time']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['log_time']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['log_time']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['log_time']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['log_time']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['log_time']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['log_time']['alter']['html'] = 0;
  $handler->display->display_options['fields']['log_time']['hide_empty'] = 0;
  $handler->display->display_options['fields']['log_time']['empty_zero'] = 0;
  $handler->display->display_options['fields']['log_time']['date_format'] = 'custom';
  $handler->display->display_options['fields']['log_time']['custom_date_format'] = 'Y-m-d H:i:s';
  /* Field: Feeds log: Request time */
  $handler->display->display_options['fields']['request_time']['id'] = 'request_time';
  $handler->display->display_options['fields']['request_time']['table'] = 'feeds_log';
  $handler->display->display_options['fields']['request_time']['field'] = 'request_time';
  $handler->display->display_options['fields']['request_time']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['request_time']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['request_time']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['request_time']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['request_time']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['request_time']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['request_time']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['request_time']['alter']['html'] = 0;
  $handler->display->display_options['fields']['request_time']['hide_empty'] = 0;
  $handler->display->display_options['fields']['request_time']['empty_zero'] = 0;
  $handler->display->display_options['fields']['request_time']['date_format'] = 'custom';
  $handler->display->display_options['fields']['request_time']['custom_date_format'] = 'Y-m-d H:i:s';
  /* Field: Feeds log: Log message */
  $handler->display->display_options['fields']['message']['id'] = 'message';
  $handler->display->display_options['fields']['message']['table'] = 'feeds_log';
  $handler->display->display_options['fields']['message']['field'] = 'message';
  $handler->display->display_options['fields']['message']['label'] = 'Message';
  $handler->display->display_options['fields']['message']['hide_empty'] = 0;
  $handler->display->display_options['fields']['message']['empty_zero'] = 0;
  /* Field: Feeds log: Severity */
  $handler->display->display_options['fields']['severity']['id'] = 'severity';
  $handler->display->display_options['fields']['severity']['table'] = 'feeds_log';
  $handler->display->display_options['fields']['severity']['field'] = 'severity';
  $handler->display->display_options['fields']['severity']['hide_empty'] = 0;
  $handler->display->display_options['fields']['severity']['empty_zero'] = 0;
  /* Field: Feeds log: Importer name */
  $handler->display->display_options['fields']['importer_name']['id'] = 'importer_name';
  $handler->display->display_options['fields']['importer_name']['table'] = 'feeds_log';
  $handler->display->display_options['fields']['importer_name']['field'] = 'importer_name';
  $handler->display->display_options['fields']['importer_name']['label'] = 'Importer';
  $handler->display->display_options['fields']['importer_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['importer_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['importer_name']['link'] = '2';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'feed_nid';
  $handler->display->display_options['fields']['title']['label'] = 'Feed node';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter: Feeds log: Severity */
  $handler->display->display_options['filters']['severity']['id'] = 'severity';
  $handler->display->display_options['filters']['severity']['table'] = 'feeds_log';
  $handler->display->display_options['filters']['severity']['field'] = 'severity';
  $handler->display->display_options['filters']['severity']['exposed'] = TRUE;
  $handler->display->display_options['filters']['severity']['expose']['operator'] = 'severity_op';
  $handler->display->display_options['filters']['severity']['expose']['label'] = 'Severity';
  $handler->display->display_options['filters']['severity']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['severity']['expose']['identifier'] = 'severity';
  $handler->display->display_options['filters']['severity']['expose']['reduce'] = 0;
  $handler->display->display_options['path'] = 'admin/reports/feeds';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Feeds log';
  $handler->display->display_options['menu']['description'] = 'Review log messages of imports and subscriptions to feeds.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';

  $views[$view->name] = $view;

  return $views;
}

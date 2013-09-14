<?php
/**
 * @file
 * rus_structure.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function rus_structure_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'broadcast_schedule';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Broadcast Schedule';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Broadcast Schedule';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'jcarousel';
  $handler->display->display_options['style_options']['wrap'] = '0';
  $handler->display->display_options['style_options']['visible'] = '';
  $handler->display->display_options['style_options']['auto'] = '0';
  $handler->display->display_options['style_options']['autoPause'] = 1;
  $handler->display->display_options['style_options']['easing'] = '';
  $handler->display->display_options['style_options']['vertical'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<a href="browse" class="view-archive-link">Archives</a>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No events have been scheduled.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: Content: Away Team (field_term_team_away) */
  $handler->display->display_options['relationships']['field_term_team_away_tid']['id'] = 'field_term_team_away_tid';
  $handler->display->display_options['relationships']['field_term_team_away_tid']['table'] = 'field_data_field_term_team_away';
  $handler->display->display_options['relationships']['field_term_team_away_tid']['field'] = 'field_term_team_away_tid';
  /* Relationship: Content: Home Team (field_term_team_home) */
  $handler->display->display_options['relationships']['field_term_team_home_tid']['id'] = 'field_term_team_home_tid';
  $handler->display->display_options['relationships']['field_term_team_home_tid']['table'] = 'field_data_field_term_team_home';
  $handler->display->display_options['relationships']['field_term_team_home_tid']['field'] = 'field_term_team_home_tid';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_datetime']['id'] = 'field_datetime';
  $handler->display->display_options['fields']['field_datetime']['table'] = 'field_data_field_datetime';
  $handler->display->display_options['fields']['field_datetime']['field'] = 'field_datetime';
  $handler->display->display_options['fields']['field_datetime']['label'] = '';
  $handler->display->display_options['fields']['field_datetime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datetime']['settings'] = array(
    'format_type' => 'broadcast_schedule',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Field: Gender */
  $handler->display->display_options['fields']['field_term_gender']['id'] = 'field_term_gender';
  $handler->display->display_options['fields']['field_term_gender']['table'] = 'field_data_field_term_gender';
  $handler->display->display_options['fields']['field_term_gender']['field'] = 'field_term_gender';
  $handler->display->display_options['fields']['field_term_gender']['label'] = '';
  $handler->display->display_options['fields']['field_term_gender']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_gender']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_gender']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_term_gender']['delta_offset'] = '0';
  /* Field: Field: Level */
  $handler->display->display_options['fields']['field_term_level']['id'] = 'field_term_level';
  $handler->display->display_options['fields']['field_term_level']['table'] = 'field_data_field_term_level';
  $handler->display->display_options['fields']['field_term_level']['field'] = 'field_term_level';
  $handler->display->display_options['fields']['field_term_level']['label'] = '';
  $handler->display->display_options['fields']['field_term_level']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_level']['alter']['max_length'] = '2';
  $handler->display->display_options['fields']['field_term_level']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_term_level']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['field_term_level']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_level']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_term_level']['delta_offset'] = '0';
  /* Field: Content: Away Team */
  $handler->display->display_options['fields']['field_term_team_away']['id'] = 'field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['table'] = 'field_data_field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['field'] = 'field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['label'] = '';
  $handler->display->display_options['fields']['field_term_team_away']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_team_away']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_team_away']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Home Team */
  $handler->display->display_options['fields']['field_term_team_home']['id'] = 'field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['table'] = 'field_data_field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['field'] = 'field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['label'] = '';
  $handler->display->display_options['fields']['field_term_team_home']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_team_home']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_team_home']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Sport */
  $handler->display->display_options['fields']['field_term_sport']['id'] = 'field_term_sport';
  $handler->display->display_options['fields']['field_term_sport']['table'] = 'field_data_field_term_sport';
  $handler->display->display_options['fields']['field_term_sport']['field'] = 'field_term_sport';
  $handler->display->display_options['fields']['field_term_sport']['label'] = '';
  $handler->display->display_options['fields']['field_term_sport']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_term_sport']['alter']['text'] = '[field_term_gender] [field_term_level]. [field_term_sport]';
  $handler->display->display_options['fields']['field_term_sport']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_sport']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Taxonomy term: Team Abbreviation */
  $handler->display->display_options['fields']['field_abbreviation']['id'] = 'field_abbreviation';
  $handler->display->display_options['fields']['field_abbreviation']['table'] = 'field_data_field_abbreviation';
  $handler->display->display_options['fields']['field_abbreviation']['field'] = 'field_abbreviation';
  $handler->display->display_options['fields']['field_abbreviation']['relationship'] = 'field_term_team_away_tid';
  $handler->display->display_options['fields']['field_abbreviation']['label'] = '';
  $handler->display->display_options['fields']['field_abbreviation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_abbreviation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_abbreviation']['type'] = 'text_plain';
  /* Field: Taxonomy term: Team Abbreviation */
  $handler->display->display_options['fields']['field_abbreviation_1']['id'] = 'field_abbreviation_1';
  $handler->display->display_options['fields']['field_abbreviation_1']['table'] = 'field_data_field_abbreviation';
  $handler->display->display_options['fields']['field_abbreviation_1']['field'] = 'field_abbreviation';
  $handler->display->display_options['fields']['field_abbreviation_1']['relationship'] = 'field_term_team_home_tid';
  $handler->display->display_options['fields']['field_abbreviation_1']['label'] = '';
  $handler->display->display_options['fields']['field_abbreviation_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_abbreviation_1']['alter']['text'] = '[field_abbreviation] @ [field_abbreviation_1-value]';
  $handler->display->display_options['fields']['field_abbreviation_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_abbreviation_1']['type'] = 'text_plain';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Date -  start date (field_datetime) */
  $handler->display->display_options['sorts']['field_datetime_value']['id'] = 'field_datetime_value';
  $handler->display->display_options['sorts']['field_datetime_value']['table'] = 'field_data_field_datetime';
  $handler->display->display_options['sorts']['field_datetime_value']['field'] = 'field_datetime_value';
  /* Filter criterion: Content: Date -  start date (field_datetime) */
  $handler->display->display_options['filters']['field_datetime_value']['id'] = 'field_datetime_value';
  $handler->display->display_options['filters']['field_datetime_value']['table'] = 'field_data_field_datetime';
  $handler->display->display_options['filters']['field_datetime_value']['field'] = 'field_datetime_value';
  $handler->display->display_options['filters']['field_datetime_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_datetime_value']['group'] = 1;
  $handler->display->display_options['filters']['field_datetime_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_datetime_value']['default_date'] = 'now';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 1;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['block_caching'] = '8';
  $export['broadcast_schedule'] = $view;

  $view = new view();
  $view->name = 'browse';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'browse';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_image' => 'field_image',
    'field_term_gender' => 'field_term_gender',
    'field_term_sport' => 'field_term_sport',
    'field_term_categories' => 'field_term_categories',
    'field_term_team_home' => 'field_term_team_home',
    'field_score_home' => 'field_score_home',
    'field_term_team_away' => 'field_term_team_away',
    'field_score_away' => 'field_score_away',
    'field_term_level' => 'field_term_level',
    'field_duration' => 'field_duration',
    'field_term_month' => 'field_term_month',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_term_gender' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_term_sport' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_term_categories' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_term_team_home' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_score_home' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_term_team_away' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_score_away' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_term_level' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_duration' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_term_month' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Field: Team Logo */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = 'Image';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'w70',
    'image_link' => 'content',
  );
  /* Field: Field: Gender */
  $handler->display->display_options['fields']['field_term_gender']['id'] = 'field_term_gender';
  $handler->display->display_options['fields']['field_term_gender']['table'] = 'field_data_field_term_gender';
  $handler->display->display_options['fields']['field_term_gender']['field'] = 'field_term_gender';
  $handler->display->display_options['fields']['field_term_gender']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_term_gender']['delta_offset'] = '0';
  /* Field: Content: Sport */
  $handler->display->display_options['fields']['field_term_sport']['id'] = 'field_term_sport';
  $handler->display->display_options['fields']['field_term_sport']['table'] = 'field_data_field_term_sport';
  $handler->display->display_options['fields']['field_term_sport']['field'] = 'field_term_sport';
  $handler->display->display_options['fields']['field_term_sport']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_term_categories']['id'] = 'field_term_categories';
  $handler->display->display_options['fields']['field_term_categories']['table'] = 'field_data_field_term_categories';
  $handler->display->display_options['fields']['field_term_categories']['field'] = 'field_term_categories';
  $handler->display->display_options['fields']['field_term_categories']['label'] = 'Video Type';
  $handler->display->display_options['fields']['field_term_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_term_categories']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_term_categories']['delta_offset'] = '0';
  /* Field: Content: Home Team */
  $handler->display->display_options['fields']['field_term_team_home']['id'] = 'field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['table'] = 'field_data_field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['field'] = 'field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Home Team Score */
  $handler->display->display_options['fields']['field_score_home']['id'] = 'field_score_home';
  $handler->display->display_options['fields']['field_score_home']['table'] = 'field_data_field_score_home';
  $handler->display->display_options['fields']['field_score_home']['field'] = 'field_score_home';
  $handler->display->display_options['fields']['field_score_home']['label'] = 'Home Score';
  $handler->display->display_options['fields']['field_score_home']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Away Team */
  $handler->display->display_options['fields']['field_term_team_away']['id'] = 'field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['table'] = 'field_data_field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['field'] = 'field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_team_away']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Away Team Score */
  $handler->display->display_options['fields']['field_score_away']['id'] = 'field_score_away';
  $handler->display->display_options['fields']['field_score_away']['table'] = 'field_data_field_score_away';
  $handler->display->display_options['fields']['field_score_away']['field'] = 'field_score_away';
  $handler->display->display_options['fields']['field_score_away']['label'] = 'Away Score';
  $handler->display->display_options['fields']['field_score_away']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Level */
  $handler->display->display_options['fields']['field_term_level']['id'] = 'field_term_level';
  $handler->display->display_options['fields']['field_term_level']['table'] = 'field_data_field_term_level';
  $handler->display->display_options['fields']['field_term_level']['field'] = 'field_term_level';
  $handler->display->display_options['fields']['field_term_level']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_level']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_term_level']['delta_offset'] = '0';
  /* Field: Content: Duration */
  $handler->display->display_options['fields']['field_duration']['id'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['table'] = 'field_data_field_duration';
  $handler->display->display_options['fields']['field_duration']['field'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['click_sort_column'] = 'timestamp';
  $handler->display->display_options['fields']['field_duration']['settings'] = array(
    'use_override' => 'none',
    'format' => 'medium',
    'component_settings' => array(
      'meridiem' => 'a',
      'year_designation' => 'ce',
      'display' => array(
        'year' => 'estimate_label',
        'month' => 'estimate_label',
        'day' => 'estimate_label',
        'hour' => 'estimate_label',
        'minute' => 'estimate_label',
        'second' => 'estimate_label',
        'timezone' => 'date_only',
      ),
      'separator' => array(
        'date' => ' ',
        'time' => ':',
        'datetime' => ' ',
        'other' => ' ',
        'range' => '',
      ),
      'components' => array(
        'year' => array(
          'format' => 'Y-ce',
          'empty' => '',
          'weight' => '0',
        ),
        'month' => array(
          'format' => 'M',
          'empty' => '',
          'weight' => '1',
        ),
        'day' => array(
          'format' => 'j-S',
          'empty' => '',
          'weight' => '2',
        ),
        'hour' => array(
          'format' => 'h',
          'empty' => '',
          'weight' => '3',
        ),
        'minute' => array(
          'format' => 'i',
          'empty' => '',
          'weight' => '4',
        ),
        'second' => array(
          'format' => 's',
          'empty' => '',
          'weight' => '5',
        ),
        'timezone' => array(
          'format' => 'T',
          'empty' => '',
          'weight' => '6',
        ),
        'c1' => array(
          'value' => '',
          'weight' => '7',
        ),
        'c2' => array(
          'value' => '',
          'weight' => '8',
        ),
        'c3' => array(
          'value' => '',
          'weight' => '9',
        ),
      ),
    ),
  );
  /* Field: Content: Month */
  $handler->display->display_options['fields']['field_term_month']['id'] = 'field_term_month';
  $handler->display->display_options['fields']['field_term_month']['table'] = 'field_data_field_term_month';
  $handler->display->display_options['fields']['field_term_month']['field'] = 'field_term_month';
  $handler->display->display_options['fields']['field_term_month']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_month']['type'] = 'taxonomy_term_reference_plain';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'scoreboard' => 'scoreboard',
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  /* Filter criterion: Content: Home Team (field_term_team_home) */
  $handler->display->display_options['filters']['field_term_team_home_tid']['id'] = 'field_term_team_home_tid';
  $handler->display->display_options['filters']['field_term_team_home_tid']['table'] = 'field_data_field_term_team_home';
  $handler->display->display_options['filters']['field_term_team_home_tid']['field'] = 'field_term_team_home_tid';
  $handler->display->display_options['filters']['field_term_team_home_tid']['value'] = '';
  $handler->display->display_options['filters']['field_term_team_home_tid']['group'] = '0';
  $handler->display->display_options['filters']['field_term_team_home_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_team_home_tid']['expose']['operator_id'] = 'field_term_team_home_tid_op';
  $handler->display->display_options['filters']['field_term_team_home_tid']['expose']['label'] = 'Home Team';
  $handler->display->display_options['filters']['field_term_team_home_tid']['expose']['operator'] = 'field_term_team_home_tid_op';
  $handler->display->display_options['filters']['field_term_team_home_tid']['expose']['identifier'] = 'field_term_team_home_tid';
  $handler->display->display_options['filters']['field_term_team_home_tid']['vocabulary'] = 'team';
  /* Filter criterion: Content: Away Team (field_term_team_away) */
  $handler->display->display_options['filters']['field_term_team_away_tid']['id'] = 'field_term_team_away_tid';
  $handler->display->display_options['filters']['field_term_team_away_tid']['table'] = 'field_data_field_term_team_away';
  $handler->display->display_options['filters']['field_term_team_away_tid']['field'] = 'field_term_team_away_tid';
  $handler->display->display_options['filters']['field_term_team_away_tid']['value'] = '';
  $handler->display->display_options['filters']['field_term_team_away_tid']['group'] = '0';
  $handler->display->display_options['filters']['field_term_team_away_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_team_away_tid']['expose']['operator_id'] = 'field_term_team_away_tid_op';
  $handler->display->display_options['filters']['field_term_team_away_tid']['expose']['label'] = 'Away Team';
  $handler->display->display_options['filters']['field_term_team_away_tid']['expose']['operator'] = 'field_term_team_away_tid_op';
  $handler->display->display_options['filters']['field_term_team_away_tid']['expose']['identifier'] = 'field_term_team_away_tid';
  $handler->display->display_options['filters']['field_term_team_away_tid']['vocabulary'] = 'team';
  /* Filter criterion: Content: Sport (field_term_sport) */
  $handler->display->display_options['filters']['field_term_sport_tid']['id'] = 'field_term_sport_tid';
  $handler->display->display_options['filters']['field_term_sport_tid']['table'] = 'field_data_field_term_sport';
  $handler->display->display_options['filters']['field_term_sport_tid']['field'] = 'field_term_sport_tid';
  $handler->display->display_options['filters']['field_term_sport_tid']['group'] = '0';
  $handler->display->display_options['filters']['field_term_sport_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_sport_tid']['expose']['operator_id'] = 'field_term_sport_tid_op';
  $handler->display->display_options['filters']['field_term_sport_tid']['expose']['label'] = 'Sport';
  $handler->display->display_options['filters']['field_term_sport_tid']['expose']['operator'] = 'field_term_sport_tid_op';
  $handler->display->display_options['filters']['field_term_sport_tid']['expose']['identifier'] = 'field_term_sport_tid';
  $handler->display->display_options['filters']['field_term_sport_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_sport_tid']['vocabulary'] = 'sport';
  /* Filter criterion: Content: Category (field_term_categories) */
  $handler->display->display_options['filters']['field_term_categories_tid']['id'] = 'field_term_categories_tid';
  $handler->display->display_options['filters']['field_term_categories_tid']['table'] = 'field_data_field_term_categories';
  $handler->display->display_options['filters']['field_term_categories_tid']['field'] = 'field_term_categories_tid';
  $handler->display->display_options['filters']['field_term_categories_tid']['group'] = '0';
  $handler->display->display_options['filters']['field_term_categories_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_categories_tid']['expose']['operator_id'] = 'field_term_categories_tid_op';
  $handler->display->display_options['filters']['field_term_categories_tid']['expose']['label'] = 'Video Type';
  $handler->display->display_options['filters']['field_term_categories_tid']['expose']['operator'] = 'field_term_categories_tid_op';
  $handler->display->display_options['filters']['field_term_categories_tid']['expose']['identifier'] = 'field_term_categories_tid';
  $handler->display->display_options['filters']['field_term_categories_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_term_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_categories_tid']['vocabulary'] = 'category';
  /* Filter criterion: Field: Gender (field_term_gender) */
  $handler->display->display_options['filters']['field_term_gender_tid']['id'] = 'field_term_gender_tid';
  $handler->display->display_options['filters']['field_term_gender_tid']['table'] = 'field_data_field_term_gender';
  $handler->display->display_options['filters']['field_term_gender_tid']['field'] = 'field_term_gender_tid';
  $handler->display->display_options['filters']['field_term_gender_tid']['group'] = '0';
  $handler->display->display_options['filters']['field_term_gender_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_gender_tid']['expose']['operator_id'] = 'field_term_gender_tid_op';
  $handler->display->display_options['filters']['field_term_gender_tid']['expose']['label'] = 'Gender';
  $handler->display->display_options['filters']['field_term_gender_tid']['expose']['operator'] = 'field_term_gender_tid_op';
  $handler->display->display_options['filters']['field_term_gender_tid']['expose']['identifier'] = 'field_term_gender_tid';
  $handler->display->display_options['filters']['field_term_gender_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_gender_tid']['vocabulary'] = 'gender';
  /* Filter criterion: Field: Level (field_term_level) */
  $handler->display->display_options['filters']['field_term_level_tid']['id'] = 'field_term_level_tid';
  $handler->display->display_options['filters']['field_term_level_tid']['table'] = 'field_data_field_term_level';
  $handler->display->display_options['filters']['field_term_level_tid']['field'] = 'field_term_level_tid';
  $handler->display->display_options['filters']['field_term_level_tid']['group'] = '0';
  $handler->display->display_options['filters']['field_term_level_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_level_tid']['expose']['operator_id'] = 'field_term_level_tid_op';
  $handler->display->display_options['filters']['field_term_level_tid']['expose']['label'] = 'Levels';
  $handler->display->display_options['filters']['field_term_level_tid']['expose']['operator'] = 'field_term_level_tid_op';
  $handler->display->display_options['filters']['field_term_level_tid']['expose']['identifier'] = 'field_term_level_tid';
  $handler->display->display_options['filters']['field_term_level_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_level_tid']['vocabulary'] = 'level';
  /* Filter criterion: Content: Month (field_term_month) */
  $handler->display->display_options['filters']['field_term_month_tid']['id'] = 'field_term_month_tid';
  $handler->display->display_options['filters']['field_term_month_tid']['table'] = 'field_data_field_term_month';
  $handler->display->display_options['filters']['field_term_month_tid']['field'] = 'field_term_month_tid';
  $handler->display->display_options['filters']['field_term_month_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_month_tid']['expose']['operator_id'] = 'field_term_month_tid_op';
  $handler->display->display_options['filters']['field_term_month_tid']['expose']['label'] = 'Month';
  $handler->display->display_options['filters']['field_term_month_tid']['expose']['operator'] = 'field_term_month_tid_op';
  $handler->display->display_options['filters']['field_term_month_tid']['expose']['identifier'] = 'field_term_month_tid';
  $handler->display->display_options['filters']['field_term_month_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_month_tid']['vocabulary'] = 'month';
  /* Filter criterion: Content: School Year (field_term_year) */
  $handler->display->display_options['filters']['field_term_year_tid']['id'] = 'field_term_year_tid';
  $handler->display->display_options['filters']['field_term_year_tid']['table'] = 'field_data_field_term_year';
  $handler->display->display_options['filters']['field_term_year_tid']['field'] = 'field_term_year_tid';
  $handler->display->display_options['filters']['field_term_year_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_year_tid']['expose']['operator_id'] = 'field_term_year_tid_op';
  $handler->display->display_options['filters']['field_term_year_tid']['expose']['label'] = 'School Year';
  $handler->display->display_options['filters']['field_term_year_tid']['expose']['operator'] = 'field_term_year_tid_op';
  $handler->display->display_options['filters']['field_term_year_tid']['expose']['identifier'] = 'field_term_year_tid';
  $handler->display->display_options['filters']['field_term_year_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_year_tid']['vocabulary'] = 'year';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'browse';
  $export['browse'] = $view;

  $view = new view();
  $view->name = 'crew';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Crew';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Crew';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field: Team Logo */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '300x300',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Job Titles */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_title']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_job_title']['settings'] = array(
    'trim_length' => '12',
  );
  $handler->display->display_options['fields']['field_job_title']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_job_title']['delta_offset'] = '0';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'crew' => 'crew',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'crew';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $export['crew'] = $view;

  $view = new view();
  $view->name = 'footer_block_ads';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Footer Block Ads';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Footer Block Ads';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '300';
  $handler->display->display_options['cache']['output_lifespan'] = '300';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: External Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Field: Team Logo */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['path'] = '[field_link]';
  $handler->display->display_options['fields']['field_image']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '220x220',
    'image_link' => '',
  );
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'block_ad' => 'block_ad',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['footer_block_ads'] = $view;

  $view = new view();
  $view->name = 'home_video';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Home Video';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '300';
  $handler->display->display_options['cache']['output_lifespan'] = '300';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['home_video'] = $view;

  $view = new view();
  $view->name = 'live_event_banner';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Live Event Banner';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<img src="/sites/all/modules/custom/rus_modules/rus_helper/images/live-event-banner.jpg" />';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Date -  start date (field_datetime) */
  $handler->display->display_options['filters']['field_datetime_value']['id'] = 'field_datetime_value';
  $handler->display->display_options['filters']['field_datetime_value']['table'] = 'field_data_field_datetime';
  $handler->display->display_options['filters']['field_datetime_value']['field'] = 'field_datetime_value';
  $handler->display->display_options['filters']['field_datetime_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_datetime_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_datetime_value']['default_date'] = 'now -2 min';
  /* Filter criterion: Content: Date - end date (field_datetime:value2) */
  $handler->display->display_options['filters']['field_datetime_value2']['id'] = 'field_datetime_value2';
  $handler->display->display_options['filters']['field_datetime_value2']['table'] = 'field_data_field_datetime';
  $handler->display->display_options['filters']['field_datetime_value2']['field'] = 'field_datetime_value2';
  $handler->display->display_options['filters']['field_datetime_value2']['operator'] = '>';
  $handler->display->display_options['filters']['field_datetime_value2']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_datetime_value2']['default_date'] = 'now +2 min';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['live_event_banner'] = $view;

  $view = new view();
  $view->name = 'live_event_player';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Live Event Player';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Date -  start date (field_datetime) */
  $handler->display->display_options['filters']['field_datetime_value']['id'] = 'field_datetime_value';
  $handler->display->display_options['filters']['field_datetime_value']['table'] = 'field_data_field_datetime';
  $handler->display->display_options['filters']['field_datetime_value']['field'] = 'field_datetime_value';
  $handler->display->display_options['filters']['field_datetime_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_datetime_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_datetime_value']['default_date'] = 'now -2 min';
  /* Filter criterion: Content: Date - end date (field_datetime:value2) */
  $handler->display->display_options['filters']['field_datetime_value2']['id'] = 'field_datetime_value2';
  $handler->display->display_options['filters']['field_datetime_value2']['table'] = 'field_data_field_datetime';
  $handler->display->display_options['filters']['field_datetime_value2']['field'] = 'field_datetime_value2';
  $handler->display->display_options['filters']['field_datetime_value2']['operator'] = '>';
  $handler->display->display_options['filters']['field_datetime_value2']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_datetime_value2']['default_date'] = 'now +2 min';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['live_event_player'] = $view;

  $view = new view();
  $view->name = 'mega_listing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Mega Listing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Mens Varsity';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'browse?field_term_gender_tid=19&field_term_level_tid=7&field_term_sport_tid=[tid]';
  $handler->display->display_options['fields']['name']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'sport' => 'sport',
  );
  /* Filter criterion: Field: Gender (field_term_gender) */
  $handler->display->display_options['filters']['field_term_gender_tid']['id'] = 'field_term_gender_tid';
  $handler->display->display_options['filters']['field_term_gender_tid']['table'] = 'field_data_field_term_gender';
  $handler->display->display_options['filters']['field_term_gender_tid']['field'] = 'field_term_gender_tid';
  $handler->display->display_options['filters']['field_term_gender_tid']['value'] = array(
    19 => '19',
  );
  $handler->display->display_options['filters']['field_term_gender_tid']['group'] = '0';
  $handler->display->display_options['filters']['field_term_gender_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_gender_tid']['vocabulary'] = 'gender';
  /* Filter criterion: Field: Level (field_term_level) */
  $handler->display->display_options['filters']['field_term_level_tid']['id'] = 'field_term_level_tid';
  $handler->display->display_options['filters']['field_term_level_tid']['table'] = 'field_data_field_term_level';
  $handler->display->display_options['filters']['field_term_level_tid']['field'] = 'field_term_level_tid';
  $handler->display->display_options['filters']['field_term_level_tid']['value'] = array(
    7 => '7',
  );
  $handler->display->display_options['filters']['field_term_level_tid']['group'] = '0';
  $handler->display->display_options['filters']['field_term_level_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_level_tid']['vocabulary'] = 'level';
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = '$term_game = 0;
$query = db_select(\'taxonomy_term_data\', \'td\');
$query->fields(\'td\', array(\'tid\', \'name\'));
$query->condition(\'td.name\', \'game\');
$term_game = $query->execute()->fetchField();

$query = db_select(\'node\', \'n\');
$t_alias = $query->innerJoin(\'taxonomy_index\', \'t\', \'%alias.nid = n.nid\');
$t2_alias = $query->innerJoin(\'taxonomy_index\', \'t2\', \'%alias.nid = n.nid\');
$query->condition(\'n.status\', 1);
$query->condition("${t_alias}.tid", $row->tid);
$query->condition("${t2_alias}.tid", $term_game);
$num_rows = $query->countQuery()->execute()->fetchField();
if($num_rows == 0){
  return TRUE;
}
';

  /* Display: Mens Varsity */
  $handler = $view->new_display('block', 'Mens Varsity', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Mens Sophomore */
  $handler = $view->new_display('block', 'Mens Sophomore', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Mens Sophomore';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'browse?field_term_gender_tid=19&field_term_level_tid=9&field_term_sport_tid=[tid]';
  $handler->display->display_options['fields']['name']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'sport' => 'sport',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filter criterion: Field: Gender (field_term_gender) */
  $handler->display->display_options['filters']['field_term_gender_tid']['id'] = 'field_term_gender_tid';
  $handler->display->display_options['filters']['field_term_gender_tid']['table'] = 'field_data_field_term_gender';
  $handler->display->display_options['filters']['field_term_gender_tid']['field'] = 'field_term_gender_tid';
  $handler->display->display_options['filters']['field_term_gender_tid']['value'] = array(
    19 => '19',
  );
  $handler->display->display_options['filters']['field_term_gender_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_gender_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_gender_tid']['vocabulary'] = 'gender';
  /* Filter criterion: Field: Level (field_term_level) */
  $handler->display->display_options['filters']['field_term_level_tid']['id'] = 'field_term_level_tid';
  $handler->display->display_options['filters']['field_term_level_tid']['table'] = 'field_data_field_term_level';
  $handler->display->display_options['filters']['field_term_level_tid']['field'] = 'field_term_level_tid';
  $handler->display->display_options['filters']['field_term_level_tid']['value'] = array(
    9 => '9',
  );
  $handler->display->display_options['filters']['field_term_level_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_level_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_level_tid']['vocabulary'] = 'level';
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = '$term_game = 0;
$query = db_select(\'taxonomy_term_data\', \'td\');
$query->fields(\'td\', array(\'tid\', \'name\'));
$query->condition(\'td.name\', \'game\');
$term_game = $query->execute()->fetchField();

$query = db_select(\'node\', \'n\');
$t_alias = $query->innerJoin(\'taxonomy_index\', \'t\', \'%alias.nid = n.nid\');
$t2_alias = $query->innerJoin(\'taxonomy_index\', \'t2\', \'%alias.nid = n.nid\');
$query->condition(\'n.status\', 1);
$query->condition("${t_alias}.tid", $row->tid);
$query->condition("${t2_alias}.tid", $term_game);
$num_rows = $query->countQuery()->execute()->fetchField();
if($num_rows == 0){
  return TRUE;
}
';

  /* Display: Mens Freshman */
  $handler = $view->new_display('block', 'Mens Freshman', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Mens Freshman';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'browse?field_term_gender_tid=19&field_term_level_tid=8&field_term_sport_tid=[tid]';
  $handler->display->display_options['fields']['name']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'sport' => 'sport',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filter criterion: Field: Gender (field_term_gender) */
  $handler->display->display_options['filters']['field_term_gender_tid']['id'] = 'field_term_gender_tid';
  $handler->display->display_options['filters']['field_term_gender_tid']['table'] = 'field_data_field_term_gender';
  $handler->display->display_options['filters']['field_term_gender_tid']['field'] = 'field_term_gender_tid';
  $handler->display->display_options['filters']['field_term_gender_tid']['value'] = array(
    19 => '19',
  );
  $handler->display->display_options['filters']['field_term_gender_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_gender_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_gender_tid']['vocabulary'] = 'gender';
  /* Filter criterion: Field: Level (field_term_level) */
  $handler->display->display_options['filters']['field_term_level_tid']['id'] = 'field_term_level_tid';
  $handler->display->display_options['filters']['field_term_level_tid']['table'] = 'field_data_field_term_level';
  $handler->display->display_options['filters']['field_term_level_tid']['field'] = 'field_term_level_tid';
  $handler->display->display_options['filters']['field_term_level_tid']['value'] = array(
    8 => '8',
  );
  $handler->display->display_options['filters']['field_term_level_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_level_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_level_tid']['vocabulary'] = 'level';
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = '$term_game = 0;
$query = db_select(\'taxonomy_term_data\', \'td\');
$query->fields(\'td\', array(\'tid\', \'name\'));
$query->condition(\'td.name\', \'game\');
$term_game = $query->execute()->fetchField();

$query = db_select(\'node\', \'n\');
$t_alias = $query->innerJoin(\'taxonomy_index\', \'t\', \'%alias.nid = n.nid\');
$t2_alias = $query->innerJoin(\'taxonomy_index\', \'t2\', \'%alias.nid = n.nid\');
$query->condition(\'n.status\', 1);
$query->condition("${t_alias}.tid", $row->tid);
$query->condition("${t2_alias}.tid", $term_game);
$num_rows = $query->countQuery()->execute()->fetchField();
if($num_rows == 0){
  return TRUE;
}
';

  /* Display: Womens Varsity */
  $handler = $view->new_display('block', 'Womens Varsity', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Womens Varsity';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'browse?field_term_gender_tid=20&field_term_level_tid=7&field_term_sport_tid=[tid]';
  $handler->display->display_options['fields']['name']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'sport' => 'sport',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filter criterion: Field: Gender (field_term_gender) */
  $handler->display->display_options['filters']['field_term_gender_tid']['id'] = 'field_term_gender_tid';
  $handler->display->display_options['filters']['field_term_gender_tid']['table'] = 'field_data_field_term_gender';
  $handler->display->display_options['filters']['field_term_gender_tid']['field'] = 'field_term_gender_tid';
  $handler->display->display_options['filters']['field_term_gender_tid']['value'] = array(
    20 => '20',
  );
  $handler->display->display_options['filters']['field_term_gender_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_gender_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_gender_tid']['vocabulary'] = 'gender';
  /* Filter criterion: Field: Level (field_term_level) */
  $handler->display->display_options['filters']['field_term_level_tid']['id'] = 'field_term_level_tid';
  $handler->display->display_options['filters']['field_term_level_tid']['table'] = 'field_data_field_term_level';
  $handler->display->display_options['filters']['field_term_level_tid']['field'] = 'field_term_level_tid';
  $handler->display->display_options['filters']['field_term_level_tid']['value'] = array(
    7 => '7',
  );
  $handler->display->display_options['filters']['field_term_level_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_level_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_level_tid']['vocabulary'] = 'level';
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = '$term_game = 0;
$query = db_select(\'taxonomy_term_data\', \'td\');
$query->fields(\'td\', array(\'tid\', \'name\'));
$query->condition(\'td.name\', \'game\');
$term_game = $query->execute()->fetchField();

$query = db_select(\'node\', \'n\');
$t_alias = $query->innerJoin(\'taxonomy_index\', \'t\', \'%alias.nid = n.nid\');
$t2_alias = $query->innerJoin(\'taxonomy_index\', \'t2\', \'%alias.nid = n.nid\');
$query->condition(\'n.status\', 1);
$query->condition("${t_alias}.tid", $row->tid);
$query->condition("${t2_alias}.tid", $term_game);
$num_rows = $query->countQuery()->execute()->fetchField();
if($num_rows == 0){
  return TRUE;
}
';

  /* Display: Womens Sophomore */
  $handler = $view->new_display('block', 'Womens Sophomore', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Womens Sophomore';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'browse?field_term_gender_tid=20&field_term_level_tid=9&field_term_sport_tid=[tid]';
  $handler->display->display_options['fields']['name']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'sport' => 'sport',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filter criterion: Field: Gender (field_term_gender) */
  $handler->display->display_options['filters']['field_term_gender_tid']['id'] = 'field_term_gender_tid';
  $handler->display->display_options['filters']['field_term_gender_tid']['table'] = 'field_data_field_term_gender';
  $handler->display->display_options['filters']['field_term_gender_tid']['field'] = 'field_term_gender_tid';
  $handler->display->display_options['filters']['field_term_gender_tid']['value'] = array(
    20 => '20',
  );
  $handler->display->display_options['filters']['field_term_gender_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_gender_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_gender_tid']['vocabulary'] = 'gender';
  /* Filter criterion: Field: Level (field_term_level) */
  $handler->display->display_options['filters']['field_term_level_tid']['id'] = 'field_term_level_tid';
  $handler->display->display_options['filters']['field_term_level_tid']['table'] = 'field_data_field_term_level';
  $handler->display->display_options['filters']['field_term_level_tid']['field'] = 'field_term_level_tid';
  $handler->display->display_options['filters']['field_term_level_tid']['value'] = array(
    9 => '9',
  );
  $handler->display->display_options['filters']['field_term_level_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_level_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_level_tid']['vocabulary'] = 'level';
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = '$term_game = 0;
$query = db_select(\'taxonomy_term_data\', \'td\');
$query->fields(\'td\', array(\'tid\', \'name\'));
$query->condition(\'td.name\', \'game\');
$term_game = $query->execute()->fetchField();

$query = db_select(\'node\', \'n\');
$t_alias = $query->innerJoin(\'taxonomy_index\', \'t\', \'%alias.nid = n.nid\');
$t2_alias = $query->innerJoin(\'taxonomy_index\', \'t2\', \'%alias.nid = n.nid\');
$query->condition(\'n.status\', 1);
$query->condition("${t_alias}.tid", $row->tid);
$query->condition("${t2_alias}.tid", $term_game);
$num_rows = $query->countQuery()->execute()->fetchField();
if($num_rows == 0){
  return TRUE;
}
';

  /* Display: Womens Freshman */
  $handler = $view->new_display('block', 'Womens Freshman', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Womens Freshman';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'browse?field_term_gender_tid=20&field_term_level_tid=8&field_term_sport_tid=[tid]';
  $handler->display->display_options['fields']['name']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'sport' => 'sport',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filter criterion: Field: Gender (field_term_gender) */
  $handler->display->display_options['filters']['field_term_gender_tid']['id'] = 'field_term_gender_tid';
  $handler->display->display_options['filters']['field_term_gender_tid']['table'] = 'field_data_field_term_gender';
  $handler->display->display_options['filters']['field_term_gender_tid']['field'] = 'field_term_gender_tid';
  $handler->display->display_options['filters']['field_term_gender_tid']['value'] = array(
    20 => '20',
  );
  $handler->display->display_options['filters']['field_term_gender_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_gender_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_gender_tid']['vocabulary'] = 'gender';
  /* Filter criterion: Field: Level (field_term_level) */
  $handler->display->display_options['filters']['field_term_level_tid']['id'] = 'field_term_level_tid';
  $handler->display->display_options['filters']['field_term_level_tid']['table'] = 'field_data_field_term_level';
  $handler->display->display_options['filters']['field_term_level_tid']['field'] = 'field_term_level_tid';
  $handler->display->display_options['filters']['field_term_level_tid']['value'] = array(
    8 => '8',
  );
  $handler->display->display_options['filters']['field_term_level_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_level_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_level_tid']['vocabulary'] = 'level';
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = '$term_game = 0;
$query = db_select(\'taxonomy_term_data\', \'td\');
$query->fields(\'td\', array(\'tid\', \'name\'));
$query->condition(\'td.name\', \'game\');
$term_game = $query->execute()->fetchField();

$query = db_select(\'node\', \'n\');
$t_alias = $query->innerJoin(\'taxonomy_index\', \'t\', \'%alias.nid = n.nid\');
$t2_alias = $query->innerJoin(\'taxonomy_index\', \'t2\', \'%alias.nid = n.nid\');
$query->condition(\'n.status\', 1);
$query->condition("${t_alias}.tid", $row->tid);
$query->condition("${t2_alias}.tid", $term_game);
$num_rows = $query->countQuery()->execute()->fetchField();
if($num_rows == 0){
  return TRUE;
}
';
  $export['mega_listing'] = $view;

  $view = new view();
  $view->name = 'scoreboard';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'scoreboard';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'jcarousel';
  $handler->display->display_options['style_options']['wrap'] = 'circular';
  $handler->display->display_options['style_options']['skin'] = 'rus-scoreboard';
  $handler->display->display_options['style_options']['visible'] = '8';
  $handler->display->display_options['style_options']['scroll'] = '8';
  $handler->display->display_options['style_options']['auto'] = '0';
  $handler->display->display_options['style_options']['autoPause'] = 1;
  $handler->display->display_options['style_options']['easing'] = '';
  $handler->display->display_options['style_options']['vertical'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = '<p style="margin-bottom:81px">No Results. Please adjust your selection and try again.</p>
';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Content: Home Team (field_term_team_home) */
  $handler->display->display_options['relationships']['field_term_team_home_tid']['id'] = 'field_term_team_home_tid';
  $handler->display->display_options['relationships']['field_term_team_home_tid']['table'] = 'field_data_field_term_team_home';
  $handler->display->display_options['relationships']['field_term_team_home_tid']['field'] = 'field_term_team_home_tid';
  /* Relationship: Content: Away Team (field_term_team_away) */
  $handler->display->display_options['relationships']['field_term_team_away_tid']['id'] = 'field_term_team_away_tid';
  $handler->display->display_options['relationships']['field_term_team_away_tid']['table'] = 'field_data_field_term_team_away';
  $handler->display->display_options['relationships']['field_term_team_away_tid']['field'] = 'field_term_team_away_tid';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_datetime']['id'] = 'field_datetime';
  $handler->display->display_options['fields']['field_datetime']['table'] = 'field_data_field_datetime';
  $handler->display->display_options['fields']['field_datetime']['field'] = 'field_datetime';
  $handler->display->display_options['fields']['field_datetime']['label'] = '';
  $handler->display->display_options['fields']['field_datetime']['alter']['text'] = '<a href="[path]"><div class="float-right">Final</div>[field_datetime]</a>';
  $handler->display->display_options['fields']['field_datetime']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_datetime']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_datetime']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_datetime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datetime']['settings'] = array(
    'format_type' => 'month_day_year',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field: Level */
  $handler->display->display_options['fields']['field_term_level']['id'] = 'field_term_level';
  $handler->display->display_options['fields']['field_term_level']['table'] = 'field_data_field_term_level';
  $handler->display->display_options['fields']['field_term_level']['field'] = 'field_term_level';
  $handler->display->display_options['fields']['field_term_level']['label'] = '';
  $handler->display->display_options['fields']['field_term_level']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_level']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_term_level']['delta_offset'] = '0';
  /* Field: Field: Gender */
  $handler->display->display_options['fields']['field_term_gender']['id'] = 'field_term_gender';
  $handler->display->display_options['fields']['field_term_gender']['table'] = 'field_data_field_term_gender';
  $handler->display->display_options['fields']['field_term_gender']['field'] = 'field_term_gender';
  $handler->display->display_options['fields']['field_term_gender']['label'] = '';
  $handler->display->display_options['fields']['field_term_gender']['alter']['max_length'] = '1';
  $handler->display->display_options['fields']['field_term_gender']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_term_gender']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['field_term_gender']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_gender']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_term_gender']['delta_offset'] = '0';
  /* Field: Content: Sport */
  $handler->display->display_options['fields']['field_term_sport']['id'] = 'field_term_sport';
  $handler->display->display_options['fields']['field_term_sport']['table'] = 'field_data_field_term_sport';
  $handler->display->display_options['fields']['field_term_sport']['field'] = 'field_term_sport';
  $handler->display->display_options['fields']['field_term_sport']['label'] = '';
  $handler->display->display_options['fields']['field_term_sport']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_sport']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_term_sport']['alter']['text'] = '[field_term_gender] [field_term_level] [field_term_sport]';
  $handler->display->display_options['fields']['field_term_sport']['alter']['max_length'] = '20';
  $handler->display->display_options['fields']['field_term_sport']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_term_sport']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['field_term_sport']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_term_sport']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_sport']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Home Team */
  $handler->display->display_options['fields']['field_term_team_home']['id'] = 'field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['table'] = 'field_data_field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['field'] = 'field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['label'] = '';
  $handler->display->display_options['fields']['field_term_team_home']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_team_home']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_team_home']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Away Team */
  $handler->display->display_options['fields']['field_term_team_away']['id'] = 'field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['table'] = 'field_data_field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['field'] = 'field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['label'] = '';
  $handler->display->display_options['fields']['field_term_team_away']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_team_away']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_team_away']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Taxonomy term: Team Abbreviation */
  $handler->display->display_options['fields']['field_abbreviation']['id'] = 'field_abbreviation';
  $handler->display->display_options['fields']['field_abbreviation']['table'] = 'field_data_field_abbreviation';
  $handler->display->display_options['fields']['field_abbreviation']['field'] = 'field_abbreviation';
  $handler->display->display_options['fields']['field_abbreviation']['relationship'] = 'field_term_team_home_tid';
  $handler->display->display_options['fields']['field_abbreviation']['label'] = 'Home Team Abbreviation';
  $handler->display->display_options['fields']['field_abbreviation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_abbreviation']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Team Abbreviation */
  $handler->display->display_options['fields']['field_abbreviation_1']['id'] = 'field_abbreviation_1';
  $handler->display->display_options['fields']['field_abbreviation_1']['table'] = 'field_data_field_abbreviation';
  $handler->display->display_options['fields']['field_abbreviation_1']['field'] = 'field_abbreviation';
  $handler->display->display_options['fields']['field_abbreviation_1']['relationship'] = 'field_term_team_away_tid';
  $handler->display->display_options['fields']['field_abbreviation_1']['label'] = 'Away Team Abbreviation';
  $handler->display->display_options['fields']['field_abbreviation_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_abbreviation_1']['element_label_colon'] = FALSE;
  /* Field: Content: Away Team Score */
  $handler->display->display_options['fields']['field_score_away']['id'] = 'field_score_away';
  $handler->display->display_options['fields']['field_score_away']['table'] = 'field_data_field_score_away';
  $handler->display->display_options['fields']['field_score_away']['field'] = 'field_score_away';
  $handler->display->display_options['fields']['field_score_away']['label'] = '';
  $handler->display->display_options['fields']['field_score_away']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_score_away']['alter']['text'] = '<a href="[path]"><div class="float-right">[field_score_away]</div>[field_abbreviation_1]@</a>';
  $handler->display->display_options['fields']['field_score_away']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_score_away']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_score_away']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Home Team Score */
  $handler->display->display_options['fields']['field_score_home']['id'] = 'field_score_home';
  $handler->display->display_options['fields']['field_score_home']['table'] = 'field_data_field_score_home';
  $handler->display->display_options['fields']['field_score_home']['field'] = 'field_score_home';
  $handler->display->display_options['fields']['field_score_home']['label'] = '';
  $handler->display->display_options['fields']['field_score_home']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_score_home']['alter']['text'] = '<a href="[path]"><div class="float-right">[field_score_home]</div>[field_abbreviation]</a>';
  $handler->display->display_options['fields']['field_score_home']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_score_home']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_score_home']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Team Logo */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'w70',
    'image_link' => 'content',
  );
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Sport (field_term_sport) */
  $handler->display->display_options['arguments']['field_term_sport_tid']['id'] = 'field_term_sport_tid';
  $handler->display->display_options['arguments']['field_term_sport_tid']['table'] = 'field_data_field_term_sport';
  $handler->display->display_options['arguments']['field_term_sport_tid']['field'] = 'field_term_sport_tid';
  $handler->display->display_options['arguments']['field_term_sport_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_term_sport_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_term_sport_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_term_sport_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_term_sport_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_term_sport_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_term_sport_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_term_sport_tid']['validate_options']['vocabularies'] = array(
    'sport' => 'sport',
  );
  $handler->display->display_options['arguments']['field_term_sport_tid']['validate']['fail'] = 'empty';
  /* Contextual filter: Content: School Year (field_term_year) */
  $handler->display->display_options['arguments']['field_term_year_tid']['id'] = 'field_term_year_tid';
  $handler->display->display_options['arguments']['field_term_year_tid']['table'] = 'field_data_field_term_year';
  $handler->display->display_options['arguments']['field_term_year_tid']['field'] = 'field_term_year_tid';
  $handler->display->display_options['arguments']['field_term_year_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_term_year_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_term_year_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_term_year_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_term_year_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_term_year_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_term_year_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_term_year_tid']['validate_options']['vocabularies'] = array(
    'year' => 'year',
  );
  $handler->display->display_options['arguments']['field_term_year_tid']['validate']['fail'] = 'empty';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'scoreboard' => 'scoreboard',
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Category (field_term_categories) */
  $handler->display->display_options['filters']['field_term_categories_tid']['id'] = 'field_term_categories_tid';
  $handler->display->display_options['filters']['field_term_categories_tid']['table'] = 'field_data_field_term_categories';
  $handler->display->display_options['filters']['field_term_categories_tid']['field'] = 'field_term_categories_tid';
  $handler->display->display_options['filters']['field_term_categories_tid']['operator'] = 'not';
  $handler->display->display_options['filters']['field_term_categories_tid']['value'] = array(
    6 => '6',
    5 => '5',
  );
  $handler->display->display_options['filters']['field_term_categories_tid']['group'] = 0;
  $handler->display->display_options['filters']['field_term_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_categories_tid']['vocabulary'] = 'category';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['scoreboard'] = $view;

  $view = new view();
  $view->name = 'video_grid_full';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Video Grid Full';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="views-grid-full-more"><a href="#">More Features</a></div>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '  <div class="views-grid-full-footer">
    <a href="/browse?field_term_categories_tid=4"><?php print variable_get(\'rus_helper_event_title\', \'Game\'); ?> Archives</a>
  </div>';
  $handler->display->display_options['footer']['area']['format'] = 'php_code';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="view-video-grid-arrow-overlay"><a href="[path]"><img src="/sites/all/themes/omega_rus/image/arrow-play.png" /></a></div>
';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Field: Team Logo */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['text'] = '[field_image] ';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '300x169',
    'image_link' => 'content',
  );
  /* Field: Content: Home Team */
  $handler->display->display_options['fields']['field_term_team_home']['id'] = 'field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['table'] = 'field_data_field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['field'] = 'field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['label'] = '';
  $handler->display->display_options['fields']['field_term_team_home']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_team_home']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_team_home']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Away Team */
  $handler->display->display_options['fields']['field_term_team_away']['id'] = 'field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['table'] = 'field_data_field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['field'] = 'field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['label'] = '';
  $handler->display->display_options['fields']['field_term_team_away']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_team_away']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_team_away']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_datetime']['id'] = 'field_datetime';
  $handler->display->display_options['fields']['field_datetime']['table'] = 'field_data_field_datetime';
  $handler->display->display_options['fields']['field_datetime']['field'] = 'field_datetime';
  $handler->display->display_options['fields']['field_datetime']['label'] = '';
  $handler->display->display_options['fields']['field_datetime']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_datetime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datetime']['settings'] = array(
    'format_type' => 'month_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '@[field_term_team_home] v [field_term_team_away] - [field_datetime]';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  /* Filter criterion: Content: Category (field_term_categories) */
  $handler->display->display_options['filters']['field_term_categories_tid']['id'] = 'field_term_categories_tid';
  $handler->display->display_options['filters']['field_term_categories_tid']['table'] = 'field_data_field_term_categories';
  $handler->display->display_options['filters']['field_term_categories_tid']['field'] = 'field_term_categories_tid';
  $handler->display->display_options['filters']['field_term_categories_tid']['value'] = array(
    4 => '4',
  );
  $handler->display->display_options['filters']['field_term_categories_tid']['group'] = '0';
  $handler->display->display_options['filters']['field_term_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_categories_tid']['vocabulary'] = 'category';

  /* Display: Games */
  $handler = $view->new_display('block', 'Games', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="views-grid-full-more">
  <div class="views-grid-full-more-trigger">
    <a href="/browse?field_term_categories_tid=4">More <?php print variable_get(\'rus_helper_event_title_many\', \'Games\'); ?></a>
  </div>
  <ul class="views-grid-full-more-menu">
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=22">January</a></li>
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=23">February</a></li>
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=24">March</a></li>
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=25">April</a></li>
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=26">May</a></li>
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=27">June</a></li>
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=28">July</a></li>
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=29">August</a></li>
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=30">September</a></li>
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=31">October</a></li>
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=32">November</a></li>
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=33">December</a></li>
  </ul>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';

  /* Display: Interviews */
  $handler = $view->new_display('block', 'Interviews', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="views-grid-full-more">
  <div class="views-grid-full-more-trigger">
    <a href="/browse?field_term_categories_tid=5">More Interviews</a>
  </div>
  <ul class="views-grid-full-more-menu">
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=22">January</a></li>
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=23">February</a></li>
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=24">March</a></li>
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=25">April</a></li>
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=26">May</a></li>
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=27">June</a></li>
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=28">July</a></li>
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=29">August</a></li>
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=30">September</a></li>
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=31">October</a></li>
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=32">November</a></li>
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=33">December</a></li>
  </ul>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '  <div class="views-grid-full-footer">
    <a href="/browse?field_term_categories_tid=5">Interview Archives</a>
  </div>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="view-video-grid-arrow-overlay"><a href="[path]"><img src="/sites/all/themes/omega_rus/image/arrow-play.png" /></a></div>
';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Field: Team Logo */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['text'] = '[field_image] ';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '300x169',
    'image_link' => 'content',
  );
  /* Field: Content: Home Team */
  $handler->display->display_options['fields']['field_term_team_home']['id'] = 'field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['table'] = 'field_data_field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['field'] = 'field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['label'] = '';
  $handler->display->display_options['fields']['field_term_team_home']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_team_home']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_team_home']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Away Team */
  $handler->display->display_options['fields']['field_term_team_away']['id'] = 'field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['table'] = 'field_data_field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['field'] = 'field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['label'] = '';
  $handler->display->display_options['fields']['field_term_team_away']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_team_away']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_team_away']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_datetime']['id'] = 'field_datetime';
  $handler->display->display_options['fields']['field_datetime']['table'] = 'field_data_field_datetime';
  $handler->display->display_options['fields']['field_datetime']['field'] = 'field_datetime';
  $handler->display->display_options['fields']['field_datetime']['label'] = '';
  $handler->display->display_options['fields']['field_datetime']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_datetime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datetime']['settings'] = array(
    'format_type' => 'month_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['text'] = '@[field_term_team_home] v [field_term_team_away] - [field_datetime]';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Category (field_term_categories) */
  $handler->display->display_options['filters']['field_term_categories_tid']['id'] = 'field_term_categories_tid';
  $handler->display->display_options['filters']['field_term_categories_tid']['table'] = 'field_data_field_term_categories';
  $handler->display->display_options['filters']['field_term_categories_tid']['field'] = 'field_term_categories_tid';
  $handler->display->display_options['filters']['field_term_categories_tid']['value'] = array(
    5 => '5',
  );
  $handler->display->display_options['filters']['field_term_categories_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_categories_tid']['vocabulary'] = 'category';

  /* Display: Features */
  $handler = $view->new_display('block', 'Features', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="views-grid-full-more">
  <div class="views-grid-full-more-trigger">
    <a href="/browse?field_term_categories_tid=6">More Features</a>
  </div>
  <ul class="views-grid-full-more-menu">
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=22">January</a></li>
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=23">February</a></li>
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=24">March</a></li>
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=25">April</a></li>
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=26">May</a></li>
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=27">June</a></li>
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=28">July</a></li>
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=29">August</a></li>
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=30">September</a></li>
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=31">October</a></li>
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=32">November</a></li>
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=33">December</a></li>
  </ul>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '  <div class="views-grid-full-footer">
    <a href="/browse?field_term_categories_tid=6">Feature Archives</a>
  </div>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="view-video-grid-arrow-overlay"><a href="[path]"><img src="/sites/all/themes/omega_rus/image/arrow-play.png" /></a></div>
';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Field: Team Logo */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['text'] = '[field_image] ';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '300x169',
    'image_link' => 'content',
  );
  /* Field: Content: Home Team */
  $handler->display->display_options['fields']['field_term_team_home']['id'] = 'field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['table'] = 'field_data_field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['field'] = 'field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['label'] = '';
  $handler->display->display_options['fields']['field_term_team_home']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_team_home']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_team_home']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Away Team */
  $handler->display->display_options['fields']['field_term_team_away']['id'] = 'field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['table'] = 'field_data_field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['field'] = 'field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['label'] = '';
  $handler->display->display_options['fields']['field_term_team_away']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_team_away']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_team_away']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_datetime']['id'] = 'field_datetime';
  $handler->display->display_options['fields']['field_datetime']['table'] = 'field_data_field_datetime';
  $handler->display->display_options['fields']['field_datetime']['field'] = 'field_datetime';
  $handler->display->display_options['fields']['field_datetime']['label'] = '';
  $handler->display->display_options['fields']['field_datetime']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_datetime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datetime']['settings'] = array(
    'format_type' => 'month_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['text'] = '@[field_term_team_home] v [field_term_team_away] - [field_datetime]';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Category (field_term_categories) */
  $handler->display->display_options['filters']['field_term_categories_tid']['id'] = 'field_term_categories_tid';
  $handler->display->display_options['filters']['field_term_categories_tid']['table'] = 'field_data_field_term_categories';
  $handler->display->display_options['filters']['field_term_categories_tid']['field'] = 'field_term_categories_tid';
  $handler->display->display_options['filters']['field_term_categories_tid']['value'] = array(
    6 => '6',
  );
  $handler->display->display_options['filters']['field_term_categories_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_categories_tid']['vocabulary'] = 'category';

  /* Display: Games Content Pane */
  $handler = $view->new_display('panel_pane', 'Games Content Pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="views-grid-full-more">
  <div class="views-grid-full-more-trigger">
    <a href="/browse?field_term_categories_tid=4">More <?php print variable_get(\'rus_helper_event_title_many\', \'Games\'); ?></a>
  </div>
  <ul class="views-grid-full-more-menu">
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=22">January</a></li>
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=23">February</a></li>
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=24">March</a></li>
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=25">April</a></li>
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=26">May</a></li>
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=27">June</a></li>
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=28">July</a></li>
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=29">August</a></li>
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=30">September</a></li>
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=31">October</a></li>
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=32">November</a></li>
    <li><a href="/browse?field_term_categories_tid=4&field_term_month_tid=33">December</a></li>
  </ul>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';

  /* Display: Interviews Content Pane */
  $handler = $view->new_display('panel_pane', 'Interviews Content Pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="views-grid-full-more">
  <div class="views-grid-full-more-trigger">
    <a href="/browse?field_term_categories_tid=5">More Interviews</a>
  </div>
  <ul class="views-grid-full-more-menu">
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=22">January</a></li>
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=23">February</a></li>
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=24">March</a></li>
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=25">April</a></li>
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=26">May</a></li>
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=27">June</a></li>
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=28">July</a></li>
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=29">August</a></li>
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=30">September</a></li>
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=31">October</a></li>
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=32">November</a></li>
    <li><a href="/browse?field_term_categories_tid=5&field_term_month_tid=33">December</a></li>
  </ul>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '  <div class="views-grid-full-footer">
    <a href="/browse?field_term_categories_tid=5">Interview Archives</a>
  </div>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="view-video-grid-arrow-overlay"><a href="[path]"><img src="/sites/all/themes/omega_rus/image/arrow-play.png" /></a></div>
';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Field: Team Logo */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['text'] = '[field_image] ';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '300x169',
    'image_link' => 'content',
  );
  /* Field: Content: Home Team */
  $handler->display->display_options['fields']['field_term_team_home']['id'] = 'field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['table'] = 'field_data_field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['field'] = 'field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['label'] = '';
  $handler->display->display_options['fields']['field_term_team_home']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_team_home']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_team_home']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Away Team */
  $handler->display->display_options['fields']['field_term_team_away']['id'] = 'field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['table'] = 'field_data_field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['field'] = 'field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['label'] = '';
  $handler->display->display_options['fields']['field_term_team_away']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_team_away']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_team_away']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_datetime']['id'] = 'field_datetime';
  $handler->display->display_options['fields']['field_datetime']['table'] = 'field_data_field_datetime';
  $handler->display->display_options['fields']['field_datetime']['field'] = 'field_datetime';
  $handler->display->display_options['fields']['field_datetime']['label'] = '';
  $handler->display->display_options['fields']['field_datetime']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_datetime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datetime']['settings'] = array(
    'format_type' => 'month_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['text'] = '@[field_term_team_home] v [field_term_team_away] - [field_datetime]';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Category (field_term_categories) */
  $handler->display->display_options['filters']['field_term_categories_tid']['id'] = 'field_term_categories_tid';
  $handler->display->display_options['filters']['field_term_categories_tid']['table'] = 'field_data_field_term_categories';
  $handler->display->display_options['filters']['field_term_categories_tid']['field'] = 'field_term_categories_tid';
  $handler->display->display_options['filters']['field_term_categories_tid']['value'] = array(
    5 => '5',
  );
  $handler->display->display_options['filters']['field_term_categories_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_categories_tid']['vocabulary'] = 'category';

  /* Display: Features Content Pane */
  $handler = $view->new_display('panel_pane', 'Features Content Pane', 'panel_pane_3');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="views-grid-full-more">
  <div class="views-grid-full-more-trigger">
    <a href="/browse?field_term_categories_tid=6">More Features</a>
  </div>
  <ul class="views-grid-full-more-menu">
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=22">January</a></li>
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=23">February</a></li>
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=24">March</a></li>
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=25">April</a></li>
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=26">May</a></li>
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=27">June</a></li>
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=28">July</a></li>
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=29">August</a></li>
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=30">September</a></li>
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=31">October</a></li>
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=32">November</a></li>
    <li><a href="/browse?field_term_categories_tid=6&field_term_month_tid=33">December</a></li>
  </ul>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '  <div class="views-grid-full-footer">
    <a href="/browse?field_term_categories_tid=6">Feature Archives</a>
  </div>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="view-video-grid-arrow-overlay"><a href="[path]"><img src="/sites/all/themes/omega_rus/image/arrow-play.png" /></a></div>
';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Field: Team Logo */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['text'] = '[field_image] ';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '300x169',
    'image_link' => 'content',
  );
  /* Field: Content: Home Team */
  $handler->display->display_options['fields']['field_term_team_home']['id'] = 'field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['table'] = 'field_data_field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['field'] = 'field_term_team_home';
  $handler->display->display_options['fields']['field_term_team_home']['label'] = '';
  $handler->display->display_options['fields']['field_term_team_home']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_team_home']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_team_home']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Away Team */
  $handler->display->display_options['fields']['field_term_team_away']['id'] = 'field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['table'] = 'field_data_field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['field'] = 'field_term_team_away';
  $handler->display->display_options['fields']['field_term_team_away']['label'] = '';
  $handler->display->display_options['fields']['field_term_team_away']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_team_away']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_team_away']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_datetime']['id'] = 'field_datetime';
  $handler->display->display_options['fields']['field_datetime']['table'] = 'field_data_field_datetime';
  $handler->display->display_options['fields']['field_datetime']['field'] = 'field_datetime';
  $handler->display->display_options['fields']['field_datetime']['label'] = '';
  $handler->display->display_options['fields']['field_datetime']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_datetime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datetime']['settings'] = array(
    'format_type' => 'month_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['text'] = '@[field_term_team_home] v [field_term_team_away] - [field_datetime]';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Category (field_term_categories) */
  $handler->display->display_options['filters']['field_term_categories_tid']['id'] = 'field_term_categories_tid';
  $handler->display->display_options['filters']['field_term_categories_tid']['table'] = 'field_data_field_term_categories';
  $handler->display->display_options['filters']['field_term_categories_tid']['field'] = 'field_term_categories_tid';
  $handler->display->display_options['filters']['field_term_categories_tid']['value'] = array(
    6 => '6',
  );
  $handler->display->display_options['filters']['field_term_categories_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_categories_tid']['vocabulary'] = 'category';
  $export['video_grid_full'] = $view;

  $view = new view();
  $view->name = 'videos_side';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Videos Side';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<a href="/browse?field_term_categories_tid=6">Features</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Field: Team Logo */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'video-side',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '15';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_datetime']['id'] = 'field_datetime';
  $handler->display->display_options['fields']['field_datetime']['table'] = 'field_data_field_datetime';
  $handler->display->display_options['fields']['field_datetime']['field'] = 'field_datetime';
  $handler->display->display_options['fields']['field_datetime']['label'] = '';
  $handler->display->display_options['fields']['field_datetime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datetime']['empty'] = '1/1/2012';
  $handler->display->display_options['fields']['field_datetime']['settings'] = array(
    'format_type' => 'month_day_year',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="view-video-side-arrow-overlay"><a href="[path]"><img src="/sites/all/themes/omega_rus/image/arrow-play-w25.png" /></a></div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  /* Filter criterion: Content: Category (field_term_categories) */
  $handler->display->display_options['filters']['field_term_categories_tid']['id'] = 'field_term_categories_tid';
  $handler->display->display_options['filters']['field_term_categories_tid']['table'] = 'field_data_field_term_categories';
  $handler->display->display_options['filters']['field_term_categories_tid']['field'] = 'field_term_categories_tid';
  $handler->display->display_options['filters']['field_term_categories_tid']['value'] = array(
    4 => '4',
  );
  $handler->display->display_options['filters']['field_term_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_categories_tid']['vocabulary'] = 'category';

  /* Display: Games */
  $handler = $view->new_display('block', 'Games', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<a href="/browse?field_term_categories_tid=4">Games</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';

  /* Display: Interviews */
  $handler = $view->new_display('block', 'Interviews', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<a href="/browse?field_term_categories_tid=5">Interviews</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  /* Filter criterion: Content: Category (field_term_categories) */
  $handler->display->display_options['filters']['field_term_categories_tid']['id'] = 'field_term_categories_tid';
  $handler->display->display_options['filters']['field_term_categories_tid']['table'] = 'field_data_field_term_categories';
  $handler->display->display_options['filters']['field_term_categories_tid']['field'] = 'field_term_categories_tid';
  $handler->display->display_options['filters']['field_term_categories_tid']['value'] = array(
    5 => '5',
  );
  $handler->display->display_options['filters']['field_term_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_categories_tid']['vocabulary'] = 'category';

  /* Display: Features */
  $handler = $view->new_display('block', 'Features', 'block_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  /* Filter criterion: Content: Category (field_term_categories) */
  $handler->display->display_options['filters']['field_term_categories_tid']['id'] = 'field_term_categories_tid';
  $handler->display->display_options['filters']['field_term_categories_tid']['table'] = 'field_data_field_term_categories';
  $handler->display->display_options['filters']['field_term_categories_tid']['field'] = 'field_term_categories_tid';
  $handler->display->display_options['filters']['field_term_categories_tid']['value'] = array(
    6 => '6',
  );
  $handler->display->display_options['filters']['field_term_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_term_categories_tid']['vocabulary'] = 'category';
  $export['videos_side'] = $view;

  return $export;
}

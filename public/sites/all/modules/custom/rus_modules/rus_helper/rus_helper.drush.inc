<?php
/**
 * @file Drush commmands for rising up sports.
 */

/**
 * Helper function that lists all of the zones and sites.
 */
function _rus_helper_get_zone_list() {
  // List of all zones and sites.
  return array(
    1 => array(
      'site' => 'risingupsports',
      'name' => 'OpenX-Front_Page-728x90',
    ),
    2 => array(
      'site' => 'risingupsports',
      'name' => 'OpenX-Front_Page-300x250',
    ),
    3 => array(
      'site' => 'risingupsports',
      'name' => 'OpenX-Sponsor-Text',
    ),
    4 => array(
      'site' => 'risingupsports',
      'name' => 'OpenX-Video-300x250',
    ),
    5 => array(
      'site' => 'risingupsports',
      'name' => 'OpenX-Video-728x90',
    ),
    6 => array(
      'site' => 'risingupsports',
      'name' => 'OpenX-Filter-728x90',
    ),
    19 => array(
      'site' => 'risingupsports',
      'name' => 'OpenX-All-200x90',
    ),
    11 => array(
      'site' => 'flucosportsnetwork',
      'name' => 'OpenX-Front_Page-728x90',
    ),
    10 => array(
      'site' => 'flucosportsnetwork',
      'name' => 'OpenX-Front_Page-300x250',
    ),
    12 => array(
      'site' => 'flucosportsnetwork',
      'name' => 'OpenX-Sponsor-Text',
    ),
    7 => array(
      'site' => 'flucosportsnetwork',
      'name' => 'OpenX-Video-300x250',
    ),
    8 => array(
      'site' => 'flucosportsnetwork',
      'name' => 'OpenX-Video-728x90',
    ),
    9 => array(
      'site' => 'flucosportsnetwork',
      'name' => 'OpenX-Filter-728x90',
    ),
    20 => array(
      'site' => 'flucosportsnetwork',
      'name' => 'OpenX-All-200x90',
    ),
    17 => array(
      'site' => 'vikingssportsnetwork',
      'name' => 'OpenX-Front_Page-728x90',
    ),
    16 => array(
      'site' => 'vikingssportsnetwork',
      'name' => 'OpenX-Front_Page-300x250',
    ),
    18 => array(
      'site' => 'vikingssportsnetwork',
      'name' => 'OpenX-Sponsor-Text',
    ),
    13 => array(
      'site' => 'vikingssportsnetwork',
      'name' => 'OpenX-Video-300x250',
    ),
    14 => array(
      'site' => 'vikingssportsnetwork',
      'name' => 'OpenX-Video-728x90',
    ),
    15 => array(
      'site' => 'vikingssportsnetwork',
      'name' => 'OpenX-Filter-728x90',
    ),
    21 => array(
      'site' => 'vikingssportsnetwork',
      'name' => 'OpenX-All-200x90',
    ),
  );
}

/**
 * Implements hook_drush_command().
 */
function rus_helper_drush_command() {
  $items['openx-zone-add'] = array(
    'callback' => 'rus_helper_openx_zone_add',
    'description' => dt('Add an openx zone.'),
    'aliases' => array('oza'),
    'arguments' => array(
      'zoneid' => "Required. The Zone id to add.",
      'Block Name' => "Optional. If you don't provide the block name, one will be looked up.",
    ),
  );
  $items['openx-zone-list'] = array(
    'callback' => 'rus_helper_openx_zone_list',
    'description' => dt('List currently defined openx zones'),
    'aliases' => array('ozl'),
  );
  $items['openx-zone-add-site'] = array(
    'callback' => 'rus_helper_openx_zone_add_site',
    'description' => dt('Add all openx zones for a known site name.'),
    'aliases' => array('ozas'),
    'arguments' => array(
      'site' => "The site name, with or without the domain. ie, risingupsports or risingupsports.com.",
    ),
  );
  $items['rus-template-switch'] = array(
    'callback' => 'rus_helper_template_switch',
    'description' => dt('Activates alternate template for site.'),
    'arguments' => array(
      'template' => 'The template to switch to, such as "event" or "sport".',
    ),
  );
  //drush_print_r($items);
  return $items;
}

/**
 * Implements hook_drush_help().
 */
function rus_helper_drush_help($section) {
  switch ($section) {
    case 'drush:openx-zone-add':
      return dt("Add an openx zone.");
    case 'drush:openx-zone-list':
      return dt("List all openx zones.");
    case 'drush:openx-zone-add-site':
      return dt("Sets up all zones for a site.");
  }
}

/**
 * Drush callback for openx-zone-add.
 */
function rus_helper_openx_zone_add($zoneid, $block_name = '') {
  $valid_block_names = array(
    'OpenX-Front_Page-728x90',
    'OpenX-Front_Page-300x250',
    'OpenX-Sponsor-Text',
    'OpenX-Video-300x250',
    'OpenX-Video-728x90',
    'OpenX-Filter-728x90',
    'OpenX-All-200x90',
  );
  if (!empty($block_name) && in_array($block_name, $valid_block_names)) {
    drush_set_error(dt("The Block Name @name is not valid.", array('@name' => $block_name)));
    return;
  }
  
  if (empty($block_name)) {
    $rus_helper_zone_list = _rus_helper_get_zone_list();
    if (isset($rus_helper_zone_list[$zoneid])) {
      $block_name = $rus_helper_zone_list[$zoneid]['name'];
    }
  }
  if (!empty($block_name)) {
    $zones = variable_get('openx_zones', array());
    $zones[] = array('id' => $zoneid, 'name' => $block_name);
    variable_set('openx_zones', $zones);
  }
}

/**
 * Drush callback for openx-zone-list.
 */
function rus_helper_openx_zone_list() {
  $zones = variable_get('openx_zones', array());
  
  if (empty($zones)) {
    drush_print(dt("No OpenX Zones have been configured on this site."));
  }
  else {
    $rows = array(
      array(
        dt('Zone ID'),
        dt('Zone Name'),
      )
    );
    
    foreach ($zones as $zone) {
      $rows[] = array(
        $zone['id'],
        "'" . $zone['name'] . "'",
      );
    }
    drush_print_table($rows, TRUE);
  }
}

/**
 * Drush callback for openx-zone-add-site.
 */
function rus_helper_openx_zone_add_site($site) {
  if (empty($site)) {
    drush_set_error(dt('Site is required for openx-zone-add-site.'));
    return;
  }
  
  $site_parts = explode('.', $site);
  if (!empty($site_parts[0])) {
    $zones = array();
    $rus_helper_zone_list = _rus_helper_get_zone_list();
    foreach ($rus_helper_zone_list as $zoneid => $zone) {
      if ($zone['site'] == $site_parts[0]) {
        $zones[] = array(
          'id' => $zoneid,
          'name' => $zone['name'],
        );
      }
    }
    if (empty($zones)) {
      drush_set_error(dt('No zones were found to set up for @site', array('@site' => $site)));
      return;
    }
    variable_set('openx_zones', $zones);
  }
}

function rus_helper_template_switch($template) {
  if (empty($template)) {
    drush_set_error(dt('Template is required for rus-template-switch'));
    return;
  }
  if ($template != 'default' && $template != 'event' && $template != 'sport') {
    drush_set_error(dt("Template can only be one of 'default', 'event', or 'sport'."));
    return;
  }
  
  if ($template == 'default') {
    variable_del('rus_helper_template');
    $default = TRUE;
  }
  else {
    variable_set('rus_helper_template', $template);
    $default = ($template == 'sport');
  }
  
  // Change 'browse sports' to 'browse events'
  if ($default) {
    variable_del('rus_helper_browse_title');
  }
  else {
    variable_set('rus_helper_browse_title', 'Browse Events');
  }
  // Change the 'games' header to 'events'
  if ($default) {
    variable_del('rus_helper_event_title');
    variable_del('rus_helper_event_title_many');
  }
  else {
    variable_set('rus_helper_event_title', 'Event');
    variable_set('rus_helper_event_title_many', 'Events');
  }
  // Change taxonomy 'sport' to 'event type'
  $vocab = taxonomy_vocabulary_machine_name_load('sport');
  if ($default) {
    $vocab->name = 'Sport';
  }
  else {
    $vocab->name = 'Event Type';
  }
  taxonomy_vocabulary_save($vocab);
  
  // Scoreboard needs to display thumbnail
  
  // Filter page 'sport' change to 'event type'
  if ($default) {
    variable_del('rus_helper_browse_event_label');
  }
  else {
    variable_set('rus_helper_browse_event_label', 'Event Type');
  }
  // Change text in footer from rising up sports to rising up networks
  if ($default) {
    variable_del('rus_helper_owner_name');
  }
  else {
    variable_set('rus_helper_owner_name', 'Rising Up Networks');
  }
  // Category -> Game term?
  $term = taxonomy_term_load(4);
  if ($default) {
    if ($term->name != 'Game') {
      $term->name = 'Game';
      taxonomy_term_save($term);
    }
  }
  else {
    if ($term->name != 'Event') {
      $term->name = 'Event';
      taxonomy_term_save($term);
    }
  }
  
  // clear caches!
  
  drush_print(dt('Done. Please clear your caches'));
}

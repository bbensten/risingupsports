<?php
/**
 * @file
 * rus_video.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function rus_video_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|video|feature_small';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'feature_small';
  $ds_fieldsetting->settings = array(
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
  $export['node|video|feature_small'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|video|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'video_vimeo' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|video|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|video|medium_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'medium_teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h3',
        'class' => '',
      ),
    ),
  );
  $export['node|video|medium_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|video|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'scoreboard_item_terms' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'scoreboard_item_score' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
      ),
    ),
  );
  $export['node|video|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function rus_video_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'sidebar_videos';
  $ds_field->label = 'Sidebar Videos';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'block' => 'panels_mini|sidebar_videos',
    'block_render' => '3',
  );
  $export['sidebar_videos'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'video_details';
  $ds_field->label = 'Video Details';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
  $title = $entity->title;
  $wrapper = entity_metadata_wrapper(\'node\', $entity, array(\'bundle\' => \'video\'));

  // Get the wrappers for each term reference field.
  $wrapper_body = $wrapper->body;
  $wrapper_term_categories = $wrapper->field_term_categories;
  $wrapper_term_sport = $wrapper->field_term_sport;
  $wrapper_term_team_home = $wrapper->field_term_team_home;
  $wrapper_term_team_away = $wrapper->field_term_team_away;
  $wrapper_datetime = $wrapper->field_datetime;
  
  // Convert any arrays into a single item wrappers.
  $wrapper_body_item            = (get_class($wrapper_body)            == "EntityListWrapper") ? $wrapper_body->get(0)            : $wrapper_body;
  $wrapper_term_categories_item = (get_class($wrapper_term_categories) == "EntityListWrapper") ? $wrapper_term_categories->get(0) : $wrapper_term_categories;
  $wrapper_term_sport_item      = (get_class($wrapper_term_sport)      == "EntityListWrapper") ? $wrapper_term_sport->get(0)      : $wrapper_term_sport;
  $wrapper_term_team_home_item  = (get_class($wrapper_term_team_home)  == "EntityListWrapper") ? $wrapper_term_team_home->get(0)  : $wrapper_term_team_home;
  $wrapper_term_team_away_item  = (get_class($wrapper_term_team_away)  == "EntityListWrapper") ? $wrapper_term_team_away->get(0)  : $wrapper_term_team_away;    
  $wrapper_datetime_item        = (get_class($wrapper_datetime)        == "EntityListWrapper") ? $wrapper_datetime->get(0)        : $wrapper_datetime;    
  
  // Extract the data if available.
  $body            = ($wrapper_body_item->value()            == "") ? ""     : $wrapper_body_item->value->value();
  $term_categories = ($wrapper_term_categories_item->value() == "") ? ""     : $wrapper_term_categories->name->value();
  $term_sport      = ($wrapper_term_sport_item->value()      == "") ? ""     : $wrapper_term_sport_item->name->value();
  $term_team_home  = ($wrapper_term_team_home_item->value()  == "") ? ""     : $wrapper_term_team_home_item->name->value();
  $term_team_away  = ($wrapper_term_team_away_item->value()  == "") ? ""     : $wrapper_term_team_away_item->name->value();
  $datetime        = ($wrapper_datetime_item->value()        == "") ? time() : $wrapper_datetime_item->value->raw();
  
  // Shrinking down body to smaller size.
  $body = $wrapper_body_item->value->value();
  $alter = array(
    \'max_length\' => 52,
    \'word_boundary\' => TRUE,
    \'ellipsis\' => TRUE,
    \'html\' => TRUE,
  );
  $body = views_trim_text($alter, $body);

  $datetime = date("n/j/Y", $datetime);
  
  if ($term_categories == "Game") {
    $title = $term_team_home . " v. " . $term_team_away . ", " . $datetime;
  }
  elseif (in_array($term_categories, array(\'Feature\', "Interview"))) {
    $title = $term_categories . ": " . $datetime;
  }

?>

<div class="video-node-details">
  <div class="video-node-details-line"><?php echo $title;?></div>
  <div class="video-node-details-line"><?php echo $body;?></div>
</div>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['video_details'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'video_side_ad';
  $ds_field->label = 'Video Side Ad';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'block' => 'block|8',
    'block_render' => '3',
  );
  $export['video_side_ad'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'video_sideblock';
  $ds_field->label = 'Video Sideblock';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'block' => 'panels_mini|sidebar_videos',
    'block_render' => '3',
  );
  $export['video_sideblock'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'video_stripe';
  $ds_field->label = 'Video Stripe';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
  $node2 = node_load($entity->nid);
  $title = $node2->title;
  $wrapper = entity_metadata_wrapper(\'node\', $entity, array(\'bundle\' => \'video\'));

  $wrapper_term_categories = $wrapper->field_term_categories;
  $wrapper_term_sport = $wrapper->field_term_sport;
  $wrapper_term_team_home = $wrapper->field_term_team_home;
  $wrapper_term_team_away = $wrapper->field_term_team_away;
  $wrapper_datetime = $wrapper->field_datetime;
  $wrapper_link = $wrapper->field_link;  
  $wrapper_score_home  = $wrapper->field_score_home;
  $wrapper_score_away  = $wrapper->field_score_away;     
  
  // Convert any arrays into a single item wrappers.
  $wrapper_term_categories_item = (get_class($wrapper_term_categories) == "EntityListWrapper") ? $wrapper_term_categories->get(0) : $wrapper_term_categories;
  $wrapper_term_sport_item      = (get_class($wrapper_term_sport)      == "EntityListWrapper") ? $wrapper_term_sport->get(0)      : $wrapper_term_sport;
  $wrapper_term_team_home_item  = (get_class($wrapper_term_team_home)  == "EntityListWrapper") ? $wrapper_term_team_home->get(0)  : $wrapper_term_team_home;
  $wrapper_term_team_away_item  = (get_class($wrapper_term_team_away)  == "EntityListWrapper") ? $wrapper_term_team_away->get(0)  : $wrapper_term_team_away;    
  $wrapper_datetime_item        = (get_class($wrapper_datetime)        == "EntityListWrapper") ? $wrapper_datetime->get(0)        : $wrapper_datetime;    
  $wrapper_link_item            = (get_class($wrapper_link)            == "EntityListWrapper") ? $wrapper_link->get(0)            : $wrapper_link;    
  
  // Extract the data if available.
  $term_categories = ($wrapper_term_categories_item->value() == "") ? ""        : $wrapper_term_categories->name->value();
  $term_sport      = ($wrapper_term_sport_item->value()      == "") ? ""        : $wrapper_term_sport_item->name->value();
  $term_team_home  = ($wrapper_term_team_home_item->value()  == "") ? ""        : $wrapper_term_team_home_item->name->value();
  $term_team_away  = ($wrapper_term_team_away_item->value()  == "") ? ""        : $wrapper_term_team_away_item->name->value();
  $datetime        = ($wrapper_datetime_item->value()        == "") ? time()    : $wrapper_datetime_item->value->raw();
  $link            = ($wrapper_link_item->value()            == "") ? "contact" : $wrapper_link_item->url->value();  
  $score_home      = $wrapper_score_home->value();
  $score_away      = $wrapper_score_away->value();
  
  // Get title and scores.
  $scores = "";
  $datetime = date("n/j/Y", $datetime);
  $options = array();  
  $link = l($title, $link, $options);
  if ($term_categories == "Game") {
    $title = $term_team_home . "<br />v.<br />" . $term_team_away;
    $scores = $score_home . "-" . $score_away;
  }
  elseif (in_array($term_categories, array(\'Feature\', "Interview"))) {
    $title = $title;
  }
?>
<div class="video-stripe">
  <div class="video-stripe-line video-stripe-sport"><?php echo $sport;?></div>
  <div class="video-stripe-line video-stripe-home"><?php echo $title;?></div>
  <div class="video-stripe-line video-stripe-scores"><?php echo $scores;?></div>
  <div class="video-stripe-line video-stripe-date"><?php echo $datetime;?></div>
  <div class="video-stripe-line video-stripe-buy"><?php echo $link;?></div>
</div>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['video_stripe'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'video_vimeo';
  $ds_field->label = 'Video Vimeo';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
  print rus_helper_field_vimeo_vimeo_helper($entity); 
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['video_vimeo'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function rus_video_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|video|feature_small';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'feature_small';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_image',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_image' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|video|feature_small'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|video|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'video_vimeo',
      ),
    ),
    'fields' => array(
      'video_vimeo' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|video|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|video|medium_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'medium_teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_image',
        2 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_image' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|video|medium_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|video|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_3col_equal_width';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'middle' => array(
        0 => 'field_image',
      ),
      'left' => array(
        0 => 'title',
        1 => 'field_datetime',
        2 => 'scoreboard_item_score',
        3 => 'scoreboard_item_terms',
      ),
      'right' => array(
        0 => 'body',
      ),
    ),
    'fields' => array(
      'field_image' => 'middle',
      'title' => 'left',
      'field_datetime' => 'left',
      'scoreboard_item_score' => 'left',
      'scoreboard_item_terms' => 'left',
      'body' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|video|teaser'] = $ds_layout;

  return $export;
}

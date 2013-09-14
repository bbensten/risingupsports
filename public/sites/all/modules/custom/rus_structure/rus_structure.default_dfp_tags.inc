<?php
/**
 * @file
 * rus_structure.default_dfp_tags.inc
 */

/**
 * Implements hook_default_dfp_tag().
 */
function rus_structure_default_dfp_tag() {
  $export = array();

  $tag = new stdClass();
  $tag->disabled = FALSE; /* Edit this to true to make a default tag disabled initially */
  $tag->api_version = 1;
  $tag->machinename = 'devel_test';
  $tag->slot = 'TestDFP';
  $tag->adunit = '/[dfp_tag:network_id]/[dfp_tag:slot]';
  $tag->size = '728x90';
  $tag->block = 1;
  $tag->settings = array(
    'slug' => '',
    'short_tag' => 0,
    'adsense_ad_types' => 'image',
    'adsense_channel_ids' => '3081807437313501',
    'adsense_colors' => array(
      'background' => '',
      'border' => '',
      'link' => '',
      'text' => '',
      'url' => '',
    ),
    'targeting' => array(),
  );
  $export['devel_test'] = $tag;

  return $export;
}

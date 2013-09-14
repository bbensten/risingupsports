<?php
/**
 * @file
 * rus_home_page.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function rus_home_page_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home';
  $context->description = 'Block placements for the home page.';
  $context->tag = 'home';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'rus_helper-scoreboard' => array(
          'module' => 'rus_helper',
          'delta' => 'scoreboard',
          'region' => 'menu',
          'weight' => '-10',
        ),
        'views-broadcast_schedule-block' => array(
          'module' => 'views',
          'delta' => 'broadcast_schedule-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'rus_helper-rus_OpenX-Front_Page-300x250' => array(
          'module' => 'rus_helper',
          'delta' => 'rus_OpenX-Front_Page-300x250',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'rus_helper-rus_OpenX-Front_Page-728x90' => array(
          'module' => 'rus_helper',
          'delta' => 'rus_OpenX-Front_Page-728x90',
          'region' => 'postscript_fourth',
          'weight' => '-10',
        ),
        'rus_helper-rus_OpenX-All-200x90' => array(
          'module' => 'rus_helper',
          'delta' => 'rus_OpenX-All-200x90',
          'region' => 'postscript_fourth',
          'weight' => '-9',
        ),
        'views-spotlights-recent_videos' => array(
          'module' => 'views',
          'delta' => 'spotlights-recent_videos',
          'region' => 'postscript_fourth',
          'weight' => '-7',
        ),
        'views-spotlights-featured_videos' => array(
          'module' => 'views',
          'delta' => 'spotlights-featured_videos',
          'region' => 'postscript_fourth',
          'weight' => '-6',
        ),
        'views-spotlights-popular_videos' => array(
          'module' => 'views',
          'delta' => 'spotlights-popular_videos',
          'region' => 'postscript_fourth',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Block placements for the home page.');
  t('home');
  $export['home'] = $context;

  return $export;
}

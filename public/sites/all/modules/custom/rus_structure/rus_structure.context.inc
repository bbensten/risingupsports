<?php
/**
 * @file
 * rus_structure.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function rus_structure_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hide-title';
  $context->description = 'Specifically hides the title on particular pages';
  $context->tag = 'theme';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'video' => 'video',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'hide-title',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Specifically hides the title on particular pages');
  t('theme');
  $export['hide-title'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'video';
  $context->description = 'Video node based contexts';
  $context->tag = 'video';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'video' => 'video',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'rus_helper-rus_OpenX-Video-728x90' => array(
          'module' => 'rus_helper',
          'delta' => 'rus_OpenX-Video-728x90',
          'region' => 'postscript_fourth',
          'weight' => '-10',
        ),
        'rus_helper-rus_OpenX-All-200x90' => array(
          'module' => 'rus_helper',
          'delta' => 'rus_OpenX-All-200x90',
          'region' => 'postscript_fourth',
          'weight' => '-9',
        ),
        'views-video_grid_full-block' => array(
          'module' => 'views',
          'delta' => 'video_grid_full-block',
          'region' => 'postscript_fourth',
          'weight' => '-8',
        ),
        'views-video_grid_full-block_1' => array(
          'module' => 'views',
          'delta' => 'video_grid_full-block_1',
          'region' => 'postscript_fourth',
          'weight' => '-7',
        ),
        'views-video_grid_full-block_2' => array(
          'module' => 'views',
          'delta' => 'video_grid_full-block_2',
          'region' => 'postscript_fourth',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Video node based contexts');
  t('video');
  $export['video'] = $context;

  return $export;
}

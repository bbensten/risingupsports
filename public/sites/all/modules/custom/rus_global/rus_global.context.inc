<?php
/**
 * @file
 * rus_global.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function rus_global_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'rus_global';
  $context->description = 'Global block positioning for Rising Up Sports blocks.';
  $context->tag = 'Global';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*' => '*',
        '~admin' => '~admin',
        '~admin/*' => '~admin/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'rus_helper-rus-event-callout' => array(
          'module' => 'rus_helper',
          'delta' => 'rus-event-callout',
          'region' => 'callout',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global');
  t('Global block positioning for Rising Up Sports blocks.');
  $export['rus_global'] = $context;

  return $export;
}

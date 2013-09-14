<?php
/**
 * @file
 * rus_blog.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function rus_blog_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_pages';
  $context->description = 'Block placements for the blog pages.';
  $context->tag = 'blog';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'blog' => 'blog',
        'blog/*' => 'blog/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-blog_archive-blog_archive' => array(
          'module' => 'views',
          'delta' => '-exp-blog_archive-blog_archive',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-dcecb47aa32079c57373514339677b86' => array(
          'module' => 'views',
          'delta' => 'dcecb47aa32079c57373514339677b86',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-edd0e1baa9eb940863ee2f3b01e3d03c' => array(
          'module' => 'views',
          'delta' => 'edd0e1baa9eb940863ee2f3b01e3d03c',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-blog_archive-blog_tags' => array(
          'module' => 'views',
          'delta' => 'blog_archive-blog_tags',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Block placements for the blog pages.');
  t('blog');
  $export['blog_pages'] = $context;

  return $export;
}

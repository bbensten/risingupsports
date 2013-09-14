<?php

/**
 * Implements hook_preprocess_block().
 */
function riseup_preprocess_block(&$variables, $hook) {
  // Move the id into the attributes_array.
  $variables['attributes_array']['id'] = $variables['block_html_id'];
  $variables['attributes_array']['class'][] = $variables['block_html_id'];

  // Add a class to the block title.
  $variables['title_attributes_array']['class'][] = 'block-title';

  // Add a class to the block content.
  $variables['content_attributes_array']['class'][] = 'block-content';

  // Add a class to the advertising.
  if ($variables['block']->module == 'openx') {
    $variables['attributes_array']['class'][] = 'advertisement';
  }

  // Add a class to the spotlight carousel blocks.
  if (strpos($variables['block']->delta, 'spotlights-') === 0) {
    $variables['attributes_array']['class'][] = 'spotlight-videos';
  }

  // Arrange the blocks in the footer.
  if ($variables['block_html_id'] == 'block-block-1') {
    $variables['attributes_array']['class'][] = 'grid-8';
    $variables['attributes_array']['class'][] = 'pull-4';
    $variables['attributes_array']['class'][] = 'omega';
  }
  if ($variables['block_html_id'] == 'block-menu-menu-footer') {
    $variables['attributes_array']['class'][] = 'grid-4';
    $variables['attributes_array']['class'][] = 'push-8';
    $variables['attributes_array']['class'][] = 'alpha';
    $variables['title_attributes_array']['class'][] = 'element-invisible';
  }

  // Arrange the header blocks.
  if ($variables['block']->region == 'branding') {
    switch ($variables['block_html_id']) {
      case 'block-search-form':
        $variables['attributes_array']['class'][] = 'grid-3';
        $variables['attributes_array']['class'][] = 'push-4';
        $variables['attributes_array']['class'][] = 'alpha';
        break;
      case 'block-panels-mini-crew-dropdown':
        $variables['attributes_array']['class'][] = 'grid-1';
        $variables['attributes_array']['class'][] = 'push-2';
        break;
      case 'block-rus-helper-mega-browse-all':
        $variables['attributes_array']['class'][] = 'grid-2';
        $variables['attributes_array']['class'][] = 'pull-1';
        break;
      case 'block-block-10':
        $variables['attributes_array']['class'][] = 'grid-2';
        $variables['attributes_array']['class'][] = 'pull-6';
        $variables['attributes_array']['class'][] = 'omega';
        break;
    }
  }

  // Make all the callout blocks 12 units wide.
  if ($variables['block']->region == 'callout') {
    $variables['attributes_array']['class'][] = 'grid-12';
    if ($variables['block_html_id'] == 'block-rus-helper-rus-event-callout') {
      $variables['attributes_array']['class'][] = 'js-hide';
    }
  }
}

<?php
/**
 * @file
 * General preprocessing for node templates.
 */

/**
 * Implements hook_preprocess_node().
 */
function riseup_preprocess_node(&$variables, $hook) {
  // Add a general class to the node content container.
  $variables['content_attributes_array']['class'][] = 'node-content';
}

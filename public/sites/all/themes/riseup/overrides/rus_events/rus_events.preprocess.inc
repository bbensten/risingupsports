<?php
/**
 * @file
 * Preprocessing related to the rus_events module.
 */

/**
 * Implements hook_preprocess_node__event().
 */
function riseup_preprocess_node__event(&$variables, $hook) {
  // Wrap the video in a div so that the video size is fluid.
  $variables['content']['livestream']['#theme_wrappers'][] = 'container';
  $variables['content']['livestream']['#attributes']['class'][] = 'video-wrapper';

  // Add a class to the node if it is free content.
  if (isset($variables['content']['free_notice'])) {
    $variables['content_attributes_array']['class'][] = 'node-free-sample';
  }

  // Move fields into a sidebar.
  $primary = array(
    'body',
    'livestream',
    'links',
    'free_notice',
    'login_or_subscribe',
  );
  $supplements = array();
  foreach ($variables['content'] as $name => &$field) {
    if (!in_array($name, $primary)) {
      $supplements[$name] = $field;
      hide($field);
    }
  }
  if (!empty($supplements)) {
    $variables['content']['supplements'] = array(
      '#theme_wrappers' => array('container'),
      '#attributes' => array(
        'class' => array('node-supplements', 'clearfix'),
      ),
      '#weight' => 999,
      'content' => $supplements,
    );
  }
}

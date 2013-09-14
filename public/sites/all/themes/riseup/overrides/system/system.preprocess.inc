<?php

/**
 * Implements hook_preprocess().
 */
function riseup_preprocess(&$variables, $hook) {
  $variables['attributes_array']['class'] = $variables['classes_array'];
}

/**
 * Implements hook_preprocess_page().
 */
function riseup_preprocess_page(&$variables, $hook) {
  // Add general classes to the page.
  $variables['attributes_array']['class'][] = 'clearfix';
  $variables['title_attributes_array']['class'][] = 'grid-12';

  // Hide the page title on teh front page.
  if ($variables['is_front']) {
    $variables['title_attributes_array']['class'][] = 'element-invisible';
  }

  // Make the logo a renderable array.
  $variables['logo_image'] = array(
    '#theme' => 'image_formatter__logo',
    '#item' => array(
      'uri' => $variables['logo'],
      'alt' => t('@name logo', array('@name' => $variables['site_name'])),
      'title' => $variables['site_name'],
      'attributes' => array(
        'class' => array('site-logo'),
      ),
    ),
  );

  if (!$variables['is_front']) {
    // Link the logo to the front page when on a sub page.
    $variables['logo_image']['#path'] = array(
      'path' => '<front>',
      'options' => array(
        'class' => array('logo-link'),
      ),
    );

    $variables['site_name'] = array(
      '#theme' => 'link__site_name',
      '#text' => $variables['site_name'],
      '#path' => '<front>',
      '#options' => array(
        'attributes' => array(
          'class' => array('site-name-link'),
        ),
      ),
    );
  }
  else {
    // Make $site_name a renderable to make the template simpler.
    $variables['site_name'] = array(
      '#markup' => $variables['site_name'],
    );
  }

  // The content region can have a variable width depending on the sidebars on
  // the page.
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['content_attributes_array']['class'][] = 'grid-6';
    $variables['content_attributes_array']['class'][] = 'push-3';
    $variables['page']['sidebar_first']['#context'] = 'all content';
    $variables['page']['sidebar_second']['#context'] = 'all content';
  }
  elseif (empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['content_attributes_array']['class'][] = 'grid-8';
    $variables['page']['sidebar_second']['#context'] = 'only content';
  }
  elseif (!empty($variables['page']['sidebar_first']) && empty($variables['page']['sidebar_second'])) {
    $variables['content_attributes_array']['class'][] = 'grid-9';
    $variables['content_attributes_array']['class'][] = 'push-3';
    $variables['content_attributes_array']['class'][] = 'omega';
    $variables['page']['sidebar_first']['#context'] = 'only content';
  }
  elseif (empty($variables['page']['sidebar_first']) && empty($variables['page']['sidebar_second'])) {
    $variables['content_attributes_array']['class'][] = 'grid-12';
    $variables['content_attributes_array']['class'][] = 'omega';
  }
  $variables['content_attributes_array']['class'][] = 'alpha';
}

/**
 * Implements hook_preprocess_region().
 */
function riseup_preprocess_region(&$variables, $hook) {
  // Add a class to the region content.
  $variables['content_attributes_array']['class'][] = 'region-content';

  // Apply grid classes to the appropriate regions.
  switch ($variables['region']) {
    case 'callout':
      $variables['attributes_array']['class'][] = 'container-12';
      $variables['attributes_array']['class'][] = 'clearfix';
      break;
    case 'user_first':
      $variables['attributes_array']['class'][] = 'grid-8';
      $variables['attributes_array']['class'][] = 'alpha';
      break;
    case 'user_second':
      $variables['attributes_array']['class'][] = 'grid-4';
      $variables['attributes_array']['class'][] = 'omega';
      break;
    case 'branding':
      $variables['attributes_array']['class'][] = 'grid-8';
      $variables['attributes_array']['class'][] = 'omega';
      break;
    case 'menu':
    case 'footer_first':
    case 'footer_second':
    case 'postscript_fourth':
      $variables['attributes_array']['class'][] = 'grid-12';
      $variables['attributes_array']['class'][] = 'alpha';
      $variables['attributes_array']['class'][] = 'omega';
      break;
    case 'header_first':
      $variables['attributes_array']['class'][] = 'grid-6';
      $variables['attributes_array']['class'][] = 'alpha';
      break;
    case 'header_second':
      $variables['attributes_array']['class'][] = 'grid-6';
      $variables['attributes_array']['class'][] = 'omega';
      break;
    case 'preface_first':
    case 'postscript_first':
      $variables['attributes_array']['class'][] = 'grid-4';
      $variables['attributes_array']['class'][] = 'alpha';
      break;
    case 'preface_second':
    case 'postscript_second':
      $variables['attributes_array']['class'][] = 'grid-4';
      break;
    case 'preface_third':
    case 'postscript_third':
      $variables['attributes_array']['class'][] = 'grid-4';
      $variables['attributes_array']['class'][] = 'omega';
      break;
    case 'sidebar_first':
      $variables['attributes_array']['class'][] = 'grid-3';
      switch ($variables['elements']['#context']) {
        case 'all content':
          $variables['attributes_array']['class'][] = 'pull-6';
          break;
        case 'only content':
          $variables['attributes_array']['class'][] = 'pull-9';
          break;
      }
      break;
    case 'sidebar_second':
      switch ($variables['elements']['#context']) {
        case 'all content':
          $variables['attributes_array']['class'][] = 'grid-3';
          break;
        case 'only content':
          $variables['attributes_array']['class'][] = 'grid-4';
          break;
      }
      $variables['attributes_array']['class'][] = 'omega';
      break;
  }
}

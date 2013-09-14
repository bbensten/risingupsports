<?php

/**
 * @file
 * This file contains the Rules hooks and functions necessary to
 * make the cart related entity, conditions, events, and actions work.
 */

/******************************************************************************
 * Rules Hooks                                                                *
 ******************************************************************************/

/**
 * Implements hook_rules_event_info().
 */
function rus_helper_rules_event_info() {
  //return $events;
}

/**
 * Implements hook_rules_action_info().
 */
function uc_file_rules_action_info() {
  //@todo: Load media emails, load node, create email template, send. Requires node data.
  //
  //return $actions;
}
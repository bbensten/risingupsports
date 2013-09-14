<?php
/**
 * @file
 * rus_structure.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function rus_structure_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '2',
  );

  // Exported role: faculty.
  $roles['faculty'] = array(
    'name' => 'faculty',
    'weight' => '3',
  );

  // Exported role: student.
  $roles['student'] = array(
    'name' => 'student',
    'weight' => '4',
  );

  return $roles;
}

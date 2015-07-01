<?php
/**
 * @file
 * admin_labels.api.inc
 */

/**
 * Allows modules to define new label types.
 *
 * @return array
 */
function hook_admin_labels_label_types() {
  return array(
    'machine-name' => array(
      'text' => 'Label Text Here',
    ),
  );
}

/**
 * Allows other modules to act upon a label assignment.
 *
 * @param string $type
 *   The object type identifier (e.g. node).
 * @param int $identifier
 *   The unique serial identifier of the object (e.g. a node's nid).
 * @param object $label
 *   The label object which has been assigned.
 */
function hook_admin_labels_label_assigned($type, $identifier, $label) {
  watchdog('admin_labels', 'A label has been assigned to object of type %type with an identifier %id.', array('%type' => $type, '%id' => $identifier), WATCHDOG_DEBUG);
}

/**
 * Allows other modules to act upon a label assignment deletion.
 *
 * @param string $type
 *   The object type identifier (e.g. node).
 * @param int $identifier
 *   The unique serial identifier of the object (e.g. a node's nid).
 * @param object $label
 *   The assigned label object which has been deleted.
 */
function hook_admin_labels_label_assignment_deleted($type, $identifier, $label) {
  watchdog('admin_labels', 'A label assignment has been deleted.', array(), WATCHDOG_DEBUG);
}

<?php
/**
 * @file
 * admin_labels.drush.inc
 */

/**
 * Implements hook_drush_command().
 */
function admin_labels_drush_command() {
  $commands = array();
  $commands['admin-labels-rebuild-label-types'] = array(
    'description' => 'Rebuild the label types.',
    'options' => array(
      'flush-cache' => 'Flush caches once label types have been rebuilt.',
    ),
    'aliases' => array('alrlt'),
  );
  $commands['admin-labels-rebuild-menu-link-preferred-label-assignments'] = array(
    'description' => 'Re-index and ensure that all menu links have the preferred menu link assignment for nodes.',
    'arguments' => array(
      'router-path' => 'The router path (e.g. node/%) to rebuild the preferred menu link labels for.',
    ),
  );
  $commands['admin-labels-clear-assigned-labels'] = array(
    'description' => 'Clears all assigned labels.',
  );
  return $commands;
}

/**
 * Drush command callback for rebuilding label types.
 */
function drush_admin_labels_rebuild_label_types() {
  $flush_caches = (bool) drush_get_option('flush-cache', FALSE);
  admin_labels_rebuild_label_types($flush_caches);
}

/**
 * Drush command callback for rebuilding preferred menu link labels.
 */
function drush_admin_labels_rebuild_menu_link_preferred_label_assignments($router_path = NULL) {
  if (empty($router_path)) {
    $router_path = 'node/%';
  }
  admin_labels_rebuild_menu_link_preferred_label_assignments($router_path);
}

/**
 * Drush command callback for clearing all assigned labels.
 */
function drush_admin_labels_clear_assigned_labels() {
  foreach (admin_labels_label_types() as $label) {
    admin_labels_label_assignment_delete_by_label($label);
  }
}

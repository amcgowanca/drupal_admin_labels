<?php
/**
 * @file
 * admin_labels.theme.inc
 */

/**
 * Theme callback for rendering a single label.
 */
function theme_admin_labels_label($variables) {
  if (!empty($variables['label'])) {
    drupal_add_css(drupal_get_path('module', 'admin_labels') . '/misc/admin_labels.css');
    $attributes = array(
      'class' => array(
        'admin-labels-label', 'label-' . $variables['label']->type
      ),
    );
    return '<span ' . drupal_attributes($attributes) . '>' . check_plain($variables['label']->text) . '</span>';
  }
}

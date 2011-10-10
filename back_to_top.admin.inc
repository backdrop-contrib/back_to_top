<?php

/**
 * @file
 * Contains the administration pages for Back To Top.
 *
 */

function back_to_top_settings($form_state) {
  
  $form['back_to_top_prevent_on_mobile'] = array(
    '#type' => 'checkbox',
    '#title' => t('Prevent on mobile and touch devices'),
    '#description' => t('Do you want Back To Top to be active on touch devices?'),
    '#default_value' => variable_get('back_to_top_prevent_on_mobile', TRUE),
  );

  return system_settings_form($form);
}

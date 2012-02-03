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
    '#description' => t('Do you want to prevent Back To Top on touch devices?'),
    '#default_value' => variable_get('back_to_top_prevent_on_mobile', TRUE),
  );
  $form['back_to_top_prevent_in_admin'] = array(
    '#type' => 'checkbox',
    '#title' => t('Prevent on administration pages and node edit'),
    '#description' => t('Do you want to prevent Back To Top on admin pages?'),
    '#default_value' => variable_get('back_to_top_prevent_in_admin', TRUE),
  );
  $form['back_to_top_button_type'] = array(
    '#type' => 'radios',
    '#title' => t('Do you want Back To Top to use a PNG-24 image or a Text/Css button?'),
    '#options' => array(
    'image' => t('Image (default)'),
    'text' => t('Text/Css')
    ),
    '#default_value' => variable_get('back_to_top_button_type', 'image'),
  );
  $form['back_to_top_button_place'] = array(
    '#title' => t('Placement'),
    '#description' => t('Where should the Back To Top button appear?'),
    '#type' => 'select',
    '#options' => array(
      1 => t('Bottom right'),
      2 => t('Bottom left'),
      3 => t('Botton center'),
      4 => t('Top right'),
      5 => t('Top left'),
      6 => t('Top center'),
      7 => t('Mid right'),
      8 => t('Mid left'),
      9 => t('Mid center'),
    ),
    '#default_value' => variable_get('back_to_top_button_place', 1),
  );
  $form['back_to_top_bg_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Text/css button background color'),
    '#description' => t('Button background color default #F7F7F7'),
    '#default_value' => variable_get('back_to_top_bg_color', '#F7F7F7'),
    '#size' => 10,
    '#maxlength' => 7,
  );
  $form['back_to_top_border_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Text/css border color'),
    '#description' => t('Border color default #CCCCCC'),
    '#default_value' => variable_get('back_to_top_border_color', '#CCCCCC'),
    '#size' => 10,
    '#maxlength' => 7,
  );
  $form['back_to_top_hover_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Text/css hover color'),
    '#description' => t('Hover color default #EEEEEE'),
    '#default_value' => variable_get('back_to_top_hover_color', '#EEEEEE'),
    '#size' => 10,
    '#maxlength' => 7,
  );
  $form['back_to_top_text_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Text/css text color'),
    '#description' => t('Text color default #333333'),
    '#default_value' => variable_get('back_to_top_text_color', '#333333'),
    '#size' => 10,
    '#maxlength' => 7,
  );
  return system_settings_form($form);
}

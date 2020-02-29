<?php
/**
 * @file
 * Admin page callbacks for the Back To Top module.
 */

function back_to_top_settings($form, &$form_state) {
  $config = config('back_to_top.settings');
  $attributes = 'style="margin-bottom: 30px;"';

  // Add libraries, JS & CSS.
  backdrop_add_library('system', 'farbtastic');
  backdrop_add_js(backdrop_get_path('module', 'back_to_top') . '/js/back_to_top.admin.js');

  $form['#config'] = 'back_to_top.settings';
  $form['disable_mobile'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable on mobile and touch devices'),
    '#description' => t('Uses the <a href="https://backdropcms.org/project/mobile_detect" target="_blank">Mobile Detect</a> module to detect mobile/touch devices and disables Back To Top on them.'),
    '#default_value' => $config->get('disable_mobile'),
  );
  if (!module_exists('mobile_detect')) {
    $form['disable_mobile']['#disabled'] = TRUE;
    $form['disable_mobile']['#description'] .= t('<br><strong>NOTE:</strong> The Mobile Detect module is not installed. Install it to enable this option.');
  }
  $form['disable_admin'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable on administrative pages'),
    '#description' => t('Disables Back To Top on all admin pages (including node add/edit forms).'),
    '#default_value' => $config->get('disable_admin'),
  );
  $form['disable_front'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable on front page'),
    '#default_value' => $config->get('disable_front'),
  );
  $form['distance'] = array(
    '#type' => 'number',
    '#title' => t('Distance'),
    '#description' => t('The distance (in pixels) you must scroll down before the Back To Top button will be displayed.'),
    '#default_value' => $config->get('distance'),
    '#min' => 0,
    '#max' => 999,
    '#field_suffix' => t('px'),
  );
  $form['placement'] = array(
    '#type' => 'select',
    '#title' => t('Placement'),
    '#description' => t('Where on the screen the Back To Top button will be displayed.'),
    '#options' => array(
      1 => t('Bottom right'),
      2 => t('Bottom left'),
      3 => t('Bottom center'),
      4 => t('Top right'),
      5 => t('Top left'),
      6 => t('Top center'),
      7 => t('Middle right'),
      8 => t('Middle left'),
      9 => t('Middle center'),
    ),
    '#default_value' => $config->get('placement'),
  );
  $form['text'] = array(
    '#type' => 'textfield',
    '#title' => t('Text'),
    '#description' => t('The text to display for the button (displayed as title text for the image button type).'),
    '#default_value' => $config->get('text'),
    '#size' => 30,
  );
  $form['title'] = array(
    '#type' => 'checkbox',
    '#title' => t('Title text'),
    '#description' => t("Add the button text to a 'title' attribute to display on hover."),
    '#default_value' => $config->get('title'),
  );
  $form['type'] = array(
    '#type' => 'radios',
    '#title' => t('Type'),
    '#description' => t('Display the button using an image or text/CSS.'),
    '#options' => array(
      'image' => t('Image'),
      'text' => t('Text/CSS'),
    ),
    '#default_value' => $config->get('type'),
  );
  $form['text_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Text/CSS settings'),
    '#states' => array(
      'visible' => array(
        ':input[name="type"]' => array(
          'value' => 'text',
        ),
      ),
    ),
  );
  $form['text_settings']['color_bg'] = array(
    '#type' => 'textfield',
    '#title' => t('Background color'),
    '#default_value' => $config->get('color_bg'),
    '#size' => 10,
    '#maxlength' => 7,
    '#suffix' => '<div id="color_bg" ' . $attributes . '></div>',
  );
  $form['text_settings']['color_border'] = array(
    '#type' => 'textfield',
    '#title' => t('Border color'),
    '#default_value' => $config->get('color_border'),
    '#size' => 10,
    '#maxlength' => 7,
    '#suffix' => '<div id="color_border" ' . $attributes . '></div>',
  );
  $form['text_settings']['color_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Text color'),
    '#default_value' => $config->get('color_text'),
    '#size' => 10,
    '#maxlength' => 7,
    '#suffix' => '<div id="color_text" ' . $attributes . '></div>',
  );
  $form['text_settings']['color_hover'] = array(
    '#type' => 'textfield',
    '#title' => t('Hover color'),
    '#description' => t("The color of the button's background and border when hovered over."),
    '#default_value' => $config->get('color_hover'),
    '#size' => 10,
    '#maxlength' => 7,
    '#suffix' => '<div id="color_hover" ' . $attributes . '></div>',
  );

  return system_settings_form($form);
}


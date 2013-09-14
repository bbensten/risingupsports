<?php

function riseup_form_search_block_form_alter(&$form, &$form_state){
  $form['actions']['submit'] = array(
    '#type' => 'image_button',
    '#src' => base_path() . path_to_theme() . '/images/search-hourglass2.png',
  );
}

<?php
 /**
  * This template is used to print a single field in a view. It is not
  * actually used in default Views, as this is registered as a theme
  * function which has better performance. For single overrides, the
  * template is perfectly okay.
  *
  * Variables available:
  * - $view: The view object
  * - $field: The field handler object that can process the input
  * - $row: The raw SQL result that can be used
  * - $output: The processed output that will normally be used.
  *
  * When fetching output from the $row, this construct should be used:
  * $data = $row->{$field->field_alias}
  *
  * The above will guarantee that you'll always get the correct data,
  * regardless of any changes in the aliasing that might happen if
  * the view is modified.
  */
?>

<?php
  //Add an arrow ONLY if the image exists.
  if(strlen($output) > 20){
    $nid = $row->nid;
    $img_html = '<img src="/sites/all/themes/omega_rus/image/arrow-play-w25.png">';
    $link_html= l($img_html, 'node/'.$nid, array('html' => TRUE));
    $html = '<div class="browse-play-overlay">' . $link_html . '</div>';
    print $html;
  }
?>

<?php print $output; ?>
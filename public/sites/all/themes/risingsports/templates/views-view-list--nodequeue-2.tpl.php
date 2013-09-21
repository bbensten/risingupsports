<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
?>

  <div id="home-slider">
      <div class="flexslider-container">
        <div id="single-post-slider" class="flexslider">
 		 <ul class="bxslidermain">
    <?php
	$i=0;
    foreach ($rows as $id => $row): ?>
      <li class="slide"><?php print $row; ?> <div class="slideshowplay" align="center">
      <a href="<?php print $view->result[$i]->_field_data['nid']['entity']->path['alias']; ?>">
      <img  src="<?php global $base_url; print $base_url;?>/sites/all/themes/risingsports/images/icon-play.png" width="84" height="84" />
      </a>
      </div>

      </li>
      
    <?php 
    $i++;
    endforeach; ?>
 		 </ul><!-- /slides -->
        </div><!-- /flexslider -->
      </div>
    </div>
    
 		 
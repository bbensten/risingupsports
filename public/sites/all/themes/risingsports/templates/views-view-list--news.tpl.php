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
<div id="news" class="news">
    <div class="news-section">
    	
				 <?php foreach ($rows as $id => $row): ?>
			   		<?php print $row; ?>
			    <?php endforeach; ?>
			   
     </div>
 </div>
			   
<?php 
// print "<pre>";
// print_r($content); ?>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // Hide comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      //print render($content);
    ?>
  </div>
  
  <div class="container" id="content">
     
     <!-- video content begins here -->
     <div class="video_content">
        
     <?php // print render($content);

    	$channel_id = $node->field_livestream_reference['und'][0]['nid'];
    	$channel = node_load($channel_id);
    	
    	print $channel->body['und'][0]['safe_value'];
    ?>
        <div class="video_info">
        
	        <span class="heading"><?php print $title; ?></span>
	        <?php $block = module_invoke('sharethis', 'block_view', 'sharethis_block'); ?>
	        <div class="clearfix"></div>	<div class="social_icon">
			<?php print $block['content']; ?></div>
	        <span class="black_row"></span>
	        
        <p><?php print $node->body['und'][0]['value']; ?>
        </p>
        </div>
        
      </div>

   <?php print render($content['comments']); ?>
<?php if (!$page): ?>
  </article> <!-- /.node -->
<?php endif; ?>
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
<?php 
	foreach ($rows as $id => $row): 
    	$rowvideo[]=$row;
    endforeach;
?>
     <div  class="featured-video">
        	<h3 class="section-title">featured videos</h3>
        	<div  class="big-video" id="featured-video">
        			<?php if ($view->result[0]->_field_data['nid']['entity']->field_is_free['und'][0]['value']) { ?>
						<div class="iconfree">
							<h6> Free
							</h6>
						</div>

					<?php } ?>
          			<a href="<?php print $view->result[0]->_field_data['nid']['entity']->path['alias']; ?>">
          		     <?php print theme('image_style', array('path'=>$view->result[0]->_field_data['nid']['entity']->field_image['und'][0]['uri'], 'style_name' => 'large-feature')); ?>
                    </a>
          		    
          		 <div class="feature-home-showhide" id="featurebody" onClick="window.location='<?php print $view->result[0]->_field_data['nid']['entity']->path['alias']; ?>'">
					<a href="<?php print $view->result[0]->_field_data['nid']['entity']->path['alias']; ?>">
					<?php print $view->result[0]->_field_data['nid']['entity']->title; ?><br />
					<span class="videoDesc"><?php print $view->result[0]->_field_data['nid']['entity']->body['und'][0]['value']; ?></span> </a>
				 </div>
				 
            </div>
            <ul class="video-gallery">
            	<li id="video-gallery-1" id="featurebody" onClick="window.location='<?php print $view->result[1]->_field_data['nid']['entity']->path['alias']; ?>'">
            	    <?php if ($view->result[1]->_field_data['nid']['entity']->field_is_free['und'][0]['value']) { ?>
						<div class="iconfree">
							<h6> Free
							</h6>
						</div>

					<?php } ?>
 					<a href="<?php print $view->result[1]->_field_data['nid']['entity']->path['alias']; ?>">
          		     <?php print theme('image_style', array('path'=>$view->result[1]->_field_data['nid']['entity']->field_image['und'][0]['uri'], 'style_name' => '225x130')); ?>
                    </a>
          		    
          		 <div class="feature-home-showhide" id="video-gallery-1-body">
					<a href="<?php print $view->result[1]->_field_data['nid']['entity']->path['alias']; ?>">
					<?php print $view->result[1]->_field_data['nid']['entity']->title; ?><br />
				    </a>
				 </div>
				</li>
            	<li id="video-gallery-2" id="featurebody" onClick="window.location='<?php print $view->result[2]->_field_data['nid']['entity']->path['alias']; ?>'">
 					   <?php if ($view->result[2]->_field_data['nid']['entity']->field_is_free['und'][0]['value']) { ?>
						<div class="iconfree">
							<h6> Free
							</h6>
						</div>

					<?php } ?>
 					<a href="<?php print $view->result[2]->_field_data['nid']['entity']->path['alias']; ?>">
          		     <?php print theme('image_style', array('path'=>$view->result[2]->_field_data['nid']['entity']->field_image['und'][0]['uri'], 'style_name' => '225x130')); ?>
                    </a>
          		 <a href="<?php print $view->result[2]->_field_data['nid']['entity']->path['alias']; ?>">
          		    
          		 <div class="feature-home-showhide" id="video-gallery-2-body">
					<a href="<?php print $view->result[2]->_field_data['nid']['entity']->path['alias']; ?>">
					<?php print $view->result[2]->_field_data['nid']['entity']->title; ?><br />
				    </a>
				 </div>
				 </a>
				 
                </li>
                
                <li id="video-gallery-3" id="featurebody" onClick="window.location='<?php print $view->result[3]->_field_data['nid']['entity']->path['alias']; ?>'">
                <?php if ($view->result[3]->_field_data['nid']['entity']->field_is_free['und'][0]['value']) { ?>
						<div class="iconfree">
							<h6> Free
							</h6>
						</div>

					<?php } ?>
                
                
 					<a href="<?php print $view->result[3]->_field_data['nid']['entity']->path['alias']; ?>">
          		     <?php print theme('image_style', array('path'=>$view->result[3]->_field_data['nid']['entity']->field_image['und'][0]['uri'], 'style_name' => '225x130')); ?>
                    </a>
          		    
          		 <div class="feature-home-showhide" id="video-gallery-3-body" >
					<a href="<?php print $view->result[3]->_field_data['nid']['entity']->path['alias']; ?>">
					<?php print $view->result[3]->_field_data['nid']['entity']->title; ?><br />
			 	    </a>
				 </div>
                </li>
                <li id="video-gallery-4" id="featurebody" onClick="window.location='<?php print $view->result[4]->_field_data['nid']['entity']->path['alias']; ?>'">
                       <?php if ($view->result[4]->_field_data['nid']['entity']->field_is_free['und'][0]['value']) { ?>
						<div class="iconfree">
							<h6> Free
							</h6>
						</div>

					<?php } ?>
 					<a href="<?php print $view->result[4]->_field_data['nid']['entity']->path['alias']; ?>">
          		     <?php print theme('image_style', array('path'=>$view->result[4]->_field_data['nid']['entity']->field_image['und'][0]['uri'], 'style_name' => '225x130')); ?>
                    </a>
          		    
          		 <div class="feature-home-showhide" id="video-gallery-4-body">
					<a href="<?php print $view->result[4]->_field_data['nid']['entity']->path['alias']; ?>">
					<?php print $view->result[4]->_field_data['nid']['entity']->title; ?><br />
					 </a>
				 </div>
                </li>
            </ul>
            <div class="clear"></div>
        </div>
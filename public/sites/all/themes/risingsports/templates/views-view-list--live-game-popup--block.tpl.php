<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
foreach ($view->result as $key=>$value){
	
$sportid = $view->result[$key]->_field_data['nid']['entity']->field_term_sport['und'][0]['tid'];
$sport = taxonomy_term_load($view->result[$key]->_field_data['nid']['entity']->field_term_sport['und'][0]['tid']);
$hometeam = taxonomy_term_load($view->result[$key]->_field_data['nid']['entity']->field_term_team_home['und'][0]['tid']);
$awayteam = taxonomy_term_load($view->result[$key]->_field_data['nid']['entity']->field_term_team_away['und'][0]['tid']);


$start_date = strtotime($view->result[$key]->_field_data['nid']['entity']->field_live_game_popup_date['und'][0]['value']);
$end_date = strtotime($view->result[$key]->_field_data['nid']['entity']->field_live_game_popup_date['und'][0]['value2']);

$curdate=  time();

if( $curdate >= $start_date && $curdate <= $end_date ){

?>
		<div class="clearfix"></div>

 		 <div class="popUpContainer">
 		     		   <div class="popHead"><?php print $sport->name; ?></div>
   					<div class="popVs"><?php print $hometeam->name; ?> <span>VS.</span> <?php print $awayteam->name; ?></div>
				    <div class="popFoot">
   				     <span class="first-child"><a href="<?php print $view->result[$key]->_field_data['nid']['entity']->path['alias']; ?>" > <span class="dot"></span>+ LIVE </a></span>
			        <span class="sec-child"><a href="<?php print $view->result[$key]->_field_data['nid']['entity']->path['alias']; ?>" >WATCH NOW</a></span>
  				  </div>
 				 </div>
		</div>
<?php 
}

}
?>
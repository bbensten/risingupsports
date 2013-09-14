<?php global $user; ?>
<div class="container" id="content">
        <div class="row-fluid">
                    
        	<div class="clearfix pricingTableWrapper">
            
            	<div class="span4" id="daily">
                	<div class="tableHead">Day</div>
                	<div class="tableHeadDesc">24 Hours</div>
                    <div class="tablePrice">
                    	<span>$</span>4.95
                    </div>
                    <div class="tableDiscount"></div>
                    <span class="selectedIcon"></span>
                </div>
                
            	<div class="span4 selected" id="monthly">
                	<div class="tableHead">Month</div>
                    <div class="tableHeadDesc">30 Days</div>
                    
                    <div class="tablePrice">
                    	<span>$</span>7.95
                    </div>
                    <div class="tableDiscount">You save 15%</div>
                    <span class="selectedIcon"></span>
                </div>
                
            	<div class="span4" id="yearly">
                	<div class="tableHead">Year</div>
                	<div class="tableHeadDesc">365 Days</div>
                	
                    <div class="tablePrice">
                    	<span>$</span>75
                    </div>
                    <div class="tableDiscount">You save 35%</div>
                    <span class="selectedIcon"></span>
                </div>
                
            </div>
            <?php if(!$user->uid){?>
            <div class="registrationForm">
                	<h4>REGISTER <a href="#" rel="block-user-login" class="popup">Already a member? Sign in</a></h4>
                    <?php print drupal_render($form['account']['name']); ?>
					<?php print drupal_render($form['account']['mail']);?>                    
                    <?php print drupal_render($form['account']['pass']);?>                    
            </div>
            <?php } ?>       
            <div class="checkoutForm">
            <h4>CHECKOUT</h4>
                	<div class="row row1">
                	<?php
					global $base_url;
                	$image_path = $base_url."/".drupal_get_path('theme', 'risingsports') . '/images/cardtype/'; ?>
                    	<?php print drupal_render($form['credit_card']['number']); ?>
                        <?php print drupal_render($form['credit_card']['type']); ?>
                        <img src="<?php print $image_path; ?>visa.png" alt="Visa" />
                        <img src="<?php print $image_path; ?>mastercard.png" alt="" />
                        <img src="<?php print $image_path; ?>americanExpress.png" alt="" />
                    </div>
                	<div class="row row2">
                    	<?php print drupal_render($form['credit_card']['number']); ?>
                    	<?php print drupal_render($form['full_name']); ?>
                    	<?php print drupal_render($form['credit_card']['code']); ?>
                    	
                    	<?php print drupal_render($form['credit_card']['exp_month']); ?>
                    	<?php print drupal_render($form['credit_card']['exp_year']); ?>
                    	
                    </div>
                    <div class="row row3">
                    	<?php print drupal_render($form['street']); ?>
                                        </div>
                    <div class="row row4">                    	
                    	<?php print drupal_render($form['city']); ?>
                    	<?php print drupal_render($form['state']); ?>
						<?php print drupal_render($form['zip']); ?>
                    	<?php print drupal_render($form['countries']); ?>
						
                    </div>
            
                <div class="checkoutArea clearfix">
                    <div class="chargedAmount">
                        <table><tr>
                                <td>You will be charged</td>
                                <td>:</td>
                                <td id="chargedamount">$7.95</td>
                            </tr><tr>
                                <td>You are upgrading</td>
                                <td>:</td>
                                <td><?php global $user; print $user->mail; ?></td>
                        </tr></table>
                    </div>
                   <?php print drupal_render($form['submit']); ?>
                    
                </div>
            
                <div class="terms">By upgrading your account, you agree to the RisingUpSports <a href="/article/368/terms-service" target="_blank">Pricing Terms</a></div>
                
                <div class="disclaimer">All amounts shown are in US dollars.</div>
				<div style="display:none" ><?php print drupal_render_children($form); ?></div>            	
       		</div>
        </div>
    </div>

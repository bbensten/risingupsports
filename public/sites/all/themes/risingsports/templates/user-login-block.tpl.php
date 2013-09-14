<div class="login-popup">  <?php global $base_url; ?>
<div style="width:100%; text-align:right" id="login-cross" ><a href="#"><img src="<?php print $base_url; ?>/sites/all/themes/risingsports/images/icon-cross.jpg" alt="cross"></a>
        </div>
      
<div style="width:380px; margin:0 auto">
<div style="width:100%; text-align:center; border-bottom:#FFF solid 1px; padding-bottom:10px;"  ><img src="<?php print $base_url; ?>/sites/all/themes/risingsports/logo.png" alt="Home">
  </div>
<div style="width:376px; text-align:center; margin:20px 0; "><h3 style="color:#FFF"><img src="<?php print $base_url; ?>/sites/all/themes/risingsports/images/icon-login.png" alt="Home"></h3></div>

<?php print drupal_render($form['name']); ?>
<?php print drupal_render($form['pass']); ?>
<?php print drupal_render($form['actions']['submit']); ?>
<div class="login-social-media">
<?php print drupal_render($form['twitter_signin']); ?><!--<img src="http://localhost/risingupsports/sites/all/themes/risingsports/images/icon-fb.png" alt="cross">-->
<?php /*?><?php print drupal_render($form['facebook_signin']); ?><?php */?>
</div>
<div style="width:376px; text-align:center; margin:20px; "><h3 style="color:#FFF"><img src="<?php print $base_url; ?>/sites/all/themes/risingsports/images/icon-text.png" alt="Home"></h3>
<h3 style="color:#FFF"><a href="<?php print $base_url; ?>/user/register"><img src="<?php print $base_url; ?>/sites/all/themes/risingsports/images/icon-reg.png" alt="Home"></a></h3></div>

</div>
</div>
<div style="display:none"><?php print drupal_render_children($form); ?></div>
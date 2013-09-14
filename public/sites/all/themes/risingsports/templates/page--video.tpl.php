<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/garland.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 */
?>
<div  id="wrap" class="clearfix">
  <div id="header-wrap">
   
    <header id="header" class="clearfix">
       <nav id="navigation-user" role="navigation-user">
       <div class="clearfix"></div>
        <div id="loginpopup"> 
        <?php global $user; if(!$user->uid) { ?><a href="#" rel="block-user-login" class="popup"> | Login</a> <?php } ?>
        </div>
        <div id="main-menu">
          <?php 
            if (module_exists('i18n_menu')) {
              $user_menu_tree = i18n_menu_translated_tree(variable_get('menu_user_links_source', 'user-menu'));
            } else {
              $user_menu_tree = menu_tree(variable_get('menu_user_links_source', 'user-menu'));
            }

            print drupal_render($user_menu_tree);
          ?>
        </div>
      
      </nav>
      
      <div id="logo">
        <?php if ($logo): ?><div id="site-logo"><a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
          <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
        </a></div><?php endif; ?>
      </div>
      <?php print render($page['header']); ?>
      <nav id="navigation" role="navigation">
        <div id="main-menu">
          <?php 
            if (module_exists('i18n_menu')) {
              $main_menu_tree = i18n_menu_translated_tree(variable_get('menu_main_links_source', 'main-menu'));
            } else {
              $main_menu_tree = menu_tree(variable_get('menu_main_links_source', 'main-menu'));
            }
            print drupal_render($main_menu_tree);
          ?>
        </div>
      </nav>
    </header>
  </div>

  <div id="main-content" style="background-image: url(images/pattern_bg.png) repeat-x scroll 0 0 #F2F2F2;" class="clearfix">
  
	<?php if($page['slider']): ?> <?php print render($page['slider']); ?> <?php endif; ?>
	
	
    <?php if($page['preface_first'] || $page['preface_middle'] || $page['preface_last'] || $page['header']) : ?>
    <div id="preface-area" class="clearfix">
      <?php if($page['preface_first'] || $page['preface_middle'] || $page['preface_last']) : ?>
      <div id="preface-block-wrap" class="clearfix">
        <?php if($page['preface_first']): ?><div class="preface-block">
          <?php print render ($page['preface_first']); ?>
        </div><?php endif; ?>
        <?php if($page['preface_middle']): ?><div class="preface-block">
          <?php print render ($page['preface_middle']); ?>
        </div><?php endif; ?>
        <?php if($page['preface_last']): ?><div class="preface-block remove-margin">
          <?php print render ($page['preface_last']); ?>
        </div><?php endif; ?>
      </div>
      <div class="clear"></div>
      <?php endif; ?>

      
    </div>
    <?php endif; ?>

    <?php $sidebarclass=" "; if($page['sidebar_first']) { $sidebarclass="sidebar-bg"; } ?>
    <div id="primary" class="container <?php print $sidebarclass; ?> clearfix">
      <section id="content" role="main" class="clearfix">
        <?php print $messages; ?>
        <?php if ($page['content_top']): ?><div id="content_top"><?php print render($page['content_top']); ?></div><?php endif; ?>
        <div id="content-wrap">
          <?php print render($title_prefix); ?>
          <?php if ($title): ?><h1 class="page-title"><?php print $title; ?></h1><?php endif; ?>
          <?php print render($title_suffix); ?>
          <?php if (!empty($tabs['#primary'])): ?><div class="tabs-wrapper clearfix"><?php print render($tabs); ?></div><?php endif; ?>
          <?php print render($page['help']); ?>
          <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
          <?php print render($page['content']); ?>
          
          <div class="clearfix"></div>
		<?php if ($page['content_bottom']): ?><?php print render($page['content_bottom']); ?><?php endif; ?> 
          </div>
      </section>
      <?php if(!$is_front){ ?>
      <?php if ($page['sidebar_first']): ?>
        <aside id="sidebar" role="complementary">
         <?php print render($page['sidebar_first']); ?>
        </aside> 
      <?php endif; ?>
      <?php } ?>
    </div>

    <div class="clear"></div>
  </div>

  <?php /*?><?php if ($page['footer_first'] || $page['footer_second'] || $page['footer_third']  || $page['footer']): ?><?php */?>
  <footer id="footer-bottom">
    <div id="footer-area" class="clearfix">
   	  <div class="footer-left">
        	
            <div class="footer-links-section">
                <ul class="footer-link">
                    <li><a href="/contact">contact</a></li>
                    <li><a href="/crew">crew</a></li>
                </ul>
                
               
            </div>
            <div id="copyright">
			&copy; 2013. Risingupsports. All Rights Reserved 
          </div>
        </div>
                 <div class="rightFooter">
        <?php global $base_url; ?>	<a href="https://www.facebook.com/GenevaTV.org"><img src="<?php print $base_url; ?>/sites/all/themes/risingsports/images/facebook.png" alt="" /></a>
        	<a href="http://www.twitter.com/GenevaSports"><img src="<?php print $base_url; ?>/sites/all/themes/risingsports/images/twitter.png" alt="" /></a>
        	
        </div>
        <div class="clear"></div>
      <?php if ($page['footer_first'] || $page['footer_second'] || $page['footer_third']): ?>
        <div id="footer-block-wrap" class="clearfix">
          <?php if($page['footer_first']): ?><div class="footer-block">
            <?php print render ($page['footer_first']); ?>
          </div><?php endif; ?>
          <?php if($page['footer_second']): ?><div class="footer-block">
            <?php print render ($page['footer_second']); ?>
          </div><?php endif; ?>
          <?php if($page['footer_third']): ?><div class="footer-block remove-margin">
            <?php print render ($page['footer_third']); ?>
          </div><?php endif; ?>
        </div>
        <div class="clear"></div>
      <?php endif; ?>
      
      <?php print render($page['footer']); ?>
    </div>
  </footer>
 <?php /*?> <?php endif; ?><?php */?>

<div id="fade"></div>
</div>
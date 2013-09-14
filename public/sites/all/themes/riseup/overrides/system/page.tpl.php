<?php
/**
 * @file
 * Alpha's theme implementation to display a single Drupal page.
 */
?>

<div<?php print $attributes; ?>>
  <?php if ($page['callout']): ?>
    <div class="callout-section">
      <?php print render($page['callout']); ?>
    </div>
  <?php endif; ?>

  <div class="header-section container-12 clearfix">
    <?php if (!empty($page['user_first']) || !empty($page['user_first'])): ?>
      <div class="user-zone grid-12">
        <?php print render($page['user_first']); ?>
        <?php print render($page['user_second']); ?>
      </div>
    <?php endif; ?>

    <?php if (!empty($page['branding'])): ?>
      <div class="branding-zone grid-12">
        <div class="site-information grid-4 alpha">
          <span class="site-name element-invisible"><?php print render($site_name); ?></span>
          <?php print render($logo_image); ?>
        </div>
        <?php print render($page['branding']); ?>
      </div>
    <?php endif; ?>

    <?php if (!empty($page['menu'])): ?>
      <div class="menu-zone grid-12">
        <?php print render($page['menu']); ?>
      </div>
    <?php endif; ?>

    <?php if (!empty($page['header_first']) || !empty($page['header_second'])): ?>
      <div class="header-zone grid-12">
        <?php print render($page['header_first']); ?>
        <?php print render($page['header_second']); ?>
      </div>
    <?php endif; ?>
  </div>

  <div class="content-section clearfix">
    <div class="preface-content container-12 clearfix">
      <?php if (!empty($page['preface_first']) || !empty($page['preface_second']) || !empty($page['preface_third'])): ?>
        <div class="preface-zone grid-12">
          <?php print render($page['preface_first']); ?>
          <?php print render($page['preface_second']); ?>
          <?php print render($page['preface_third']); ?>
        </div>
      <?php endif; ?>
    </div>

    <div class="main-content clearfix">
      <div class="main-content-inner container-12">
        <?php if (!empty($messages) || !empty($page['sidebar_first']) || !empty($page['content']) || !empty($page['sidebar_second'])): ?>
          <div class="content-zone grid-12">
            <?php print render($title_prefix); ?>
            <?php if ($title): ?>
              <h1<?php print $title_attributes; ?>><?php print $title; ?></h1>
            <?php endif; ?>
            <?php print render($title_suffix); ?>
            <?php print render($page['highlighted']); ?>
            <div<?php print $content_attributes; ?>>
              <?php print render($tabs); ?>
              <?php print render($page['help']); ?>
              <?php if (!empty($messages)) {
                print $messages;
              } ?>
              <?php print render($page['content']); ?>
            </div>
            <?php print render($page['sidebar_first']); ?>
            <?php print render($page['sidebar_second']); ?>
          </div>
        <?php endif; ?>
      </div>
    </div>

    <div class="container-12 supplementary-content">
      <?php if (!empty($page['postscript_first']) || !empty($page['postscript_second']) || !empty($page['postscript_third']) || !empty($page['postscript_fourth'])): ?>
        <div class="postscript-zone grid-12">
          <?php print render($page['postscript_first']); ?>
          <?php print render($page['postscript_second']); ?>
          <?php print render($page['postscript_third']); ?>
          <?php print render($page['postscript_fourth']); ?>
        </div>
      <?php endif; ?>
    </div>
  </div>

  <div class="footer-section clearfix">
    <div class="footer-section-inner container-12">
      <?php if (!empty($page['footer_first']) || !empty($page['footer_second'])): ?>
        <div class="footer-zone grid-12">
          <?php print render($page['footer_first']); ?>
          <?php print render($page['footer_second']); ?>
        </div>
      <?php endif; ?>
    </div>
  </div>
</div>

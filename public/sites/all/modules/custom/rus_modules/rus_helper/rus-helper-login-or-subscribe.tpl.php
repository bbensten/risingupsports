<div class="<?php print drupal_clean_css_identifier($type); ?>-wrapper vimeo-wrapper login-prompt-wrapper">
  <div class="<?php print drupal_clean_css_identifier($type);?>-content">
    <?php
      global $user;
      if (empty($user->uid)): ?>
    <p><?php print t('To view this @type, you must either Login or Subscribe:', array('@type' => $type));?></p>
    <div class="prompt-login-wrapper"><?php print l(t('Login'), 'user/login', array('attributes' => array('class' => array('button', 'prompt-login')), 'query' => array('destination' => 'node/' . $nid))); ?></div>
    <div class="prompt-login-wrapper"><?php print l(t('Subscribe'), 'subscribe', array('attributes' => array('class' => array('button', 'prompt-login')), 'query' => array('destination' => 'node/' . $nid))); ?></div>
    <?php else: ?>
    <p><?php print t('To view this @type, you must Subscribe:', array('@type' => $type));?></p>
    <div class="prompt-login-wrapper"><?php print l(t('Subscribe'), 'subscribe', array('attributes' => array('class' => array('button', 'prompt-login')), 'query' => array('destination' => 'node/' . $nid))); ?></div>
    <?php endif; ?>
  </div>
</div>

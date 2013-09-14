(function($) {
  //Mega dropdown functionality
  $('.mega-browse-all-trigger a').live('mouseenter', function () {
    //If column has zero width, remove.
    if($('.mega-browse-all-wrapper-0').length){
      $('.mega-browse-all-content-wrapper').remove();
    }

    $('#block-rus-helper-mega-browse-all').css('z-index',90);
    $('.mega-browse-all-content-wrapper').slideDown('fast');
  });

  $('.mega-browse-all-wrapper').live('mouseleave', function () {
    $('.mega-browse-all-content-wrapper').slideUp('fast', function(){
      $('#block-rus-helper-mega-browse-all').css('z-index',0);
    });
  });
})(jQuery);
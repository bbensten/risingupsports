(function($) {

//Mega dropdown functionality
$('#zone-branding-wrapper .block-mega-table .panel-col-top a').live('mouseenter', function () {
  $('#zone-branding-wrapper .block-mega-table .center-wrapper').slideDown('fast');
});

$('#zone-branding-wrapper .block-mega-table').live('mouseleave', function () {
  $('#zone-branding-wrapper .block-mega-table .center-wrapper').slideUp('fast');
});

//Crew dropdown functionality
$('#mini-panel-crew_dropdown').live('mouseenter', function () {
  $('#mini-panel-crew_dropdown .pane-views-panes').slideDown('fast');
});

$('#mini-panel-crew_dropdown').live('mouseleave', function () {
  $('#mini-panel-crew_dropdown .pane-views-panes').slideUp('fast');
});

////More videos dropdown functionality.
//$('.views-grid-full-more').live('mouseenter', function () {
//  $(this).children('.views-grid-full-more-menu').slideDown('fast');
//});
//
//$('.views-grid-full-more').live('mouseleave', function () {
//  $(this).children('.views-grid-full-more-menu').slideUp('fast');
//});

$('.kaltura-embed').live('mousedown', function(){
  $('.field-name-video-stripe').fadeOut('slow');
});




})(jQuery);;
(function ($) {

Drupal.behaviors.textarea = {
  attach: function (context, settings) {
    $('.form-textarea-wrapper.resizable', context).once('textarea', function () {
      var staticOffset = null;
      var textarea = $(this).addClass('resizable-textarea').find('textarea');
      var grippie = $('<div class="grippie"></div>').mousedown(startDrag);

      grippie.insertAfter(textarea);

      function startDrag(e) {
        staticOffset = textarea.height() - e.pageY;
        textarea.css('opacity', 0.25);
        $(document).mousemove(performDrag).mouseup(endDrag);
        return false;
      }

      function performDrag(e) {
        textarea.height(Math.max(32, staticOffset + e.pageY) + 'px');
        return false;
      }

      function endDrag(e) {
        $(document).unbind('mousemove', performDrag).unbind('mouseup', endDrag);
        textarea.css('opacity', 1);
      }
    });
  }
};

})(jQuery);
;

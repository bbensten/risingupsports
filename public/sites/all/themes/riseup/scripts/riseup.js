(function($) {

  /**
   * Make the crew list appear on hover.
   */
  Drupal.behaviors.crewDropdown = {
    attach: function (context, settings) {
      $('.block-panels-mini-crew-dropdown', context).once('crewDropdown', function () {
        var crewMenu = $(this),
            crewList = crewMenu.find('.pane-views-panes');

        crewList.addClass('element-invisible');

        crewMenu.mouseenter(function () {
          crewList.toggleClass('element-invisible');
        });

        crewMenu.mouseleave(function () {
          crewList.toggleClass('element-invisible');
        });
      });
    }
  };
  
  $(document).ready(function() {
    var closeLink = $('#block-rus-helper-rus-event-callout div.rus-event-callout-close a');
    if (closeLink.length) {
      $('#block-rus-helper-rus-event-callout div.rus-event-callout-close a').click(function(event) {
        $('#block-rus-helper-rus-event-callout').hide();
        $.cookie('Drupal.eventCallout.timeSet', $.now(), {expires: $.now() + Drupal.settings.eventCalloutExpiration});
        return false;
      });
      
      if ((typeof $.cookie('Drupal.eventCallout.timeSet') !== 'undefined')) {
        var time = parseInt($.cookie('Drupal.eventCallout.timeSet'));
        if (time && ($.now() - $.cookie('Drupal.eventCallout.timeSet') < Drupal.settings.eventCalloutExpiration)) {
          $('#block-rus-helper-rus-event-callout').hide();
        }
        else {
          $('#block-rus-helper-rus-event-callout').show();
        }
      }
    }
  });

})(jQuery);

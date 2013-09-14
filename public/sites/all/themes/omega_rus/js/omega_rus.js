(function($) {

//Crew dropdown functionality
$('#mini-panel-crew_dropdown').live('mouseenter', function () {
  $('#mini-panel-crew_dropdown .pane-views-panes').slideDown('fast');
});

$('#mini-panel-crew_dropdown').live('mouseleave', function () {
  $('#mini-panel-crew_dropdown .pane-views-panes').slideUp('fast');
});

$(document).ready(function() {
  $('#block-rus-helper-rus-event-callout div.rus-event-callout-close a').click(function(event) {
    $('#block-rus-helper-rus-event-callout').hide();
    $.cookie('Drupal.eventCallout.timeSet', $.now());
    event.stopPropagation();
  });
  
  if ((typeof $.cookie('Drupal.eventCallout.timeSet') !== 'undefined')) {
    var time = parseInt($.cookie('Drupal.eventCallout.timeSet'));
    if (time && ($.now() - $.cookie('Drupal.eventCallout.timeSet') < Drupal.settings.eventCalloutExpiration)) {
      $('#block-rus-helper-rus-event-callout').hide();
    }
  }
});

})(jQuery);

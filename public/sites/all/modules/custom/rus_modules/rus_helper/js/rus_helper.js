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

/**event node add js **/

jQuery(function () {
	
	jQuery("#edit-field-datetime-und-0-value-month").change(function() {
			$mon = jQuery("#edit-field-datetime-und-0-value-month").val();
			jQuery("#edit-field-live-game-popup-date-und-0-value-month").val($mon);
	});
	
	jQuery("#edit-field-datetime-und-0-value-year").change(function() {
		$year = jQuery("#edit-field-datetime-und-0-value-year").val();
		jQuery("#edit-field-live-game-popup-date-und-0-value-year").val($year);
    });
	
	jQuery("#edit-field-datetime-und-0-value-day").change(function() {
		$day = jQuery("#edit-field-datetime-und-0-value-day").val();
		jQuery("#edit-field-live-game-popup-date-und-0-value-day").val($day);
    });
	
	jQuery("#edit-field-datetime-und-0-value-hour").change(function() {
		$hour = jQuery("#edit-field-datetime-und-0-value-hour").val();
		jQuery("#edit-field-live-game-popup-date-und-0-value-hour").val($hour);
    });
	
	jQuery("#edit-field-datetime-und-0-value-minute").change(function() {
		$min = jQuery("#edit-field-datetime-und-0-value-minute").val();
		jQuery("#edit-field-live-game-popup-date-und-0-value-minute").val($min);
    });

	
	
				
	jQuery("#edit-field-datetime-und-0-value2-month").change(function() {
			$emon = jQuery("#edit-field-datetime-und-0-value2-month").val();
			jQuery("#edit-field-live-game-popup-date-und-0-value2-month").val($emon);
	});
	
	jQuery("#edit-field-datetime-und-0-value2-year").change(function() {
		$eyear = jQuery("#edit-field-datetime-und-0-value2-year").val();
		jQuery("#edit-field-live-game-popup-date-und-0-value2-year").val($eyear);
	});
	
	jQuery("#edit-field-datetime-und-0-value2-day").change(function() {
		$eday = jQuery("#edit-field-datetime-und-0-value2-day").val();
		jQuery("#edit-field-live-game-popup-date-und-0-value2-day").val($eday);
	});
	
	jQuery("#edit-field-datetime-und-0-value2-hour").change(function() {
		$ehour = jQuery("#edit-field-datetime-und-0-value2-hour").val();
		jQuery("#edit-field-live-game-popup-date-und-0-value2-hour").val($ehour);
	});
	
	jQuery("#edit-field-datetime-und-0-value2-minute").change(function() {
		$emin = jQuery("#edit-field-datetime-und-0-value2-minute").val();
		jQuery("#edit-field-live-game-popup-date-und-0-value2-minute").val($emin);
	});
	
	
	
		
});


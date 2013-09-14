jQuery( document ).ready(function() {

jQuery('.bxslider').bxSlider({
 slideWidth: 230,
 slideMargin: 10,
 minSlides: 3,
 maxSlides:8,
 infiniteLoop: false,
 hideControlOnEnd: true
});



jQuery('.bxslidermain').bxSlider({
  minSlides: 1,
  maxSlides:8,
  slideWidth: 1350,
  slideMargin: 0,
  auto:true,
  pause:6000,

});

//show hide feature video big video title/body
jQuery('#featured-video').hover(
   function(){
        jQuery('#featurebody').show();
   },
   function(){
   jQuery('#featurebody').hide();

});

//show hide small video title/body
jQuery('#video-gallery-1').hover(
		   function(){
		        jQuery('#video-gallery-1-body').show();
		   },
		   function(){
		   jQuery('#video-gallery-1-body').hide();

});


jQuery('#video-gallery-2').hover(
		   function(){
		        jQuery('#video-gallery-2-body').show();
		   },
		   function(){
		   jQuery('#video-gallery-2-body').hide();

});

jQuery('#video-gallery-3').hover(
		   function(){
		        jQuery('#video-gallery-3-body').show();
		   },
		   function(){
		   jQuery('#video-gallery-3-body').hide();

});


jQuery('#video-gallery-4').hover(
		   function(){
		        jQuery('#video-gallery-4-body').show();
		   },
		   function(){
		   jQuery('#video-gallery-4-body').hide();

});



jQuery('#login-cross').click(function() {


// Add markup ids of all custom popup box here 						  
jQuery('#fade , #popuprel , #popuprel2 , #block-user-login').fadeOut();
return false;
});
		
// Here we will write a function when link click under class popup				   
jQuery('a.popup').click(function() {
									
									
	// Here we will describe a variable popupid which gets the
	// rel attribute from the clicked link							
	var popupid = jQuery(this).attr('rel');


	// Now we need to popup the marked which belongs to the rel attribute
	// Suppose the rel attribute of click link is popuprel then here in below code
	// #popuprel will fadein
	jQuery('#' + popupid).fadeIn();


	// append div with id fade into the bottom of body tag
	// and we allready styled it in our step 2 : CSS
	jQuery('body').append('<div id="fade"></div>');
	jQuery('#fade').css({'filter' : 'alpha(opacity=80)'}).fadeIn();


	// Now here we need to have our popup box in center of 
	// webpage when its fadein. so we add 10px to height and width 
	var popuptopmargin = (jQuery('#' + popupid).height() + 10) / 2;
	var popupleftmargin = (jQuery('#' + popupid).width() + 10) / 2;


	// Then using .css function style our popup box for center allignment
	jQuery('#' + popupid).css({
	'margin-top' : -popuptopmargin,
	'margin-left' : -popupleftmargin
	});
});


// Now define one more function which is used to fadeout the 
// fade layer and popup window as soon as we click on fade layer
jQuery('#fade').click(function() {


// Add markup ids of all custom popup box here 						  
jQuery('#fade , #popuprel , #popuprel2 , #block-user-login').fadeOut()
return false;
});
});

jQuery('#login-cross').click(function() {


	// Add markup ids of all custom popup box here 						  
	jQuery('#login-cross , #popuprel , #popuprel2 , #block-user-login').fadeOut()
	return false;
});


//JavaScript Document

jQuery(function () {
	jQuery( ".pricingTableWrapper .span4" ).click(function() {
		jQuery(this).parent().find('.selected').removeClass('selected');
		jQuery(this).addClass('selected');
		
	});
});

jQuery(function () {
	jQuery("#daily" ).click(function() {
		jQuery('input:radio[name="membership_type_duration"]').filter('[value="1"]').attr('checked', true);
		jQuery('input:radio[name="membership_type_duration"]').filter('[value="30"]').attr('checked', false);
		jQuery('input:radio[name="membership_type_duration"]').filter('[value="365"]').attr('checked', false);
		
		jQuery("#chargedamount").html("$4.95");
		
		
	});
	jQuery("#monthly" ).click(function() {
		jQuery('input:radio[name="membership_type_duration"]').filter('[value="1"]').attr('checked', false);
		jQuery('input:radio[name="membership_type_duration"]').filter('[value="30"]').attr('checked', true);
		jQuery('input:radio[name="membership_type_duration"]').filter('[value="365"]').attr('checked', false);
		
		jQuery("#chargedamount").html("$7.95");

	});
	

	jQuery("#yearly" ).click(function() {
		
		jQuery('input:radio[name="membership_type_duration"]').filter('[value="1"]').attr('checked', false);
		jQuery('input:radio[name="membership_type_duration"]').filter('[value="30"]').attr('checked', false);
		jQuery('input:radio[name="membership_type_duration"]').filter('[value="365"]').attr('checked', true);

		jQuery("#chargedamount").html("$75");

		
	});
	
	
});


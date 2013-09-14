/*
This file is part of the Kaltura Collaborative Media Suite which allows users
to do with audio, video, and animation what Wiki platfroms allow them to do with
text.

Copyright (C) 2006-2008  Kaltura Inc.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/


// initModalBox called from gotoCW - to open the contribution wizard as an iFrame in the

// widget page

function kalturaInitModalBox ( url, options ) {
	var objBody = document.getElementsByTagName("body").item(0);

	// create overlay div and hardcode some functional styles (aesthetic styles are in CSS file)

	var objOverlay = document.createElement("div");

	objOverlay.setAttribute('id','kaltura_overlay');

	objBody.appendChild(objOverlay, objBody.firstChild);

	
	if (options)
	{
		if (options.width)
			width = options.width;
		if (options.height)
			height = options.height;
	} else {
		width = 680;
		height = 360;
	}


	// create modalbox div, same note about styles as above

	var objModalbox = document.createElement("div");

	objModalbox.setAttribute('id','modalbox');
	//objModalbox.setAttribute('style', 'width:'+width+'px;height:'+height+'px;margin-top:'+(0-height/2)+'px;margin-left:'+(0-width/2)+'px;');
	objModalbox.style.width = width+'px';
	objModalbox.style.height = height+'px';
	objModalbox.style.marginTop = (0-height/2)+'px';
	objModalbox.style.marginLeft = (0-width/2)+'px';
	

	// create content div inside objModalbox

	var objModalboxContent = document.createElement("div");

	objModalboxContent.setAttribute('id','mbContent');

	if ( url != null )

	{

		objModalboxContent.innerHTML = '<iframe id="kaltura_modal_iframe" scrolling="no" width="' + width + '" height="' + height + '" frameborder="0" src="' + url + '"/>';

	}

	objModalbox.appendChild(objModalboxContent, objModalbox.firstChild);

	

	objBody.appendChild(objModalbox, objOverlay.nextSibling);	

	

	return objModalboxContent;

}

function SendTopToNodePage(){

	window.top.location.href = node_url;

}

function SendTopToEntriesPage(){
  window.top.location.href = goto_url;
}



function closeEditorHandler() {
	kalturaCloseModalBox();
}

function kalturaCloseModalBox () {
	if ( this != window.top )

	{

		window.top.kalturaCloseModalBox();

		return false;

	}


	// TODO - have some JS to close the modalBox without refreshing the page if there is no need

	overlay_obj = document.getElementById("kaltura_overlay");

	modalbox_obj = document.getElementById("modalbox");

	overlay_obj.parentNode.removeChild( overlay_obj );

	modalbox_obj.parentNode.removeChild( modalbox_obj );

	

	return false;

}

function $id(x){ return document.getElementById(x); }

function kalturaRefreshTop () {
	if ( this != window.top )

	{

		window.top.kalturaRefreshTop();

		return false;

	}	

	window.location.reload(true);

}

function switch_to_exist_partner() {

	var href = location.href;

	tmp = href.replace('&register=no', '');

	href = tmp.replace('?register=no', '');

	if(href.indexOf('?') > 0)

		location.href = href + '&register=no'

	else

		location.href = href + '?register=no'

}

function switch_to_saas()
{

    var href = location.href;

	if(href.indexOf('?') > 0)
    {
        href = href + '&op=Continue%20>>';
    }
    else
    {
        href = href + '?op=Continue%20>>';
    }
    href = href + '&kaltura_registration_mode=1';

    location.href = href;
}

function switch_to_register() {

	var href = location.href;

	tmp = href.replace('&register=no', '');

	href = tmp.replace('?register=no', '');

	location.href = href;

}

KalturaThumbRotator = {



	slices : 16, // number of thumbs per video

	frameRate : 1000, // frameRate in milliseconds for changing the thumbs

	

	timer : null,

	slice : 0,

	img  : new Image(),

	

	thumbBase : function (o) // extract the base thumb path by removing the slicing parameters

	{

		var path = o.src;

		var pos = path.indexOf("/vid_slice");

		if (pos != -1)

			path = path.substring(0, pos);


		return path;

	},

	



	change : function (o, i) // set the Nth thumb, request the next one and set a timer for showing it

	{

		slice = (i + 1) % this.slices;



		var path = this.thumbBase(o);

		

		o.src = path + "/vid_slice/" + i + "/vid_slices/" + this.slices;

		this.img.src = path + "/vid_slice/" + slice + "/vid_slices/" + this.slices;



		i = i % this.slices;

		i++;

		

		this.timer = setTimeout(function () { KalturaThumbRotator.change(o, i) }, this.frameRate);

	},

	

	start : function (o) // reset the timer and show the first thumb

	{

		clearTimeout(this.timer);

		var path = this.thumbBase(o);

		this.change(o, 1);

	},



	end : function (o) // reset the timer and restore the base thumb

	{

		clearTimeout(this.timer);

		o.src = this.thumbBase(o);

	}

};

function remove_items_from_field(field_id) { document.getElementById(field_id).value = ''; }

function remove_item_from_field(field_id, entry_id, kaltura_server) {

	field_obj = document.getElementById(field_id);

	field_obj.value = field_obj.value.replace(entry_id, '');

	update_field_thumbs(field_obj, kaltura_server);

}

function get_title() {

	title = document.getElementById("edit-title").value;
	
	if (title != '') {return title;}
	else {return "My Remix"; }
	
}

function kaltura_activate_player(thumb_div, player_div) {

	document.getElementById(thumb_div).style.display = 'none';

	document.getElementById(player_div).style.display = 'block';

}

function update_field_thumbs(hidden_field_obj, kaltura_server) {

	entries = Array();

	entries = hidden_field_obj.value.split(',');

	target_div = window.top.document.getElementById(hidden_field_obj.id + '_thumbs_div');

	target_div.innerHTML = '<div class="title">Added Media:</div>';

	for(i=0;i<entries.length;i++) {

		if(entries[i].length > 1) {

			target_div.innerHTML += '<div class="kaltura_field_thumb"><img src="'+ kaltura_server +'/entry_id/'+ entries[i] +'" /><br />'+

				'<input type="button" onclick="remove_item_from_field(\''+hidden_field_obj.id+'\', \''+ entries[i] +'\', \''+ kaltura_server +'\');" class="remove_media" /></div>';

		}

	}

	target_div.innerHTML += '<div class="clear-block"></div>';

}

/*
 *jQuery(document).ready( function () {
 *      var pager = jQuery('.view-kaltura-list-entries .item-list').html();
 *      jQuery('.view-kaltura-list-entries .view-content').before('<div class="item-list">' + pager + '</div>');
 *  });
 */
;
(function ($) {
  Drupal.behaviors.kaltura = {
    attach: function(context, settings) {
      $('.remove_media', context).click( function () {
        $(this).parents('.kaltura-thumb-wrap').nextAll().children('input:hidden').val('');
        $(this).parents('.kaltura-thumb-wrap').html('');
        });
      }

    }
    Drupal.behaviors.kaltura_add = {
      attach: function (context, settings) {
        var mediaTypes = [];
        mediaTypes[1] = 'Video';
        mediaTypes[2] = 'Image';
        mediaTypes[5] = 'Audio';
        $('.kentry_add', context).click( function () {
          var field_name = $(this).attr('name');
          var entry_id = $(this).attr('id');
          var media_type = $(this).attr('rel');
          var src = $(this).parent().prevAll('.views-field-kaltura-thumbnail-url').find('img').attr('src');
          var t = '<div class="title">Added ' +  mediaTypes[media_type] + ' </div><div class="kaltura_field_thumb"><img src="' + src + '"/><br/> <input type="button" title="remove item" class="remove_media" /></div>';
          var mtselect = "#" + field_name + "-media-type input";
          var etselect = "#" + field_name + "-entryid input";
          var thumb_select = "#" + field_name + "-thumb-wrap";
          $(etselect).val(entry_id);
          $(mtselect).val(media_type);
          $(thumb_select).html(t);
          Drupal.attachBehaviors();
          $('.close').triggerHandler('click');
          }
          );
          /*
           *$('#tab-kaltura_browse a').click(function () {
           *  $(".close").trigger("click");}
           *);
           */
        }
      };
      Drupal.behaviors.kaltura_roate = {
      attach: function (context, settings) {
      $('img.k-rotate').hover(function () {
        KalturaThumbRotator.start(this);},
        function () {
          KalturaThumbRotator.end(this);}
        );}
        }

      Drupal.behaviors.kaltura_prev_roate = {
      attach: function (context, settings) {
      $('img.k-prev-rotate').hover(function () {
        var prev = $(this).next('img.k-preview');
        prev.show();
        KalturaThumbRotator.start(prev[0]);
        },
        function () {
          var prev = $(this).next('img.k-preview');
          prev.hide();
          KalturaThumbRotator.end(prev[0]);}
        );}
        }
          function tog (val) {
            switch (val)
            {
              case 'both':
                $('.details').show();
                $('.views-field-kaltura-thumbnail-url').show();
                break;
              case 'thumbs':
                $('.details').hide();
                $('.views-field-kaltura-thumbnail-url').show();
                break;
              case 'details':
                $('.details').show();
                $('.views-field-kaltura-thumbnail-url').hide();
                break;
              }
          }

      Drupal.behaviors.kaltura_entries = {
        attach: function (context, settings) {
          var current = $('#edit-view-opts').val();
          tog(current);
          $('#edit-view-opts').change( function () {
            var val = this.value;
            tog(val);
          }
            );
       }
      }
      Drupal.behaviors.kaltura_checkall = {
        attach: function (context, settings) {
          $('.checkall').click(function () {
            $('.form-checkbox').attr('checked', this.checked);
            var text = this.checked === true ? 'uncheck all' : 'check all';
            $(this).next().text(text);
            });
          }
        };
        /*
         *Drupal.behaviors.kaltura_search = {
         *  attach: function (context, settings) {
         *      var edit = $('.view-kaltura-existing #edit-kaltura-text, .view-kaltura-list-entries #edit-kaltura-text');
         *      edit.val('Search');
         *      edit.focus( function () {
         *        if ($(this).val() === 'Search') {
         *          $(this).val('');
         *        }
         *        });
         *      edit.blur( function () {
         *        if ($(this).val() === '') {
         *            $(this).val('Search');
         *          }
         *        });
         *    }
         *  };
         */

  })(jQuery);
;

(function ($) {
  Drupal.Panels = {};

  Drupal.Panels.autoAttach = function() {
    if ($.browser.msie) {
      // If IE, attach a hover event so we can see our admin links.
      $("div.panel-pane").hover(
        function() {
          $('div.panel-hide', this).addClass("panel-hide-hover"); return true;
        },
        function() {
          $('div.panel-hide', this).removeClass("panel-hide-hover"); return true;
        }
      );
      $("div.admin-links").hover(
        function() {
          $(this).addClass("admin-links-hover"); return true;
        },
        function(){
          $(this).removeClass("admin-links-hover"); return true;
        }
      );
    }
  };

  $(Drupal.Panels.autoAttach);
})(jQuery);
;
(function($) {

Drupal.admin = Drupal.admin || {};
Drupal.admin.behaviors = Drupal.admin.behaviors || {};
Drupal.admin.hashes = Drupal.admin.hashes || {};

/**
 * Core behavior for Administration menu.
 *
 * Test whether there is an administration menu is in the output and execute all
 * registered behaviors.
 */
Drupal.behaviors.adminMenu = {
  attach: function (context, settings) {
    // Initialize settings.
    settings.admin_menu = $.extend({
      suppress: false,
      margin_top: false,
      position_fixed: false,
      tweak_modules: false,
      tweak_permissions: false,
      tweak_tabs: false,
      destination: '',
      basePath: settings.basePath,
      hash: 0,
      replacements: {}
    }, settings.admin_menu || {});
    // Check whether administration menu should be suppressed.
    if (settings.admin_menu.suppress) {
      return;
    }
    var $adminMenu = $('#admin-menu:not(.admin-menu-processed)', context);
    // Client-side caching; if administration menu is not in the output, it is
    // fetched from the server and cached in the browser.
    if (!$adminMenu.length && settings.admin_menu.hash) {
      Drupal.admin.getCache(settings.admin_menu.hash, function (response) {
          if (typeof response == 'string' && response.length > 0) {
            $('body', context).prepend(response);
          }
          var $adminMenu = $('#admin-menu:not(.admin-menu-processed)', context);
          // Apply our behaviors.
          Drupal.admin.attachBehaviors(context, settings, $adminMenu);
      });
    }
    // If the menu is in the output already, this means there is a new version.
    else {
      // Apply our behaviors.
      Drupal.admin.attachBehaviors(context, settings, $adminMenu);
    }
  }
};

/**
 * Collapse fieldsets on Modules page.
 */
Drupal.behaviors.adminMenuCollapseModules = {
  attach: function (context, settings) {
    if (settings.admin_menu.tweak_modules) {
      $('#system-modules fieldset:not(.collapsed)', context).addClass('collapsed');
    }
  }
};

/**
 * Collapse modules on Permissions page.
 */
Drupal.behaviors.adminMenuCollapsePermissions = {
  attach: function (context, settings) {
    if (settings.admin_menu.tweak_permissions) {
      // Freeze width of first column to prevent jumping.
      $('#permissions th:first', context).css({ width: $('#permissions th:first', context).width() });
      // Attach click handler.
      $('#permissions tr:has(td.module)', context).once('admin-menu-tweak-permissions', function () {
        var $module = $(this);
        $module.bind('click.admin-menu', function () {
          // @todo Replace with .nextUntil() in jQuery 1.4.
          $module.nextAll().each(function () {
            var $row = $(this);
            if ($row.is(':has(td.module)')) {
              return false;
            }
            $row.toggleClass('element-hidden');
          });
        });
      }).trigger('click.admin-menu');
    }
  }
};

/**
 * Apply margin to page.
 *
 * Note that directly applying marginTop does not work in IE. To prevent
 * flickering/jumping page content with client-side caching, this is a regular
 * Drupal behavior.
 */
Drupal.behaviors.adminMenuMarginTop = {
  attach: function (context, settings) {
    if (!settings.admin_menu.suppress && settings.admin_menu.margin_top) {
      $('body:not(.admin-menu)', context).addClass('admin-menu');
    }
  }
};

/**
 * Retrieve content from client-side cache.
 *
 * @param hash
 *   The md5 hash of the content to retrieve.
 * @param onSuccess
 *   A callback function invoked when the cache request was successful.
 */
Drupal.admin.getCache = function (hash, onSuccess) {
  if (Drupal.admin.hashes.hash !== undefined) {
    return Drupal.admin.hashes.hash;
  }
  $.ajax({
    cache: true,
    type: 'GET',
    dataType: 'text', // Prevent auto-evaluation of response.
    global: false, // Do not trigger global AJAX events.
    url: Drupal.settings.admin_menu.basePath.replace(/admin_menu/, 'js/admin_menu/cache/' + hash),
    success: onSuccess,
    complete: function (XMLHttpRequest, status) {
      Drupal.admin.hashes.hash = status;
    }
  });
};

/**
 * @defgroup admin_behaviors Administration behaviors.
 * @{
 */

/**
 * Attach administrative behaviors.
 */
Drupal.admin.attachBehaviors = function (context, settings, $adminMenu) {
  if ($adminMenu.length) {
    $adminMenu.addClass('admin-menu-processed');
    $.each(Drupal.admin.behaviors, function() {
      this(context, settings, $adminMenu);
    });
  }
};

/**
 * Apply 'position: fixed'.
 */
Drupal.admin.behaviors.positionFixed = function (context, settings, $adminMenu) {
  if (settings.admin_menu.position_fixed) {
    $adminMenu.addClass('admin-menu-position-fixed');
    $adminMenu.css('position', 'fixed');
  }
};

/**
 * Move page tabs into administration menu.
 */
Drupal.admin.behaviors.pageTabs = function (context, settings, $adminMenu) {
  if (settings.admin_menu.tweak_tabs) {
    $('ul.tabs.primary li', context).addClass('admin-menu-tab').appendTo('#admin-menu-wrapper > ul');
    $('ul.tabs.secondary', context).appendTo('#admin-menu-wrapper > ul > li.admin-menu-tab.active').removeClass('secondary');
    $('ul.tabs.primary', context).remove();
  }
};

/**
 * Perform dynamic replacements in cached menu.
 */
Drupal.admin.behaviors.replacements = function (context, settings, $adminMenu) {
  for (var item in settings.admin_menu.replacements) {
    $(item, $adminMenu).html(settings.admin_menu.replacements[item]);
  }
};

/**
 * Inject destination query strings for current page.
 */
Drupal.admin.behaviors.destination = function (context, settings, $adminMenu) {
  if (settings.admin_menu.destination) {
    $('a.admin-menu-destination', $adminMenu).each(function() {
      this.search += (!this.search.length ? '?' : '&') + Drupal.settings.admin_menu.destination;
    });
  }
};

/**
 * Apply JavaScript-based hovering behaviors.
 *
 * @todo This has to run last.  If another script registers additional behaviors
 *   it will not run last.
 */
Drupal.admin.behaviors.hover = function (context, settings, $adminMenu) {
  // Hover emulation for IE 6.
  if ($.browser.msie && parseInt(jQuery.browser.version) == 6) {
    $('li', $adminMenu).hover(
      function () {
        $(this).addClass('iehover');
      },
      function () {
        $(this).removeClass('iehover');
      }
    );
  }

  // Delayed mouseout.
  $('li.expandable', $adminMenu).hover(
    function () {
      // Stop the timer.
      clearTimeout(this.sfTimer);
      // Display child lists.
      $('> ul', this)
        .css({left: 'auto', display: 'block'})
        // Immediately hide nephew lists.
        .parent().siblings('li').children('ul').css({left: '-999em', display: 'none'});
    },
    function () {
      // Start the timer.
      var uls = $('> ul', this);
      this.sfTimer = setTimeout(function () {
        uls.css({left: '-999em', display: 'none'});
      }, 400);
    }
  );
};

/**
 * @} End of "defgroup admin_behaviors".
 */

})(jQuery);
;
(function($) {

Drupal.admin = Drupal.admin || {};
Drupal.admin.behaviors = Drupal.admin.behaviors || {};

/**
 * @ingroup admin_behaviors
 * @{
 */

/**
 * Apply active trail highlighting based on current path.
 *
 * @todo Not limited to toolbar; move into core?
 */
Drupal.admin.behaviors.toolbarActiveTrail = function (context, settings, $adminMenu) {
  if (settings.admin_menu.toolbar && settings.admin_menu.toolbar.activeTrail) {
    $adminMenu.find('> div > ul > li > a[href="' + settings.admin_menu.toolbar.activeTrail + '"]').addClass('active-trail');
  }
};

/**
 * @} End of "defgroup admin_behaviors".
 */

})(jQuery);
;
/**
 * @file base.js
 *
 * Some basic behaviors and utility functions for Views.
 */
(function ($) {

Drupal.Views = {};

/**
 * jQuery UI tabs, Views integration component
 */
Drupal.behaviors.viewsTabs = {
  attach: function (context) {
    if ($.viewsUi && $.viewsUi.tabs) {
      $('#views-tabset').once('views-processed').viewsTabs({
        selectedClass: 'active'
      });
    }

    $('a.views-remove-link').once('views-processed').click(function(event) {
      var id = $(this).attr('id').replace('views-remove-link-', '');
      $('#views-row-' + id).hide();
      $('#views-removed-' + id).attr('checked', true);
      event.preventDefault();
   });
  /**
    * Here is to handle display deletion
    * (checking in the hidden checkbox and hiding out the row)
    */
  $('a.display-remove-link')
    .addClass('display-processed')
    .click(function() {
      var id = $(this).attr('id').replace('display-remove-link-', '');
      $('#display-row-' + id).hide();
      $('#display-removed-' + id).attr('checked', true);
      return false;
  });
  }
};

/**
 * Helper function to parse a querystring.
 */
Drupal.Views.parseQueryString = function (query) {
  var args = {};
  var pos = query.indexOf('?');
  if (pos != -1) {
    query = query.substring(pos + 1);
  }
  var pairs = query.split('&');
  for(var i in pairs) {
    if (typeof(pairs[i]) == 'string') {
      var pair = pairs[i].split('=');
      // Ignore the 'q' path argument, if present.
      if (pair[0] != 'q' && pair[1]) {
        args[decodeURIComponent(pair[0].replace(/\+/g, ' '))] = decodeURIComponent(pair[1].replace(/\+/g, ' '));
      }
    }
  }
  return args;
};

/**
 * Helper function to return a view's arguments based on a path.
 */
Drupal.Views.parseViewArgs = function (href, viewPath) {
  var returnObj = {};
  var path = Drupal.Views.getPath(href);
  // Ensure we have a correct path.
  if (viewPath && path.substring(0, viewPath.length + 1) == viewPath + '/') {
    var args = decodeURIComponent(path.substring(viewPath.length + 1, path.length));
    returnObj.view_args = args;
    returnObj.view_path = path;
  }
  return returnObj;
};

/**
 * Strip off the protocol plus domain from an href.
 */
Drupal.Views.pathPortion = function (href) {
  // Remove e.g. http://example.com if present.
  var protocol = window.location.protocol;
  if (href.substring(0, protocol.length) == protocol) {
    // 2 is the length of the '//' that normally follows the protocol
    href = href.substring(href.indexOf('/', protocol.length + 2));
  }
  return href;
};

/**
 * Return the Drupal path portion of an href.
 */
Drupal.Views.getPath = function (href) {
  href = Drupal.Views.pathPortion(href);
  href = href.substring(Drupal.settings.basePath.length, href.length);
  // 3 is the length of the '?q=' added to the url without clean urls.
  if (href.substring(0, 3) == '?q=') {
    href = href.substring(3, href.length);
  }
  var chars = ['#', '?', '&'];
  for (i in chars) {
    if (href.indexOf(chars[i]) > -1) {
      href = href.substr(0, href.indexOf(chars[i]));
    }
  }
  return href;
};

})(jQuery);
;

(function ($) {
	Drupal.behaviors.backtotop = {
		attach: function(context) {
			var exist= jQuery('#backtotop').length;
      if(exist == 0) {
        $("body", context).once(function () {
          $(this).append("<div id='backtotop'>"+Drupal.t(Drupal.settings.back_to_top.back_to_top_button_text)+"</div>");
        });
      }
			$(window).scroll(function() {
				if($(this).scrollTop() > Drupal.settings.back_to_top.back_to_top_button_trigger) {
					$('#backtotop').fadeIn();	
				} else {
					$('#backtotop').fadeOut();
				}
			});

      $('#backtotop', context).once(function () {
			  $(this).click(function() {
				  $('body,html').animate({scrollTop:0},1200,'easeOutQuart');
			  });
			});
		}
	};
})(jQuery);
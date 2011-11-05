Drupal.behaviors.backtotop = {
  attach: function(context) {
      (function($) {
      $("body").append("<div id='backtotop'>"+Drupal.t("Back to Top")+"</div>");
      $(window).scroll(function() {
        if($(this).scrollTop() != 0) {
          $('#backtotop').fadeIn();	
        } else {
          $('#backtotop').fadeOut();
        }
      });
  
      $('#backtotop').click(function() {
        $('body,html').animate({scrollTop:0},1200,'easeOutQuart');
      });	
    })(jQuery);
  }
};

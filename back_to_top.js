Drupal.behaviors.backtotop = {
  attach: function(context) {
      (function($) {
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

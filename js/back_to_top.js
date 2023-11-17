/**
 * @file
 * Javascript for the Back To Top module.
 */

(function($) {

Backdrop.behaviors.backToTop = {
  attach: function(context, settings) {

    var $settings = Backdrop.settings.back_to_top;
    var $title = ($settings.title) ? Backdrop.t($settings.text) : '';
    var $page = $('html, body');

    // Add button.
    if (!$('#backtotop').length) {
      $('body').append('<div id="backtotop" class="' + $settings.type + '" title="' + $title + '">' + Backdrop.t($settings.text) + '</div>');
    }

    // Fade button in & out on scroll.
    $(window).scroll(function() {
      if ($(this).scrollTop() > $settings.distance) {
        $('#backtotop').fadeIn();
      }
      else {
        $('#backtotop').fadeOut();
      }
    });

    // Scroll to top on button click.
    $('#backtotop').click(function() {
      $page.bind('scroll mousedown DOMMouseScroll mousewheel keyup', function() {
        $page.stop();
      });

      $page.animate({ scrollTop: 0 }, 500, function() {
        $page.unbind('scroll mousedown DOMMouseScroll mousewheel keyup');
      });

      return false;
    });

  }
};

})(jQuery);


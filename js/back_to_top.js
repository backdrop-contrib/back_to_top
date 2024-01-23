/**
 * @file
 * Javascript for the Back To Top module.
 */

(function ($) {

  var scrollTo = function (to, duration) {
    var element = document.scrollingElement || document.documentElement,
      start = element.scrollTop,
      change = to - start,
      startTs = performance.now(),
      easeOutQuart = function (t, b, c, d) {
        t /= d;
        t--;
        return -c * (t * t * t * t - 1) + b;
      },
      animateScroll = function (ts) {
        var currentTime = ts - startTs;
        element.scrollTop = parseInt(easeOutQuart(currentTime, start, change, duration));
        if (currentTime < duration) {
          frame = requestAnimationFrame(animateScroll);
        } else {
          element.scrollTop = to;
        }
      };
    requestAnimationFrame(animateScroll);
  };

  var $settings = Backdrop.settings.back_to_top;
  var $title = ($settings.title) ? Backdrop.t($settings.text) : '';

  Backdrop.behaviors.backToTop = {
    attach: function (context, settings) {
      var exist = $('#backtotop').length;
      if (exist == 0) {
        $('body').once('backtotop', context).each(function () {
          $(this).append("<button id='backtotop' aria-label='" + Backdrop.t("Back to top") + "' title='" + $title + "' class='" + $settings.type + "'>" + Backdrop.t($settings.text) + "</button>");
        });
      }

      backToTop();
      $(window).scroll(function () {
        backToTop();
      });

      var duration = 600;
      var motionQuery = window.matchMedia('(prefers-reduced-motion)');
      if (motionQuery.matches) {
        duration = 0;
      }
      $('#backtotop').once('backtotop', context).each(function () {
        $(this).click(function () {
          $("html, body").bind("scroll mousedown DOMMouseScroll mousewheel keyup", function () {
            window.cancelAnimationFrame(frame);
          });
          scrollTo(0, duration);
        });
        $(this).keyup(function (event) {
          if (event.keyCode === 13) {
            event.preventDefault();

            $("#backtotop").click();
          }
        });

      });

      /**
       * Hide show back to top links.
       */
      function backToTop() {
        if ($(window).scrollTop() > $settings.distance) {
          $('#backtotop').fadeIn();
        } else {
          $('#backtotop').fadeOut();
        }
      }
    }
  };

})(jQuery);

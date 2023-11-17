/**
 * @file
 * Javascript for the Back To Top admin form.
 */

(function($) {

Backdrop.behaviors.backToTopAdmin = {
  attach: function(context, settings) {

    $("#color_bg").farbtastic("#edit-color-bg");
    $("#color_border").farbtastic("#edit-color-border");
    $("#color_text").farbtastic("#edit-color-text");
    $("#color_hover").farbtastic("#edit-color-hover");

  }
};

})(jQuery);


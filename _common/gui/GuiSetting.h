#ifndef SOURCE_GUISETTING_H_
#define SOURCE_GUISETTING_H_

#include <string>

struct Setting
{
    /// Name that appears in the application titlebar
    static const char* game_name;

    /// Path to the icon that appears in the application titlebar
    static const char* icon_path;

    /// Path to images relative to the source files, must end with a trailing
    /// slash
    static const std::string image_path;

    /// Set first element to -1 to disable colour keying, otherwise set to a
    /// colour such as { 0, 0xFF, 0xFF }
    static const int color_key[];

    /// Set a background colour for the renderer
    static const int background_color[];

    /// Changing the scale factor adjusts the size of the images and the
    /// playing window
    static const int scale_factor = 6;

    /// Width of the clipped sprite sheet image used for the grid
    static const int grid_sprite_width = 16;

    /// Height of the clipped sprite sheet image used for the grid
    static const int grid_sprite_height = 16;

    /// Amount of columns to draw for the grid, changing this will affect
    /// window_width and actual_window_width
    static const int grid_columns = 7;

    /// Amount of rows to draw for the grid, changing this will affect
    /// window_height and actual_window_height
    static const int grid_rows = 6;

    /// Width of the application window
    static const int window_width = grid_columns * grid_sprite_width;

    /// Height of the application window
    static const int window_height = grid_rows * grid_sprite_height;

    /// Width of the playing area without the scaling factor applied
    static const int actual_window_width = window_width * scale_factor;

    /// Height of the playing area without the scaling factor applied
    static const int actual_window_height = window_height * scale_factor;
};

#endif /* SOURCE_GUISETTING_H_ */

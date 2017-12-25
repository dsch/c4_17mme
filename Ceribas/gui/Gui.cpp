#include <iostream>

#include "Gui.h"
#include "GuiSetting.h"
#include "ResourceManager.h"

SDL_Renderer* Gui::renderer = NULL;

Gui::Gui() : window() {
    init(Setting::game_name, Setting::window_width, Setting::window_height);

    ResourceManager::load_image("cell_sprite");
    ResourceManager::load_image("grid_overlay");

    ResourceManager::load_image("red_piece")->set_position_hidden();
    ResourceManager::load_image("yellow_piece")->set_position_hidden();

    ResourceManager::load_image("red_wins")->set_position_centered();
    ResourceManager::load_image("yellow_wins")->set_position_centered();
    ResourceManager::load_image("draw")->set_position_centered();
}

Gui::~Gui() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    ResourceManager::unload_image("cell_sprite");
    ResourceManager::unload_image("grid_overlay");

    ResourceManager::unload_image("red_piece");
    ResourceManager::unload_image("yellow_piece");

    ResourceManager::unload_image("red_wins");
    ResourceManager::unload_image("yellow_wins");
    ResourceManager::unload_image("draw");
}

void Gui::init(const char* title, int window_width, int window_height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
    }

    // Create window
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, window_width * Setting::scale_factor,
                              window_height * Setting::scale_factor, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
    }

    // Set title bar icon
    if (Setting::icon_path) {
        SDL_Surface* icon = SDL_LoadBMP(Setting::icon_path);
        if (icon == NULL) {
            throw std::runtime_error(std::string("SDL_LoadBMP Error: ") + SDL_GetError());
        }

        SDL_SetWindowIcon(window, icon);
        SDL_FreeSurface(icon);
    }

    // Create renderer for window
    renderer = SDL_CreateRenderer(window, -1,
                                  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        throw std::runtime_error(std::string("SDL_CreateRenderer Error: ") + SDL_GetError());
    }

    // Set background color
    SDL_SetRenderDrawColor(renderer,
                           Setting::background_color[0],
                           Setting::background_color[1],
                           Setting::background_color[2],
                           Setting::background_color[3]);
}

Gui::ColumnType Gui::askPlayer(Gui::Color) {
    Gui::ColumnType column;
    while (true) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {

            // Let the state handle events
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                int mouse_x, mouse_y;
                Gui::get_mouse_position(&mouse_x, &mouse_y);
                column = mouse_x / (Setting::window_width / Setting::grid_columns);
                return column;
            }

            // Handle window quit event
            if (event.type == SDL_QUIT) {
                throw Gui::Abort();
            }
        }

        SDL_RenderPresent(renderer);
    }
}

void Gui::updateBoard(const Gui::GridType &board) {
    // Clear screen
    SDL_RenderClear(renderer);

    // Render the state
    render(board);

    // Update screen taking into account SDL v-sync. This is what stops the
    // game loop from running too fast
    SDL_RenderPresent(renderer);
}

void Gui::render(const Gui::GridType &board) {
    // Render yellow and red pieces now so that they will appear under the
    // grid overlay that is rendered next
    ResourceManager::get_image("red_piece")->render();
    ResourceManager::get_image("yellow_piece")->render();

    grid_render(board);
}

void Gui::grid_render(const Gui::GridType &board) {
    SDL_Rect sprite_clips[3];
    for (int i = 0; i < 3; i++) {
        sprite_clips[i].x = 0;
        sprite_clips[i].y = i * Setting::grid_sprite_height;
        sprite_clips[i].w = Setting::grid_sprite_width;
        sprite_clips[i].h = Setting::grid_sprite_height;
    }

    // Iterate over columns and rows and render play sprites and grid overlay
    for (int col = 0; col < Setting::grid_columns; col++) {
        for (int row = 0; row < Setting::grid_rows; row++) {
            // Calculate coords for the grid layout
            int x = col * Setting::grid_sprite_width;
            int y = row * Setting::grid_sprite_height;

            // Position sprites in grid layout and render sprite with current
            // clipping rectangle
            ResourceManager::get_image("cell_sprite")->set_position(x, y);
            SDL_Rect* clip;
            if (board[row][col].isEmpty()) {
                clip = &sprite_clips[0];
            } else {
                if (board[row][col].getColor() == Gui::Color::RED) {
                    clip = &sprite_clips[1];
                } else {
                    clip = &sprite_clips[2];
                }
            }

            ResourceManager::get_image("cell_sprite")->render(clip);

            // Position grid overlay image in grid layout and render
            ResourceManager::get_image("grid_overlay")->set_position(x, y);
            ResourceManager::get_image("grid_overlay")->render();
        }
    }
}

void Gui::notifyWinner(Color color) {
    if (color == Color::RED) {
        ResourceManager::get_image("red_wins")->render();
    } else if (color == Color::YELLOW) {
        ResourceManager::get_image("yellow_wins")->render();
    }

    waitForQuit();
}

void Gui::notifyDraw() {
    ResourceManager::get_image("draw")->render();
    waitForQuit();
}

void Gui::waitForQuit() const {
    while (true) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                return;
            }
            if (event.type == SDL_QUIT) {
                return;
            }
        }
        SDL_RenderPresent(renderer);
    }
}

void Gui::get_mouse_position(int* mouse_x, int* mouse_y) {
    SDL_GetMouseState(mouse_x, mouse_y);
    *mouse_x = *mouse_x / Setting::scale_factor;
    *mouse_y = *mouse_y / Setting::scale_factor;
}

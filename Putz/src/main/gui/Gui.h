#include "SDLWrapper.h"
#include "../UserInterface.h"

class Gui: public UserInterface
{
public:
    Gui();
    ~Gui();
    ColumnType askPlayer(Color color);
    void updateBoard(const GridType& board);
    void notifyWinner(Color color);
    void notifyDraw();

    static SDL_Renderer* get_renderer() {
        return renderer;
    }
    static void get_mouse_position(int* mouse_x, int* mouse_y);

private:
    Gui(const Gui&);
    Gui& operator=(const Gui&);
    SDL_Window* window;
    static SDL_Renderer* renderer;

    void init(const char* title, int window_width, int window_height);

    void render(const Gui::GridType& board);
    void grid_render(const Gui::GridType& board);

    void waitForQuit() const;
};

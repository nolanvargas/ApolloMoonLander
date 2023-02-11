#include "game.h"
using namespace std;

void callBack(const Interface* pUI, void* p)
{
    ogstream gout;

    // Cast a void pointer to the game object
    Game* game = (Game*)p;

    game->input(pUI);
    game->gamePlay();
    game->display(pUI);
}

#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ PWSTR pCmdLine,
    _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
    // Initialize OpenGL
    Point ptUpperRight(400.0, 400.0);
    Interface ui(0, NULL,
        "Open GL Demo",
        ptUpperRight);

    // Initialize the game class
    Game game(ptUpperRight);

    // set everything into action
    ui.run(callBack, &game);

    return 0;
}
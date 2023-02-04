#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ground.h"
#include "lander.h"
#include "game.h"
#include "thrust.h"
using namespace std;

void callBack(const Interface* pUI, void* p)
{
    ogstream gout;

    // Cast a void pointer to the game object
    Game* game = (Game*)p;

    Thrust thrust; // We will do something with this
    game->input(pUI);
    game->gamePlay(thrust);
    game->display(thrust, pUI);
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
    Point ptUpperRight(1000.0, 1000.0);
    Interface ui(0, NULL,
        "Open GL Demo",
        ptUpperRight);

    // Initialize the game class
    Game game(ptUpperRight);

    // set everything into action
    ui.run(callBack, &game);

    return 0;
}
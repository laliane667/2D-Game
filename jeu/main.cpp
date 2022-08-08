#include "engine.h"
#include "game.h"
#include "world.h"

int main()
{
    Engine::GetInstance()->initialize();
    while (!key[KEY_ESC])
        Engine::GetInstance()->run();

    Engine::GetInstance()->quit();
    delete Engine::GetInstance();
    delete Game::GetInstance();
    delete World::GetInstance();
    return 0;
}
END_OF_MAIN();



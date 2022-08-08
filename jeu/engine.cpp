#include "engine.h"

Engine *Engine::s_Instance = nullptr;

void Engine::initialize()
{
    cout << "Engine running..." << endl;
    set_etape("MENU");
    srand(time(NULL));
    allegro_init();
    install_keyboard();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1200,750,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    m_bitmaps.add_bitmap(create_bitmap(SCREEN_W,SCREEN_H),"PAGE");
    if (!m_bitmaps.get_bitmap("PAGE"))
    {
        allegro_message("Erreur de creation de page");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    User u;
    m_user = u;

}

void Engine::keyProtect()
{
    if(get_keyProtect("SPACE") == false && !key[KEY_SPACE]) set_keyProtect("SPACE", true);
    if(get_keyProtect("RIGHT") == false && !key[KEY_RIGHT]) set_keyProtect("RIGHT", true);
    if(get_keyProtect("LEFT") == false && !key[KEY_LEFT]) set_keyProtect("LEFT", true);
}

void Engine::run()
{
    clear_bitmap(get_bitmap("PAGE"));
    keyProtect();
    m_timeCounter += 1;
    m_time = (float)m_timeCounter/60;
    m_deltaTime = m_time - m_lastTime;
    if(m_timeCounter%1 == 0)
    {
        m_lastTime = m_time;
        directory();
        blit(get_bitmap("PAGE"),screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
    this_thread::sleep_for(chrono::milliseconds((int)(m_UT *16))); // sleep for 1 second*/
}


void Engine::directory()
{
    if(get_etape() == "MENU")
        GetInstance()->Menu();
    else if(get_etape() == "INITGAME")
        Game::GetInstance()->initialize();
    else if(get_etape() == "INGAME")
        Game::GetInstance()->inGame();
}

void Engine::Menu()
{
    rectfill(get_bitmap("PAGE"), (SCREEN_W/2)- 150, (SCREEN_H/2), (SCREEN_W/2)+150, (SCREEN_H/2)+30, makecol(91, 91, 91));
    textout_ex(get_bitmap("PAGE"),font,"Press P to launch the game", (SCREEN_W/2)-100, (SCREEN_H/2)+10, makecol(255,255,255),-1);
    if(key[KEY_P])
        set_etape("INITGAME");

}

void Engine::quit()
{
    destroy_bitmap(get_bitmap("PAGE"));
    allegro_exit();
    exit(EXIT_SUCCESS);
}

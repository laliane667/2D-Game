#include "game.h"

Game *Game::s_Instance = nullptr;

void Player::initialize(string name)
{
    m_x = 0;
    m_y = 5;
    m_name = name;
}

void Player::update()
{
    double r, p, f;
    p = m_mass* Engine::GetInstance()->getGravity(); ///Definition du poids

    if(World::GetInstance()->getCollision(m_x, m_y + m_dy * Engine::GetInstance()->getDeltaTime()) == true)
        m_onGround = true;
    else if (World::GetInstance()->getCollision(m_x, m_y + m_dy * Engine::GetInstance()->getDeltaTime()) == false)
        m_onGround = false;

    if(m_onGround)   ///Reaction normale
    {
        r = m_mass* Engine::GetInstance()->getGravity();
        f = m_gripConstant;
    }
    else
    {
        r = 0;
        f = 0;
    }

    m_ay =  r/m_mass - Engine::GetInstance()->getGravity();
    if(m_ay == 0) m_dy = 0;



    if(Engine::GetInstance()->get_keyProtect("SPACE") == true && key[KEY_SPACE] && m_onGround)
    {
        Engine::GetInstance()->set_keyProtect("SPACE", false);
        m_dy += m_jumpForce;
    }

    if(abs(m_dx) < m_speedMax)
    {
        if (key[KEY_RIGHT] && m_dx >= 0)
            m_dx += m_speedForce;
        if(key[KEY_LEFT] &&  m_dx <= 0)
            m_dx -= m_speedForce;
    }

    if((key[KEY_RIGHT] && m_dx < 0) || (key[KEY_LEFT] && m_dx > 0))
        m_dx -= m_dx;

    if(m_dx > 0)
        m_dx -= f/m_mass;
    else if (m_dx < 0)
        m_dx += f/m_mass;

    m_dx += m_ax * Engine::GetInstance()->getDeltaTime();
    m_dy += m_ay * Engine::GetInstance()->getDeltaTime();

    m_x += m_dx * Engine::GetInstance()->getDeltaTime();
    m_y += m_dy * Engine::GetInstance()->getDeltaTime();

}

void Player::display()
{
    circlefill(Engine::GetInstance()->get_bitmap("PAGE"),Engine::GetInstance()->getXCam(m_x), Engine::GetInstance()->getYCam(m_y),10, makecol(125,0,125));
}

void Game::initialize()
{
    string name = Engine::GetInstance()->getUserName();
    Player p;
    p.initialize(name);
    m_players.push_back(p);
    World::GetInstance()->initialize();
    Engine::GetInstance()->set_etape("INGAME");
}

void Game::inGame()
{
    for(int i = 0; i < m_players.size(); i++)
    {
        m_players[i].update();
        m_players[i].display();
    }
}

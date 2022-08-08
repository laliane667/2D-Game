#ifndef GAME_H
#define GAME_H
#include "header.h"
#include "engine.h"
#include "world.h"



class Player
{
    public:
        Player(){}
        ~Player(){}

        void initialize(string name);
        void display();
        void update();

    private:
        string m_name;
        int m_mass = 75;
        int m_jumpForce = 3;
        float m_speedForce = 1;
        int m_speedMax = 2;
        float m_gripConstant = 2;
        bool m_onGround = false;
        double m_x = 0, m_y = 0;
        double m_dx = 0, m_dy = 0;
        double m_ax = 0, m_ay = 0;

};

class Game
{
    public:
        static Game* GetInstance(){
            return s_Instance = (s_Instance != nullptr)? s_Instance : new Game();
        }
        ~Game(){}

        void inGame();
        void initialize();

        void addPlayer(Player player){m_players.push_back(player);}
        Player getPlayer(int i){return m_players[i];}

    private:
        static Game* s_Instance; ///UNIQUE INSTANCE DE LA CLASSE ENGINE, OMNIPRESENTE DU DEBUT A LA FIN DU JEU
        vector<Player> m_players;
};

#endif // GAME_H

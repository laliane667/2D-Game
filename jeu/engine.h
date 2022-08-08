#ifndef ENGINE_H
#define ENGINE_H
#include "header.h"
#include "game.h"

class User
{
    private:
        string m_UserName;
    public:
        User(){}
        ~User(){}

        void setUserName(string name){m_UserName = name;}
        string getUserName(){return m_UserName;}
};

class Bitmap
{
    private:
        map<string, BITMAP*> m_bitmaps;
    public:
        Bitmap(){}
        ~Bitmap(){}

        void add_bitmap(BITMAP* b, string s){m_bitmaps[s] = b;}
        BITMAP* get_bitmap(string s){return m_bitmaps[s.c_str()];}
};

///================================================================\\ ENGINE // =====================================================================

class Engine
{
    private:
        static Engine* s_Instance; ///UNIQUE INSTANCE DE LA CLASSE ENGINE, OMNIPRESENTE DU DEBUT A LA FIN DU JEU
        string m_etapeActuelle; ///AIGUILLAGE QUI PERMET DE SE DEPLACER ENTRE LES DIFFERENTS MENUS
        Bitmap m_bitmaps;
        User m_user;
        int m_timeCounter = 0;
        float m_UT = 1, m_time = 0, m_lastTime = 0, m_deltaTime = 0;
        double m_gravity = 10;
        map<string, bool> m_keyProtect;
        float m_xCam = -8;
        float m_yCam = 7;



    public:
        static Engine* GetInstance(){
            return s_Instance = (s_Instance != nullptr)? s_Instance : new Engine();
        }
        ~Engine(){}

        void initialize();
        void run();
        void directory();
        void quit();

        void Menu();

        BITMAP* get_bitmap(string s){return m_bitmaps.get_bitmap(s.c_str());}

        void set_etape(string s){m_etapeActuelle = s;}
        string get_etape(){return m_etapeActuelle;}

        string getUserName(){return m_user.getUserName();}

        double getGravity(){return m_gravity;}
        void setGravity(double g){m_gravity = g;}

        void keyProtect();
        bool get_keyProtect(string s){return m_keyProtect[s.c_str()];}
        void set_keyProtect(string s, bool b){m_keyProtect[s] = b;}

        float getDeltaTime(){return m_deltaTime;}

        int getXCam(float x){return (int)(x*75 - m_xCam*75);}
        int getYCam(float y){return -(int)(y*75 - m_yCam*75);}

};

#endif // ENGINE_H

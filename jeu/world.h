#ifndef WORLD_H
#define WORLD_H

class Floor
{
    public:
        Floor(){}
        ~Floor(){}
        double get_y(){return m_y;}
        double get_x(){return m_x;}

    private:
        double m_x = 0;
        double m_y = 0;
};

class World
{
    public:
        static World* GetInstance(){
            return s_Instance = (s_Instance != nullptr)? s_Instance : new World();
        }
        ~World(){}

        void initialize();
        bool getCollision(double x, double y);


    private:
        static World* s_Instance; ///UNIQUE INSTANCE DE LA CLASSE ENGINE, OMNIPRESENTE DU DEBUT A LA FIN DU JEU
        Floor m_floor;
};

#endif // WORLD_H

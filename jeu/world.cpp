#include "world.h"

World *World::s_Instance = nullptr;

void World::initialize()
{
    Floor floor;
    m_floor = floor;
}

bool World::getCollision(double x, double y)
{
    if(y <= m_floor.get_y())
        return true;
    else return false;
}

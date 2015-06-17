#include "warehouse.h"

Warehouse::Warehouse()
{
    food = 0;
    wood = 0;
    stone = 0;
}


void Warehouse::increase_food(int i_food)
{
    food += i_food;
}

void Warehouse::increase_wood(int i_wood)
{
    wood += i_wood;
}

void Warehouse::increase_stone(int i_stone)
{
    stone += i_stone;
}


int Warehouse::get_food()
{
    return food;
}

int Warehouse::get_wood()
{
    return wood;
}

int Warehouse::get_stone()
{
    return stone;
}


void Warehouse::take_food(int value_f)
{
    food-=value_f;
}

void Warehouse::take_wood(int value_w)
{
    wood-=value_w;
}

void Warehouse::take_stone(int value_s)
{
    stone-=value_s;
}


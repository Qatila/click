#include "building.h"

Building::Building()
{
    Produced = 0;
    Capacity = 5;
}

void Building::Update()
{
    for(unsigned int i=0; i < People.size(); i++)
    {
    Produced += People[i].Get_Capacity();
    }
}

int Building::Get_Produced()
{
    int value = Produced;
    Produced = 0;
    return value;
}

int Building::Get_Capacity()
{
    return Capacity;
}

int Building::Get_People()
{
    return People.size();
}

void Building::Recruit()
{
    People.resize(People.size()+1);
}


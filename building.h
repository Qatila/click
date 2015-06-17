#ifndef BUILDING_H
#define BUILDING_H

#include "person.h"
#include <vector>
#include <string>

class Building
{
public:
    Building();
    void Update();
    int Get_Produced();
    int Get_Capacity();
    int Get_People();
    void Recruit();

    private:
    int Capacity;
    int Produced;
    std::vector <Person> People;
};

#endif // BUILDING_H

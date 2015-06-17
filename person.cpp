#include "person.h"

Person::Person()
{
    Capacity = 1; //poprawione
}

    int Person::Get_Capacity()
{
    return Capacity;
}

    void Person::Increase_Capacity()
{
    Capacity++;

}


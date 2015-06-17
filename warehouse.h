#ifndef WAREHOUSE_H
#define WAREHOUSE_H


class Warehouse
{
public:
    Warehouse();

    void increase_food(int i_food);
    void increase_wood(int i_wood);
    void increase_stone(int i_stone);

    int get_food();
    int get_wood();
    int get_stone();

    void take_food(int value_f);
    void take_wood(int value_w);
    void take_stone(int value_s);

private:
    int food;
    int wood;
    int stone;
};

#endif // WAREHOUSE_H

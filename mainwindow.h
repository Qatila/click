#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "building.h"
#include "warehouse.h"

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <Qtimer>
#include <vector>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

private:
    Warehouse warehouse;

    QTimer *timer;

    std::vector <Building> bakery;
    std::vector <Building> sawmill;
    std::vector <Building> mine;

    QPushButton *button_food;
    QPushButton *button_wood;
    QPushButton *button_stone;

    QPushButton *button_bakery;
    QPushButton *button_sawmill;
    QPushButton *button_mine;

    QPushButton *button_recruit_bakery;
    QPushButton *button_recruit_sawmill;
    QPushButton *button_recruit_mine;


    QLabel *label_food;
    QLabel *label_wood;
    QLabel *label_stone;

    QLabel *label_bakery;
    QLabel *label_sawmill;
    QLabel *label_mine;

    QLabel *label_recruit_bakery;
    QLabel *label_recruit_sawmill;
    QLabel *label_recruit_mine;


private slots:
    void update();

    void increase_food();
    void increase_wood();
    void increase_stone();
    void increase_recruit_bakery();
    void increase_recruit_sawmill();
    void increase_recruit_mine();
    void increase_bakery();
    void increase_sawmill();
    void increase_mine();

    void set_label_food();
    void set_label_wood();
    void set_label_stone();

    void set_label_bakery();
    void set_label_sawmill();
    void set_label_mine();

    void set_label_recruit_bakery();
    void set_label_recruit_sawmill();
    void set_label_recruit_mine();
};

#endif // MAINWINDOW_H

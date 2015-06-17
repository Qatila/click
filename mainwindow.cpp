#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(3000);

    button_food = new QPushButton (tr("food"), this);
    button_food->setGeometry(20,30, 200,50);

    button_wood = new QPushButton (tr("wood"), this);
    button_wood->setGeometry(20,100, 200,50);

    button_stone = new QPushButton (tr("stone"), this);
    button_stone->setGeometry(20,170, 200,50);


    button_bakery = new QPushButton (tr("build bakery"), this);
    button_bakery->setGeometry(20,400, 200,50);

    button_sawmill = new QPushButton (tr("build sawmill"), this);
    button_sawmill->setGeometry(20,470, 200,50);

    button_mine = new QPushButton (tr("build mine"), this);
    button_mine->setGeometry(20,540, 200,50);


    button_recruit_bakery = new QPushButton (tr("recruit to bakery"), this);
    button_recruit_bakery->setGeometry(440,400, 200,50);

    button_recruit_sawmill = new QPushButton (tr("recruit to sawmill"), this);
    button_recruit_sawmill->setGeometry(440,470, 200,50);

    button_recruit_mine = new QPushButton (tr("recruit to mine"), this);
    button_recruit_mine->setGeometry(440,540, 200,50);



    label_food = new QLabel (tr("0"), this);
    label_food->setGeometry(240,30, 200,50);

    label_wood = new QLabel (tr("0"), this);
    label_wood->setGeometry(240,100, 200,50);

    label_stone = new QLabel (tr("0"), this);
    label_stone->setGeometry(240,170, 200,50);


    label_bakery = new QLabel (tr("0"), this);
    label_bakery->setGeometry(240,400, 200,50);

    label_sawmill = new QLabel (tr("0"), this);
    label_sawmill->setGeometry(240,470, 200,50);

    label_mine = new QLabel (tr("0"), this);
    label_mine->setGeometry(240,540, 200,50);


    label_recruit_bakery = new QLabel (tr("0"), this);
    label_recruit_bakery->setGeometry(660,400, 200,50);

    label_recruit_sawmill = new QLabel (tr("0"), this);
    label_recruit_sawmill->setGeometry(660,470, 200,50);

    label_recruit_mine = new QLabel (tr("0"), this);
    label_recruit_mine->setGeometry(660,540, 200,50);


    connect(button_food, SIGNAL(clicked()), this, SLOT(set_label_food()));
    connect(button_wood, SIGNAL(clicked()), this, SLOT(set_label_wood()));
    connect(button_stone, SIGNAL(clicked()), this, SLOT(set_label_stone()));

    connect(button_bakery, SIGNAL(clicked()), this, SLOT(set_label_bakery()));
    connect(button_sawmill, SIGNAL(clicked()), this, SLOT(set_label_sawmill()));
    connect(button_mine, SIGNAL(clicked()), this, SLOT(set_label_mine()));

    connect(button_recruit_bakery, SIGNAL(clicked()), this, SLOT(set_label_recruit_bakery()));
    connect(button_recruit_sawmill, SIGNAL(clicked()), this, SLOT(set_label_recruit_sawmill()));
    connect(button_recruit_mine, SIGNAL(clicked()), this, SLOT(set_label_recruit_mine()));
}


void MainWindow::update()
{
    QString a;

    for(unsigned int i=0; i<bakery.size(); i++)
    {
        bakery[i].Update();
        warehouse.increase_food(bakery[i].Get_Produced());

        a.setNum(warehouse.get_food());
        label_food->setText(a);
    }

    for(unsigned int i=0; i<sawmill.size(); i++)
    {
        sawmill[i].Update();
        warehouse.increase_wood(sawmill[i].Get_Produced());

        a.setNum(warehouse.get_wood());
        label_wood->setText(a);
    }

    for(unsigned int i=0; i<mine.size(); i++)
    {
        mine[i].Update();
        warehouse.increase_stone(mine[i].Get_Produced());

        a.setNum(warehouse.get_stone());
        label_stone->setText(a);
    }

}


void MainWindow::set_label_food()
{
    warehouse.increase_food(1);
    QString a;
    a.setNum(warehouse.get_food());
    label_food->setText(a);
}

void MainWindow::set_label_wood()
{
    warehouse.increase_wood(1);
    QString a;
    a.setNum(warehouse.get_wood());
    label_wood->setText(a);
}

void MainWindow::set_label_stone()
{
    warehouse.increase_stone(1);
    QString a;
    a.setNum(warehouse.get_stone());
    label_stone->setText(a);
}


void MainWindow::set_label_recruit_bakery()
{
    if(warehouse.get_food()>=10)
    {

        int value = 0;

        increase_recruit_bakery();

        for (unsigned int i=0; i<bakery.size(); i++)
        {
            value+=bakery[i].Get_People();
        }

        QString a;
        a.setNum(value);
        label_recruit_bakery->setText(a);

        warehouse.take_food(10);

        a.setNum(warehouse.get_food());
        label_food->setText(a);
    }
}

void MainWindow::set_label_recruit_sawmill()
{
    if(warehouse.get_food()>=10)
    {

        int value = 0;

        increase_recruit_sawmill();

        for(unsigned int i=0; i<sawmill.size(); i++)
        {
            value+=sawmill[i].Get_People();
        }

        QString a;
        a.setNum(value);
        label_recruit_sawmill->setText(a);

        warehouse.take_food(10);

        a.setNum(warehouse.get_food());
        label_food->setText(a);
    }
}

void MainWindow::set_label_recruit_mine()
{
    if(warehouse.get_food()>=10)
{

        int value = 0;

        increase_recruit_mine();

        for(unsigned int i=0; i<mine.size(); i++)
        {
            value+=mine[i].Get_People();
        }

        QString a;
        a.setNum(value);
        label_recruit_mine->setText(a);

        warehouse.take_food(10);

        a.setNum(warehouse.get_food());
        label_food->setText(a);
    }
}
void MainWindow::set_label_bakery()
{
    if((warehouse.get_wood()>=10) & (warehouse.get_stone()>=10))
    {
        bakery.resize(bakery.size()+1);
        QString a;
        a.setNum(bakery.size());
        label_bakery->setText(a);

        warehouse.take_wood(10);
        warehouse.take_stone(10);

        a.setNum(warehouse.get_wood());
        label_wood->setText(a);
        a.setNum(warehouse.get_stone());
        label_stone->setText(a);
    }
}

void MainWindow::set_label_sawmill()
{
    if((warehouse.get_wood()>=10) & (warehouse.get_stone()>=10))
    {
        sawmill.resize(sawmill.size()+1);
        QString a;
        a.setNum(sawmill.size());
        label_sawmill->setText(a);

        warehouse.take_wood(10);
        warehouse.take_stone(10);

        a.setNum(warehouse.get_wood());
        label_wood->setText(a);
        a.setNum(warehouse.get_stone());
        label_stone->setText(a);
    }
}

void MainWindow::set_label_mine()
{
    if((warehouse.get_wood()>=10) & (warehouse.get_stone()>=10))
    {
        mine.resize(mine.size()+1);
        QString a;
        a.setNum(mine.size());
        label_mine->setText(a);

        warehouse.take_wood(10);
        warehouse.take_stone(10);

        a.setNum(warehouse.get_wood());
        label_wood->setText(a);
        a.setNum(warehouse.get_stone());
        label_stone->setText(a);
    }
}



void MainWindow::increase_food()
{
    warehouse.increase_food(1);
}

void MainWindow::increase_wood()
{
    warehouse.increase_wood(1);
}

void MainWindow::increase_stone()
{
    warehouse.increase_stone(1);
}

void MainWindow::increase_recruit_bakery()
{
    for(unsigned int i=0; i<bakery.size(); i++)
    {
       if(bakery[i].Get_People()<bakery[i].Get_Capacity())
       {
           bakery[i].Recruit();
           break;
       }
    }
}

void MainWindow::increase_recruit_sawmill()
{
    for(unsigned int i=0; i<sawmill.size(); i++)
    {
       if(sawmill[i].Get_People()<sawmill[i].Get_Capacity())
       {
           sawmill[i].Recruit();
           break;
       }
    }
}

void MainWindow::increase_recruit_mine()
{
    for(unsigned int i=0; i<mine.size(); i++)
    {
       if(mine[i].Get_People()<mine[i].Get_Capacity())
       {
           mine[i].Recruit();
           break;
       }
    }
}

void MainWindow::increase_bakery()
{
    bakery.resize(bakery.size()+1);
}

void MainWindow::increase_sawmill()
{
    sawmill.resize(sawmill.size()+1);
}

void MainWindow::increase_mine()
{
    mine.resize(mine.size()+1);
}

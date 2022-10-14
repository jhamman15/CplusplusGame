#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "playgame.h"
#include "maingamewindow.h"

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_pbtnPlayGame_clicked()
{
    MainGameWindow MainGameWindow;
    MainGameWindow.setModal(true);
    MainGameWindow.exec();
}

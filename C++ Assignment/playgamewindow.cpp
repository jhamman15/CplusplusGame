#include "playgamewindow.h"
#include "ui_playgamewindow.h"

PlayGameWindow::PlayGameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayGameWindow)
{
    ui->setupUi(this);
}

PlayGameWindow::~PlayGameWindow()
{
    delete ui;
}

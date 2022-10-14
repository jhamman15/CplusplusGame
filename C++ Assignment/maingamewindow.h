#ifndef MAINGAMEWINDOW_H
#define MAINGAMEWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainGameWindow;
}

class MainGameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainGameWindow(QWidget *parent = nullptr);
    ~MainGameWindow();

    QTimer *timer;

public slots:
    void MyTimerSlot();

private:
    Ui::MainGameWindow *ui;
};

#endif // MAINGAMEWINDOW_H

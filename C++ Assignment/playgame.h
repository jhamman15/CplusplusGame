#ifndef PLAYGAME_H
#define PLAYGAME_H

#include <QDialog>

namespace Ui {
class PlayGame;
}

class PlayGame : public QDialog
{
    Q_OBJECT

public:
    explicit PlayGame(QWidget *parent = nullptr);
    ~PlayGame();

    QTimer *timer;

public slots:
    void MyTimerSlot();

private slots:
    void on_btnSaveName_clicked();

    void on_btnGuess_clicked();

    void on_rdbtnEasy_clicked();

    void on_rdbtnMedium_clicked();

    void on_rdbtnHard_clicked();

private:
    Ui::PlayGame *ui;
};

#endif // PLAYGAME_H

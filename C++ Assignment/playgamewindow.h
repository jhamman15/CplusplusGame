#ifndef PLAYGAMEWINDOW_H
#define PLAYGAMEWINDOW_H

#include <QDialog>

namespace Ui {
class PlayGameWindow;
}

class PlayGameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PlayGameWindow(QWidget *parent = nullptr);
    ~PlayGameWindow();

private:
    Ui::PlayGameWindow *ui;
};

#endif // PLAYGAMEWINDOW_H

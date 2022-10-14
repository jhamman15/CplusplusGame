#include "maingamewindow.h"
#include "ui_maingamewindow.h"

MainGameWindow::MainGameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainGameWindow)
{
    ui->setupUi(this);
}

MainGameWindow::~MainGameWindow()
{
    delete ui;
}
//    timer = new QTimer(this);

//        QObject::connect(timer, SIGNAL(timeout()),this, SLOT(MyTimerSlot()));

//        timer->start(1000);

    ui->txtName->setPlaceholderText("Enter Name");
}


bool bRun = true;
bool bGame = true;
bool bColorSwitch = true;
int iGuessCorrect = 0;
int iGameMatches = 0;
int iGuesses = 0;
int iGuessLimit = 10;
string sLine = "";
string sSecretWord = "";
string sInput;
string sUsername;
string sEmptiedString = "";

Show showWord;
Read readFile;
CheckLetter checkLetter;
Score GetHighScore;

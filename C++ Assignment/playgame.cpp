#include "playgame.h"
#include "ui_playgame.h"
#include <iostream>
#include <fstream>
#include <locale>
#include <cctype>
#include <string>
#include <QObject>
#include <QPlainTextEdit>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QTimer>
#include "wordarrays.h"
#include "checkletter.h"
#include "readfile.h"
#include "score.h"
#include "mainmenu.h"


PlayGame::PlayGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayGame)
{
    ui->setupUi(this);

//    timer = new QTimer(this);

//        QObject::connect(timer, SIGNAL(timeout()),this, SLOT(MyTimerSlot()));

//        timer->start(1000);

    ui->txtName->setPlaceholderText("Enter Name");
}

PlayGame::~PlayGame()
{
    delete ui;
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



void PlayGame::on_btnSaveName_clicked()
{
    this->ui->lblName->setText(this->ui->txtName->toPlainText());

    QString qsName = this->ui->txtName->toPlainText();

    sUsername = qsName.toStdString();

    this->ui->txtName->setText("");
}

void PlayGame::on_btnGuess_clicked()
{
    this->ui->lblWord->setText(QString::fromStdString(sEmptiedString));

    QString qsInput = this->ui->txtGuessedLetter->toPlainText();

    sInput = qsInput.toStdString();

    if (sInput == "hint") {
      sEmptiedString = checkLetter.GiveHint(sSecretWord, sEmptiedString);
      this->ui->lblWord->setText(QString::fromStdString(sEmptiedString));
    }
    else {
     sEmptiedString = checkLetter.CheckGuess(sInput[0], sSecretWord, sEmptiedString);
     this->ui->lblWord->setText(QString::fromStdString(sEmptiedString));
    }


    //this runs the game, checking and providing feedback, as well as adding scores.
        if (iGuesses != iGuessLimit) {
            int iCheckReturn = checkLetter.CheckCorrect(sSecretWord, sEmptiedString);

            QString score = QString::number(GetHighScore.GetScore());
            QString highscore = QString::number(GetHighScore.HighScore(sUsername, GetHighScore.GetScore()));
            this->ui->lblScore->setText("Score: "+score);

            if (iCheckReturn == 0) {
                this->ui->lblCheck->setText("That is incorrect!");
                this->ui->lblCheck->setStyleSheet("QLabel{background-color:red;}");
                this->ui->lblScore->setText("Score: "+score);
                iGuesses++;
            }
            else if (iCheckReturn == 1) {
                this->ui->lblCheck->setText("You guessed all the letters, You Win! Final Score: "+ highscore);
                this->ui->lblCheck->setStyleSheet("QLabel{background-color:white;}");
                this->ui->lblScore->setText("Score: "+score);
                //Logger("Game Won.");

                //This block will create a log file that stores the date and time automatically when the game is won.
                QFile LogFile("C:\\Users\\jhamm\\Desktop\\GRCC\\CIS 227 C++ 2\\Assignment9\\Assignment-8-main\\LogFile.txt");

                  if(LogFile.open(QFile::WriteOnly | QFile::Text)){

                  QTextStream out(&LogFile);

                  QString qsLogMessage = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss ") + "Game Won";
                  out << qsLogMessage;
                  LogFile.flush();

                  LogFile.close();
                  }

            }
            else if (iCheckReturn == 2) {
                this->ui->lblCheck->setText("Thats correct.");
                this->ui->lblScore->setText("Score: "+score);
                this->ui->lblCheck->setStyleSheet("QLabel{background-color:green;}");
            }

            if (sInput == "hint") {
                sEmptiedString = checkLetter.GiveHint(sSecretWord, sEmptiedString);
                this->ui->lblScore->setText("Score: "+score);
            }
            else {
                sEmptiedString = checkLetter.CheckGuess(sInput[0], sSecretWord, sEmptiedString);
            }
            this->ui->txtGuessedLetter->setText("");
        }
        else {
            this->ui->lblCheck->setText("You are out of guesses. Game Over. Final score" +
               QString::number(GetHighScore.HighScore(sUsername, GetHighScore.GetScore())));
            this->ui->lblCheck->setStyleSheet("QLabel{background-color:white;}");
        }
    }


void PlayGame::on_rdbtnEasy_clicked()
{
    //select a word based on the entered number from the array and store it as the secret word when the radial button is selected
    int iValue;

    QString qsNumber = this->ui->txtNumber->toPlainText();

    iValue = qsNumber.toInt();

    sSecretWord = showWord.getEasyWord(iValue);

    //for testing to see the word selected for the secret word
    //this->ui->lblSecretWord -> setText(QString::fromStdString(sSecretWord));

    sEmptiedString = checkLetter.CreateEmptiedString(sSecretWord);
}

void PlayGame::on_rdbtnMedium_clicked()
{
    //select a word based on the entered number from the array and store it as the secret word when the radial button is selected
    int iValue;

    QString qsNumber = this->ui->txtNumber->toPlainText();

    iValue = qsNumber.toInt();

    sSecretWord = showWord.getMediumWord(iValue);

//    for testing to see the word selected for the secret word
//    this->ui->lblSecretWord -> setText(QString::fromStdString(sSecretWord));

    sEmptiedString = checkLetter.CreateEmptiedString(sSecretWord);
}

void PlayGame::on_rdbtnHard_clicked()
{
    //select a word based on the entered number from the array and store it as the secret word when the radial button is selected
    int iValue;

    QString qsNumber = this->ui->txtNumber->toPlainText();

    iValue = qsNumber.toInt();

    vector<string> vWords = readFile.ReadWordList();

    sSecretWord = vWords[iValue - 1];

    //for testing to see the word selected for the secret word
    //this->ui->lblSecretWord -> setText(QString::fromStdString(sSecretWord));

    sEmptiedString = checkLetter.CreateEmptiedString(sSecretWord);
}

void PlayGame::MyTimerSlot()
{

    int iValue = ui->lcdTimer->intValue();
    iValue++;
    ui->lcdTimer->display(iValue);

//    if(iValue % 60 == 0 && bColorSwitch){
//        ui->centralwidget->setStyleSheet("background-color: rgb(85, 170, 127);");
//        bColorSwitch = false;
//    }else if(iValue % 60 == 0 && !bColorSwitch){
//        ui->centralwidget->setStyleSheet("background-color: rgb(85, 85, 255);");
//        bColorSwitch = true;
//    }

}



























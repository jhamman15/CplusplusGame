#include "mainmenu.h"
#include "readfile.h"
#include<QSplashScreen>
#include<QTimer>
#include<QString>
#include <QApplication>



Read Read;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu w;

    QString qsVersionNumber = "0.0.6";
   //obtains a random int from 1-12
   srand(time(0));
   unsigned short int iRandom = rand() % 12;

   //reads in the vector of quotes, chooses one based on random int and converts from string to QString
   QString qsQuote = (QString::fromStdString(Read.SplashScreenQuotes()[iRandom]))
           +"\n\nLetter Guessing Game \n By: Jesse, Joe, & Joe \n Version Number: "
           + qsVersionNumber + "\n\n\n\n\n\n";

   QPixmap SplashImage(800,800);
   SplashImage.fill(QColor(143,188,143));

   QFont HangmanSplashScreenFont;
   HangmanSplashScreenFont.setPixelSize(14);

   QSplashScreen HangmanSplashScreen(SplashImage, Qt::WindowStaysOnTopHint);
   HangmanSplashScreen.setFont(HangmanSplashScreenFont);
   HangmanSplashScreen.show();
   HangmanSplashScreen.setEnabled(false);

   HangmanSplashScreen.showMessage(qsQuote, Qt::AlignCenter | Qt::TextWordWrap);

   //If used will hold the splashscreen on the screen for 5 seconds
   QTimer::singleShot(500, &HangmanSplashScreen, SLOT(close())); // keep displayed for 5 seconds
   QTimer::singleShot(500, &w, SLOT(show()));

    w.show();
    return a.exec();
}

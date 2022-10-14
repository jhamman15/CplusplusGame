#include "readfile.h"
#include <iostream>
#include <locale>
#include <cctype>
#include <fstream>
#include <string>
#include <QFile>
#include <QTextStream>


using namespace std;

//create function of class Read to be a vector of strings
vector<string> Read::ReadWordList()
{
    vector<string> vRandWords;
    string sLine;
    ifstream MyFile;

    QFile File("C:\\Users\\jhamm\\Desktop\\GRCC\\CIS 227 C++ 2\\Assignment9\\Assignment-8-main\\RandomWords.txt");

    QString qsLine;

    if (File.open(QIODevice::ReadOnly))
    {
        QTextStream in(&File);
        while (!in.atEnd())
        {
             qsLine = in.readLine();
             sLine = qsLine.toStdString();
             vRandWords.push_back(sLine);

        }
        File.close();
    }


    //for testing - prints out the words from the vector - don't delete
    /*for (auto i = vRandWords.begin(); i != vRandWords.end(); ++i)

        cout << *i << ' ';*/

    return vRandWords;
}


//creates a vector of splash screen quotes from text file. Returns the whole
//vector so an individual element can be called on the splash screen in main.cpp
vector<string> Read::SplashScreenQuotes()
{

    vector<string> vQuotes;
    string sLine;
    QString qsLine;

    QFile QuotesFile("C:\\Users\\jhamm\\Desktop\\GRCC\\CIS 227 C++ 2\\Assignment9\\Assignment-8-main\\quotes.txt");

    if (QuotesFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&QuotesFile);
        while (!in.atEnd())
        {
             qsLine = in.readLine();
             sLine = qsLine.toStdString();
             vQuotes.push_back(sLine);
        }
        QuotesFile.close();
    }

    return vQuotes;
}

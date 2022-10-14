


#pragma once
#include <string>
using namespace std;

#ifndef CHECKLETTER_H_
#define CHECKLETTER_H_

class CheckLetter {
public:
    CheckLetter();
    string CreateEmptiedString(string);
    string CheckGuess(char, string, string);
    int CheckCorrect(string, string);
    string GiveHint(string, string);
private:
    char cPreviousGuess;
    string sPreviousEmptiedString;
};

#endif


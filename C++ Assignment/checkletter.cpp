#include <iostream>
#include <string>
#include "CheckLetter.h"
#include "Score.h"
using namespace std;
Score score;

CheckLetter::CheckLetter() {

}

//creates a string of dashes, the string will be used to keep track of players correct guesses.
string CheckLetter::CreateEmptiedString(string sSecretWord) {
    string sEmptiedString = sSecretWord;
    for (int i = 0; i < sSecretWord.length(); i++) {
        sEmptiedString[i] = '-';
    }
    return sEmptiedString;
}

//using the secret word, the guessed character, and string of dashes as input
//it replaces the proper dashes in the emptiedString with the guessed letter
string CheckLetter::CheckGuess(char cGuess, string sSecretWord, string sEmptiedString) {

    //input emptiedstring is added to a private variable to be used in the check correct later.
    cPreviousGuess = cGuess;
    sPreviousEmptiedString = sEmptiedString;

    for (int i = 0; i < sSecretWord.length(); i++) {
        if (cGuess == sSecretWord[i]) {
            sEmptiedString[i] = cGuess;
        }
    }
    return sEmptiedString;
}

//this function takes in the secret word and string of dashes to see if the user scored points in the last guess
//it also checks if the string is completed and gives appropriate points if game is won
//this function returns ints for the UI to know if the guess was correct or if the game is won
int CheckLetter::CheckCorrect(string sSecretWord, string sEmptiedString) {
    //cout << sPreviousEmptiedString << endl;
    if (sPreviousEmptiedString == sEmptiedString) {
        score.ModifyScore(0);
        return 0;
    }
    else if (sEmptiedString == sSecretWord) {
        score.ModifyScore(1);
        return 1;
    }
    else {
        score.ModifyScore(2);
        return 2;
    }
}

// It adds one letter to the Emptied string as a hint and removes some points from the players score
string CheckLetter::GiveHint(string sSecretWord, string sEmptiedString) {
    for (int i = 0; i < sSecretWord.length(); i++) {
        if (sEmptiedString[i] != sSecretWord[i]) {
            sEmptiedString[i] = sSecretWord[i];
            sPreviousEmptiedString = sEmptiedString;
            score.ModifyScore(3);
            return sEmptiedString;
        }
    }
    return sEmptiedString;
}

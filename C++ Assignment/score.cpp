#include <iostream>
#include <string>
#include <iterator>
#include "score.h"
using namespace std;

int iCurrentScore;

map<string, int> Map;

Score::Score() {
    iCurrentScore = 0;
}

int Score::ModifyScore(int iScoreOption) {
    /* Scoring options / Primarily used by the checkcorrect function
    0: Incorrect Guess
    1: Correct Word
    2: Correct Guess
    3: Hint Used
    4: No Additon
    */
    int iMaxOption = 4;
    int iScoringArray[5] = { -5, 100, 20, -30, 0 };

    //Sets the option to zero points if not an applicable input
    if (iScoreOption > iMaxOption || iScoreOption < 0) {
        iScoreOption = iMaxOption;
    }
    //adds or removes points based on choice
    iCurrentScore += iScoringArray[iScoreOption];
    return iCurrentScore;
}

// returns score
int Score::GetScore() {
    return iCurrentScore;
}

// checks if current score is high score for player and adds it to map
int Score::HighScore(string sName, int iInputScore) {
    if (Map[sName] < iInputScore) {
        Map[sName] = iInputScore;
    }

    for (auto& t : Map)
        cout << t.first << ", ";

    //returns the current high score as an int
    return Map[sName];
}

//returns the current high score as an int
int Score::GetHighScore(string sName) {

    for (auto& t : Map)
        cout << t.first << ": ";

    return Map[sName];
}

//resets current score
void Score::ResetCurrentScore() {
    iCurrentScore = 0;
}

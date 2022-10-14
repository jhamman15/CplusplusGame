#ifndef WORDARRAYS_H
#define WORDARRAYS_H
#pragma once
#include <string>

class Show {

private:
    // The array of values for the user to select
    std::string sEasyWords[12] = { "Cat", "Mat", "Sat", "Lap", "Pat", "Run", "Lap", "Map", "Game", "Cook", "Cube", "Movie" };
    std::string sMediumWords[12] = { "Running", "Attack", "Payment", "Assignment", "Greater", "Contact",
                                     "Window", "Button", "Medium", "Spring", "Conveying", "Modifying" };

public:
    // Function definitions
    std::string getEasyWord(int);
    std::string getMediumWord(int);
};
#endif

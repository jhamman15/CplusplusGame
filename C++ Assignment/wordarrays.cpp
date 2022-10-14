

#include "wordarrays.h"
#include <iostream>
#include <string>

std::string Show::getEasyWord(int userInput) {
    return Show::sEasyWords[userInput - 1];
}

std::string Show::getMediumWord(int userInput) {
    return Show::sMediumWords[userInput - 1];
}

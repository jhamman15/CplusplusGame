#include <string>
#include <iostream>
#include <locale>
#include <cctype>
#include <fstream>
#include <vector>

using namespace std;

#ifndef READ_H_
#define READ_H_

class Read
{

public:
    // function definiton
    vector<string> ReadWordList();
    vector<string> SplashScreenQuotes();
};

#endif

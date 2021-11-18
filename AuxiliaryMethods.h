#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>

using namespace std;

class AuxiliaryMethods
{
public:
    static string convertIntToString(int number);
    static string loadTextLine();
    static string changeFirstLetterToUppercaseAndRestToLowercase(string text);
    static int convertStringToInt(string number);
    static char loadCharacter();
    static int loadIniger();
};

#endif // AUXILIARYMETHODS_H

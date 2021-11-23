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
    static string convertIntToString(int numberInt);
    static string convertDoubleToString(double numberDouble);
    static string loadTextLine();
    static string changeFirstLetterToUppercaseAndRestToLowercase(string text);
    static int convertStringToInt(string number);
    static char loadCharacter();
    static int loadIniger();
    static string replaceCommaWithDot(string modifiedText);
    static double convertStringToDouble(string numberString);
};

#endif // AUXILIARYMETHODS_H

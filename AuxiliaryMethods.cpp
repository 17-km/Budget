#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int numberInt)
{
    ostringstream ss;
    ss << numberInt;
    string numberString = ss.str();
    return numberString;
}

string AuxiliaryMethods::loadTextLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

string AuxiliaryMethods::changeFirstLetterToUppercaseAndRestToLowercase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int AuxiliaryMethods::convertStringToInt(string numberString)
{
    int numberInt;
    istringstream iss(numberString);
    iss >> numberInt;

    return numberInt;
}

char AuxiliaryMethods::loadCharacter()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "This is not a single character. Please retype." << endl;
    }
    return character;
}

int AuxiliaryMethods::loadIniger()
{
    string input = "";
    int number = 0;

    while (true)
    {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "This is not a number. Please retype." << endl;
    }
    return number;
}

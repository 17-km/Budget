#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <ctime>

#include "AuxiliaryMethods.h"

using namespace std;

class DateManager
{
    public:
    const int TODAYS_DATE;
    const int MINIMUM_DATE;
    int getTodaysDate();
    bool isYearLeap(int date);
    int numberOfDaysInMonth(int date);
    bool isDateFormatCorrect(string dateAsText);
    bool isDateCorrect(int date);
    bool isDateInAllowedRange(int date);
    static int changeDateFromTextToNumber (string dateAsText);
    static string changeDateFromNumberToText (int date);
    static int extractDayFromDate(int date);
    static int extractMonthFromDate(int date);
    static int extractYearFromDate(int date);
    int findLastDayOfMonth(int date);
    int findFirstDayOfCurrentMonth();
    int findFirstDayOfPreviousMonth();

//public:
    DateManager();
    int getUsersDate();

};

#endif // DATEMANAGER_H

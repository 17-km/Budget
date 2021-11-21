#include "DateManager.h"

using namespace std;

DateManager::DateManager()
    : TODAYS_DATE(getTodaysDate()), MINIMUM_DATE(20000101){}

int DateManager::getTodaysDate()
{
    int todaysDate, year, month, day;
    time_t now = time(0);
    tm* localTime = localtime(&now);
    year = 1900 + localTime->tm_year;
    month = 1 + localTime->tm_mon;
    day = localTime->tm_mday;
    todaysDate = year * 10000 + month * 100 + day;
    return todaysDate;
}

int DateManager::getUsersDate()
{
    string dateAsText;
    int date = 0;
    cout << "Enter date in the format YYYY-MM-DD: ";
    do
    {
        dateAsText = AuxiliaryMethods::loadTextLine();
        if (!isDateFormatCorrect(dateAsText))
        {
            cout << "Incorrect date format, enter date again in the format YYYY-MM-DD: ";
        }
        else
        {
            int dateAsNumber = changeDateFromTextToNumber(dateAsText);
            if (!isDateCorrect(dateAsNumber))
            {
                cout << "Incorrect date, enter date again: ";
            }
            else if (!isDateInAllowedRange(dateAsNumber))
            {
                cout << "Date is out of allowable range. Enter a date between " << changeDateFromNumberToText(MINIMUM_DATE);
                cout << " and " << changeDateFromNumberToText(TODAYS_DATE) << " : ";
            }
            else
            {
                date = dateAsNumber;
            }
        }

    }
    while (date == 0);
    return date;
}

int DateManager::changeDateFromTextToNumber (string dateAsText)
{
    int year = AuxiliaryMethods::convertStringToInt(dateAsText.substr(0,4));
    int month = AuxiliaryMethods::convertStringToInt(dateAsText.substr(5,2));
    int day = AuxiliaryMethods::convertStringToInt(dateAsText.substr(8,2));

    return year * 10000 + month * 100 + day;
}

string DateManager::changeDateFromNumberToText (int date)
{
    int year = extractYearFromDate(date);
    int month = extractMonthFromDate(date);
    int day = extractDayFromDate(date);

    string dateAsText = AuxiliaryMethods::convertIntToString(year);
    dateAsText += "-";
    dateAsText += AuxiliaryMethods::convertIntToString(month/10);
    dateAsText += AuxiliaryMethods::convertIntToString(month%10);
    dateAsText += "-";
    dateAsText += AuxiliaryMethods::convertIntToString(day/10);
    dateAsText += AuxiliaryMethods::convertIntToString(day%10);

    return dateAsText;
}

bool DateManager::isDateFormatCorrect(string dateAsText)
{
    bool correctDateFormat = true;
    if (dateAsText.length() != 10)
    {
        correctDateFormat = false;
    }
    else
    {
        for (int characterPosition = 0; characterPosition < 10; characterPosition++)
        {
            if (characterPosition == 4 || characterPosition == 7)
            {
                if(dateAsText[characterPosition] != '-')
                {
                    correctDateFormat = false;
                    break;
                }
            }
            else
            {
                if(!isdigit(dateAsText[characterPosition]))
                {
                    correctDateFormat = false;
                    break;
                }
            }
        }
    }
    return correctDateFormat;
}

int DateManager::extractDayFromDate(int date)
{
    return date%100;
}

int DateManager::extractMonthFromDate(int date)
{
    return (date/100)%100;
}

int DateManager::extractYearFromDate(int date)
{
    return date/10000;
}

bool DateManager::isYearLeap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}

int DateManager::numberOfDaysInMonth(int date)
{
    int year = extractYearFromDate(date);
    int month = extractMonthFromDate(date);
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if (month == 2)
        {
            if (isYearLeap(year))
                return 29;
            else
                return 28;
        }
    else
        return 31;
}

bool DateManager::isDateCorrect(int date)
{
    int month = extractMonthFromDate(date);
    int day = extractDayFromDate(date);

    bool correctDate = false;

    if (month >= 1 && month <= 12)
    {
        if (day >= 1 && day <= numberOfDaysInMonth(date))
            {
                correctDate = true;
            }
    }

    return correctDate;
}

bool DateManager::isDateInAllowedRange(int date)
{
    int dateOfLastDayOfCurrentMonth = findLastDayOfMonth(TODAYS_DATE);
    bool dateIsInRange = false;

    if (date >= MINIMUM_DATE && date <= dateOfLastDayOfCurrentMonth)
    {
        dateIsInRange = true;
    }

    return dateIsInRange;
}

int DateManager::findLastDayOfMonth(int date)
{
    int dateSearchedFor = (date / 100) * 100 + numberOfDaysInMonth(date);
    return dateSearchedFor;
}

int DateManager::findFirstDayOfCurrentMonth()
{
    int dateSearchedFor = (TODAYS_DATE / 100) * 100 + 1;
    return dateSearchedFor;
}

int DateManager::findFirstDayOfPreviousMonth()
{
    int dateSearchedFor;
    int year = extractYearFromDate(TODAYS_DATE);
    int month = extractMonthFromDate(TODAYS_DATE);

    if (month != 1)
    {
        dateSearchedFor = year * 10000 + (month - 1) * 100 + 1;
    }
    else
    {
        dateSearchedFor = (year - 1) * 10000 + 12 * 100 + 1;
    }
    return dateSearchedFor;
}

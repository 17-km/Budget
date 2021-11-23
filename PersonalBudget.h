#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "CashFlowManager.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    CashFlowManager *cashFlowManager;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

public:
    PersonalBudget(string nameOfUsersFile, string incomesFileName, string expensesFileName);
    ~PersonalBudget();
    void registerUser();
    void displayAllUsers();
    void loginUser();
    void displayLoggedInUser();
    void changeLoggedInUserPassword();
    void logoutUser();

    void addIncome();
    void addExpense();
    void displayBudgetBalanceForCurrentMonth();
    void displayBudgetBalanceForPreviousMonth();
    void displayBudgetBalanceForSelectedPeriod();

    bool isUserLoggedIn();

    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();

};

#endif // PERSONALBUDGET_H

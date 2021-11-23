#include "PersonalBudget.h"

PersonalBudget::PersonalBudget(string nameOfUsersFile, string incomesFileName, string expensesFileName)
    : userManager(nameOfUsersFile), INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName)
{
    cashFlowManager = NULL;
}

PersonalBudget::~PersonalBudget()
{
    delete cashFlowManager;
    cashFlowManager = NULL;
}

void PersonalBudget::registerUser()
{
    userManager.registerUser();
}

void PersonalBudget::displayAllUsers()
{
    userManager.displayAllUsers();
}

void PersonalBudget::loginUser()
{
    userManager.loginUser();
    if (userManager.isUserLoggedIn())
    {
        cashFlowManager = new CashFlowManager(INCOMES_FILE_NAME, EXPENSES_FILE_NAME, userManager.getLoggedInUserId());
    }
}

void PersonalBudget::displayLoggedInUser()
{
    userManager.displayLoggedInUser();
}

void PersonalBudget::changeLoggedInUserPassword()
{
    userManager.changeLoggedInUserPassword();
}

void PersonalBudget::logoutUser()
{
    userManager.logoutUser();
    delete cashFlowManager;
    cashFlowManager = NULL;
}

void PersonalBudget::addIncome()
{
    if (userManager.isUserLoggedIn())
    {
        cashFlowManager->addIncome();
    }
    else
    {
        cout << "To add income, please log in first" << endl;
        system("pause");
    }
}

void PersonalBudget::addExpense()
{
    if (userManager.isUserLoggedIn())
    {
        cashFlowManager->addExpense();
    }
    else
    {
        cout << "To add expense, please log in first" << endl;
        system("pause");
    }
}

void PersonalBudget::displayBudgetBalanceForCurrentMonth()
{
    if (userManager.isUserLoggedIn())
    {
        cashFlowManager->displayBudgetBalanceForCurrentMonth();
    }
    else
    {
        cout << "To see your budget balance, please log in first" << endl;
        system("pause");
    }
}

void PersonalBudget::displayBudgetBalanceForPreviousMonth()
{
    if (userManager.isUserLoggedIn())
    {
        cashFlowManager->displayBudgetBalanceForPreviousMonth();
    }
    else
    {
        cout << "To see your budget balance, please log in first" << endl;
        system("pause");
    }
}

void PersonalBudget::displayBudgetBalanceForSelectedPeriod()
{
    if (userManager.isUserLoggedIn())
    {
        cashFlowManager->displayBudgetBalanceForSelectedPeriod();
    }
    else
    {
        cout << "To see your budget balance, please log in first" << endl;
        system("pause");
    }
}

char PersonalBudget::selectOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register" << endl;
    cout << "2. Log in" << endl;
    cout << "9. Exit program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}

char PersonalBudget::selectOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USERS MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Budget balance for current month" << endl;
    cout << "4. Budget balance for previous month" << endl;
    cout << "5. Budget balance for selected period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}

bool PersonalBudget::isUserLoggedIn()
{
    if (userManager.getLoggedInUserId() > 0)
        return true;
    else
        return false;
}

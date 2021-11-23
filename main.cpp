#include <iostream>
#include "PersonalBudget.h"

using namespace std;

#include <iostream>

int main()
{
    PersonalBudget personalBudget("users.xml","incomes.xml","expenses.xml");
    char choice;

    while (true)
    {
        if (personalBudget.isUserLoggedIn())
        {
            choice = personalBudget.selectOptionFromUserMenu();

            switch (choice)
            {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.displayBudgetBalanceForCurrentMonth();
                break;
            case '4':
                personalBudget.displayBudgetBalanceForPreviousMonth();
                break;
            case '5':
                personalBudget.displayBudgetBalanceForSelectedPeriod();
                break;
            case '6':
                personalBudget.changeLoggedInUserPassword();
                break;
            case '7':
                personalBudget.logoutUser();
                break;
            }
        }
        else
        {
            choice = personalBudget.selectOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                personalBudget.registerUser();
                break;
            case '2':
                personalBudget.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in the menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }

    return 0;
}

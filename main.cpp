#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("Users.xml");
    personalBudget.registerUser();
    personalBudget.registerUser();
    personalBudget.displayAllUsers();
    personalBudget.loginUser();
    personalBudget.displayLoggedInUser();
    personalBudget.logoutUser();
    personalBudget.displayLoggedInUser();
    personalBudget.loginUser();
    personalBudget.displayLoggedInUser();
    personalBudget.displayAllUsers();
    personalBudget.changeLoggedInUserPassword();
    personalBudget.displayLoggedInUser();
    personalBudget.displayAllUsers();
    personalBudget.logoutUser();
    personalBudget.displayLoggedInUser();
    personalBudget.displayAllUsers();
    personalBudget.registerUser();
    personalBudget.displayLoggedInUser();
    personalBudget.displayAllUsers();

}

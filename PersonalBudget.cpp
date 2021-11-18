#include "PersonalBudget.h"

PersonalBudget::PersonalBudget(string nameOfUsersFile)
    : userManager(nameOfUsersFile)
{

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
}

bool PersonalBudget::isUserLoggedIn()
{
    if (userManager.getLoggedInUserId() > 0)
        return true;
    else
        return false;
}

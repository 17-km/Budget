#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;

public:
    PersonalBudget(string nameOfUsersFile);
    void registerUser();
    void displayAllUsers();
    void loginUser();
    void displayLoggedInUser();
    void changeLoggedInUserPassword();
    void logoutUser();

    bool isUserLoggedIn();

};

#endif // PERSONALBUDGET_H

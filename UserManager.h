#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector<User> users;

    User enterDataOfNewUser();
    int getIdOfNewUser();
    bool doesLoginExist(string login);
    int findUserId();

public:
    UserManager();
    void registerUser();
    void displayAllUsers();
    void loginUser();
    void displayLoggedInUser();
    void changeLoggedInUserPassword();
    void logoutUser();
    int getLoggedInUserId();
    bool isUserLoggedIn();
};

#endif // USERMANAGER_H

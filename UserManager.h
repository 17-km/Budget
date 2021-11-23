#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "UsersFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector<User> users;
    UsersFile usersFile;

    User enterDataOfNewUser();
    int getIdOfNewUser();
    bool doesLoginExist(string login);
    int findUserId();

public:
    UserManager(string nameOfUsersFile);
    void registerUser();
    void displayAllUsers();
    void loginUser();
    void displayLoggedInUser();
    void changeLoggedInUserPassword();
    void logoutUser();
    bool isUserLoggedIn();
    int getLoggedInUserId();
};

#endif // USERMANAGER_H

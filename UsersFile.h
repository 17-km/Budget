#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "TextFile.h"

using namespace std;

class UsersFile : public TextFile
{
public:
    UsersFile(string nameOfUsersFile): TextFile(nameOfUsersFile){};
    void addUserToFile(User user);
    vector<User> loadUsersFromFile();
    void updateUsersPasswordInFile(string userLogin, string newPassword);
};

#endif // USERSFILE_H

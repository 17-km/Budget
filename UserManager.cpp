#include "UserManager.h"

UserManager::UserManager(string nameOfUsersFile)
    : usersFile(nameOfUsersFile)
{
    loggedInUserId = 0;
    users = usersFile.loadUsersFromFile();
}

void UserManager::registerUser()
{
    system("cls");
    cout << " >>> USER REGISTER <<<" << endl << endl;
    User user = enterDataOfNewUser();

    users.push_back(user);

    usersFile.addUserToFile(user);

    cout << endl << "User account has been created successfully" << endl << endl;
    system("pause");
}

User UserManager::enterDataOfNewUser()
{
    User user;

    user.setId(getIdOfNewUser());

    string name;
    cout << "Enter your name: ";
    name = AuxiliaryMethods::loadTextLine();
    name = AuxiliaryMethods::changeFirstLetterToUppercaseAndRestToLowercase(name);
    user.setName(name);

    string surname;
    cout << "Enter your surname: ";
    surname = AuxiliaryMethods::loadTextLine();
    surname = AuxiliaryMethods::changeFirstLetterToUppercaseAndRestToLowercase(surname);
    user.setSurname(surname);

    string login;

    do
    {
        cout << "Set your login: ";
        login = AuxiliaryMethods::loadTextLine();
        user.setLogin(login);
    }
    while (doesLoginExist(user.getLogin()) == true);

    string password;
    cout << "Set your password: ";
    password = AuxiliaryMethods::loadTextLine();
    user.setPassword(password);

    return user;
}

int UserManager::getIdOfNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::doesLoginExist(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "The user login you entered already exist. Please enter a different login." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::displayAllUsers()
{
    for (int i = 0; i < users.size(); i++)
    {
        cout << users[i].getId() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
    system("pause");
}

void UserManager::loginUser()
{
    loggedInUserId = findUserId();
}

int UserManager::findUserId()
{
    system("cls");
    cout << " >>> USER LOGIN <<<" << endl << endl;
    User user;
    string login = "", password = "";

    cout << "Type login: ";
    login = AuxiliaryMethods::loadTextLine();

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                cout << "Type password. Remaining attempts: " << numberOfAttempts << ": ";
                password = AuxiliaryMethods::loadTextLine();

                if (users[i].getPassword() == password)
                {
                    cout << endl << "You have successfully logged in." << endl << endl;
                    system("pause");
                    return users[i].getId();
                }
            }
            cout << "A wrong password has been entered 3 times. User login failed." << endl;
            system("pause");
            return 0;
        }
    }

    cout << "The user login you entered does not exist." << endl << endl;
    system("pause");
    return 0;
}

void UserManager::displayLoggedInUser()
{
    if (loggedInUserId == 0)
        cout << "No user is logged in." << endl;
    else
    {
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getId() == loggedInUserId)
            {
                cout << "Logged in user:" << endl;
                cout << users[i].getId() << endl;
                cout << users[i].getName() << endl;
                cout << users[i].getSurname() << endl;
                cout << users[i].getLogin() << endl;
                cout << users[i].getPassword() << endl;
            }
        }
    }
    system("pause");
}

void UserManager::changeLoggedInUserPassword()
{
    system("cls");
    cout << " >>> USER PASSWORD CHANGE <<<" << endl << endl;
    string newPassword = "";
    cout << "Type in new password: ";
    newPassword = AuxiliaryMethods::loadTextLine();

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getId() == loggedInUserId)
        {
            users[i].setPassword(newPassword);
            usersFile.updateUsersPasswordInFile(users[i].getLogin(),newPassword);
            cout << "Password has been changed successfully." << endl << endl;
            system("pause");
        }
    }
}

void UserManager::logoutUser()
{
    loggedInUserId = 0;
    cout << "You have successfully logged out." << endl;
    system("pause");
}

int UserManager::getLoggedInUserId()
{
    return loggedInUserId;
}

bool UserManager::isUserLoggedIn()
{
    if (loggedInUserId > 0)
        return true;
    else
        return false;
}

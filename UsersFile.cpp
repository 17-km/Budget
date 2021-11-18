#include "UsersFile.h"

using namespace std;

void UsersFile::addUserToFile(User user)
{
    CMarkup xmlFile;
    bool fileExist = xmlFile.Load(FILE_NAME);

    if (fileExist || isFileEmpty(xmlFile))
    {
        if (!fileExist)
        {
            xmlFile.AddElem("USERS");
        }
        xmlFile.FindElem();
        xmlFile.IntoElem();
        xmlFile.AddElem("USER");
        xmlFile.IntoElem();
        xmlFile.AddElem("ID",user.getId());
        xmlFile.AddElem("NAME",user.getName());
        xmlFile.AddElem("SURNAME",user.getSurname());
        xmlFile.AddElem("LOGIN",user.getLogin());
        xmlFile.AddElem("PASSWORD",user.getPassword());
        xmlFile.OutOfElem();
        xmlFile.Save(FILE_NAME);
    }
    else
        cout << "Failed to open file " << FILE_NAME << " and write data to it." << endl;
}

vector<User> UsersFile::loadUsersFromFile()
{
    vector<User> users;
    CMarkup xmlFile;

    bool fileExist = xmlFile.Load(FILE_NAME);

    if (fileExist)
    {
    xmlFile.FindElem();
    xmlFile.IntoElem();
    while (xmlFile.FindElem("USER"))
    {
        User user;
        xmlFile.IntoElem();
        xmlFile.FindElem("ID");
        user.setId(AuxiliaryMethods::convertStringToInt(xmlFile.GetData()));
        xmlFile.FindElem("NAME");
        user.setName(xmlFile.GetData());
        xmlFile.FindElem("SURNAME");
        user.setSurname(xmlFile.GetData());
        xmlFile.FindElem("LOGIN");
        user.setLogin(xmlFile.GetData());
        xmlFile.FindElem("PASSWORD");
        user.setPassword(xmlFile.GetData());
        xmlFile.OutOfElem();
        users.push_back(user);
    }
    }

    return users;
}

void UsersFile::updateUsersPasswordInFile(string userLogin, string newPassword)
{
    CMarkup xmlFile;
    bool fileExist = xmlFile.Load(FILE_NAME);
    if (fileExist)
    {
    xmlFile.FindElem();
    xmlFile.IntoElem();
    while (xmlFile.FindElem("USER"))
    {
        User user;
        xmlFile.FindChildElem("LOGIN");
        if (xmlFile.GetChildData() == userLogin)
            break;
    }

    xmlFile.FindChildElem("PASSWORD");
    xmlFile.SetChildData(newPassword);
    xmlFile.Save(FILE_NAME);
    }
    else
        cout << "Failed to open file " << FILE_NAME << " and updagte it." << endl;
}

#ifndef CASHFLOW_H
#define CASHFLOW_H

#include <iostream>

using namespace std;

class CashFlow
{
    int id;
    int usersId;
    int date;
    string description;
    double amount;

public:
    void setId(int newId);
    void setUsersId(int newUsersId);
    void setDate(int newDate);
    void setDescription(string newDescription);
    void setAmount(double newAmount);

    int getId();
    int getUsersId();
    int getDate();
    string getDescription();
    double getAmount();
};

#endif // CASHFLOW_H

#include "CashFlow.h"

void CashFlow::setId(int newId)
{
    if (newId >= 0)
        id = newId;
}
void CashFlow::setDate(int newDate)
{
    date = newDate;
}
void CashFlow::setDescription(string newDescription)
{
    description = newDescription;
}
void CashFlow::setAmount(double newAmount)
{
    amount = newAmount;
}

int CashFlow::getId()
{
    return id;
}
int CashFlow::getDate()
{
    return date;
}
string CashFlow::getDescription()
{
    return description;
}
double CashFlow::getAmount()
{
    return amount;
}

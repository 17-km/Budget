#include "CashFlowManager.h"

CashFlowManager::CashFlowManager(int loggedInUserId)
    : LOGGED_IN_USER_ID(loggedInUserId)
    {
        int maxIncomeId = 0;
        int maxExpenseId = 0;
    }


bool CashFlowManager::isCashFlowEarlier(CashFlow &earlierCashFlow, CashFlow &laterCashFlow)
{
    return earlierCashFlow.getDate() < laterCashFlow.getDate();
}

void CashFlowManager::addIncome()
{
    CashFlow newIncome;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    newIncome.setId(++maxIncomeId);
    newIncome.setUsersId(LOGGED_IN_USER_ID);
    cout << "Enter description of income (e.g. salary, interest on deposits, Internet sales, etc.): ";
    newIncome.setDescription(AuxiliaryMethods::loadTextLine());
    newIncome.setDate(getUsersDate());
    newIncome.setAmount(getAmountOfCashFlow());
    incomes.push_back(newIncome);

}

void CashFlowManager::sortIncomesVectorByDate()
{
    sort(incomes.begin(), incomes.end(), &isCashFlowEarlier);
}

double CashFlowManager::getAmountOfCashFlow()
{
    int amount;
    string amountAsText;
    cout << "Enter amount, be accurate to two decimal places: ";
    amountAsText = AuxiliaryMethods::replaceCommaWithDot(AuxiliaryMethods::loadTextLine());
    amount = roundToTwoDecimalPlaces(AuxiliaryMethods::convertStringToDouble(amountAsText));

    return amount;
}

double CashFlowManager::roundToTwoDecimalPlaces(double amount)
{
    return round(amount * 100) / 100;
}


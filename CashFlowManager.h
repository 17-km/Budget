#ifndef CASHFLOWMANAGER_H
#define CASHFLOWMANAGER_H

#include <iostream>
#include <vector>
#include <math.h>

#include "CashFlow.h"
#include "DateManager.h"

using namespace std;

class CashFlowManager : public DateManager
{
    const int LOGGED_IN_USER_ID;
    vector<CashFlow> incomes;
    vector<CashFlow> expenses;
    void sortIncomesVectorByDate();
    CashFlow enterDataOfNewCashFlow();
    void displayCashFlowData();
    int maxIncomeId;
    int maxExpenseId;
    double getAmountOfCashFlow();
    double roundToTwoDecimalPlaces(double amount);
    static bool isCashFlowEarlier(CashFlow &earlierCashFlow, CashFlow &laterCashFlow);

public:
    CashFlowManager(int loggedInUserId);
    void addIncome();
    void addExpense();
    void displayCashFlowsForGiverPreriod(int startDate, int endDate);
};

#endif // CASHFLOWMANAGER_H

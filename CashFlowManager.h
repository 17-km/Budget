#ifndef CASHFLOWMANAGER_H
#define CASHFLOWMANAGER_H

#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

#include "CashFlow.h"
#include "DateManager.h"
#include "CashFlowsFile.h"

using namespace std;

class CashFlowManager : public DateManager
{
    const int LOGGED_IN_USER_ID;
    vector<CashFlow> incomes;
    vector<CashFlow> expenses;
    CashFlowsFile incomesFile;
    CashFlowsFile expensesFile;

    void sortCashFlowsVectorByDate(vector<CashFlow> &cashFlows);
    CashFlow enterDataOfNewCashFlow();
    void displayCashFlowData();
    int maxIncomeId;
    int maxExpenseId;
    double getAmountOfCashFlow();
    double roundToTwoDecimalPlaces(double amount);
    static bool isCashFlowEarlier(CashFlow &earlierCashFlow, CashFlow &laterCashFlow);
    double displayCashFlowsForGiverPreriod(int startDate, int endDate, vector<CashFlow> &cashFlows);
    void displayBudgetBalanceForGivenPeriod(int startDate, int endDate);

public:
    CashFlowManager(string incomesFileName, string expensesFileName, int loggedInUserId);
    void addIncome();
    void addExpense();
    void displayBudgetBalanceForCurrentMonth();
    void displayBudgetBalanceForPreviousMonth();
    void displayBudgetBalanceForSelectedPeriod();

};

#endif // CASHFLOWMANAGER_H

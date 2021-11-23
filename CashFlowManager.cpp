#include "CashFlowManager.h"

CashFlowManager::CashFlowManager(int loggedInUserId)
    : LOGGED_IN_USER_ID(loggedInUserId)
    {
        int maxIncomeId = 0;
        int maxExpenseId = 0;
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
    sortCashFlowsVectorByDate(incomes);
}

void CashFlowManager::addExpense()
{
    CashFlow newExpense;
    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    newExpense.setId(++maxExpenseId);
    newExpense.setUsersId(LOGGED_IN_USER_ID);
    cout << "Enter description of expense (e.g. food, restaurant, housing, transport, etc.): ";
    newExpense.setDescription(AuxiliaryMethods::loadTextLine());
    newExpense.setDate(getUsersDate());
    newExpense.setAmount(-getAmountOfCashFlow());
    expenses.push_back(newExpense);
    sortCashFlowsVectorByDate(expenses);
}

double CashFlowManager::getAmountOfCashFlow()
{
    int amount;
    string amountAsText;
    cout << "Enter amount, be accurate to two decimal places: ";
    amountAsText = AuxiliaryMethods::replaceCommaWithDot(AuxiliaryMethods::loadTextLine());
    amount = abs(roundToTwoDecimalPlaces(AuxiliaryMethods::convertStringToDouble(amountAsText)));

    return amount;
}

double CashFlowManager::roundToTwoDecimalPlaces(double amount)
{
    return round(amount * 100) / 100;
}

bool CashFlowManager::isCashFlowEarlier(CashFlow &earlierCashFlow, CashFlow &laterCashFlow)
{
    return earlierCashFlow.getDate() < laterCashFlow.getDate();
}

void CashFlowManager::sortCashFlowsVectorByDate(vector<CashFlow> &cashFlows)
{
    sort(cashFlows.begin(), cashFlows.end(), &isCashFlowEarlier);
}

double CashFlowManager::displayCashFlowsForGiverPreriod(int startDate, int endDate, vector<CashFlow> &cashFlows)
{
    double totalAmountOfCashFlows = 0;
    for (int i = 0; i < cashFlows.size(); i++)
    {
        if(cashFlows[i].getDate() >= startDate)
        {
            if(cashFlows[i].getDate() <= endDate)
            {
                cout.width(15);
                cout << right << fixed << setprecision(2) << showpos << cashFlows[i].getAmount();
                cout << '\t' << '\t';
                cout.width(10);
                cout << changeDateFromNumberToText(cashFlows[i].getDate());
                cout << cashFlows[i].getDescription() << endl;
                totalAmountOfCashFlows += cashFlows[i].getAmount();
            }
            else
            {
                break;
            }
        }
    }
    return totalAmountOfCashFlows;
}

void CashFlowManager::displayBudgetBalanceForGivenPeriod(int startDate, int endDate)
{
    double budgetBalance = 0;

    cout << " >>> BUDGET BALANCE FROM " << changeDateFromNumberToText(startDate) << " TO " << changeDateFromNumberToText(endDate) << " <<<" << endl << endl;

    cout << " ---------- INCOMES ---------- " << endl;
    cout.width(15);
    cout << right << "AMOUUNT:";
    cout << '\t' << '\t';
    cout.width(10);
    cout << "DATE: ";
    cout << "DESCRIPTION: " << endl;
    budgetBalance += displayCashFlowsForGiverPreriod(startDate,endDate,incomes);

    cout << endl;

    cout << " ---------- EXPENSES ---------- " << endl;
    cout.width(15);
    cout << right << "AMOUUNT:";
    cout << '\t' << '\t';
    cout.width(10);
    cout << "DATE: ";
    cout << "DESCRIPTION: " << endl;
    budgetBalance += displayCashFlowsForGiverPreriod(startDate,endDate,expenses);

    cout << endl << endl;

    cout << "Your total balance of incomes and expenses is: " << fixed << setprecision(2) << showpos << budgetBalance << endl;;
    if (budgetBalance > 0)
    {
        cout << "You saved your money. Great job!" << endl;
    }
    else if (budgetBalance < 0)
    {
        cout << "You spent more than you earned. Tighten your belt ;)" << endl;
    }
    else
    {
        cout << "you spent exactly as much as you earned. Tighten your belt ;)" << endl;
    }
}

void CashFlowManager::displayBudgetBalanceForCurrentMonth()
{
    int startDate = findFirstDayOfCurrentMonth();
    int endDate = findLastDayOfMonth(startDate);
    displayBudgetBalanceForGivenPeriod(startDate,endDate);
}

void CashFlowManager::displayBudgetBalanceForPreviousMonth()
{
    int startDate = findFirstDayOfPreviousMonth();
    int endDate = findLastDayOfMonth(startDate);
    displayBudgetBalanceForGivenPeriod(startDate,endDate);
}

void CashFlowManager::displayBudgetBalanceForSelectedPeriod()
{
    system("cls");
    cout << " >>> CHOSE BUDGT BALANCE RANGE <<<" << endl << endl;
    cout << " --- FIRST DATE OF BALANCE ---";
    int startDate = getUsersDate();
    cout << " --- LAST DATE OF BALANCE ---";
    int endDate = getUsersDate();

    if (endDate >= startDate)
    {
        displayBudgetBalanceForGivenPeriod(startDate,endDate);
    }
    else
    {
        cout << endl << endl << "Incorrect time range!";
    }
}


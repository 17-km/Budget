#ifndef CASHFLOWSFILE_H
#define CASHFLOWSFILE_H

#include <iostream>
#include <vector>
//#include <fstream>
//#include <cstdlib>

#include "CashFlow.h"
#include "AuxiliaryMethods.h"
#include "TextFile.h"
#include "DateManager.h"

using namespace std;

class CashFlowsFile : public TextFile
{
    int lastCashFlowId;
public:
    CashFlowsFile(string nameOfCashFlowsFile): TextFile(nameOfCashFlowsFile){};
    bool addCashFlowToFile(CashFlow cashFlow);
    vector<CashFlow> loadCashFlowsFromFile(int loggedInUserId);
    int getLastCashFlowId();
};

#endif // CASHFLOWSFILE_H

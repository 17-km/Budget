#include "CashFlowsFile.h"

using namespace std;

bool CashFlowsFile::addCashFlowToFile(CashFlow cashFlow)
{
    CMarkup xmlFile;
    bool fileExist = xmlFile.Load(FILE_NAME);

    if (fileExist || isFileEmpty(xmlFile))
    {
        if (!fileExist)
        {
            xmlFile.AddElem("CASHFLOWS");
        }
        xmlFile.FindElem();
        xmlFile.IntoElem();
        xmlFile.AddElem("CASHFLOW");
        xmlFile.IntoElem();
        xmlFile.AddElem("USERID",cashFlow.getUsersId());
        xmlFile.AddElem("ID",cashFlow.getId());
        xmlFile.AddElem("DATE",DateManager::changeDateFromNumberToText(cashFlow.getDate()));
        xmlFile.AddElem("DESCRIPTION",cashFlow.getDescription());
        xmlFile.AddElem("AMOUNT",AuxiliaryMethods::convertDoubleToString(cashFlow.getAmount()));
        xmlFile.OutOfElem();
        xmlFile.Save(FILE_NAME);

        lastCashFlowId++;
        return true;
    }

    return false;
}

vector<CashFlow> CashFlowsFile::loadCashFlowsOfLoggedInUserFromFile(int loggedInUserId)
{
    vector<CashFlow> cashFlows;
    CMarkup xmlFile;

    bool fileExist = xmlFile.Load(FILE_NAME);

    if (fileExist)
    {
    xmlFile.FindElem();
    xmlFile.IntoElem();
    while (xmlFile.FindElem("CASHFLOW"))
    {
        CashFlow cashFlow;
        xmlFile.IntoElem();
        xmlFile.FindElem("USERID");
        int loadedUserId = AuxiliaryMethods::convertStringToInt(xmlFile.GetData());
        if (loadedUserId == loggedInUserId)
        {
        cashFlow.setUsersId(loadedUserId);
        xmlFile.FindElem("ID");
        cashFlow.setId(AuxiliaryMethods::convertStringToInt(xmlFile.GetData()));
        xmlFile.FindElem("DATE");
        cashFlow.setDate(DateManager::changeDateFromTextToNumber(xmlFile.GetData()));
        xmlFile.FindElem("DESCRIPTION");
        cashFlow.setDescription(xmlFile.GetData());
        xmlFile.FindElem("AMOUNT");
        cashFlow.setAmount(AuxiliaryMethods::convertStringToDouble(xmlFile.GetData()));
        cashFlows.push_back(cashFlow);
        }
        xmlFile.OutOfElem();
    }
    xmlFile.FindChildElem("ID");
    lastCashFlowId = AuxiliaryMethods::convertStringToInt(xmlFile.GetChildData());
    }
    else
    {
        lastCashFlowId = 0;
    }

    return cashFlows;
}

int CashFlowsFile::getLastCashFlowId()
{
    return lastCashFlowId;
}


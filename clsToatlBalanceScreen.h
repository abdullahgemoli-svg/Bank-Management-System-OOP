#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUtil.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

using namespace std;

class clsToatlBalanceScreen:protected clsScreen
{

    static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << setw(25) << left << "" << "|" << left << setw(15) << Client.AccountNumber();
        cout << "| " << left << setw(40) << Client.FullName();
        cout << "| " << left << setw(12) << Client.AccountBalance;

    }


public:

    static void ShowTotallBalancesScreen()
    {
        vector< clsBankClient>vClients = clsBankClient::GetClientsList();

        string Tixte = "\tTotalBalances List Screen";
        string SubTitle = "\t     (" + to_string(vClients.size()) + ")  Client(s)..\n";
        _DrewScreenHeader(Tixte, SubTitle);



        cout << setw(8) << left <<
            "\n\t_____________________________________________________________________________________________________\n\n";
        cout << setw(25) << left << "" << "|" << left << setw(15) << "AccountNumber";
        cout << "| " << left << setw(40) << " Client Name";
        cout << "| " << left << setw(12) << " Balance";
        cout << setw(8) << left <<
            "\n\t_____________________________________________________________________________________________________\n\n";


        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)

            cout << "\t\t\t\t No CLients Available In the System  ! ";
        else
            for (clsBankClient Client : vClients)
            {
                _PrintClientRecordBalanceLine(Client);
                cout << "\n";
            }
        cout << setw(8) << left <<
            "\n\t_____________________________________________________________________________________________________\n\n";
        cout << "\t\t\t\t\t  Total Balance = " << TotalBalances << endl;
        cout << "\t\t\t\t\t  (" << clsUtil::NumberToText(TotalBalances) << ")" << endl;
        

    }
};


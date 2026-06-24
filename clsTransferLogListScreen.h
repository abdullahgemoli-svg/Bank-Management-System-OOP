#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsTransferLogListScreen:protected clsScreen
{
private:

    static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransRecord)
    {
        cout << setw(8) << left << "" << "|" << left << setw(23) << TransRecord.DateTime;
        cout << "|" << setw(10) << left << TransRecord.SourceAccountNumber;
        cout << "|" << setw(10) << left << TransRecord.DestinationAccountNumber;
        cout << "|" << setw(11) << left << TransRecord.Amount;
        cout << "|" << setw(11) << left << TransRecord.srcBalanceAfter;
        cout << "|" << setw(11) << left << TransRecord.destBalanceAfter;
        cout << "|" << setw(12) << left << TransRecord.UserName;

    }



public:

    static  void ShowTransfeLogListScreen()
    {

        if (!CheckAccessRights(clsUsres::enPermissions::pAddNewClient))
        {
            return;
        }

        vector< clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();
        string Title = "\t Transfer Log List Screen";
        string SubTitle = "\t     (" + to_string(vTransferLogRecord.size()) + ")  Record(s)..\n";

        _DrewScreenHeader(Title, SubTitle);

        cout << setw(8) << left <<
            "\n\t_____________________________________________________________________________________________________\n\n";
        cout << setw(8) << left << "" << "|" << left << setw(23) << "Date/Time ";
        cout << "| " << left << setw(10) << "s.Acct";
        cout << "| " << left << setw(10) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(10) << "User";

        cout << setw(8) << left <<
            "\n\t_____________________________________________________________________________________________________\n\n";


        if (vTransferLogRecord.size() == 0)

            cout << "\t\t\t\t No Login Available In the System  ! ";
        else
            for (clsBankClient::stTransferLogRecord Record : vTransferLogRecord)
            {
                _PrintTransferLogRecordLine(Record);
                cout << "\n";
            }

        cout << setw(8) << left <<
            "\n\t_____________________________________________________________________________________________________\n";

    }

};


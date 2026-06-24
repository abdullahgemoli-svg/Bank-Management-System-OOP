#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUsres.h"
#include"clsLoginScreen.h"

class clsLoginRegisterListScreen:protected clsScreen
{
private:

    static void _PrintLoginRegisterRecordLine(clsUsres::stLoginRegisterRecord LoginRegisterRecord)
    {
        cout << setw(8) << left << "" << "|" << left << setw(35) << LoginRegisterRecord.DateTime;
        cout << "|" << setw(20) << left << LoginRegisterRecord.UserName;
        cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
        cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;
    }


public:

    static  void ShowLoginRegisterScreen()
    {

        if (!CheckAccessRights(clsUsres::enPermissions::pAddNewClient))
        {
            return;
        }

        vector< clsUsres::stLoginRegisterRecord> vLoginRegisterRecord = clsUsres::GetLoginRegisterList(); 
        string Title = "\t Login Register List Screen";
        string SubTitle = "\t     (" + to_string(vLoginRegisterRecord.size()) + ")  Client(s)..\n";

        _DrewScreenHeader(Title, SubTitle);

        cout << setw(8) << left <<
            "\n\t_____________________________________________________________________________________________________\n\n";
        cout << setw(8) << left << "" << "|" << left << setw(35) << "Date/Time ";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << " Password";
        cout << "| " << left << setw(10) << " Permissions";
        cout << setw(8) << left <<
            "\n\t_____________________________________________________________________________________________________\n\n";


        if (vLoginRegisterRecord.size() == 0)

            cout << "\t\t\t\t No Login Available In the System  ! ";
        else
            for (clsUsres::stLoginRegisterRecord Record : vLoginRegisterRecord)
            {
                _PrintLoginRegisterRecordLine(Record);
                cout << "\n";
            }

        cout << setw(8) << left <<
            "\n\t_____________________________________________________________________________________________________\n";

    }
};


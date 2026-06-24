#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUsres.h"
using namespace std;

class clsListUserScreen:protected clsScreen
{
private:

    static void _PrintListUserLine(clsUsres User)
    {
        cout << setw(8) << left << "" << "|" << left << setw(15) << User.UserName;
        cout << "|" << setw(20) << left << User.FullName();
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(22) << left << User.Email;
        cout << "| " << setw(12) << left << User.Password;
        cout << "| " << setw(12) << left << User.Permissions;
    }

public:

    static  void ShowtsListUserScreen()
    {
        if (!CheckAccessRights(clsUsres::enPermissions::pAddNewClient))
        {
            return;
        }

        vector< clsUsres>vClients = clsUsres::GetUsersList();
        string Title = "\tUser List Screen";
        string SubTitle = "\t     (" + to_string(vClients.size()) + ")  Client(s)..\n";

        _DrewScreenHeader(Title, SubTitle);

        cout << setw(8) << left <<
            "\n\t_____________________________________________________________________________________________________\n\n";
        cout << setw(8) << left << "" << "|" << left << setw(15) << " UserName";
        cout << "| " << left << setw(20) << "FullName";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(22) << "Eamil";
        cout << "| " << left << setw(12) << " Password";
        cout << "| " << left << setw(12) << " Permissions";

        cout << setw(8) << left <<
            "\n\t_____________________________________________________________________________________________________\n\n";


        if (vClients.size() == 0)

            cout << "\t\t\t\t No Users Available In the System  ! ";
        else
            for (clsUsres Client : vClients)
            {
                _PrintListUserLine(Client);
                cout << "\n";
            }

        cout << setw(8) << left <<
            "\n\t_____________________________________________________________________________________________________\n";

    }
};


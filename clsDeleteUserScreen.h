#pragma once
#include<iostream>
#include"clsUsres.h"

#include"clsScreen.h"
#include"clsInputValidate.h"

using namespace std;
class clsDeleteUserScreen:protected clsScreen
{
private:

    static void _PrintUser(clsUsres User)
    {

        cout << "\n User card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUserName    : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";
    }

public:

    static void ShowDeleteUserScreen()
    {

        _DrewScreenHeader("\tDelete User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();

       /* if (UserName == "Admin")
        {
            cout << "\n You Can't Delete Admin \n ";
            return;
            
        }*/

        while (!clsUsres::IsUserExist(UserName))
        {
            cout << "\nUserName is Already Used, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUsres User = clsUsres::Find(UserName);
        _PrintUser(User);


        cout << "\nAre you sure you want to delete this User y/n?";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            if (User.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";
                _PrintUser(User);
            }

        }
    }

};


#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUsres.h"
#include"clsInputValidate.h"
using namespace std;

class clsFindUserScreen:protected clsScreen
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

    static void ShowFindUserScreen()
    {

        _DrewScreenHeader("\t Find User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUsres::IsUserExist(UserName))
        {
            cout << "\nUserName is Already Used, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUsres User = clsUsres::Find(UserName);


        if (!User.IsEmpty())
        {
            cout << "\n User Found:-)\n";

        }
        else
        {
            cout << "\n Usre was is not Found:-)\n";
        }
        _PrintUser(User);

    }
};


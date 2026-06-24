#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUsres.h"
#include"clsInputValidate.h"
using namespace std;

class clsUpdatUserScreen:protected clsScreen
{

private:

    static void _ReadUserInfo(clsUsres& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permissions: ";
        User.Permissions = _ReadPermissionsToSet();
    }

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

    static int _ReadPermissionsToSet()
    {
        int Permissions = 0;
        char Answer = 'n';

        cout << "\nDo you want to give full access? y/n ?";

        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\n Show Client List ? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUsres::enPermissions::PListClients;
        }
        cout << "\n Add New Clinet ? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUsres::enPermissions::pAddNewClient;
        }
        cout << "\n Delete Clinet ? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUsres::enPermissions::pDeleteClint;
        }
        cout << "\n Update Clinet ? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUsres::enPermissions::pUpdateClint;
        }
        cout << "\n Find Clinet ? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUsres::enPermissions::pFindCleint;
        }
        cout << "\n Transactions  ? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUsres::enPermissions::pTranactions;
        }
        cout << "\n Manage  Users ? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUsres::enPermissions::pManageUsers;
        }
        return Permissions;
    }

public:

    static void ShowUpdateUserScreen()
    {
        

            _DrewScreenHeader("\t Update User Screen");

            string UserName = "";

            cout << "\nPlease Enter UserName: ";
            UserName = clsInputValidate::ReadString();

            if (UserName == "Admin")
            {
                cout << "\n You Can't Update Admin \n ";
                return;

            }

            while (!clsUsres::IsUserExist(UserName))
            {
                cout << "\nUserName is Already Used, choose another one: ";
                UserName = clsInputValidate::ReadString();
            }

            clsUsres User = clsUsres::Find(UserName);
            _PrintUser(User);


            cout << "\nAre you sure you want to Update this User y/n?";
            char Answer = 'n';
            cin >> Answer;

            if (Answer == 'y' || Answer == 'Y')
            {
                cout << "\n User Update Info \n";
                cout << "___________________________\n";

                _ReadUserInfo(User);
            }

            clsUsres::enSaveResults SaveResult;

            SaveResult = User.Save();


            switch (SaveResult)
            {
            case clsUsres::enSaveResults::svSucceeded:
            {
                cout << "\n UserName Addeded Successfully :-)\n";
                _PrintUser(User);
                break;

            }
            case clsUsres::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError Name was not saved because it's Empty";
                break;
            }
            case clsUsres::enSaveResults::svFaildAccountNumberExists:
            {
                cout << " Error account was not saved because account number is used!\n";
                break;
            }
            }
    }


};


#pragma once
#include<iostream>
#include<string>
#include"clsUtil.h"
#include"clsPerson.h"
#include"clsString.h"

#include<vector>
#include<fstream>
#include"clsBankClient.h"

using namespace std;

class clsUsres :public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	
	bool _MarledForDelete = false;

    struct stLoginRegisterRecord;
    
    static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
    {
        stLoginRegisterRecord LoginRegisterRecord;

        vector<string> LoginRegisterDateLine = clsString::Split(Line, Seperator);
        LoginRegisterRecord.DateTime = LoginRegisterDateLine[0];
        LoginRegisterRecord.UserName = LoginRegisterDateLine[1];
        LoginRegisterRecord.Password = clsUtil::DecryptText(LoginRegisterDateLine[2]);
        LoginRegisterRecord.Permissions = stoi(LoginRegisterDateLine[3]);
        return LoginRegisterRecord;

    }

    string _PrepareLogInRecord(string Seperator = "#//#")
    {
        string LoginRecord = "";
        LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
        LoginRecord += UserName + Seperator;
        LoginRecord += clsUtil::EncryptText(Password) + Seperator;
        LoginRecord +=to_string( Permissions) + Seperator;
        return LoginRecord;
    }

    static clsUsres _ConvertLinetoUsersObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsUsres(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], clsUtil::DecryptText( vClientData[5]) , stoi(vClientData[6]));

    }

    static string _ConverUsersObjectToLine(clsUsres User, string Seperator = "#//#")
    {
        string UserRecord = "";
        UserRecord += User.FirstName + Seperator;
        UserRecord += User.LastName + Seperator;
        UserRecord += User.Email + Seperator;
        UserRecord += User.Phone + Seperator;
        UserRecord += User.UserName + Seperator;
        UserRecord += clsUtil::EncryptText(User.Password) + Seperator;
        UserRecord += to_string(User.Permissions);

        return UserRecord;
    }

    static  vector <clsUsres> _LoadUsersDataFromFile()
    {

        vector <clsUsres> vClients;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsUsres Client = _ConvertLinetoUsersObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static void _SaveUsersDataToFile(vector <clsUsres> vClients)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUsres C : vClients)
            {
                if (C.MarkedForDeleted() == false)
                {
                    DataLine = _ConverUsersObjectToLine(C);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }


    void _Update()
    {
        vector <clsUsres> _vUser;
        _vUser = _LoadUsersDataFromFile();

        for (clsUsres& C : _vUser)
        {
            if (C.UserName == UserName)
            {
                C = *this;
                break;
            }

        }

        _SaveUsersDataToFile(_vUser);

    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConverUsersObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsUsres _GetEmptyUsersObject()
    {
        return clsUsres(enMode::EmptyMode, "", "", "", "", "", "",0 );
    }

    
public:

    enum enPermissions
    {
        eAll = -1, PListClients = 1, pAddNewClient = 2, pDeleteClint = 4,
        pUpdateClint = 8, pFindCleint = 16, pTranactions = 32, pManageUsers = 64, pLoginRegister = 128
    };

    struct stLoginRegisterRecord
    {
        string DateTime;
        string UserName;
        string Password;
        int Permissions;

    };

    clsUsres(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string UserName, string Password,
        int Permissions) :

        clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;

    }


    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }


    bool MarkedForDeleted()
    {
        return _MarledForDelete;
    }


    string GetUserName()
    {
        return _UserName;
    }

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }
    __declspec(property(get = GetUserName, put = SetUserName))string UserName;


    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }

    __declspec(property(get = GetPassword, put = SetPassword))string Password;

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermissions()
    {
        return _Permissions;
    }
    __declspec(property(get = GetPermissions, put = SetPermissions))int Permissions;

    static clsUsres Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUsres User = _ConvertLinetoUsersObject(Line);
                if (User.UserName == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUsersObject();
    }

    static clsUsres Find(string UserName,string Password)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {
           
            string Line;
            while (getline(MyFile, Line))
            {
                
                clsUsres User = _ConvertLinetoUsersObject(Line);
                
                if (User.UserName == UserName && User.Password == Password)
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUsersObject();

    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {

            return enSaveResults::svFaildEmptyObject;
        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }
        case enMode::AddNewMode:
        {
            if (clsUsres::IsUserExist(UserName))
            {
                return enSaveResults::svFaildAccountNumberExists;

            }
            else
            {
                _AddNew();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;

            }

        }


        }

        return svFaildEmptyObject;

    }

    static bool IsUserExist(string UserName)
    {

        clsUsres Client1 = clsUsres::Find(UserName);
        return (!Client1.IsEmpty());
    }

    bool Delete()
    {
        vector<clsUsres>_vUser;
        _vUser = _LoadUsersDataFromFile();

        for (clsUsres& C : _vUser)
        {
            if (C.UserName == UserName )
            {
                C._MarledForDelete = true;
                break;
            }
        }
        _SaveUsersDataToFile(_vUser);

        *this = _GetEmptyUsersObject();

        return true;
    }

    static clsUsres GetAddNewUserObject(string UserName)
    {
        return clsUsres(enMode::AddNewMode, "", "", "",  "", UserName, "", 0);

    }

    static vector<clsUsres> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }

    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this->Permissions == enPermissions::eAll)
            return true;
        if ((Permission & this->Permissions) == Permission)
            return true;
        else
            return false;

    }

    void RegisterLogIn()
    {
        string stDataLine = _PrepareLogInRecord();
        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static vector<stLoginRegisterRecord>GetLoginRegisterList()
    {
        vector <stLoginRegisterRecord> vLoginRegisterRecord;

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            stLoginRegisterRecord LoginRegisterRecord;

            while (getline(MyFile, Line))
            {
                LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

                vLoginRegisterRecord.push_back(LoginRegisterRecord);
            }

            MyFile.close();
        }
        return vLoginRegisterRecord;
    }

};


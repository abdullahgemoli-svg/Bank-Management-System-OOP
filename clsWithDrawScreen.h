#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
class clsWithDrawScreen:protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	static string _ReadAccountNumer()
	{
		string AccountNumber;
		cout << "\nPlease Enter  AccountNumber: ";
		getline(cin >> ws, AccountNumber);
		return AccountNumber;
	}


public:

	static void ShowWithDrawScreen()
	{
		_DrewScreenHeader("\tDeposit Screen");


		vector<clsBankClient>vClient = clsBankClient::GetClientsList();

		string AccountNumber = _ReadAccountNumer();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found,";
			AccountNumber = _ReadAccountNumer();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);


		double Amount = 0;
		cout << "Please enter deposit amount ?";
		Amount = clsInputValidate::ReadDblNumber();

		char Answer = 'n';
		cout << "\n\n Are you sure you want perform this transaction?y/n ?";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{

			if (Client.Withdraw(Amount))
			{
				cout << "\nAmount Withdraw Successfully.  \n";
				cout << "\nNew Balance Is: " << Client.AccountBalance;
			}
			
			else
			{
				cout << "\nCannot Withdraw, Insuffecient Balance!\n";
				cout << "\nAmount to withdraw is: " << Amount;
				cout << "\nYour Balance is: " << Client.AccountBalance;
			}

		}
		else
		{
			
			cout << "\nOperation was cancelled.\n";
		}

	}

};


#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUsres.h"
#include<iomanip>
#include"clsMainScreen.h"

#include"Global.h"

class clsLoginScreen:protected clsScreen
{
private:
	
	static bool _Login()
	{
		int FaildLoginCount = 0;
		bool LoginFaild = false;
	
		string UserName, password;
		do
		{

			if (LoginFaild)
			{
				FaildLoginCount++;

				cout << "\nInvlaid UserName/Password\n";
				cout << "\nYou have  " << (3-FaildLoginCount) 
					<< "  Trial(s) to login.\n\n";

			}

			if (FaildLoginCount == 3)
			{
				cout << "Your are Locked after 3 faild trails ";
				return false;
			}

			cout << "Enter UserName? ";
			cin >> UserName;

			cout << "Enter Password? ";
			cin >> password;

			CurrentUser = clsUsres::Find(UserName, password);

			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);

		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
		return true;

	}

public:

	static bool ShowLoginScreen()
	{
		 system("cls");
		_DrewScreenHeader("\t  Login Screen");
		return _Login();

	}

};


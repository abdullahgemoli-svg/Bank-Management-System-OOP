#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsListUserScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdatUserScreen.h"
#include"clsFindUserScreen.h"

using namespace std;

class clsManageUsersScreen:protected clsScreen
{
private:
	enum enManageUsersMenueOption
	{
		eListUser = 1,
		eAddNewUser = 2,
		DeletUser = 3,
		UpdateUser = 4,
		FindUsre = 5,
		eMainMenue = 6


	};

	static short _ReadManageUsersOptionScreen()
	{
		cout << setw(37) << left << "" << "Chooce what do you wantto do [1] to [6] ?";
		short Chooce = clsInputValidate::ReadShortNumberBetween(1, 6, " Enter between [1] to [6] ?\n  ");

		return Chooce;
	}

	static void _GoBackToManageUsersScreen()
	{

		cout << "\n\t\tPlease enter any key to beak Mange Users Menue.......";
		system("pause>0");

		ShowMangeUsersMenueScreen();

	}

	static void _ShowListUsresScreen()
	{
		//cout << "\nList Usres will be hear...";
		clsListUserScreen::ShowtsListUserScreen();
	}

	static void _ShowAddNewUsresScreen()
	{
		//cout << "\nAdd New Usres will be hear...";
		clsAddNewUserScreen::ShowAddNewUsersScreen();
	}

	static void _ShowDeleteUsresScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUsresScreen()
	{
		//cout << "\nUpdat Usres will be hear..";
		clsUpdatUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUsresScreen()
	{
		//cout << "\nFind Usres will be hear..";

		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _ShowMainMenueScreen()
	{
		cout << "\nMain Menue will be hear..";
	}

	static void _PerfromMangeUserMenueOption(enManageUsersMenueOption MangeMenueOption)
	{
		switch (MangeMenueOption)
		{
		case enManageUsersMenueOption::eListUser:

			

			system("cls");
			_ShowListUsresScreen();
			_GoBackToManageUsersScreen();
			break;

		case enManageUsersMenueOption::eAddNewUser:
			system("cls");
			_ShowAddNewUsresScreen();
			_GoBackToManageUsersScreen();
			break;

		case enManageUsersMenueOption::DeletUser:
			system("cls");
			_ShowDeleteUsresScreen();
			_GoBackToManageUsersScreen();
			break;

		case enManageUsersMenueOption::UpdateUser:
			system("cls");
			_ShowUpdateUsresScreen();
			_GoBackToManageUsersScreen();
			break;

		case enManageUsersMenueOption::FindUsre:
			system("cls");
			_ShowFindUsresScreen();
			_GoBackToManageUsersScreen();
			break;

		case enManageUsersMenueOption::eMainMenue:

			break;
		}
	}



public:

	static void ShowMangeUsersMenueScreen()
	{
		system("cls");

		if (!CheckAccessRights(clsUsres::enPermissions::pManageUsers))
		{
			return;
		}

		_DrewScreenHeader("\tManage Usres Menue");

		cout << setw(37) << left << "" << "=============================================================\n";
		cout << setw(37) << left << "" << "\t\t Manage Usres Menue Screen  \n";
		cout << setw(37) << left << "" << "=============================================================\n";
		cout << setw(37) << left << "" << "\t\t[1] List Usres.\n ";
		cout << setw(37) << left << "" << "\t\t[2] Add New Usres.\n";
		cout << setw(37) << left << "" << "\t\t[3] Delete Usres .\n";
		cout << setw(37) << left << "" << "\t\t[4] Update Usres\n";
		cout << setw(37) << left << "" << "\t\t[5] Find Usres.\n";
		cout << setw(37) << left << "" << "\t\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "=============================================================\n";

		_PerfromMangeUserMenueOption((enManageUsersMenueOption)_ReadManageUsersOptionScreen());
	}


};


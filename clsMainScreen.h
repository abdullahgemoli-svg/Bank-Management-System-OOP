#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUsres.h"
#include"clsInputValidate.h"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdatClientsScreen.h"
#include"clsFindClientsScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsersScreen.h"
#include"clsLoginScreen.h"
#include"Global.h"
#include"clsLoginRegisterListScreen.h"
#include"clsCurrencyExchangeScreen.h"
using namespace std;

class clsMainScreen :protected clsScreen
{
private:

	enum enMainMenueOptions {
		eListClients = 1, eAddNewClient = 2,
		eDeleteClient = 3, eUpdateClient = 4,
		eFindCLient = 5, enShowTransactionMenue = 6, eMangeUsers = 7,
		eLoginRegister = 8, eCurrencyExchange = 9 ,  eExit = 10
	};

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Chooce what do you wantto do [1] to [10] ?";
		short Chooce = clsInputValidate::ReadShortNumberBetween(1, 10, "\n\n\t\t\t\t\tPlease Enter between [1] to [9] ?  ");
		
		return Chooce;
	}

	static void _GoBackToMainMenue()
	{

		cout << "\n\t\tPlease enter any key to beak Main Menue.......";
		system("pause>0");

		ShowMainMenue();

	}

	static void _ShowAllClientsScreen()
	{
		//cout << "Client List Screen will be hear...\n";
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientsScreen()
	{
		//cout << " Add New Client  Screen will be hear...\n";
		clsAddNewClientScreen::ShowAddNewClientsScreen();
	}
	
	static void _ShowDeleteClientScreen()
	{
		//cout << "Delete Client  Screen will be hear...\n";
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		//cout << "Update Client  Screen will be hear...\n";
		clsUpdatClientsScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		//cout << "Find Client  Screen will be hear...\n";
		clsFindClientsScreen::ShowFindClientsScreen();
	}
	
	static void _ShowTransactionsMenue()
	{
		//cout << "TransactionsMenue  Client  Screen will be hear...\n";
		clsTransactionsScreen::ShowTransactionsScreen();
	} 

	static void _ShowManageUsersMenue()
	{
		//cout << "Manage Users Menue  Screen will be hear...\n";
		clsManageUsersScreen::ShowMangeUsersMenueScreen();
	}

	static void  _ShowLoginRegisterListScreen()
	{
		clsLoginRegisterListScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeScreen()
	{
		clsCurrencyExchangeScreen::ShowCurrenciesMenue();
	}

	//static void _ShowEndScreen()
	//{
	//	//cout << "End programming will be hear....\n";
	//	clsLoginScreen::ShowLoginScreen();
	//}

	static void _Logout()
	{
		CurrentUser = clsUsres::Find("", "");

	}
	

	static void _PerfromMenueOption(enMainMenueOptions MainMenueoption)
	{
		switch (MainMenueoption)
		{
		case enMainMenueOptions::eListClients:


			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenue();
				
			break;


		case enMainMenueOptions::eAddNewClient:
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eFindCLient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;


		case enMainMenueOptions::enShowTransactionMenue:
			system("cls");
			_ShowTransactionsMenue();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eMangeUsers:
			system("cls");
			_ShowManageUsersMenue();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eLoginRegister:
			system("cls");
			_ShowLoginRegisterListScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eCurrencyExchange:
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eExit:
			system("cls");
			_Logout();
			break;
		}

	}

public:

	static void ShowMainMenue()
	{
		system("cls");
		_DrewScreenHeader("\t\tMain Screen");

		cout << setw(37) << left << "" << "==========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "==========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client..\n";
		cout << setw(37) << left << "" << "\t[4] Update Client.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "=======================================\n";

		_PerfromMenueOption(enMainMenueOptions(_ReadMainMenueOption()));

	}


};


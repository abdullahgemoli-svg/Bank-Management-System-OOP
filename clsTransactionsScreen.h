#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithDrawScreen.h"
#include"clsToatlBalanceScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogListScreen.h"

class clsTransactionsScreen:protected clsScreen
{

	enum enTransactionMenueOptions
	{
		enDeposit = 1, enWithdraw = 2,
		enShowTotalBalances = 3, enTransfer = 4, enTransferLog = 5 ,enShowMainMenue = 6
	};

	static short _ReadTransactionsMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want  from [1 to 6]?";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "the Number ivalid Enter agin");
		return Choice;
	}

	static void _GoBackToTransactionMenue()
	{
		cout << "\n\t\tPlease enter any key to beak Main Menue.......";
		system("pause>0");
		ShowTransactionsScreen();
	}
	
	static void _ShowDepositScreen()
	{
		//cout << "\nDeposit Screent will be hear....";
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithDrawScreen()
	{
	//	cout << "\nWothDraw Screen will be hear....";
		clsWithDrawScreen::ShowWithDrawScreen();
	}

	static void _ShowTotalBlanceScreen()
	{
		//cout << "\n Balances Screen  will be hear....";
		clsToatlBalanceScreen::ShowTotallBalancesScreen();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsTransferLogListScreen::ShowTransfeLogListScreen();
	}

	static void _ShowMainMenue()
	{
		//cout << "\n Show Main Menue  will be hear....";
	}

	static void _PerfromTranactionMenueOption(enTransactionMenueOptions TransactionMenueOption)
	{
		switch (TransactionMenueOption)
		{
		case enTransactionMenueOptions::enDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionMenueOptions::enWithdraw:
		{
			system("cls");
			_ShowWithDrawScreen();
			_GoBackToTransactionMenue();
			break;


		}
		case enTransactionMenueOptions::enShowTotalBalances:
		{
			system("cls");
			_ShowTotalBlanceScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionMenueOptions::enTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionMenueOptions::enTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionMenueOptions::enShowMainMenue:
		{
			
		}

		}
	}


public:
	static void ShowTransactionsScreen()
	{
		system("cls");

		if (!CheckAccessRights(clsUsres::enPermissions::pTranactions))
		{
			return;
		}
		_DrewScreenHeader("\t Transactions  Screen     ");
		
		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t\t Transactions Menuen\n";
		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t [1] Deposit.\n";
		cout << setw(37) << left << "" << "\t [2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t [3] Total Balances .\n";
		cout << setw(37) << left << "" << "\t [4] Transfer .\n";
		cout << setw(37) << left << "" << "\t [5] Transfer Log .\n";
		cout << setw(37) << left << "" << "\t [6] Main Menue.\n";
		cout << setw(37) << left << "" << "============================================\n";

		_PerfromTranactionMenueOption((enTransactionMenueOptions)_ReadTransactionsMenueOption());
	}


	
};


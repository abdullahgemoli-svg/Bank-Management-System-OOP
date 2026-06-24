#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include<iomanip>
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrenciesScreen.h"
#include"clsUpdateCurrencyRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"
using namespace std;


class clsCurrencyExchangeScreen :protected clsScreen
{

private:
	enum enCurrenciesMainMenueOptions {
		eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3,
		eCurrencyCalculatot = 4, eMainMenue = 5
	};

	static short _ReadCurrenciesMainMenueOptions()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do  ? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number from [1 to 5]");
		return Choice;
	}

	static void _GoBackToCurrenciesMenue()
	{
		cout << "\n\nPleass any key to go back to Currencies Menue...";
		system("pause>0");
		ShowCurrenciesMenue();

	}

	static void _ShowCurrenciesListScreen()
	{
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}
	
	static void _ShowCurrenciesFindScreen()
	{
		clsFindCurrenciesScreen::ShowFindCurrencyScreen();
	}

	static void _ShowCurrenciesUpdateScreen()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrenciesCalculatot()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _PerformCurrenciesMainMenueOptions(enCurrenciesMainMenueOptions CurrenciesMainMenueOptions)
	{

		switch (CurrenciesMainMenueOptions)
		{
		case enCurrenciesMainMenueOptions::eListCurrencies:
		{
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrenciesMenue();
			break;
		}

		case enCurrenciesMainMenueOptions::eFindCurrency:
		{
			system("cls");
			_ShowCurrenciesFindScreen();
			_GoBackToCurrenciesMenue();
			break;
		}

		case enCurrenciesMainMenueOptions::eUpdateCurrencyRate:
		{
			system("cls");
			_ShowCurrenciesUpdateScreen();
			_GoBackToCurrenciesMenue();
			break;
		}

		case enCurrenciesMainMenueOptions::eCurrencyCalculatot:
		{
			system("cls");
			_ShowCurrenciesCalculatot();
			_GoBackToCurrenciesMenue();
			break;
		}

		case enCurrenciesMainMenueOptions::eMainMenue:
		{

		}

		}
	}

public:
	static void ShowCurrenciesMenue()
	{
		system("cls");
		_DrewScreenHeader("\tCurrancy Exhange Main Screen");

		cout << setw(37) << left << "" << "==========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrancy Exhange Menue\n";
		cout << setw(37) << left << "" << "==========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currenccies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "==========================================\n";

		_PerformCurrenciesMainMenueOptions(enCurrenciesMainMenueOptions(_ReadCurrenciesMainMenueOptions()));
	}
};


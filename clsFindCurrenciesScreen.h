#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include<iomanip>
#include"clsCurrency.h"
using namespace std;

class clsFindCurrenciesScreen :protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "______________________________\n";
		cout << "\nCountry    :" << Currency.Country();
		cout << "\nCod        :" << Currency.CurrencyCode();
		cout << "\nName       :" << Currency.CurrencyName();
		cout << "\nRate(1$)=  :" << Currency.Rate();

		cout << "\n____________________________\n";

	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);

		}
		else
		{
			cout << "\nCurrency was not Found :-)";

		}
	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrewScreenHeader("\t Find Currency Screen");

		cout << "\nFind By: [1] Code or [2] Country ? ";
		short Answer = 1;
		
		cin >> Answer;
		if (Answer == 1)
		{
			string CurrencyCod;
			cout << "\nPlease Enter CurrencyCod:";
			CurrencyCod = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCod);
			_ShowResults(Currency);
		}
		else
		{
			string Country;
			cout << "\nPlease Enter Country Name: ";
			Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);

		}
	}
	
};


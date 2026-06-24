#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"

class clsUpdateCurrencyRateScreen:protected clsScreen
{

private:

	static float _ReadRate()
	{
		cout << "\nEnter New Rate:";
		float NewRate = 0;

		NewRate = clsInputValidate::ReadFloatNumber();
		return NewRate;


	}

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nNaem       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();


	}

public:

	static void ShowUpdateCurrencyRateScreen()
	{

		_DrewScreenHeader("\tUpdate Currency Screen");

		string CurrencyCode = "";

		cout << "\nPlease Enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found , choose another oneL";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCountry(CurrencyCode);
		_PrintCurrency(Currency);

		cout << "\nAre sure you want to update the rate ?";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'Y')
		{
			cout << "\n\nUpdate Currency Rate:";
			cout << "\n________________________\n";

			Currency.UpdateRate(_ReadRate());

		    cout << "\nCurrency Rate Update Successfully  :-)\n";
			_PrintCurrency(Currency);


		}
	}

};


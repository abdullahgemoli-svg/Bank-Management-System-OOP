#pragma once
#include<iostream>
using namespace std;

template <typename T> static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n")
{
	T Number;
	while (!(cin >> Number)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << ErrorMessage;
	}
	return Number;
}





template <typename T> static T ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range, Enter again:\n")
{
	T  Number = ReadNumber<T>();

	while (!IsNumberBetween(Number, From, To))
	{
		cout << ErrorMessage;
		Number = ReadNumber<T>();
	}
	return Number;
}

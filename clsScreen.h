#pragma once
#include<iostream>
#include"clsUsres.h"
#include"Global.h"
#include"clsDate.h"

using namespace std;
class clsScreen
{
protected:

	static void _DrewScreenHeader(string Title, string SubTitle="")
	{
		cout << "\n\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\t" << Title;
		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t" << SubTitle;
		}
		cout << "\n\t\t\t\t\t______________________________________\n";

		cout << "\n\t\t\t\t\t User: " << CurrentUser.UserName << "\n\t\t\t\t\t Date: " << clsDate::DateToString(clsDate()) << "\n\n";
		//cout << "\t\t\t\t\t Date: " << clsDate::DateToString(clsDate()) << "\n\n";
	}

	static bool CheckAccessRights(clsUsres::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			cout << "\t\t\t\t\t___________________________________________";
			cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin";
			cout << "\n\t\t\t\t\t___________________________________________";
			return false;
		}
		else
		{
			return true;
		}
	}  

};


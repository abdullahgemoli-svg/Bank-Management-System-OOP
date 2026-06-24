#pragma once
#include<iostream>
#include<string>
using namespace std;

class InterfaceCommunication
{

public:
	virtual void SendEmail(string Title, string Body) = 0;
	virtual void SendFaxt(string Title, string Body) = 0;
	virtual void SendSMS(string Title, string Body) = 0;


};


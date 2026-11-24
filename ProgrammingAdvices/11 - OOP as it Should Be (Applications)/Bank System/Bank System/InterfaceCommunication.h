#pragma once
#include<iostream>
using namespace std;

class InterfaceCommunication
{
	virtual void SendEmail(string Title, string Body) = 0;
	virtual void SendFax(string Title, string Body) = 0;
	virtual void SendSMS(string Title, string Body) = 0;
};


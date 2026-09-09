#include <iostream>
using namespace std;

class clsPerson
{
private:
	virtual void SendSMS(string PhoneNumber, string SMSBody) = 0;
	virtual void SendEMAIL(string EMAI, string EMAILTITLE, string EMAILBODY) = 0;
};

class clsStudent :public clsPerson
{
public:
	void SendSMS(string PhoneNumber, string SMSBody)
	{

	};

	void SendEMAIL(string EMAI, string EMAILTITLE, string EMAILBODY)
	{

	};

	void x()
	{

	}
	
};


int main()
{

	clsStudent pp;
	pp.SendEMAIL("jiji","uioji","uiouo");

	return 0;
}
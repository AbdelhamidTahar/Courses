#include <iostream>
using namespace std;
#include "InputLib.h"





void IsNumberPositeve(int Number)
{

	 (Number > 0) ? cout <<"Positive" : cout << "Negative";

}
int main()
{
	int Number = 0;
	Number = User_Input::ReadNumber("Please Enter A Number");
    IsNumberPositeve(Number);




	return 0;
}
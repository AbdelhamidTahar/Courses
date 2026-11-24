#include<iostream>
#include <map>

using namespace std;

int main()
{

	map<string, int> Person;
	Person["Hamid"] = 1;
	Person["Ali"] = 2;
	Person["Mohammed"] = 3;
	Person["Sara"] = 4;
	Person["Alex"] = 454;

	pair<string, int> n("AAAAA", 55);
	Person.insert(n);

	for (map<string,int>::iterator it = Person.begin(); it != Person.end();it++)
	{
		cout << "Name: " << it->first << " Value: " << it->second << endl;
	}
	cout << "___________________________________________________\n";


	for ( pair <const string, int>& ThePair : Person)
	{
		cout << "Name: " << ThePair.first << " Value: " << ThePair.second << endl;
	}
	cout << "___________________________________________________\n";



	map< string, int>::iterator it = Person.find("aaaa");
	
	if (it != Person.end())
	{
		cout << "we founf\n";
	}
	else
	{
		cout << "we can't found";
	}
}


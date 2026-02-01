#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> vNumbers{ 5435,43,5,34,5,435,43,5,4,35,43,5 };

	if (vNumbers.size() != 0)
	{

		for (int i = 0; i < 1000; i++)
		{

			if (i < vNumbers.size())
			{
				cout << "Print Element vector Usuing .at \n";
				cout << "Element [" << i + 1 << "] " << vNumbers.at(i);

				cout << endl;
				cout << endl;

				cout << "Print Element vector Usuing Normal Index Accses \n";
				cout << "Element [" << i + 1 << "] " << vNumbers[i];

				cout << endl;
				cout << endl;
			}

		}

	}

	return 0;
}
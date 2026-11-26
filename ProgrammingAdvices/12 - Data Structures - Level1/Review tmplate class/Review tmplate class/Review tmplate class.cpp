#include <iostream>
using namespace std;


template <class t1, class t2>
class Calculator
{
private:
	t1 _First;
	t2 _Second;
public:
	void SetFirst(t1 FirstValue)
	{
		_First = FirstValue;
	}
	t1 GetFirst()
	{
		return _First;
	}
	__declspec(property(put = SetFirst, get = GetFirst)) t1 First;

	void SetSecond(t2 SecondValue)
	{
		_Second = SecondValue;
	}
	t2 GetSecond()
	{
		return _Second;
	}
	__declspec(property(put = SetSecond, get = GetSecond)) t2 Second;

	double Sum ()
	{
		return _First + _Second;
	}
	double Subs()
	{
		return _First - _Second;
	}
	double Mult()
	{
		return _First * _Second;
	}
	double Div ()
	{
		return _First / _Second;
	}

};
int main()
{
	Calculator<int, float> C1;

	 C1.First = 15;
	 C1.Second = 20;

	 cout << C1.Sum() << endl;
	 cout << C1.Subs() << endl;
	 cout << C1.Mult() << endl;
	 cout << C1.Div() << endl;

	return 0;
}
#include <iostream>
#include <string>
using namespace std;

class clsCalculator
{
private:
	int _Result;
	int _InputValue;
	string _OperationType;

	void _SetResult(int Result)
	{
		_Result = Result;
	}
	__declspec(property(get = GetFinalResults, put = _SetResult))int Result;

	void _SetInputValue(int InputValue)
	{
		_InputValue = InputValue;
	}
	int _GetInputValue()
	{
		return _InputValue;
	}
	__declspec(property(get = _GetInputValue, put = _SetInputValue))int InputValue;

	void _SetOperationType(string OperationType)
	{
		_OperationType = OperationType;
	}
	string _GetOperationType()
	{
		return _OperationType;
	}
	__declspec(property(get = _GetOperationType, put = _SetOperationType))string OperationType;

public:
	int GetFinalResults()
	{
		return _Result;
	}
	bool Clear()
	{
		Result = 0;
		InputValue = 0;
		OperationType = "Clear";
		return true;
	}
	bool Add(int Input)
	{
		OperationType = "Adding";
		InputValue = Input;
		Result = Result + InputValue;
		return true;
	}
	bool Divide(int Input)
	{
		Input = (Input == 0) ? 1 : Input;

		OperationType = "Dividing";
		InputValue = Input;
		Result = Result / InputValue;
		return true;
	}
	bool Multiplay(int Input)
	{
		OperationType = "Multiplaying";
		InputValue = Input;
		Result = Result * InputValue;
		return true;
	}
	bool Subtract(int Input)
	{
		OperationType = "Subtracing";
		InputValue = Input;
		Result = Result - InputValue;
		return true;
	}
	void PrintResult()
	{
		cout << "Result After " +
			OperationType + " " +
			to_string(InputValue) + " is: " +
			to_string(GetFinalResults()) +
			"\n";
	}

};
int main()
{
	clsCalculator Calculator1;
	Calculator1.Clear();
	Calculator1.PrintResult();

	Calculator1.Add(14);
	Calculator1.PrintResult();

	Calculator1.Subtract(4);
	Calculator1.PrintResult();

	Calculator1.Multiplay(9);
	Calculator1.PrintResult();

	Calculator1.Divide(4);
	Calculator1.PrintResult();

	Calculator1.Divide(0);
	Calculator1.PrintResult();

	Calculator1.Clear();
	Calculator1.PrintResult();


	return 0;
}
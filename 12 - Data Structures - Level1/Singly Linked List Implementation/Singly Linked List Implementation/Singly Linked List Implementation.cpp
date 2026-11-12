#include <iostream>
using namespace std;

class Node
{
private:
	int _Value;
	Node* _Next;
public:
	void SetValue(int Value)
	{
		_Value = Value;
	}
	int GetValue()
	{
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue) )int Value;

	void SetNext(Node* Next)
	{
		_Next = Next;
	}
	Node* GetNext()
	{
		return _Next;
	}
	__declspec(property(get = GetNext, put = SetNext))Node* Next;

};

int main()
{

	
	Node* L1;
	Node* L2;
	Node* L3;

	L1 = new Node ();
	L2 = new Node();
	L3 = new Node();

	L1->Value = 22;
	L1->Next = L2;

	L2->Value = 66;
	L2->Next = L3;

	L3->Value = 99;
	L3->Next = NULL;

	Node* Head;
	Head = L1;

	
	while (Head != NULL)
	{
		cout << Head->Value << endl;
		Head = Head->Next;
	}
	delete L1;
	delete L2;
	delete L3;



	return 0;
}
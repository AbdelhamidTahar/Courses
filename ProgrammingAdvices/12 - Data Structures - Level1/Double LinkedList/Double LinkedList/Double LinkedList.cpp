#include <iostream>
using namespace std;
class Node
{
private:
	int _Value;
	Node* _Next;
	Node* _Prev;
public:
	void SetValue(int Value)
	{
		_Value = Value;
	}
	int GetValue()
	{
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue))int Value;

	void SetNext(Node* Next)
	{
		_Next = Next;
	}
	Node* GetNext()
	{
		return _Next;
	}
	__declspec(property(get = GetNext, put = SetNext))Node* Next;

	void SetPrev(Node* Prev)
	{
		_Prev = Prev;
	}
	Node* GetPrev()
	{
		return _Prev;
	}
	__declspec(property(get = GetPrev, put = SetPrev))Node* Prev;

};


int main()
{


	Node* Node1, * Node2, *Node3;

	Node1 = new Node();
	Node2 = new Node();
	Node3 = new Node();

	Node1->Value = 12;
	Node2->Value = 16;
	Node3->Value = 99;

	Node1->Prev = NULL;
	Node1->Next = Node2;

	Node2->Prev = Node1;
	Node2->Next = Node3;

	Node3->Prev = Node2;
	Node3->Next = NULL;

	Node* Head = Node1;

	while (Head != NULL)
	{
		cout << Head->Value << " ";
		Head = Head->Next;
	}
}
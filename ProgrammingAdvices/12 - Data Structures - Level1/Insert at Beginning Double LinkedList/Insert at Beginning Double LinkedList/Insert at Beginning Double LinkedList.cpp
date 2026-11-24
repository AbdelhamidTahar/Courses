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


void InserAtBeginnig(Node* &Head, int Value)
{
	Node* NewNode = new Node();

	NewNode->Value = Value;
	NewNode->Next = Head;
	NewNode->Prev = NULL;

	if (Head != NULL)
	{
		Head->Prev = NewNode;
	}
	Head = NewNode;

}

void PrintDoubleLinkedList(Node* Head)
{
	while (Head != NULL)
	{
		cout << Head->Value << " ";
		Head = Head->Next;
	}
}

void PrintDoubleLinkedListWithDitels(Node* Head)
{
	while (Head != NULL)
	{
		if (Head->Prev != NULL)
			cout << Head->Prev->Value;			
		else
			cout << "NULL";

		cout << "<-- " << Head->Value << " -->";

		if (Head->Next != NULL)
			cout << Head->Next->Value << endl;
		else
			cout << "NULL" << endl;
		
		Head = Head->Next;
	}
}


int main()
{
	Node* Head = NULL;
	
	InserAtBeginnig(Head, 10);
	InserAtBeginnig(Head, 20);
	InserAtBeginnig(Head, 30);
	InserAtBeginnig(Head, 40);
	InserAtBeginnig(Head, 50);
	InserAtBeginnig(Head, 60);
	InserAtBeginnig(Head, 70);


	PrintDoubleLinkedListWithDitels(Head);
}
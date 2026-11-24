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

};


void InsertAtBeginning(Node*& Head, int Value)
{
	Node* NewNode = new Node();

	NewNode->Value = Value;
	NewNode->Next = Head;

	Head = NewNode;
}

void PrintAllNodes(Node* Head)
{
	while (Head != NULL)
	{
		cout << Head->Value << endl;
		Head = Head->Next;
	}

}

bool IsLinkdListEmpty(Node* Head)
{
	return (Head == NULL);
}

Node* Find(Node* Head, int Value)
{
	while (Head != NULL)
	{
		if (Head->Value == Value)
			return Head;
		Head = Head->Next;
	}

	return NULL;
}

Node* FindNodeBefore(Node* Head, int Value)
{

	if (IsLinkdListEmpty(Head))
		return NULL;

	if (Head->Value == Value)
		return NULL;


	Node* Prv = NULL;
	while (Head->Next != NULL && Head->Value != Value)
	{
		Prv = Head;
		Head = Head->Next;
	}

	//if can't found the node.
	if (Head->Next == NULL)
		return NULL;

	return Prv;
}

bool IsFirstNode(Node* Head, int Value)
{
	if (IsLinkdListEmpty(Head))
		return false;
	return (Head->Value == Value);
}

bool IsNodeExist(Node* LinkdList, int Value)
{
	return (Find(LinkdList, Value) != NULL);
}

void DeleteFirstNode(Node*& Head)
{
	if (IsLinkdListEmpty(Head))
		return;

	Node* Current = Head;
	Head = Current->Next;

	delete Current;
}

void DeleteNode(Node*& Head, int Value)
{
	if (IsLinkdListEmpty(Head))
		return;
	if (IsFirstNode(Head, Value))
	{
		DeleteFirstNode(Head);
		return;
	}

	Node* Current, * Prv;
	Current = Head;
	while (Current->Next != NULL && Current->Value != Value)
	{
		Prv = Current;
		Current = Current->Next;
	}
	if (Current == NULL)
		return;

	Prv = Current->Next;
	delete Current;
}



int main()
{
	Node* Head = NULL;

	//same stack
	InsertAtBeginning(Head, 10);
	InsertAtBeginning(Head, 20);
	InsertAtBeginning(Head, 30);
	InsertAtBeginning(Head, 40);
	InsertAtBeginning(Head, 50);
	InsertAtBeginning(Head, 60);
	InsertAtBeginning(Head, 70);
	InsertAtBeginning(Head, 80);

	DeleteFirstNode(Head);
	DeleteFirstNode(Head);
	DeleteFirstNode(Head);
	DeleteFirstNode(Head);
	DeleteFirstNode(Head);
	DeleteFirstNode(Head);
	DeleteFirstNode(Head);
	DeleteFirstNode(Head);
	DeleteFirstNode(Head);
	DeleteFirstNode(Head);


	PrintAllNodes(Head);



	return 0;
}
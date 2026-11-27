#include <iostream>
using namespace std;


class Node
{
public:
	Node* Next;
	int Value;
};

void InsertAtBeginning(Node*& Head, int Value)
{
	Node* NewNode = new Node();
	NewNode->Value = Value;
	NewNode->Next = Head;
	Head = NewNode;
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

void InsertAfter(Node* Prev_Node, int value)
{
	if (Prev_Node == NULL)
		return;

	Node* NewNode = new Node();
	NewNode->Value = value;
	NewNode->Next = Prev_Node->Next;
	Prev_Node->Next = NewNode;
}

void InsertAtEnd(Node*& Head, int Value)
{
	Node* NewNode = new Node();
	NewNode->Value = Value;
	NewNode->Next = NULL;

	if (Head == NULL)
	{
		Head = NewNode;
		return;
	}

	Node* LastNode = Head;
	while (LastNode->Next != NULL)
	{
		LastNode = LastNode->Next;
	}
	LastNode->Next = NewNode;


}

void DeleteNode(Node* &Head, int Value)
{
	if (Head == NULL)
		return;

	Node* Current = Head;
	if (Head->Value == Value)
	{
		Head = Head->Next;
		delete Current;
		return;
	}

	Node* Prev = Head;
	while (Current != NULL && Current->Value != Value)
	{
		Prev = Current;
		Current = Current->Next;
	}
	if (Current == NULL)
		return;
	Prev->Next = Current->Next;
	delete Current;
}

void DeleteFirstNode(Node*& Head)
{
	if (Head == NULL)
		return;
	Node* Current = Head;
	Head = Head->Next;
	delete Current;
}

void DeleteLastNode(Node* &Head)
{
	if (Head == NULL)
		return;

	if (Head->Next == NULL)
	{
		delete Head;
		Head = NULL;
		return;
	}

	Node* Current = Head, * Prev = Head;
	while (Current->Next != NULL)
	{
		Prev = Current;
		Current = Current->Next;
	}
	Prev->Next = NULL;
	delete Current;
}

void InsertBefore(Node*& Head, int ValueToInserstBefore,int ValueToInsert)
{
	if (Head == NULL)
		return;

	Node* NewNode = new Node();
	NewNode->Value = ValueToInsert;

	if (Head->Value == ValueToInserstBefore)
	{
		InsertAtBeginning(Head, ValueToInsert);
		return;
	}

	Node* Current = Head, * Prev = Head;
	while (Current != NULL && Current->Value != ValueToInserstBefore)
	{
		Prev = Current;
		Current = Current->Next;
	}

	if (Current != NULL)
	{
		Prev->Next = NewNode;
		NewNode->Next = Current;
	}
}

int main()
{



	return 0;
}
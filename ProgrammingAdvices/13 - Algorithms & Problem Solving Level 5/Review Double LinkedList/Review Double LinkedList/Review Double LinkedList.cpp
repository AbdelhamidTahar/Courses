#include <iostream>
using namespace std;

class Node
{
public:
	Node* Next;
	int Value;
	Node* Prev;
};


void InsertInsertAtBeginning(Node* Head, int Value)
{
	Node* NewNode = new Node();
	NewNode->Value = Value;
	NewNode->Prev = NULL;
	NewNode->Next = Head;

	if (Head != NULL)
		Head->Prev = NewNode;

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

void InsertAfter(Node* Current, int Value)
{
	if (Current == NULL) return;

	Node* NewNode = new Node();

	NewNode->Value = Value;
	NewNode->Prev = Current;
	NewNode->Next = Current->Next;

	if (Current->Next != NULL)
		Current->Next->Prev = NewNode;

	Current->Next = NewNode;
}


int main()
{


	return 0;
}
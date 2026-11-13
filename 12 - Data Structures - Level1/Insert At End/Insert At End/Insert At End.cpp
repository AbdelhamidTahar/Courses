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


bool IsLinkdListEmpty(Node* Head)
{
	return (Head == NULL);
}

Node* GetLastNode(Node* Head)
{
	if (IsLinkdListEmpty(Head))
		return NULL;

	while (Head->Next != NULL)
	{
		Head = Head->Next;
	}
	return Head;
}

void InsertAtEnd(Node*& Head, int Value)
{

	Node* NewNode = new Node();
	NewNode->Value = Value;
	NewNode->Next = NULL;
	if (IsLinkdListEmpty(Head))
	{
		Head = NewNode;
	}
	else
	{
		Node* LastNode = GetLastNode(Head);
		LastNode->Next = NewNode;
	}
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


	InsertAtEnd(Head, 9000);

	PrintAllNodes(Head);

	Node* TempHead = Find(Head, 9000);
	if (TempHead != NULL)
		cout << "His Found \n";
	else
		cout << "Not Found\n";

	return 0;
}
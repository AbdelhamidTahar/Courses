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

bool IsSameNode(Node* Node1, Node* Node2)
{
	return (Node1 == Node2);
}

void InsertBefor(Node* &Head, int Before, int Value)
{
	Node* TempHead = Head;
	Node* FindNode = Find(TempHead, Before);
	if (FindNode == NULL)
		return;

	Node* NewNode = new Node();

	NewNode->Value = Value;
	NewNode->Next = FindNode;

	// if the first Node we nedd add before?.
	if (IsSameNode(Head, FindNode))
	{
		Head = NewNode;
		return;
	}
	
	//Move Node By Node To Find What Is Node To Point To Node To Insert After.
	while (TempHead != NULL)
	{
		if (TempHead->Next == FindNode)
		{
			TempHead->Next = NewNode;
			break;
		}
		TempHead = TempHead->Next;
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
	InsertBefor(Head, 50, 80);

	PrintAllNodes(Head);

	Node* TempHead = Find(Head, 99);
	if (TempHead != NULL)
		cout << "His Found \n";
	else
		cout << "Not Found\n";

	return 0;
}
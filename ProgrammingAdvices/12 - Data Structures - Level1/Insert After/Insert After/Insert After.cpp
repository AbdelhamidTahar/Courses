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

void InsertAfter(Node* prev_node, int Value) {

	if (prev_node == NULL) {
		cout << "the given previous node cannot be NULL";
		return;
	}

	Node* new_node = new Node();
	new_node->Value = Value;
	new_node->Next = prev_node->Next;
	prev_node->Next = new_node;
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
	
	Node* ptrNode = Find(Head,70);
	InsertAfter(ptrNode, 00);

	PrintAllNodes(Head);

	Node* TempHead = Find(Head, 00);
	if (TempHead != NULL)
		cout << "His Found \n";
	else
		cout << "Not Found\n";

	return 0;
}
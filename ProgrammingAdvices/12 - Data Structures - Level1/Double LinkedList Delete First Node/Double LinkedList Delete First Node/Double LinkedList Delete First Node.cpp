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

void InsertAtBeginning(Node*& head, int value) {


	/*
		1-Create a new node with the desired value.
		2-Set the next pointer of the new node to the current head of the list.
		3-Set the previous pointer of the current head to the new node.
		4-Set the new node as the new head of the list.
	*/

	Node* newNode = new Node();
	newNode->Value = value;
	newNode->Next = head;
	newNode->Prev = NULL;

	if (head != NULL) {
		head->Prev = newNode;
	}
	head = newNode;
}

Node* Find(Node* head, int Value)
{

	while (head != NULL) {

		if (head->Value == Value)
			return head;


		head = head->Next;
	}

	return NULL;


}

// Print the linked list
void PrintList(Node* head)

{
	cout << "NULL <--> ";
	while (head != NULL) {
		cout << head->Value << " <--> ";
		head = head->Next;
	}
	cout << "NULL";

}

void InsertAfter(Node* Current, int Value)
{
	if (Current == NULL)
		return;

	Node* NewNode = new Node();

	NewNode->Value = Value;
	NewNode->Next = Current->Next;
	NewNode->Prev = Current;

	Current->Next = NewNode;

	if (Current->Next != NULL)
		Current->Next->Prev = NewNode;


}

void InsertAtEnd(Node*& Head, int Value)
{
	Node* NewNode = new Node();
	NewNode->Value = Value;
	NewNode->Next = NULL;

	if (Head == NULL)
	{
		NewNode->Prev = NULL;
		Head = NewNode;
	}
	else
	{
		Node* Current = Head;
		while (Current->Next != NULL)
		{
			Current = Current->Next;
		}
		Current->Next = NewNode;
		NewNode->Prev = Current;
	}
}

void DeleteNode(Node*& Head, Node* Current)
{
	if (Head == NULL || Current == NULL)
		return;

	if (Current == Head)
		Head = Current->Next;

	if (Current->Prev != NULL)
		Current->Prev->Next = Current->Next;

	if (Current->Next != NULL)
		Current->Next->Prev = Current->Prev;

	delete Current;
}

void DeleteFirstNode(Node*& Head)
{
	if (Head == NULL)
		return;

	Node* Temp;
	Temp = Head;
	Head = Head->Next;

	if (Head != NULL)
		Head->Prev = NULL;

	delete Temp;
}

int main()
{
	Node* head = NULL;

	cout << "\nLinked List Contenet:\n";

	InsertAtBeginning(head, 99);


	PrintList(head);
	
	DeleteFirstNode(head);

	Node* N1 = Find(head, 3);

	cout << endl;

	PrintList(head);

	system("pause>0");

}
#include <iostream>
using namespace std;
struct Node
{
	Node *prev;
	int data;
	Node *next;
};
void insertNode(Node *&head)
{
	int value;
	cout << "Enter an Integer to add to List: ";
	cin >> value;
	Node *newNode = new Node;
	newNode->prev = nullptr;
	newNode->data = value;
	newNode->next = nullptr;
	if (!head)
	{
		head = newNode;
	}
	else
	{
		Node *currentNode = head;
		while (currentNode->next)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
		newNode->prev = currentNode;
	}
	cout << "One Node Inserted!!" << endl;
}
void searchValue(Node *&head)
{
	if (!head)
	{
		cout << "The List is Empty!!!" << endl;
		return;
	}
	int value;
	cout << "enter an integer to search: ";
	cin >> value;
	Node *currentNode = head;
	while (currentNode)
	{
		if (currentNode->data == value)
		{
			cout << "The Number " << value << " Present in the List" << endl;
			return;
		}
		currentNode = currentNode->next;
	}
}
void displayFromFront(Node *&head)
{
	if (!head)
	{s
		cout << "The List is Empty" << endl;
		return;
	}
	Node *currentNode = head;
	cout << "The Elements present in the list: (forward order) " << endl;
	while (currentNode)
	{
		cout << currentNode->data << "\t";
		currentNode = currentNode->next;
	}
	cout << endl;
}
void displayFromBack(Node *&head)
{
	if (!head)
	{
		cout << "The List is Empty" << endl;
		return;
	}
	Node *currentNode = head;
	cout << "The Elementd present in the list: (Reverse Order) " << endl;
	while (currentNode->next)
	{
		currentNode = currentNode->next;
	}
	while (currentNode)
	{
		cout << currentNode->data << "\t";
		currentNode = currentNode->prev;
	}
	cout << endl;
}
void deleteNode(Node *&head)
{
	if (!head)
	{
		cout << "The List is Empty!!" << endl;
		return;
	}

	int value;
	cout << "Enter Value to delete: ";
	cin >> value;

	Node *currentNode = head;

	while (currentNode && currentNode->data != value)
	{
		currentNode = currentNode->next;
	}

	if (currentNode)
	{
		if (currentNode->prev)
		{
			currentNode->prev->next = currentNode->next;
		}
		else
		{
			head = currentNode->next;
		}

		if (currentNode->next)
		{
			currentNode->next->prev = currentNode->prev;
		}

		delete currentNode;
		cout << "The node with Value: " << value << " is deleted" << endl;
	}
	else
	{
		cout << "No such Value present in the list!!!" << endl;
	}
}
int main()
{
	Node *head = nullptr;
	int choice;
	while (true)
	{
		cout << "1.Add A Value To List" << endl
			 << "2.Search A Value" << endl
			 << "3.Delete A Value" << endl
			 << "4.Display From Front" << endl
			 << "5.Display From Back" << endl
			 << "6.Exit" << endl;
		cout << "Enter Your Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			insertNode(head);
			break;
		case 2:
			searchValue(head);
			break;
		case 3:
			deleteNode(head);
			break;
		case 4:
			displayFromFront(head);
			break;
		case 5:
			displayFromBack(head);
			break;
		case 6:
			cout << "exiting the program!!!" << endl;
			return 0;
		default:
			cout << "Invalid Choice!!" << endl;
		}
	}
	return 0;
}

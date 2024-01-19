#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

void insertNode(Node *&head)
{
	int value;
	cout << "Enter An Integer: ";
	cin >> value;
	Node *newNode = new Node;
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
	}
	cout << "One Node Inserted!!" << endl;
}

void displayList(Node *&head)
{
	Node *currentNode = head;
	cout << "Integers present in the list: ";
	while (currentNode)
	{
		cout << currentNode->data << "\t";
		currentNode = currentNode->next;
	}
	cout << endl;
}

void searchValue(Node *head)
{
	if (!head)
	{
		cout << "The List is empty" << endl;
		return;
	}
	else
	{
		int value;
		cout << "Enter An Integer to Search: ";
		cin >> value;
		Node *currentNode = head;
		while (currentNode)
		{
			if (currentNode->data == value)
			{
				cout << "The value " << value << " Present in the List!" << endl;
				return;
			}
			currentNode = currentNode->next;
		}
		cout << "The value " << value << " not Present in the List" << endl;
	}
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
	Node *prev = nullptr;
	while (currentNode && currentNode->data != value)
	{
		prev = currentNode;
		currentNode = currentNode->next;
	}
	if (currentNode)
	{
		if (prev)
		{
			prev->next = currentNode->next;
		}
		else
		{
			head = currentNode->next;
		}
		delete currentNode;
		cout << "The node with Value: " << value << " is deleted" << endl;
	}
	else
	{
		cout << "No such Value present in list!!!" << endl;
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
			 << "4.Display All" << endl
			 << "5.Exit" << endl;
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
			displayList(head);
			break;
		case 5:
			cout << "exiting the program!!!" << endl;
			return 0;
		default:
			cout << "Invalid Choice!!" << endl;
		}
	}
	return 0;
}

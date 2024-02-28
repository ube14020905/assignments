#include "Linkedlist.h"
#include <iostream>
using namespace std;
Node::Node(int value) : data(value), next(nullptr) {}
// Getter
int Node::getData(){
    return data;
}
Node* Node::getNext(){
    return next;
}
// Setter
void Node::setData(int value) {
    data = value;
}
void Node::setNext(Node* nextNode) {
    next = nextNode;
}
int Count(Node* head, int searchFor) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        if (current->getData() == searchFor) {
            count++;
        }
        current = current->getNext();
    }
    return count;
}

int GetNth(Node* head, int index) {
    Node* current = head;
    for (int i = 0; i < index; i++) {
        if (current == nullptr) {
            std::cerr << "Invalid index\n";
            return -1;
        }
        current = current->getNext();
    }

    return current->getData();
}

// Function to delete all nodes of the list and set its head pointer to NULL
void DeleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->getNext();
        delete temp;
    }
}

// Function to pop the head node and return its data
int Pop(Node*& head) {
    if (head == nullptr) {
        std::cerr << "List is empty\n";
        return -1;
    }

    int data = head->getData();
    Node* temp = head;
    head = head->getNext();
    delete temp;

    return data;
}

// Function to insert a new node at a given index in the list
void InsertNth(Node*& head, int index, int data) {
    Node* newNode = new Node(data);

    if (index == 0) {
        newNode->setNext(head);
        head = newNode;
        return;
    }

    Node* current = head;
    for (int i = 0; i < index - 1; i++) {
        if (current == nullptr) {
            std::cerr << "Invalid index\n";
            delete newNode;
            return;
        }
        current = current->getNext();
    }

    newNode->setNext(current->getNext());
    current->setNext(newNode);
}

// Function to insert a new node into a sorted list at the correct position
void SortedInsert(Node*& head, Node* newNode) {
    if (head == nullptr || head->getData() >= newNode->getData()) {
        newNode->setNext(head);
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->getNext() != nullptr && current->getNext()->getData() < newNode->getData()) {
        current = current->getNext();
    }

    newNode->setNext(current->getNext());
    current->setNext(newNode);
}

// Function to perform insertion sort on a list
void InsertSort(Node*& head) {
    Node* sortedList = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->getNext();
        SortedInsert(sortedList, current);
        current = nextNode;
    }

    head = sortedList;
}
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
// Function to append list 'b' onto the end of list 'a' and set 'b' to NULL
void Append(Node*& list1, Node*& list2) {
    if (list1 == nullptr){
        list1=list2;
    } else {
        Node*current = list1;
        while(current->getNext()!= nullptr){
            current = current->getNext();
        }
        current->setNext(list2);
    }
    list2 = nullptr;
}
// Function to split a list into front and back halves
void FrontBackSplit(Node* source, Node*& front, Node*& back) {
    if (source == nullptr) {
        front = back = nullptr;
        return;
    }
    Node* slow = source;
    Node* fast = source->getNext();
    while (fast != nullptr) {
        fast = fast->getNext();
        if (fast != nullptr) {
            slow = slow->getNext();
            fast = fast->getNext();
        }
    }
    front = source;
    back = slow->getNext();
    slow->setNext(nullptr);
}
// Function to remove duplicates from a sorted list
void RemoveDuplicates(Node* head) {
    Node* current = head;
    while (current != nullptr && current->getNext() != nullptr) {
        if (current->getData() == current->getNext()->getData()) {
            Node* nextNode = current->getNext()->getNext();
            delete current->getNext();
            current->setNext(nextNode);
        } else {
            current = current->getNext();
        }
    }
}

// Function to move the front node from the source list to the front of the destination list
void MoveNode(Node*& dest, Node*& source) {
    if (source == nullptr) {
        std::cerr << "Source list is empty\n";
        return;
    }
    Node* newNode = source;
    source = source->getNext();
    newNode->setNext(dest);
    dest = newNode;
}

// Function to alternate nodes between two lists
void AlternatingSplit(Node* source, Node*& list1, Node*& list2) {
    list1 = list2 = nullptr;
    Node* current = source;
    bool addToA = true;

    while (current != nullptr) {
        Node* nextNode = current->getNext();
        if (addToA) {
            MoveNode(list1, current);
        } else {
            MoveNode(list2, current);
        }
        addToA = !addToA;
        current = nextNode;
    }
}

// Function to merge nodes alternately between two lists
Node* ShuffleMerge(Node* list1, Node* list2) {
    Node* result = nullptr;
    Node* currentList1 = list1;
    Node* currentList2 = list2;

    while (currentList1 != nullptr || currentList1 != nullptr) {
        if (currentList1 != nullptr) {
            MoveNode(result, currentList1);
        }
        if (currentList2 != nullptr) {
            MoveNode(result, currentList2);
        }
    }

    return result;
}

// Function to merge two sorted lists into one sorted list
Node* SortedMerge(Node* list1, Node* list2) {
    Node* result = nullptr;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->getData() <= list2->getData()) {
            MoveNode(result, list1);
        } else {
            MoveNode(result, list2);
        }
    }

    while (list1 != nullptr) {
        MoveNode(result, list1);
    }

    while (list2 != nullptr) {
        MoveNode(result, list2);
    }

    return result;
}

// Function to recursively merge sort a list
void MergeSort(Node*& head) {
    if (head == nullptr || head->getNext() == nullptr) {
        return;
    }

    Node* front = nullptr;
    Node* back = nullptr;

    FrontBackSplit(head, front, back);

    MergeSort(front);
    MergeSort(back);

    head = SortedMerge(front, back);
}

// Function to compute a new sorted list that represents the intersection of two given sorted lists
Node* SortedIntersect(Node* list1, Node* list2) {
    Node* result = nullptr;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->getData() < list2->getData()) {
            list1 = list1->getNext();
        } else if (list1->getData() > list2->getData()) {
            list2 = list2->getNext();
        } else {
            // Data values are equal, add to the result list
            Node* newNode = new Node(list1->getData());
            SortedInsert(result, newNode);
            list1 = list1->getNext();
            list2 = list2->getNext();
        }
    }

    return result;
}
void insertAtFirst(Node* & head,int value){
    Node* node=new Node(value);
    if(!head){
        head=node;
    }
    else{
        node->setNext(head);
    }
}
void Reverse(Node* &head){
    Node* rev=nullptr;
    Node* currentNode=head;
    while(currentNode){
        insertAtFirst(rev,currentNode->getData());
        currentNode=currentNode->getNext();
    }
    while(rev){
        cout<<rev->getData()<<" ";
        rev = rev->getNext()
    }
}
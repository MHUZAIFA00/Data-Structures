#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
};
class List
{
public:
	Node* head;
	List()
	{
		head = NULL;
	}
	void insertNodeAtBeginning(int);
	void insertNodeInMiddle(int val, int key);
    void insertNodeAtEnd(int val);
	void deleteFirstNode();
	void deleteNode(int key);
	void deleteLastNode();
	void display();
	bool search(int data);
};
void List::insertNodeAtBeginning(int val)    // 0(1)
{
	Node* curr = head;
	Node* newNode = new Node();
	newNode->data = val;
	newNode->next = NULL;
	if (!head)
	{
		head = newNode;
	}
	else if(curr->next == NULL)
	{
		curr->next = newNode;
	}
}
void  List::insertNodeInMiddle(int val, int key)
{
	int count = 0;
	Node* curr = head;
	Node* newNode = new Node();
	newNode->data = val;
	newNode->next = NULL;
	for (count; count < key - 1 && curr != NULL;)
	{
		curr = curr->next;
		count++;
	}
	newNode->next = curr->next;
	curr->next = newNode;
}
void List::insertNodeAtEnd(int val)           // 0(n)
{
	Node* curr = head;
	Node* newNode = new Node();
	newNode->data = val;
	newNode->next = NULL;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = newNode;
}
void List::deleteFirstNode()
{
	if (head)
	{
		Node* curr = head;
		head = head->next;
		delete curr;
		curr = NULL;
	}
}
void List::deleteNode(int key)
{
	if (!head) 
	{
		cout << "List is empty!" << endl;
		return;
	}
	Node* prev = nullptr;
	Node* curr = head;
	int count = 0;
	while (curr && count < key) 
	{
		prev = curr;
		curr = curr->next;
		count++;
	}
	if (!curr) 
	{
		cout << "Key not found!" << endl;
		return;
	}
	if (prev) 
	{
		prev->next = curr->next;
	}
	else 
	{
		head = curr->next;
	}
	delete curr;
}
void List::deleteLastNode()
{
	Node* curr = head;
	Node* prev = NULL;
	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	if (prev != NULL)
	{
		prev->next = NULL;
	}
	else
	{
		head = NULL;
	}
	delete curr;
	curr = NULL;
}
bool List::search(int data)
{
	Node* curr = head;
	if (!curr)
	{
		cout << "List Empty!" << endl;
	}
	while (curr->next != NULL)
	{
		if (curr->data = data)
		{
			cout << "Item found!";
			return true;
		}
		curr = curr->next;
	}
}
void List::display()
{
	Node* curr = head;
	if (!curr)
	{
		cout << "List Empty!" << endl;
	}
	cout << "List Items : ";
	while (curr->next != NULL)               // traversing 0(n)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << curr->data;
	cout << endl;
}
int main()
{
	List mylist;
	int val,opt, chk,index;
		do
		{
			cout << "1.Insert at start" << endl;
			cout << "2.Insert in middle" << endl;
			cout << "3.Insert at end" << endl;
			cout << "4.Search" << endl;
			cout << "5.Delete specific node" << endl;
			cout << "6.Delete 1st node" << endl;
			cout << "7.Delete last node" << endl;
			cout << "8.display" << endl;
			cin >> opt;
			switch (opt)
			{
			case 1:
				cout << "Enter value : ";
				cin >> val;
				mylist.insertNodeAtBeginning(val);
				cout << endl;
				break;
			case 2:
				cout << "Enter Value : ";
				cin >> val;
				cout << "Enter Index : ";
				cin >> index;
				mylist.insertNodeInMiddle(val, index);
				cout << endl;
				break;
			case 3:
				cout << "Enter Value : ";
				cin >> val;
				mylist.insertNodeAtEnd(val);
				cout << endl;
				break;
			case 4:
				cout << "Enter value to search : ";
				cin >> val;
				mylist.search(val);
				cout << endl;
				break;
			case 5:
				cout << "Enter index : ";
				cin >> index;
				mylist.deleteNode(index);
				cout << endl;
				break;
			case 6:
				mylist.deleteFirstNode();
				cout << endl;
				break;
			case 7:
				mylist.deleteLastNode();
				cout << endl;
				break;
			case 8:
				mylist.display();
				cout << endl;
				break;
			default:
				cout << "Invalid choice!";
				exit(0);
			}
		} while (opt != 0);
		
}

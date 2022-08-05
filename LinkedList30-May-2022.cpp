#include <iostream>
using namespace std;

//Node class to be handled by Linked List (List)
class Node {
private:
	int data;
	Node* next;

public:
	Node(int data, Node* next) {
		this->data = data;
		this->next = next;
	}

	friend class List;
};

//Linked List Operations
class List {
private:
	Node* head;
	Node* end;
public:
	//default constructor
	List() {
		head = NULL;
		end = NULL;
	}

	//list is empty or not
	bool isEmpty() {
		return (head);
	}

	//insert at End
	// void insertAtEnd(int item) {
	// 	Node* newNode = new Node(item, NULL);

	// 	if (head == NULL) {
	// 		head = newNode;
	// 	}
	// 	else {
	// 		Node* curNode = head;

	// 		while (curNode->next != NULL)
	// 			curNode = curNode->next;

	// 		curNode->next = newNode;
	// 	}
	// }
	void insertAtEnd(int item) {
		Node* newnode = new Node(item, NULL);
		if (head == NULL) {
			head = newnode;
			end = newnode;
		}
		else {
			end->next = newnode;
			end = newnode;
		}
	}
	void insertAtFirst(int item) {
		Node* newnode = new Node(item, NULL);
		if (head == NULL) {
			head = newnode;
		}
		else {
			newnode->next = head;
			head = newnode;
		}
	}
	
		//display the contents of list
	void display() {
		if (head == NULL)
			cout << "List is empty." << endl;
		else {
			Node* curNode = head;

			while (curNode != NULL) {
				cout << curNode->data << endl;
				curNode = curNode->next;
			}
		}
	}
};

int main() {
	List obj;

	obj.insertAtEnd(1);
	obj.insertAtEnd(2);
	obj.insertAtEnd(3);
	obj.insertAtEnd(4);
	obj.insertAtFirst(1);
	obj.insertAtFirst(2);
	obj.insertAtFirst(3);
	obj.insertAtFirst(4);

	obj.display();		//1	2 3

	return 0;
}

//============================================================================
// Name        : queue_link_based.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// Name        : singly_linked_Queue.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdlib.h>
using namespace std;

class Queue;

class Node {
	int element;
	Node *next;


public:
	Node() {
	element = 0;
	next = NULL;
	}

	Node(int element) {
	this->element = element;
	next = NULL;
	}

	friend class Queue;
};


class Queue {
	Node *head;

public:
	Queue() {
		head = NULL;
	}


	void enQueue(int element) {
		Node *newNode = new Node(element);
		if(head == NULL) {
			head = newNode;
		}
		else {
			Node *trav = head;
			while(trav->next != NULL)
				trav = trav->next;
			trav->next = newNode;
		}
		cout<<"One element inserted!!"<<endl;
	}


	void display() {
		if(head == NULL)
			cout<<"Queue is empty!!"<<endl;
		else {
			cout<<"Queue elements are: "<<endl;
			Node *trav = head;
			while(trav != NULL) {
				cout<<trav->element<<"\t";
				trav = trav->next;
			}
			cout<<endl;
		}
	}

	void deQueue() {
		if(head == NULL)
			cout<<"Queue is already empty!!"<<endl;
		else {
			int element = head->element;
			Node *temp = head;
			head = head->next;
			delete temp;
			cout<<"One Element deleted is: "<<element<<endl;
		}
	}





};



int main() {
	int choice, element;
	Queue q;
	while(1) {
		cout<<"1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice) {
		case 1:
			// enqueue
			cout<<"Enter element you want to enter: ";
			cin>>element;
			q.enQueue(element);
			break;
		case 2:
			// dequeue
			q.deQueue();
			break;
		case 3:
			// display
			q.display();
			break;
		case 4:
			exit(0);
			break;
		default: cout<<"Invalid choice!!"<<endl;

		}
	}
	return 0;
}


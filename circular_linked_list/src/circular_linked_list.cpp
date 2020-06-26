//============================================================================
// Name        : circular_linked_list.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdlib.h>
using namespace std;

class LinkedList;

class Node {
	int element;
	Node *next;

public:
	Node() {
	element = 0;
	next = this;
	}

	Node(int element) {
	this->element = element;
	next = this;
	}

	friend class LinkedList;
};


class LinkedList {
	Node *head;
	Node *tail;

public:
	LinkedList() {
		head = NULL;
	}

	void insertionAtBegin(int element) {
		Node *newNode = new Node(element);
		if(head == NULL) {
			head = tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
			tail->next = newNode;
		}
		cout<<"One node inserted!!"<<endl;
	}

	void insertionAtEnd(int element) {
		Node *newNode = new Node(element);
		if(head == NULL) {
			head = tail = newNode;

		}
		else {
			tail->next = newNode;
			tail = newNode;
			newNode->next = head;
		}
		cout<<"One node inserted!!"<<endl;
	}

	int count() {
		Node *trav = head;
		int count = 0;
		if(head != NULL && head->next == head)
			return count + 1;
		while(head != NULL && trav->next != head) {
			count++;
			trav = trav->next;
		}

		if(count == 0)
			return count;
		else
			return count + 1;
	}

	void insertionAtSpecific(int element, int pos) {
		if(pos<1 || pos>count() + 1) {
			cout<<"Invalid position!!"<<endl;
			cout<<count()<<endl;
		}
		else {
			Node **current = &head, *newNode = new Node(element);

			while(pos--) {
				if(pos == 0) {
					if(*current!=head) {
						newNode->next = *current;
						*current = newNode;
					}
					else {
						*current = newNode;
						newNode->next = head;
						tail = newNode;
					}



				}
				else
					current = &(*current)->next;
			}
			cout<<"One node inserted!!"<<endl;
		}

	}

	void display() {
		if(head == NULL)
			cout<<"List is empty!!"<<endl;
		else {
			cout<<"List elements are: "<<endl;
			Node *trav = head;
			if(head->next == head )
				cout<<head->element<<" -> ";
			else {
				while(trav->next != head) {
					cout<<trav->element<<" -> ";
					trav = trav->next;
				}
				cout<<trav->element<<" -> ";
			}
			cout<<"HEAD"<<endl;
		}
	}

	void deletionAtBegin() {
		if(head == NULL)
			cout<<"List is already empty!!"<<endl;
		else {
			Node *temp = head;
			if(head->next == head)
				head = tail = NULL;
			else {
				head = head->next;
				tail->next = head;
			}
			delete temp;
			cout<<"One node deleted!!"<<endl;
		}
	}


	void deletionAtEnd() {
		if(head == NULL)
			cout<<"List is already empty!!"<<endl;
		else {
			Node *trav = head, *prev = NULL;

			while(trav->next!=head) {
				prev = trav;
				trav = trav->next;
			}

			if(prev == NULL)
				head = NULL;
			else
				prev->next = head;
			delete trav;
			cout<<"One node deleted!!"<<endl;
		}
	}


	void deletionAtSpecific(int pos) {
		if(pos<1 || pos>count())
			cout<<"Invalid position!!"<<endl;
		else {
			Node **temp = &head, *prev;
			while(pos--) {
				if(pos == 0) {
						Node *temporary = (*temp)->next;
						if(head->next == head) {
							head = tail = NULL;
							delete *temp;
						}
						else if(temporary == head) {
							delete *temp;
							*temp = temporary;
							tail = prev;
						}
						else {
							delete *temp;
							*temp = temporary;
						}

				}
				else {
					prev = *temp;
					temp = &(*temp)->next;
				}
			}
			cout<<"One node deleted!!"<<endl;
		}
	}
};



int main() {
	int choice, choice1, element, pos;
	LinkedList li;
	while(1) {
		cout<<"1. Exit\n2. Insertion\n3. Deletion\n4. Display\n";
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice) {
		case 1:
			exit(0);
			break;
		case 2: // insertion
			cout<<"Enter element that you want to insert: ";
			cin>>element;
			cout<<"1. Begin\n2. End\n3. Specific\n";
			cout<<"Enter your choice: ";
			cin>>choice1;
			switch(choice1) {
			case 1:
				li.insertionAtBegin(element);
				// insertion at begin
				break;
			case 2:
				li.insertionAtEnd(element);
				// insertion at end
				break;
			case 3:
				// insertion at specific
				cout<<"Enter position: ";
				cin>>pos;
				li.insertionAtSpecific(element, pos);
				break;
			default:cout<<"Invalid choice!!!\n";
			}
			break;
		case 3: // deletion
			cout<<"1. Begin\n2. End\n3. Specific\n";
			cout<<"Enter your choice: ";
			cin>>choice1;
			switch(choice1) {
			case 1:
				// deletion at begin
				li.deletionAtBegin();
				break;
			case 2:
				// deletion at end
				li.deletionAtEnd();
				break;
			case 3:
				// deletion at specific
				cout<<"Enter position: "<<endl;
				cin>>pos;
				li.deletionAtSpecific(pos);
				break;
			default:cout<<"Invalid choice!!!\n";
			}
			break;
		case 4: // display
			li.display();
			break;
		default: cout<<"Invalid choice!!!\n";
		}
	}
	return 0;
}

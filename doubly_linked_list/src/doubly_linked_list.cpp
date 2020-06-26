//============================================================================
// Name        : doubly_linked_list.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class LinkedList;

class Node {
	int element;
	Node *next;
	Node *prev;


public:
	Node() {
		element = 0;
		next = NULL;
		prev = NULL;
	}

	Node(int element) {
		this->element = element;
		next = NULL;
		prev= NULL;
	}

	friend class LinkedList;
};


class LinkedList {
	Node *head;

public:
	LinkedList() {
		head = NULL;
	}

	void insertionAtBegin(int element) {
		Node *newNode = new Node(element);
		if(head == NULL) {
			head = newNode;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		cout<<"One node inserted!!"<<endl;
	}

	void insertionAtEnd(int element) {
		Node *newNode = new Node(element);
		if(head == NULL) {
			head = newNode;
		}
		else {
			Node *trav = head;
			while(trav->next != NULL)
				trav = trav->next;
			newNode->prev = trav;
			trav->next = newNode;
		}
		cout<<"One node inserted!!"<<endl;
	}

	int count() {
		Node *trav = head;
		int count = 0;
		while(trav!=NULL) {
			count++;
			trav = trav->next;
		}
		return count;
	}

	void insertionAtSpecific(int element, int pos) {
		if(pos<1 || pos>count() + 1) {
			cout<<"Invalid position!!"<<endl;
		}
		else {
			Node **current = &head, *temp = head, *newNode = new Node(element);

			while(pos--) {
				if(pos == 0) {
					newNode->next = *current;
					if(*current != NULL) {
						newNode->prev = (*current)->prev;
						(*current)->prev = newNode;
					}
					else
						newNode->prev = temp;
					*current = newNode;
				}
				else {
					temp = *current;
					current = &(*current)->next;
				}
			}
			cout<<"One node inserted!!"<<endl;
		}

	}

	void display() {
		if(head == NULL)
			cout<<"List is empty!!"<<endl;
		else {
			cout<<"List elements in forward direction are: "<<endl;
			Node *trav = head, *previous;
			while(trav != NULL) {
				cout<<trav->element<<" -> ";
				previous = trav;
				trav = trav->next;
			}
			cout<<"NULL"<<endl;

			cout<<"List elements in backward direction are: "<<endl;
			trav = previous;
			while(trav != NULL) {
				cout<<trav->element<<" -> ";
				trav = trav->prev;
			}
			cout<<"NULL"<<endl;
		}
	}

	void deletionAtBegin() {
		if(head == NULL)
			cout<<"List is already empty!!"<<endl;
		else {
			Node *temp = head;
			head = head->next;
			if(head != NULL)
				head->prev = NULL;
			delete temp;
			cout<<"One node deleted!!"<<endl;
		}
	}


	void deletionAtEnd() {
		if(head == NULL)
			cout<<"List is already empty!!"<<endl;
		else {
			Node *trav = head, *prev = NULL;

			while(trav->next!=NULL) {
				prev = trav;
				trav = trav->next;
			}

			if(prev == NULL)
				head = NULL;
			else
				prev->next = NULL;
			delete trav;
			cout<<"One node deleted!!"<<endl;
		}
	}


	void deletionAtSpecific(int pos) {
		if(pos<1 || pos>count())
			cout<<"Invalid position!!"<<endl;
		else {
			Node **temp = &head;
			while(pos--) {
				if(pos == 0) {
					Node *temporary = (*temp)->next;
					if(temporary != NULL) {
						temporary->prev = (*temp)->prev;

					}
					delete *temp;
					*temp = temporary;
				}
				else
					temp = &(*temp)->next;
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


//============================================================================
// Name        : stack_linked_list_based.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdlib.h>
using namespace std;

class Stack;

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

	friend class Stack;
};


class Stack {
	Node *top;

public:
	Stack() {
		top = NULL;
	}

	void push(int element) {
		Node *newNode = new Node(element);
		if(top == NULL) {
			top = newNode;
		}
		else {
			newNode->next = top;
			top = newNode;
		}
		cout<<"One element pushed!!"<<endl;
	}



	int count() {
		Node *trav = top;
		int count = 0;
		while(trav!=NULL) {
			count++;
			trav = trav->next;
		}
		return count;
	}



	void display() {
		if(top == NULL)
			cout<<"Stack is underflow!!"<<endl;
		else {
			cout<<"Stack elements are: "<<endl;
			Node *trav = top;
			while(trav != NULL) {
				cout<<trav->element<<endl;
				trav = trav->next;
			}
		}
	}

	void pop() {
		if(top == NULL)
			cout<<"Stack is underflow!!"<<endl;
		else {
			Node *temp = top;
			top = top->next;
			delete temp;
			cout<<"One element deleted!!"<<endl;
		}
	}

	int peek() {
		if(top == NULL) {
			cout<<"Stack is underflow!!"<<endl;
			return -1;
		}
		else
			return top->element;


	}

};



int main() {
	int choice, element;
	Stack st;
	while(1) {
		cout<<"1. Exit\n2. Push\n3. Pop\n4. Display\n5. Peek\n";
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice) {
		case 1:
			exit(0);
			break;
		case 2: // insertion
			cout<<"Enter element that you want to insert: ";
			cin>>element;
			st.push(element);
			break;
		case 3: // deletion
			st.pop();
			break;
		case 4: // display
			st.display();
			break;
		case 5: // peek
			element = st.peek();
			if(element != -1)
				cout<<"Top element is "<<element<<endl;
			break;
		default: cout<<"Invalid choice!!!\n";
		}
	}
	return 0;
}

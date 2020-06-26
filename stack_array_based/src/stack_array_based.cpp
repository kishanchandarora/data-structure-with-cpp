//============================================================================
// Name        : stack_array_based.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define SIZE 5

class Stack {
	int arr[SIZE];
	int top;

public:
	Stack() {
		for(int i=0; i<SIZE; i++)
			arr[i] = -1;
		top = -1;
	}

	void push(int element) {
		if(top == SIZE-1) {
			cout<<"Stack is overflow!!"<<endl;
			return;
		}
		arr[++top] = element;
		cout<<"One element pushed"<<endl;
	}

	void pop() {
		if(top == -1) {
			cout<<"Stack is underflow!!"<<endl;
			return;
		}

		arr[top--] = -1;
		cout<<"One element popped!!"<<endl;
	}

	void display() {
		if(top == -1) {
			cout<<"Stack is underflow!!"<<endl;
			return;
		}

		cout<<"Stack elements are: "<<endl;
		for(int i=top; i>=0; i--) {
			cout<<arr[i]<<endl;
		}
	}

	int peek() {
		if(top == -1) {
			cout<<"Stack is underflow!!"<<endl;
			return -1;
		}

		return arr[top];
	}


};
int main() {
	// menu driven
	int choice, element;
	Stack st;

	while(1) {
		cout<<"1. Push\n2. Pop\n3. Display\n4. peek\n5. Exit\n";
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice) {
		case 1:
			cout<<"Enter element you want to push: ";
			cin>>element;
			st.push(element);
			break;
		case 2:
			st.pop();
			break;
		case 3:
			st.display();
			break;
		case 4:
			element = st.peek();
			if(element != -1)
				cout<<"Peek element is: "<<element<<endl;
			break;
		case 5:
			exit(0);
			break;
		default: cout<<"Invalid choice!!"<<endl;
		}
	}
	return 0;
}

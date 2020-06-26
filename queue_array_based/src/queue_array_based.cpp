//============================================================================
// Name        : queue_array_based.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define SIZE 5


class Queue {
	int arr[SIZE];
	int rear, front;

public:
	Queue() {
		for(int i=0; i<SIZE; i++)
			arr[i] = -1;
		rear = front = -1;
	}


	void enQueue(int element) {
		if(rear == SIZE - 1) {
			cout<<"Queue is FULL!!! Insertion is not possible!!!"<<endl;
			return;
		}
		arr[++rear] = element;
		cout<<"One element is enqueued"<<endl;
	}

	void deQueue() {
		if(rear == front) {
			cout<<"Queue is EMPTY!!! Deletion is not possible!!!"<<endl;
			return;
		}
		cout<<"Deleted element is: "<<arr[++front]<<endl;
		if(front == rear) {
			rear = front = -1;
		}
	}

	void display() {
		if(rear == front)
			cout<<"Queue is Empty!!!"<<endl;
		else{
			cout<<"Queue elements are: "<<endl;
			for(int i=front+1; i<=rear; i++)
				cout<<arr[i]<<"\t";
			cout<<endl;
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

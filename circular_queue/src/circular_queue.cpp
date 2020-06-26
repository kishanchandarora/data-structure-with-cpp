//============================================================================
// Name        : circular_queue.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#define SIZE 5
#include <iostream>
using namespace std;

class CircularQueue {
	int arr[SIZE];
	int front, rear;
public:
	CircularQueue() {
		for(int i=0; i<SIZE; i++)
			arr[i] = -1;
		front = rear = -1;
	}

	bool isFull() {
		if((front == -1 && rear == SIZE -1 ) || (rear == front && rear != -1) )
			return true;
		return false;
	}

	bool isEmpty() {
		if(front == -1 && rear == -1)
			return true;
		return false;
	}

	void enQueue(int element) {
		if(isFull()) {
			cout<<"Queue is FULL!!! Insertion is not possible!!!"<<endl;
			return;
		}

		if(rear == SIZE - 1 )
			rear = 0;
		else
			rear = rear + 1;
		arr[rear] = element;
		cout<<"One element inserted!!!"<<endl;
	}

	void deQueue() {
		if(isEmpty()) {
			cout<<"Queue is EMPTY!!! Deletion is not possible!!!"<<endl;
			return;
		}
		if(front == SIZE - 1)
			front = 0;
		else
			front = front + 1;

		cout<<"One element deleted is: "<<arr[front]<<endl;

		if(front == rear)
			front = rear = -1;
	}

	void display() {
		if(isEmpty())
			cout<<"Queue is EMPTY!!!"<<endl;
		else {
			int i = front + 1;

			if(front < rear) {
				while(i<=rear) {
					cout<<arr[i]<<"\t";
					i++;
				}
				cout<<endl;
			}
			else {
				while(i <=SIZE - 1) {
					cout<<arr[i]<<"\t";
					i++;
				}
				i=0;
				while(i<=rear) {
					cout<<arr[i]<<"\t";
					i++;
				}
				cout<<endl;
			}
		}
	}
};

int main() {
	int choice, element;
	CircularQueue q;
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

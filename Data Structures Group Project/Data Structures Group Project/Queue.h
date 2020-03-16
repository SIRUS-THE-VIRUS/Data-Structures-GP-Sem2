#include "LNode.h"
using namespace std;

class Queue {
private:
	LNode* front;
	LNode* rear;
public:
	Queue() {
		front = NULL;
		rear = NULL;
	}
	LNode* getFront() {
		return front;
	}
	LNode* getRear() {
		return rear;
	}
	void setFront(LNode* n) {
		front = n;
	}
	void setRear(LNode* n) {
		rear = n;
	}
	void Enqueue(string guess) {
		LNode* temp = new LNode(guess);
		if (temp != NULL) {
			if (front == NULL) {
				front = temp;
				rear = temp;
			}
			else {
				rear->setNextNode(temp);
				temp->setPrevNode(rear);
				rear = temp;
			}
		}
		else {
			cout << "The list is full.Cannot add another node." << endl;
		}
	}
	string Dequeue(){
		letters dataToReturn;
		if (front != NULL)
		{
			if (front == rear)
			{
				rear = NULL;
			}
				LNode* temp = front;
			dataToReturn = front->getData();
			front = front->getNextNode();
			temp = NULL;
		}
		return dataToReturn.getguess();
	}

	int CountNodes()
	{
		int count = 0;
		Queue* tempQueue = new Queue();
		while (front != NULL)
		{
			tempQueue->Enqueue(Dequeue());
			count++;
		}
		while (tempQueue->getFront() != NULL)
		{
			Enqueue(tempQueue->Dequeue());
		}
		return count;
	}
	int searchNode(string search)
	{
		int found = 0;
		Queue* tempQueue = new Queue();
		while (front != NULL)
		{
			if (search == getFront()->getData().getguess()) {
				found = 1;
			}
			tempQueue->Enqueue(Dequeue());
		}
		while (tempQueue->getFront() != NULL)
		{
			Enqueue(tempQueue->Dequeue());
		}
		return found;
	}
};
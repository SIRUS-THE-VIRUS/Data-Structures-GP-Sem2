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
	
};
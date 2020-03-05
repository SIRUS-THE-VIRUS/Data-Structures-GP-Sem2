#include "LNode.h"

class Queue {
private:
	Node* Front;
	Node* Rear;
public:
	Queue() {
		Front = NULL;
		Rear = NULL;
	}
	Node* getFront() {
		return Front;
	}
	Node* getRear() {
		return Rear;
	}
	void setFront(Node* n) {
		Front = n;
	}
	void setRear(Node* n) {
		Rear = n;
	}
	void Enqueue(string guess) {
		Node* temp = new Node(guess);
		if (temp != NULL) {
			if (Front == NULL) {
				Front = temp;
				Rear = temp;
			}
			else {
				Rear->setNextNode(temp);
				temp->setPrevNode(Rear);
				Rear = temp;
			}
		}
		else {
			cout << "The list is full.Cannot add another node." << endl;
		}
	}
	
};
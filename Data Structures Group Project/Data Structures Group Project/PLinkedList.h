#include "PNode.h"
using namespace std;

class PLinkedList {
private:
	PNode* head;
public:
	PLinkedList() {
		head = NULL;
	}
	void append(int playerNum, string playerName, float grandTotal) {
		if (head == NULL) {
			head = new PNode(playerNum, playerName, grandTotal);
			return;
		}
		PNode* current = head;
		while (current->getNext() != NULL) {
			current = current->getNext();
		}
		current->setNext(new PNode(playerNum, playerName, grandTotal));
	}
	void display() {
		PNode* temp = new PNode;
		temp = head;
		while (temp != NULL) {
			temp->getdata();
			temp = temp->getNext();
		}
	}
};
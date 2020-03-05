#include <iostream>
#include "PNode.h"
using namespace std;

class PLinkedList {
private:
	Node* head;
public:
	PLinkedList() {
		head = NULL;
	}
	void append(int playerNum, string playerName, float grandTotal) {
		if (head == NULL) {
			head = new Node(playerNum, playerName, grandTotal);
			return;
		}
		Node* current = head;
		while (current->getNext() != NULL) {
			current = current->getNext();
		}
		current->setNext(new Node(playerNum, playerName, grandTotal));
	}
	void display() {
		Node* temp = new Node;
		temp = head;
		while (temp != NULL) {
			temp->getdata();
			temp = temp->getNext();
		}
	}
};
#include <iostream>
#include "WNode.h"
string wtype;
using namespace std;
class WLinkedList {
private:
	WNode* head;
	WNode* tail;
public:
	WLinkedList() {
		head = NULL;
		tail = NULL;
	}
	void append(string type, int value) {
		WNode* newNode = new WNode(type, value);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
			newNode->setNext(head);
		}
		else {
			tail->setNext(newNode);
			tail = newNode;
			tail->setNext(head);
		}
	}
	int traverse(int pos) {
		WNode* cur = new WNode;
		cur = head;
		for (int i = 1; i < pos; i++) {
			cur = cur->getNext();
		}
		if (cur->getdataType() == "Money") {
			return cur->getdataValue();
		}
		else {
			wtype = cur->getdataType();
			return 0;
		}
	}
	void display() {
		WNode* cur = head;
		while (cur != NULL) {
			cur->getdata();
			cur = cur->getNext();
		}
	}
};
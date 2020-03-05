#include <iostream>
#include "Card.h"
using namespace std;

class Node {
private:
	card data;
	Node* next;
public:
	Node():data() {
		next = NULL;
	}
	Node(string type, int value) {
		data.setType(type);
		data.setValue(value);
	}
	void setNext(Node* next) {
		this->next = next;
	}
	Node* getNext() {
		return next;
	}
	void getdata() {
		data.display();
	}
	int getdataValue() {
		return data.getValue();
	}
	string getdataType() {
		return data.getType();
	}

};

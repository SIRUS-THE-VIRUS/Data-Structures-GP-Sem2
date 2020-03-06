#include <iostream>
#include "Card.h"
using namespace std;

class WNode {
private:
	card data;
	WNode* next;
public:
	WNode():data() {
		next = NULL;
	}
	WNode(string type, int value) {
		data.setType(type);
		data.setValue(value);
	}
	void setNext(WNode* next) {
		this->next = next;
	}
	WNode* getNext() {
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

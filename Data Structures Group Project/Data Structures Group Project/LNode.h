#include "Letters.h"

class LNode {
private:
	letters data;
	LNode* NextNode;
	LNode* PrevNode;
public:
	LNode() :data() {
		NextNode = NULL;
		PrevNode = NULL;
	}
	LNode(string guess) :data(guess) {
		NextNode = NULL;
		PrevNode = NULL;
	}
	LNode* getNextNode() {
		return NextNode;
	}
	void setNextNode(LNode* nextNode) {
		NextNode = nextNode;
	}
	LNode* getPrevNode() {
		return PrevNode;
	}
	void setPrevNode(LNode* prevNode) {
		PrevNode = prevNode;
	}
	letters getData() {
		return data;
	}
	void setData(letters data) {
		this->data = data;
	}
};
#include "Letters.h"

class Node {
private:
	letters data;
	Node* NextNode;
	Node* PrevNode;
public:
	Node() :data() {
		NextNode = NULL;
		PrevNode = NULL;
	}
	Node(string guess) :data(guess) {
		NextNode = NULL;
		PrevNode = NULL;
	}
	Node* getNextNode() {
		return NextNode;
	}
	void setNextNode(Node* nextNode) {
		NextNode = nextNode;
	}
	Node* getPrevNode() {
		return PrevNode;
	}
	void setPrevNode(Node* prevNode) {
		PrevNode = prevNode;
	}
	letters getData() {
		return data;
	}
	void setData(letters data) {
		this->data = data;
	}
};
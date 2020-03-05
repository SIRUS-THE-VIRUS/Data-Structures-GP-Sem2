#include <iostream>
#include "Player.h"
using namespace std;

class Node {
private:
	player data;
	Node* next;
public:
	Node() {
		player();
		next = NULL;
	}
	Node(int playerNum, string playerName, int grandTotal) {
		data.setPlayerNum(playerNum);
		data.setPlayerName(playerName);
		data.setGrandTotal(grandTotal);
	}
	void setNext(Node* next) {
		this->next = next;
	}
	Node* getNext() {
		return next;
	}
	//get data from Player to be implemented
	void getdata() {
		data.display();
	}
};


#include "Player.h"
using namespace std;

class PNode {
private:
	player data;
	PNode* next;
public:
	PNode():data() {
		next = NULL;
	}
	PNode(int playerNum,string playerName,float grandTotal):data(playerNum,playerName,grandTotal) {

	}
	void setNext(PNode* next) {
		this->next = next;
	}
	PNode* getNext() {
		return next;
	}
	//get data from Player to be implemented
	void getdata() {
		data.display();
	}
};

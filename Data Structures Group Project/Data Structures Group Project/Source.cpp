#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
using namespace std;
string wtype;
class player {
private:
	int playerNum;
	string playerName;
	int grandTotal;
public:
	player() {
		playerNum = 0;
		playerName = "Undefined";
		grandTotal = 0.0;
	}
	player(int playerNum,string playerName,int grandTotal) {
		this->playerName = playerName;
		this->playerNum = playerNum;
		this->grandTotal = grandTotal;
	}
	//setters mutators
	void setPlayerNum(int playerNum) {
		this->playerNum = playerNum;
	}
	void setPlayerName(string playerName) {
		this->playerName = playerName;
	}
	void setGrandTotal(int grandTotal) {
		this->grandTotal = grandTotal;
	}
	//getters
	int getPlayerNum() {
		return playerNum;
	}
	string getPlayerName() {
		return playerName;
	}
	int getGrandTotal() {
		return grandTotal;
	}
	//display funtion to be used in the get data for the PNode class
	void display() {
		cout << "Player Number:      " << playerNum << endl;
		cout << "Player Name:        " << playerName << endl;
		cout << "Player Grand Total: " << grandTotal << endl;
	}
};

class PNode {
private:
	player data;
	PNode* next;
public:
	PNode() {
		player();
		next = NULL;
	}
	PNode(int playerNum,string playerName,int grandTotal) {
		data.setPlayerNum(playerNum);
		data.setPlayerName(playerName);
		data.setGrandTotal(grandTotal);
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
//Everything above has to do with the Player Linked List (PNode - Player Node)

class card {
private:
	string type;
	int value;
public:
	card() {
		type = "None";
		value = 9999;
	}
	void setType(string type) {
		this->type = type;
	}
	void setValue(int value) {
		this->value = value;
	}
	string getType() {
		return type;
	}
	int getValue() {
		return value;
	}
	void display() {
		cout << "Card Type:      " << type << endl;
		cout << "Card Value:        " << value << endl;
	}
};

class WNode {
private:
	card data;
	WNode* next;
public:
	WNode() {
		player();
		next = NULL;
	}
	WNode(string type,int value) {
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
		WNode* newNode = new WNode(type,value);
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

class Round {
private:
	string category;
	string puzzle;
	int roundTotal;
public:
	Round() {
		category = "";
		puzzle = "";
		roundTotal = 0;
	}
	void setCategory(string category) {
		this->category = category;
	}
	void setPuzzle(string puzzle) {
		this->puzzle = puzzle;
	}
	void setRoundTotal(int roundTotal) {
		this->roundTotal = roundTotal;
	}
	string getCategory() {
		return category;
	}
	string getPuzzle() {
		return puzzle;
	}
	int getRoundTotal() {
		return roundTotal;
	}
};

int main() {
	string temp,temp2,cattemp;
	PLinkedList* list = new PLinkedList();
	WLinkedList* wheel = new WLinkedList();
	Round roundObj;
	cout << "Welcome to wheel of fortune... 3 player game" << endl;
	for (int i = 1; i <= 3; i++) {
		cout << "Enter player "<< i <<" name: ";
		cin >> temp;
		list->append(i, temp, 0);
	}
	cout << "Genereating Wheel........." << endl;
	wheel->append("bankrupcy", 0);
	wheel->append("bankrupcy", 0);
	wheel->append("bankrupcy", 0);
	wheel->append("bankrupcy", 0);
	wheel->append("bankrupcy", 0);
	wheel->append("bankrupcy", 0);
	wheel->append("bankrupcy", 0);
	cout << "Wheel Generated successfully" << endl;
	//wheel->display();
	cout << "Generating Round data......." << endl;

	cout << "Round 1" << endl;
	cout << "Player 1 press enter to spin the wheel " << endl;
	int randomnum = 50 + rand() % 150;
	cout << "random number genereated : " << randomnum << endl;
	if (wheel->traverse(randomnum) > 0) {
		cout << "You landed on money" << endl;

	}
	else {
		cout << "You landed on " << wtype << endl;
	}

	cout << "Player 1 select Category (Person,Place,Thing,) : ";
	cin >> cattemp;
	ifstream infile;
	infile.open("puzzle.txt");
	while (infile >> temp >> temp2) {
		if (temp == cattemp) {
			roundObj.setCategory(temp);
			roundObj.setPuzzle(temp2);
		}
	}



	cout << "Round data generated successfully" << endl;
	cout << "=======================================" << endl;
	return 0;
}
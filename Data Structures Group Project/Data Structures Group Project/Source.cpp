#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
using namespace std;

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
};
class WLinkedList {
private:
	WNode* head;
public:
	WLinkedList() {
		head = NULL;
	}
	void append(string type, int value) {
		if (head == NULL) {
			head = new WNode(type,value);
			return;
		}
		WNode* current = head;
		while (current->getNext() != NULL) {
			current = current->getNext();
		}
		current->setNext(new WNode(type, value));
	}
	void display() {
		WNode* temp = new WNode;
		temp = head;
		while (temp != NULL) {
			temp->getdata();
			temp = temp->getNext();
		}
	}
};

class round {
private:
	string category;
	string puzzle;
	int roundTotal;
public:
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
	string temp;
	PLinkedList* list = new PLinkedList();
	WLinkedList* wheel = new WLinkedList();
	cout << "Welcome to wheel of fortune... 3 player game" << endl;
	for (int i = 1; i <= 3; i++) {
		cout << "Enter player "<< i <<" name: ";
		cin >> temp;
		list->append(i, temp, 0);
	}
	cout << "Genereating Wheel........." << endl;
	for (int i = 0; i < 21; i++) {
		int money = 500 + rand()%2000;
		wheel->append("Money", money);
	}
	wheel->append("Lose a Turn", 0);
	wheel->append("Bankruptcy", 0);
	wheel->append("Bankruptcy", 0);
	wheel->append("Bankruptcy", 0);
	cout << "Wheel Generated successfully" << endl;
	cout << "Generating Round data......." << endl;





	cout << "Round data generated successfully" << endl;

	list->display();
	cout << "=======================================" << endl;
	wheel->display();
	return 0;
}
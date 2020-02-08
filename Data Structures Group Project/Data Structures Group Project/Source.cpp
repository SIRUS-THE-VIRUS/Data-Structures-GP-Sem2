#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
using namespace std;

class player {
private:
	int playerNum;
	string playerName;
	float grandTotal;
public:
	player() {
		playerNum = 0;
		playerName = "Undefined";
		grandTotal = 0.0;
	}
	player(int playerNum,string playerName,float grandTotal) {
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
	void setGrandTotal(float grandTotal) {
		this->grandTotal = grandTotal;
	}
	//getters
	int getPlayerNum() {
		return playerNum;
	}
	string getPlayerName() {
		return playerName;
	}
	float getGrandTotal() {
		return grandTotal;
	}
	//display funtion to be used in the get data for the node class
	void display() {
		cout << "Player Number:      " << playerNum << endl;
		cout << "Player Name:        " << playerName << endl;
		cout << "Player Grand Total: " << grandTotal << endl;
	}
};

class Node {
private:
	player data;
	Node* next;
public:
	Node(int playerNum,string playerName,float grandTotal) {
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
	
};

class linkedList {
private:
	Node* head;
public:
	linkedList() {
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
};
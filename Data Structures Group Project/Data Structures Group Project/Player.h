#include <iostream>
#include <string>
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
	player(int playerNum, string playerName, float grandTotal) {
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
	//display funtion to be used in the get data for the PNode class
	void display() {
		cout << "Player Number:      " << playerNum << endl;
		cout << "Player Name:        " << playerName << endl;
		cout << "Player Grand Total: " << grandTotal << endl;
	}
};

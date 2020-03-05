#include "Queue.h"
#include "PLinkedList.h"
#include "WLinkedList.h"
#include <fstream>
#include <iostream>
using namespace std;

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
	int round = 1;
	string temp,temp2,cattemp,ans,guess;
	bool solved = false;
	PLinkedList* list = new PLinkedList();
	WLinkedList* wheel = new WLinkedList();
	Queue* g_letters = new Queue();
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
	while (round <= 3) {
		cout << "Round " << round << endl;
		cout << "select Category (Person,Place,Thing) : ";
		cin >> cattemp;
		ifstream infile;
		infile.open("puzzle.txt");
		while (infile >> temp >> temp2) {
			if (temp == cattemp){
				roundObj.setCategory(temp);
				roundObj.setPuzzle(temp2);
			}
		}
		while (solved == false) {
			cout << "press enter to spin the wheel " << endl;
			int randomnum = 50 + rand() % 150;
			cout << "random number genereated : " << randomnum << endl;
			if (wheel->traverse(randomnum) > 0) {
				cout << "You landed on money" << endl;

			}
			else {
				cout << "You landed on " << wtype << endl;
			}

			cout << "would you like to Guess or Solve: ";
			cin >> temp;
			if (temp == "Guess") {
				cout << "What letter: ";
				cin >> guess;
				//if guess is in the queue of guessed letters then you can't guess that letter try again
				//otherwise do the enqueue of the guess letter below
				g_letters->Enqueue(guess);
			}
			else if (temp == "Solve") {
				cout << "What is the answer: ";
				cin >> ans;
				if (ans == roundObj.getPuzzle()) {
					cout << "correct";
					solved = true;
				}
				else {
					cout << "incorrect";
				}
			}
		}
		cout << "End of Round " << round << endl;
		round += 1;
	}
	return 0;
}
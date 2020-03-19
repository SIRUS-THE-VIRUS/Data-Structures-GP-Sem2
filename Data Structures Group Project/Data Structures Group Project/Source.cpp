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
	int roundTotal[3];
public:
	Round() {
		category = "";
		puzzle = "";
	}
	void setCategory(string category) {
		this->category = category;
	}
	void setPuzzle(string puzzle) {
		this->puzzle = puzzle;
	}
	void setRoundTotal(int roundTotal,int i) {
		this->roundTotal[i] = roundTotal;
	}
	string getCategory() {
		return category;
	}
	string getPuzzle() {
		return puzzle;
	}
	int getRoundTotal(int i) {
		return roundTotal[i];
	}
};

int main() {

	int round = 1,money_value = 0;
	int total[4] = { 0,0,0,0 };
	int vowel_amount = 50;
	string name[4];
	string Answer;
	string temp, temp2, cattemp, ans, guess;
	bool solved = false;
	PLinkedList* list = new PLinkedList();
	WLinkedList* wheel = new WLinkedList();
	Queue* g_letters = new Queue();
	Round roundObj;
	cout << "\t \t \t ***********************************************\n";
	cout << "\t\t\t   Welcome to wheel of fortune... 3 player game" << endl;
	cout << "\t \t \t ***********************************************\n\n";
	for (int i = 1; i <= 3; i++) {
		cout << "Enter player " << i << " name: ";
		cin >> temp;
		name[i] = temp;
		list->append(i, temp, 0);
	}
	//list->display();
	//list->deleteNode(1);
	//list->display();
	////list->insertNth(2, "daddy", 5000, 1);
	//list->display();
	system("pause");
	system("CLS");

	cout << "Generating Wheel........." << endl;
	system("pause");
	system("CLS");
	wheel->append("Money", 100);
	wheel->append("Money", 200);
	wheel->append("Money", 300);
	wheel->append("Money", 400);
	wheel->append("Money", 500);
	wheel->append("Money", 600);
	wheel->append("Money", 700);

	cout << "\nWheel was Generated successfully\n" << endl;

	while (round <= 3) {
		int skip[4] = { 0,0,0,0 };
		cout << "\t \t \t \t Round " << round << endl;
		cout << "Select a Category  (Person,Place,Thing) : ";
		cin >> cattemp;
		system("CLS");
		cout << "Category: " << cattemp << endl;
		cout << "\n" << endl;
		ifstream infile;

		infile.open("puzzle.txt");
		while (infile >> temp >> temp2) 
		{
			if (temp == cattemp)
			{
				roundObj.setCategory(temp);
				roundObj.setPuzzle(temp2);
			}
		}
		for (int i = 1; i <= 3; i++) {
			cout << "\n";
			while (solved == false)
			{
				if (skip[1] == 1 && skip[2] == 1 && skip[3] == 1) {
					cout << "you all are bankrupt no one wins" << endl;
					round++;
					i = 3;
					break;
				}
				else if(skip[i] == 1) {
					if (i == 3) {
						i = 0;
						break;
					}
					break;
				}
				cout << "Player " << i << endl;
				cout << "\n";
				cout << "Press enter to spin the wheel " << endl;
				system("pause");

				int randomnum = 50 + rand() % 150;
				cout << "Random number genereated : " << randomnum << endl;
				money_value = wheel->traverse(randomnum);
				if (money_value > 0) {
					cout << "You landed on money" << endl;
					cout << "TEST" << endl;
					cout << "Money : " << money_value << endl;	
				}
				else if(money_value==0) {
					cout << "You landed on " << wtype << endl;
					if (wtype == "bankrupcy") {
						roundObj.setRoundTotal(0, i);
						if (i == 3) {
							skip[i] = 1;
							i = 0;
							break;
						}
						skip[i] = 1;
						break;
					}
					else if (wtype == "lose a turn") {
						if (i == 3) {
							i = 0;
							break;
						}
						break;
					}
					}
				cout << money_value;
				cout << "Would you like to Guess or Solve or BuyVowel: ";
				cin >> temp;
				if (temp == "Guess") {
					int occurence = 0;
					char guess2[2];
					while (true) {
						cout << "What letter?  " << endl;
						cin >> guess;
						strcpy_s(guess2, guess.c_str());
						if (g_letters->searchNode(guess) == 1) {
							cout << "This letter has already been guessed" << endl;
							cout << "Try again" << endl;
						}
						else {
							break;
						}
					}
					if (g_letters->searchNode(guess) != 1) {
						g_letters->Enqueue(guess);
						string s = roundObj.getPuzzle();
						for (int x = 0; x < s.length(); x++) {
							if (s[x] == guess2[0]) {
								occurence++;
							}
						}
						if (occurence == 0) {
							cout << "That letter was not found in the word" << endl;
							if (i == 3) {
								i = 0;
								break;
							}
							break;
						}
						else {
							total[i] += occurence * money_value;
							roundObj.setRoundTotal(total[i], i);
							cout << "That letter was found in the word" << endl;
						}

					}
				}
				else if (temp == "Solve") {
					if (total[i] > 0) {
						cout << "What is the answer? ";
						cin >> ans;
						if (ans == roundObj.getPuzzle()) {
							cout << "correct\n";
							total[i] += money_value;
							list->deleteNode(i-1);
							list->insertNth(i, name[i], total[i], i-1);
							cout << "SCORES BELOW" << endl;
							list->display();
							solved = true;
						}
						else {

							cout << "incorrect\n";
						}
					}
					else {
						cout << "you can't solve. you do not have any money" << endl;
					}
					
				}
				else if (temp == "BuyVowel")
				{
					int num;
					string vowel;
					cout << "\n";
					cout << "Enter the vowel you wish to buy (a, e, i, o or u): " << endl;
					cin >> vowel;

					if (vowel == "a" || vowel == "e" || vowel == "i" || vowel == "o" || vowel == "u")
					{
						if (total[i] > vowel_amount)
						{
							cout << " Money left :" << total[i] << endl;
							int occurence = 0;
							char guess2[2];
							strcpy_s(guess2, vowel.c_str());
							if (g_letters->searchNode(vowel) == 1)
							{
								cout << "Vowel has already been guessed" << endl;
								cout << "try again" << endl;
							}
							else {
								total[i] = money_value - vowel_amount;
								g_letters->Enqueue(vowel);
								string s = roundObj.getPuzzle();
								for (int x = 0; x < s.length(); x++){
									occurence++;
								}
							}
							if (occurence == 0)
							{
								cout << "That letter was not found in the word" << endl;
								if (i == 3)
								{
									i = 0;
									break;
								}
								break;
							}
							else {
								total[i] += occurence * money_value;
								roundObj.setRoundTotal(total[i], i);
								cout << "That letter was found in the word" << endl;
							}
						}
						else if (total[i] < vowel_amount)
						{
							cout << "Sorry, you dont have enough money \n";
						}
					}
					else
					{
						cout << "You did not enter a vowel \n";
					}
				}
				if (solved == true) {
					cout << "End of Round " << round << endl;
					round++;
					cout << "Do you want to exit the game?" << endl;
					cin >> Answer;
					if (Answer == "Yes" || Answer == "yes")
					{
						cout << "Scores before exiting shown below" << endl;
						list->display();
						cout << "Thank you for playing" << endl;
						exit(0);
					}
					else if (Answer == "No" || Answer == "no")
					{
						g_letters->setFront(NULL);
						solved = false;
						break;
					}
				}
			}
			if (Answer == "No" || Answer == "no")
				break;
		}
		cout << "End of 3 rounds... Scores shown below" << endl;
		list->display();
	}
	return 0;
}
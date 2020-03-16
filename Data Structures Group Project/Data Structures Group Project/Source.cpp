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

	int round = 1;
	int total[4] = {0,0,0,0};
	int vowel_amount = 50;
	string temp, temp2, cattemp, ans, guess;
	bool solved = false;
	PLinkedList* list = new PLinkedList();
	WLinkedList* wheel = new WLinkedList();
	Queue* g_letters = new Queue();
	Round roundObj;
	cout << "Welcome to wheel of fortune... 3 player game" << endl;
	for (int i = 1; i <= 3; i++) {
		cout << "Enter player " << i << " name: ";
		cin >> temp;
		list->append(i, temp, 0);
	}
	system("pause");
	system("CLS");

	cout << "Generating Wheel........." << endl;
	wheel->append("money", 10);
	wheel->append("money", 20);
	wheel->append("money", 30);
	wheel->append("money", 40);
	wheel->append("money", 50);
	wheel->append("money", 60);
	wheel->append("bankrupcy", 70);


	cout << "Wheel Generated successfully\n" << endl;

	while (round <= 3) {
		cout << "Select a Category for round(Person,Place,Thing) : ";
		cin >> cattemp;
		system("CLS");
		cout << "Category: " << cattemp << endl;
		cout << "\n" << endl;
		ifstream infile;

		infile.open("puzzle.txt");
		while (infile >> temp >> temp2) {
			if (temp == cattemp) {
				roundObj.setCategory(temp);
				roundObj.setPuzzle(temp2);
			}
		}
		for (int i = 1; i <= 3; i++) { //new
			cout << "\t \t \t \t Round " << round << endl;
			cout << "\n";
			while (solved == false) {
				cout << "Player " << i << endl; //new
				cout << "\n";
				cout << "press enter to spin the wheel " << endl;
				system("pause");

				int randomnum = 50 + rand() % 150;
				cout << "random number genereated : " << randomnum << endl;
				int money_value = wheel->traverse(randomnum);
				if (money_value > 0) {
					cout << "You landed on money" << endl;
					cout << "money : " << money_value << endl;

				}
				else {

					cout << "You landed on " << wtype << endl;
					if (wtype == "bankrupcy") {
						roundObj.setRoundTotal(0, i);
						break;
					}
					else if (wtype == "lose a turn") {
						break;
					}

				}

				cout << "would you like to Guess or Solve or BuyVowel: ";
				cin >> temp;
				if (temp == "Guess") {
					while (true) {
						int occurence = 0;
						cout << "What letter: "<<endl;
						cin >> guess;
						char guess2[2];
						strcpy_s(guess2, guess.c_str());
						if (g_letters->searchNode(guess) == 1) {
							cout << "Letter has already been guessed" << endl;
							cout << "try again" << endl;
						}
						else {
							g_letters->Enqueue(guess);
							string s = roundObj.getPuzzle();
							for (int i = 0; i < s.length(); i++) {
								if (s[i] == guess2[0]) {
									occurence++;
								}
							}
							if (occurence == 0) {
								break;
							}
							else { 
								total[i] += occurence * money_value;
								roundObj.setRoundTotal(total[i], i);
								break;
							}
						}
					}
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
				else if (temp == "BuyVowel")
				{
					int num;
					char vowel;
					cout << "Enter player number: ";
					cin >> num;
					cout << "\n";
					cout << "Enter the vowel you wish to buy (a, e, i, o or u): " << endl;
					cin >> vowel;
					int i =0;
					
					if (vowel == 'a'||vowel =='e'||vowel=='i'||vowel=='o'||vowel =='u') 
					{
						if (money_value > vowel_amount)
						{
							while (num = i )
							{
								total[i] = money_value - vowel_amount;
								cout << " Money left :" << total[i] << endl;
								i++;
							}
							//add the vowel to the word if it is in the word if not then tell them it is not a part of the word
						}
						else
						{
							cout << "You dont have enough money \n";
						}
					}
				}
			}
			if (solved == true) {
				cout << "End of Round " << round << endl;
				string Answer;
				cout << "Do you want to exit the game?"<< endl;
				cin >> Answer;
				if (Answer == "Yes" || Answer == "yes")
				{
					cout << "Thank you for playing" << endl;
					exit(0);
				}
				else if (Answer == "No" || Answer == "no")
				{
					solved = false;
					break;
				}
			}
		}
	}
	return 0;
}
#include "Queue.h"
#include "PLinkedList.h"
#include "WLinkedList.h"
#include <fstream>
#include <iostream>
#include <algorithm>
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
	string getCategory() { // guess
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
	string underscore;
	string temp, temp2, cattemp, ans,guess;
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
	system("pause");
	system("CLS");

	cout << "\nGenerating Wheel........." << endl;
	system("pause");
	system("CLS");
	wheel->append("Money", 200);
	wheel->append("Money", 200);
	wheel->append("Money", 200);
	wheel->append("Money", 200);
	wheel->append("Money", 200);
	wheel->append("Money", 200);
	wheel->append("Money", 200);

	cout << "\nWheel was Generated successfully\n" << endl;

	while (round <= 3) {
		int skip[4] = { 0,0,0,0 };
		cout << "\t \t \t \t Round " << round << endl;
		try //Exception Handling
		{
			cout << "Select a Category  (Person,Place,Thing) : " << endl;
			cin >> cattemp;
			if (!(cattemp == "Person" || cattemp == "Place" || cattemp == "Thing"))// checking the category entered is valid
			{
				throw(cattemp); //using throw block to transfer error to catch block
			}
		}
		catch (string cattempp)
		{
			cout << "Invalid category name" << endl; //Showing error
		}
		system("CLS");
		cout << "Category: " << cattemp << endl;
		cout << "\n" << endl;
		ifstream infile;

		infile.open("puzzle.txt"); //opens the file in which the answers are stored
		while (infile >> temp >> temp2)
		{
			if (temp == cattemp)
			{
				roundObj.setCategory(temp);
				roundObj.setPuzzle(temp2);
				underscore = string(temp2.size(), '_'); // init a string with underscores equal to the length of 'word'
			}
		}
		for (int i = 1; i <= 3; i++) {
			cout << "\n";
			while (solved == false)
			{
				if (skip[1] == 1 && skip[2] == 1 && skip[3] == 1) {
					cout << "you all are bankrupt no one wins" << endl; //all 3 players are bankrupt
					round++;
					i = 3;
					break;
				}
				else if (skip[i] == 1) {
					if (i == 3) {
						i = 0;
						break;
					}
					break;
				}
				cout << "\nPlayer " << i << endl;
				cout << "\n";
				cout << "Press enter to spin the wheel " << endl;
				system("pause");
				int randomnum = 50 + rand() % 150; // the wheel spins and then stops on a card
				cout << "Random number genereated : " << randomnum << endl;
				money_value = wheel->traverse(randomnum);
				if (money_value > 0) { // the player only can play if they have money
					cout << "\nYou landed on money" << endl;
					cout << "Money : " << money_value << endl;
				}
				else if (money_value == 0) {
					cout << "You landed on " << wtype << endl;
					if (wtype == "bankrupcy")
					{
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
				int err = 0;
				try //Exception Handling
				{

					cout << "\nWould you like to Guess or Solve or BuyVowel: " << endl;
					cin >> temp;
					if (!(temp == "Guess" || temp == "Solve" || temp == "BuyVowel"))
					{
						throw(temp); //using throw block to transfer error to catch block
					}
				}
				catch (string tempp)
				{
					cout << "Invalid choice\n" << endl; //showing the error
				}
				cout << "\n" << endl;

				/*
				string word  = roundObj.getPuzzle();
				string underscore = string(word.size(), '_'); // init a string with underscores equal to the length of 'word'
				string guess = "mansomething";
				// iterate over the characters in word and guess
				for (size_t i = 0, iend = min(word.size(), guess.size()); i < iend; i++) {
					if (word[i] == guess[i])
						underscore[i] = word[i];  // if the characters match at position i, update the underscore.
				}

				cout << underscore << endl;
				
				*/
				if (temp == "Guess") {
					int occurence = 0;
					char guess2[2];
					while (true) {
						cout << "What letter?  " << endl;
						cin >> guess;
						string word = roundObj.getPuzzle();
						// iterate over the characters in word and guess
						for (size_t i = 0, iend = word.size(); i < iend; i++) {
							if (word[i] == guess[0])
								underscore[i] = word[i];  // if the characters match at position i, update the underscore.
						}

						cout << underscore << endl;
						strcpy_s(guess2, guess.c_str());
						if (g_letters->searchNode(guess) == 1) {
							cout << "This letter has already been guessed\n" << endl;
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
							cout << "That letter was not found in the word\n" << endl;
							if (i == 3) {
								i = 0;
								break;
							}
							break;
						}
						else {
							total[i] += occurence * money_value;
							roundObj.setRoundTotal(total[i], i);
							cout << "That letter was found in the word\n" << endl;
						}

					}
				}
				else if (temp == "Solve") {
					if (money_value > 0) {
						cout << "What is the answer? ";
						cin >> ans;
						if (ans == roundObj.getPuzzle()) {
							cout << "correct\n\n";
							total[i] += money_value;
							list->deleteNode(i - 1);
							list->insertNth(i, name[i], total[i], i - 1);
							system("CLS");
							cout << "SCORES BELOW" << endl; 
							// after a player answers a puzzle correctly the scores are displayed after
							list->display();
							solved = true;
							system("pause");
							system("CLS");
						}
						else {

							cout << "incorrect\n";
						}
					}
					else {
						cout << "you can't solve. you do not have any money\n" << endl;
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
						//ensures that vowels alone are entered
					{
						if (total[i] > vowel_amount)// checks to see if the player can buy a vowel
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
								for (int x = 0; x < s.length(); x++) {
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
								string word = roundObj.getPuzzle();
								// iterate over the characters in word and guess
								for (size_t i = 0, iend = word.size(); i < iend; i++) {
									if (word[i] == vowel[0])
										underscore[i] = word[i];  // if the characters match at position i, update the underscore.
								}
								cout << underscore << endl;
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
					cout << "\nEnd of Round " << round << endl;
					round++;
					cout << "\nDo you want to exit the game?" << endl; 
					cin >> Answer;
					cout << "\n";
					system("CLS");
					if (Answer == "Yes" || Answer == "yes")
					{
						cout << "\nScores before exiting shown below" << endl;
						list->display();
						cout << "\nThank you for playing wheel of fortune!!" << endl;
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
			if ((Answer == "No" || Answer == "no") && solved == true)
				break;
			}
		}
		cout << "\nEnd of 3 rounds... Scores shown below" << endl;
		list->display();
		cout << "\n";
		int plyr;
		for (int i = 0; i < 3; i++) //search for the player with the most points
		{
			if (total[0] < total[i])
			{
				total[0] = total[i];
			}
			for (int j = 1; j < 4; j++)
			{
				if (total[0] == total[i])
				{
					plyr = j;
				}
				break;
			}
		}
		cout << "************************************************************************************************************************************************************************";
		cout << "\nTHE WINNER OF TODAY'S WHEEL OF FORTUNE IS PLAYER " << plyr << " " << "WITH A TOTAL OF " << total[0] << "POINTS" << endl;

		cout << "\n\nPlay wheel of fortune today......you could be our next lucky winner.\n";
		cout << "************************************************************************************************************************************************************************\n";
		return 0;
}
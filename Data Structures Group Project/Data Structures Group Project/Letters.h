#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class letters {
private:
	string guess;
public:
	//default constructor
	letters() {
		guess = "";
	}
	//getters and setters
	letters(string guess) {
		this->guess = guess;
	}
	void setguess(string guess) {
		this->guess = guess;
	}
	string getguess() {
		return guess;
	}
};
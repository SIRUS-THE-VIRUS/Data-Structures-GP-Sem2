#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class letters {
private:
	string guess;
public:
	letters() {
		guess = "";
	}
	letters(string guess) {
		this->guess = guess;
	}

};
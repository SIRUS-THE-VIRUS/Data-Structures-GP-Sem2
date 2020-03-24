#include <iostream>
using namespace std;

class card {
private:
	string type;
	int value;
public:
	//default constructor
	card() {
		type = "None";
		value = 9999;
	}
	//getters and setters
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
	//display method
	void display() {
		cout << "Card Type:      " << type << endl;
		cout << "Card Value:        " << value << endl;
	}
};


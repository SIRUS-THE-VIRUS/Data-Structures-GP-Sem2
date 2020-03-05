#include <iostream>
using namespace std;

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


#include "phonenumber.h"
#include "contactelement.h"

phonenumber::phonenumber(string value) : contactelement(value) {
	cout << "What is the phone number?" << endl;
	cin >> value;
	address = value;
}

phonenumber::~phonenumber() {}

void phonenumber::test() {
	

}
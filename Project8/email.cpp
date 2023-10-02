#include"email.h"
#include "contactelement.h"

email::email(string value) : contactelement(value) {

	cout << "What is the email address?" << endl;
	cin >> value;
	address = value;
}

email::~email() {}
void email::test() {


}
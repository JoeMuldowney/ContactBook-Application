#include "company.h"
#include "contact.h"

company::company(string value) : contact(value) {
	cout << "What is the companys name?" << endl;
	cin >> value;
	this->name = value;
}
company::~company() {}
void company::test() {

}

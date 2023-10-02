#include"web.h"

web::web(string value) : contactelement(value) {
	cout << "What is the web address?" << endl;
	cin >> value;
	address = value;
}
web::~web() {}

void web::test() {
	
}
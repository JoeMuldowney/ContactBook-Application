#include "contactelement.h"
#include <fstream>
contactelement::contactelement(string value) {
	
	this->address = value;
}
void contactelement::print() {

	cout << "this is from contact element print function" << endl;
	cout << address << endl;
}
string contactelement::getAddress() const {
	
	return address;
}
void contactelement::save(ofstream* txtfile) {
	(*txtfile)<<address<<endl;
}
contactelement::~contactelement() {}
void contactelement::test() {


}

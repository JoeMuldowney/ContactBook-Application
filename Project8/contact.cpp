#include "contactelement.h"
#include "web.h"
#include "contact.h"
#include "phonenumber.h"
#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include "email.h"
#include <fstream>
#include "company.h"
contact::contact(string value){
	
	this->name = value;
}
void contact::addContactElement(string address) {
			
	contactelement* elem = new contactelement(address);
	element.push_back(elem);
	elem = nullptr;
}
void contact::deleteContactElement(string address) {
	
	if (address == "all") {
		element.clear();
		return;
	}	
	if(element.empty()) {
		cout << "Contact has no info to delete"<< endl;
		return;
	}

	cout << "Contact: " << name << endl;
	cout << "Contact information:" << endl;
	for (size_t i = 0; i < element.size(); ++i) {
		cout << i + 1 << ". " << element[i]->getAddress() << endl;
	}

	int choice;
	cout << "Enter the number of the contact infomation to delete (1-" << element.size() << "): ";
	cin >> choice;

	if (choice >= 1 && choice <= static_cast<int>(element.size())) {
		choice--; // Adjust for 0-based index
		delete element[choice]; // Free memory as we are deleting the element
		element.erase(element.begin() + choice);
		cout << "Contact info deleted." << endl;
	}
	else {
		cout << "Invalid choice. No contact info deleted." << endl;
	}
}
string contact::getName() {

	return name;
}
void contact::save(ofstream* txtfile) {
	(*txtfile) << name << endl;
	for (const auto& elements : element) {
		elements->save(txtfile);
	}
}
void contact::print(int pick) {

	if (name.length() >= 4 && name.compare(name.length() - 4, 4, ".inc") == 0) {
		cout << "Company: " << name << endl;
	}
	else {
		cout << "Person: " << name << endl;
	}
	for (const auto elementPtr : element) {
		// It's a regular contact element
		string address = elementPtr->getAddress();
		if (pick == 1) {
			if (address.compare(0, 4, "http") == 0) {
				cout << "Website: " << address << endl;
			}
		}
		else if (pick == 2) {
			// Print only email addresses
			if (address.find('@') != std::string::npos) {
				cout << "Email: " << address << endl;
			}
		}
		else if (pick == 3) {

			if (!address.empty() && std::isdigit(address[0])) {
				cout << "Phone Number: " << address << endl;
			}
		}
		else {
			cout << "Invalid choice." << endl;
		}
	}
}

void contact::print() {

	if (name.length() >= 4 && name.compare(name.length() - 4, 4, ".inc") == 0) {
		cout << "Company: " << name << endl;
	}
	else {
		cout << "Person: " << name << endl;
	}
	for (const auto elementPtr : element) {
		// It's a regular contact element
		string address = elementPtr->getAddress();

		if (address.find('@') != std::string::npos) {
			cout << "Email: " << address << endl;
		}
		else if (!address.empty() && std::isdigit(address[0])) {
			cout << "Phone Number: " << address << endl;
		}
		else if (address.compare(0, 4, "http") == 0) {
			cout << "Website: " << address << endl;
		}
		else {
			cout << "No contact info" << endl;
		}
	}
}
void contact::test() {

	string address = "";
	contactelement* wb = new web(address);
	contactelement* em = new email(address);
	contactelement* ph = new phonenumber(address);
	//wb->print();
	cout << wb->getAddress() << endl;
	//ph->print();
	person* p = new person(address);

	contact peep(address);
	peep.addContactElement(wb->getAddress());
	peep.addContactElement(ph->getAddress());
	peep.addContactElement(em->getAddress());
	

	peep.print();

	//ph->print();


}
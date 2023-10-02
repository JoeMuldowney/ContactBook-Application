#include "addressbook.h"
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
#include "addressexceptions.h"

addressbook::addressbook() {
		
}
void addressbook::menu() {
	
	cout << "1) Search for a contact." << endl;
	cout << "2) Add contact" << endl;
	cout << "3) Add contact element for a specific contact" << endl;
	cout << "4) Delete contact" << endl;
	cout << "5) Delete contact element for a specific contact" << endl;
	cout << "6) Print a Contact Element, Contact and the entire address book" << endl;
	cout << "7) Exit" << endl;
}
int addressbook::menuch(int num) {

	menu();

	cout << "Select an option from the menu...";
	cin >> num;
	return num;
}
contact* addressbook::searchContact(string name) {
	
	cout << "What is the name of the contact?" << endl;
	cin >> name;
	for (auto contactPtr : info) {
		if (contactPtr->getName() == name) {
			
			   return contactPtr;
		}
	}
	cout << "Contact not found: " << name << endl;
	return nullptr;
}
void addressbook::save(string fileName) {

	ofstream outFile("contact.txt");
	if (!outFile) {
		std::cerr << "Error opening file: " << fileName << std::endl;
		return;
	}

	for (const auto& contactPtr : info) {
		contactPtr->save(&outFile);
		outFile << std::endl; // Add a newline between contacts
	}
	outFile.close();
}
void addressbook::load(string fileName) {
	ifstream inFile("contact.txt");
	if (!inFile) {
		std::cerr << "Error opening file: " << fileName << std::endl;
		return;
	}

	string line;
	string contactName;
	contact* currentContact = nullptr;

	while (getline(inFile, line)) {
		if (line.empty()) {
			// Empty line, move to the next contact
			currentContact = nullptr;
			continue;
		}

		if (!currentContact) {
			// Create a new contact using the first non-empty line
			currentContact = new contact(line);
			info.push_back(currentContact);
		}
		else {
			// Create a new contact element and add it to the current contact
			currentContact->addContactElement(line);
		}
	}

	inFile.close();
}
void addressbook::addContact(string name) {

	contact* p = new person(name);
	info.push_back(p);
	p=nullptr;
}
void addressbook::deleteContact(string name) {
	
	for (auto it = info.begin(); it != info.end(); ++it) {
		if ((*it)->getName() == name) {
			string address = "all";
			(*it)->deleteContactElement(address); // Clear all contact elements for this contact
			it = info.erase(it);; // Remove the contact from the vector
			break; // Exit the loop since the contact is found and deleted
		}
	}
}
void addressbook::addContactElement(string address, string name) {
	
	contact* found = searchContact(name);

	if (found != nullptr) {
		
		cout << "Enter contact information" << endl;
		cin >> address;
		contactelement* elem = new contactelement(address);
		// Add the contactelement to the found contact
		found->addContactElement(address);

		cout << "contact information: " << address << " added to contact." << endl;
	}
	else {
		cout << "Contact with name " << name << " not found." << endl;
	}
	found = nullptr;
}
void addressbook::deleteContactElement(string address, string name) {
	contact* foundContact = searchContact(name);

	if (foundContact) {
		foundContact->deleteContactElement(address);
	}
	else {
		cout << "Contact with name " << name << " not found." << endl;
	}
	foundContact = nullptr;
}
void addressbook::print() {
	int choice = 0;
	cout << "Enter 1 to print a contact with its contact elements." << endl;
	cout << "Enter 2 to print a specific contact element from a contact." << endl;
	cout << "Enter 3 to print the whole address book ";
	cin >> choice;
	if (choice == 1) {
		try {
			string name;
			contact* foundContact = searchContact(name);
			if (foundContact != nullptr) {
				foundContact->print();
			}
			else {
				throw noName();
			}
		}
		catch (noName& e) {
			e.print();
		}
	}
	else if (choice == 2) {
		try {
			string name;
			int pick = 0;
			contact* foundContact = searchContact(name);
			if (foundContact != nullptr) {
				cout << "What do you want to get for this contact?" << endl;
				cout << "Enter 1 for web address(es)" << endl;
				cout << "Enter 2 for email address(es)" << endl;
				cout << "Enter 3 for phone Number(s)" << endl;
				cin >> pick;
				foundContact->print(pick);
			}
			else {
				throw noName();
			}
		}
		catch (noName& e) {
			e.print();
		}
	}
	else {
		for (const auto contactPtr : info) {
			contactPtr->print();
			cout << endl;
		}
	}

}
void addressbook::process(){

	string address = "";
	string name = "";
	string fileName = "contact.txt";
	addressbook books;
	contact peep(name);
	bool run = true;
	bool running = true;
	int num = 0;
	cout << "\t\t\t\tWelcome to my address book app" << endl;
	cout << "\t\tEnter contacts and contact elements to load into the app and make changes" << endl;
	while (running) {
		int choice;
		cout << "1) Add contact" << endl;
		cout << "2) Add contact element for a specific contact" << endl;
		cout << "3) Save, exit and load app" << endl;
		cin >> choice;
		if (choice == 1) {
			cout << "Enter a person or company name(company contacts must end with .inc)" << endl;
			cin >> name;
			books.addContact(name);
		}
		else if (choice == 2) {

			books.addContactElement(address, name);
		}
		else if (choice == 3) {
			books.save(fileName);
			running = false;
		}
		else {
			cout << "Invalid input" << endl;
		}
	}

	books.load(fileName);
	while (run) {




		int pick = books.menuch(num);

		switch (pick) {

		case 1: {

			contact* foundContact = books.searchContact(name);

			if (foundContact != nullptr) {
				foundContact->print();
			}

			break;
		}
		case 2: {

			cout << "Enter a person or company name(company contacts must end with .inc)" << endl;
			cin >> name;
			books.addContact(name);

			break;
		}
		case 3: {

			books.addContactElement(address, name);
			break;
		}
		case 4: {
			
			cout << "What is the name of the contact" << endl;
			cin >> name;
			books.deleteContact(name);

			break;
		}case 5: {

			books.deleteContactElement(address, name);
			
			break;
		}
		case 6: {

			books.print();
			
			break;
		}
		case 7: {
			exit(0);

			break;
		}


		}

	}
}
void addressbook::test() {
	string address = "";
	string name = "";
	string fileName = "";
	addressbook books;
	contact peep(name);
	bool run = true;
	bool running = true;
	int num = 0;
	cout << "\t\t\t\tWelcome to my address book app" << endl;
	cout << "\t\tEnter contacts and contact elements to load into the app and make changes" << endl;
	while (running) {
		int choice;
		cout << "1) Add contact" << endl;
		cout << "2) Add contact element for a specific contact" << endl;
		cout << "3) Save, exit and load app" << endl;
		cin >> choice;
		if (choice == 1) {
			cout << "Enter a person or company name(company contacts must end with .inc)" << endl;
			cin >> name;
			books.addContact(name);
		}
		else if(choice == 2) {

			books.addContactElement(address, name);
		}
		else if (choice == 3) {
			running = false;
		}
		else {
			cout << "Invalid input" << endl;
		}
	}
	
	books.load(fileName);
	while (run) {




		int pick = books.menuch(num);

		switch (pick) {

		case 1: {
			
			contact* member = books.searchContact(name);
			
			break;
		}
		case 2: {
			cout << "Enter a person or company name(company contacts must end with .inc)" << endl;
			cin >> name;
			books.addContact(name);
			
			break;
		}
		case 3: {
			
			books.addContactElement(address, name);
			break;
		}
		case 4: {
			cout << "What is the name of the contact" << endl;
			cin >> name;
			books.deleteContact(name);
			break;
		}case 5: {

			books.deleteContactElement(address, name);
			//contactelement* wb = new web(address);
			//contactelement* em = new email(address);
			//contactelement* ph = new phonenumber(address);

			//peep.addContactElement(wb->getAddress());
			//peep.addContactElement(ph->getAddress());
			//peep.addContactElement(em->getAddress());
			
			break;
		}
		case 6: {

			books.print();
			//contactelement* wb = new web(address);
			//contactelement* em = new email(address);
			//contactelement* ph = new phonenumber(address);
			
			break;
		}
		case 7: {
			//peep.print();
			exit(0);

			break;
		}
		
		
		}

	}
}
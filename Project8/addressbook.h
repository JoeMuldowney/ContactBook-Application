#pragma once
#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include "contact.h"
#include <vector>
#include <iostream>
#include "contactelement.h"
using namespace std;

class addressbook
{

public:
	addressbook();
	contact* searchContact(string name);
	void save(string fileName);
	void load(string fileName);
	void addContact(string name);
	void deleteContact(string name);
	void addContactElement(string address, string name);
	void deleteContactElement(string address, string name);
	void print();
	void process();
	static void test();
	void menu();
	int menuch(int num);

private:
	
	vector<contact*> info;
};
#endif

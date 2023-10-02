#pragma once
#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <vector>
#include "contactelement.h"
#include "web.h"
#include <fstream>
using namespace std;
class contact
{
public:	
	contact(string value);
	void addContactElement(string address);
	void deleteContactElement(string address);
	void print();
	void print(int choice);
	static void test();
	string getName();
	void save(ofstream* txtfile);
protected:	
	string name;	
	vector<contactelement*> element;
};
#endif


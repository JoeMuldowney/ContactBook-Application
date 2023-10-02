#pragma once
#ifndef CONTACTELEMENT_H
#define CONTACTELEMENT_H

using namespace std;

#include <string>
#include <iostream>
#include <fstream>
class contactelement
{
public:
	
	contactelement(string value);
	virtual ~contactelement();
	virtual void print();
	string getAddress() const;
	static void test();
	void save(ofstream* txtfile);
protected:
	string address;

private:
	void deleteObject();
	
};
#endif


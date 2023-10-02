#pragma once
#include "addressbook.h"
#include "contact.h"
#ifndef ADDRESSEXECEPTION_H
#define ADDRESSEXECEPTION_H

class noName
{

public:
	virtual void print() {
		cerr << "Error code: " << errorCode << " " << message << endl;
	}
	noName() {
		errorCode = 0000000001;
		message = "Contact does not exist in address book";
	}
	virtual ~noName() {};
protected:
	int errorCode;
	string message;

};

#endif

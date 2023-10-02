#pragma once
#ifndef EMAIL_H
#define EMAIL_H

using namespace std;

#include <string>
#include "contactelement.h"

class email: public contactelement
{
public:
	email(string value);
	virtual ~email();
	//void print();
	static void test();


private:
	void deleteObject();
};
#endif

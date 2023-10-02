#pragma once
#ifndef PHONENUMBER_H
#define PHONENUMBER_H

using namespace std;

#include <string>
#include "contactelement.h"

class phonenumber : public contactelement
{
public:
	phonenumber(string value);
	virtual ~phonenumber();
	//void print();
	static void test();


private:
	void deleteObject();
};
#endif
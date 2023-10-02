#pragma once
#ifndef PERSON_H
#define PERSON_H
#include "contact.h"
#include <iostream>

using namespace std;
class person : public contact
{
public:
	person(string value);
	virtual ~person();
	//void print();
	static void test();


private:
	void deleteObject();
};
#endif
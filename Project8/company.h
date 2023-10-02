#pragma once
#ifndef COMAPNY_H
#define COMPANY_H

#include "contact.h"
#include <iostream>

using namespace std;
class company : public contact
{
public:
	company(string value);
	virtual ~company();
	//void print();
	static void test();


private:
	void deleteObject();
};
#endif


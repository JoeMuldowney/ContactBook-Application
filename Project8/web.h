#pragma once
#ifndef WEB_H
#define WEB_H

using namespace std;

#include <string>
#include "contactelement.h"

class web : public contactelement
{
public:
	
	web(string value);
	virtual ~web();
	//void print();
	static void test();
	

private:
	void deleteObject();
};
#endif

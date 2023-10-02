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

using namespace std;

int main() {

	addressbook book;
	book.process();
	return 0;

}
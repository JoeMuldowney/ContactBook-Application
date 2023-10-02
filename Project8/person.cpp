#include "person.h"
#include "contact.h"

person::person(string value) : contact(value) {
	this->name = value;
}

person::~person() {}

void person::test() {

}

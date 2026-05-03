#include "Person.h"

Person::Person() : id(0), name("") {}   

Person::Person(int id, const string& name)
    : id(id), name(name) {}

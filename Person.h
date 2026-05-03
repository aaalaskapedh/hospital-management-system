#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    int id;
    string name;

public:
    Person(int id, const string& name);
    virtual ~Person() = default;

    // abstract methods (pure virtual)
    virtual void display() const = 0;
    virtual void inputFromUser() = 0;

    // common getters
    int getId() const { return id; }
    const string& getName() const { return name; }
};

#endif

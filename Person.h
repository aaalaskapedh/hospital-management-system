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
    Person();                                   
    Person(int id, const string& name);
    virtual ~Person() = default;

    
    virtual void display() const = 0;
 

 int getId() const { return id; }
    const string& getName() const { return name; }
    string toFileString() const { return ""; }  
};

#endif

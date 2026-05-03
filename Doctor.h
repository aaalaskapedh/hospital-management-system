#ifndef DOCTOR_H
#define DOCTOR_H

#include "Person.h"
#include <string>
using namespace std;

class Doctor : public Person {
private:
    string specialization;

public:
    Doctor(int id, const string& name, const string& specialization);
    void addDoctor() override;
    void display() const override;
    void displayDoctors();
};

#endif

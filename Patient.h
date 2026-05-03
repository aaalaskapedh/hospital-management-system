#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"
#include <string>
using namespace std;

class Patient : public Person {
private:
    int age;
    string disease;

public:
    Patient(int id, const string& name, int age, const string& disease);
    void addPatient() override;
    void display() const override;
    void displayPatients();
};

#endif

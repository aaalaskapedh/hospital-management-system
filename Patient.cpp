#include <iostream>
#include <fstream>
#include <string>
#include "Patient.h"
using namespace std;

Patient::Patient() : Person(0, ""), age(0), disease("") {}   // FIX: default constructor

Patient::Patient(int id, const string& name, int age, const string& disease)
    : Person(id, name), age(age), disease(disease) {}

void Patient::inputFromUser() {
    cout << "Enter Patient ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Patient Name: ";
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();

    cout << "Enter Disease: ";
    getline(cin, disease);
}

void Patient::addPatient() {
    inputFromUser();

    ofstream file("data/patient.txt", ios::app);
    if (!file.is_open()) {
        throw runtime_error("Cannot open patient file.");
    }

    file << id << "|" << name << "|" << age << "|" << disease << endl;
    file.close();

    cout << "Patient added successfully!\n";
}

void Patient::display() const {
    cout << "ID: " << id
         << ", Name: " << name
         << ", Age: " << age
         << ", Disease: " << disease << endl;
}

void Patient::displayPatients() {
    ifstream file("data/patient.txt");
    if (!file.is_open()) {
        cout << "Error: Cannot open patient file.\n";
        return;
    }

    string record;
    cout << "\n--- Patient Records ---\n";
    while (getline(file, record)) {
        cout << record << endl;
    }
    file.close();
}

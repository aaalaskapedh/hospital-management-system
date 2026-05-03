#include <iostream>
#include <fstream>
#include <string>
#include "Doctor.h"
using namespace std;

Doctor::Doctor() : Person(0, ""), specialization("") {}   // FIX: default constructor

Doctor::Doctor(int id, const string& name, const string& specialization)
    : Person(id, name), specialization(specialization) {}

void Doctor::inputFromUser() {
    cout << "Enter Doctor ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Doctor Name: ";
    getline(cin, name);

    cout << "Enter Specialization: ";
    getline(cin, specialization);
}

void Doctor::addDoctor() {
    inputFromUser();

    ofstream file("data/doctors.txt", ios::app);
    if (!file.is_open()) {
        throw runtime_error("Cannot open doctors file.");
    }

    file << id << "|" << name << "|" << specialization << endl;
    file.close();

    cout << "Doctor added successfully!\n";
}

void Doctor::display() const {
    cout << "ID: " << id
         << ", Name: " << name
         << ", Specialization: " << specialization << endl;
}

void Doctor::displayDoctors() {
    ifstream file("data/doctors.txt");
    if (!file.is_open()) {
        cout << "Error: Cannot open doctors file.\n";
        return;
    }

    string record;
    cout << "\n--- Doctor Records ---\n";
    while (getline(file, record)) {
        cout << record << endl;
    }
    file.close();
}

#include <iostream>
#include <fstream>
#include <string>
#include "Patient.h"
using namespace std;

void Patient::addPatient() {
    int id, age;
    string name, disease;

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

    ofstream file("data/patient.txt", ios::app);
    file << id << "|" << name << "|" << age << "|" << disease << endl;
    file.close();

    cout << "Patient added successfully!\n";
}

void Patient::displayPatients() {
    ifstream file("data/patient.txt");
    string record;

    cout << "\n--- Patient Records ---\n";
    while(getline(file, record)) {
        cout << record << endl;
    }

    file.close();
}
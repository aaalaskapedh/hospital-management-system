#include <iostream>
#include <fstream>
#include <string>
#include "Doctor.h"
using namespace std;

void Doctor::addDoctor() {
    int id;
    string name, specialization;

    cout << "Enter Doctor ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Doctor Name: ";
    getline(cin, name);

    cout << "Enter Specialization: ";
    getline(cin, specialization);

    ofstream file("data/doctors.txt", ios::app);
    file << id << "|" << name << "|" << specialization << endl;
    file.close();

    cout << "Doctor added successfully!\n";
}

void Doctor::displayDoctors() {
    ifstream file("data/doctors.txt");
    string record;

    cout << "\n--- Doctor Records ---\n";
    while(getline(file, record)) {
        cout << record << endl;
    }

    file.close();
}
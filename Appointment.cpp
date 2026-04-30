#include <iostream>
#include <fstream>
#include <string>
#include "Appointment.h"
using namespace std;

void Appointment::bookAppointment() {
    int patientID;
    string patientName, doctorName, date;

    cout << "Enter Patient ID: ";
    cin >> patientID;
    cin.ignore();

    cout << "Enter Patient Name: ";
    getline(cin, patientName);

    cout << "Enter Doctor Name: ";
    getline(cin, doctorName);

    cout << "Enter Appointment Date: ";
    getline(cin, date);

    ofstream file("data/appointments.txt", ios::app);
    file << patientID << "|" << patientName << "|" << doctorName << "|" << date << endl;
    file.close();

    cout << "Appointment booked successfully!\n";
}

void Appointment::displayAppointments() {
    ifstream file("data/appointments.txt");
    string record;

    cout << "\n--- Appointment Records ---\n";
    while(getline(file, record)) {
        cout << record << endl;
    }

    file.close();
}
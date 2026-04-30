#include <iostream>
#include <fstream>
#include <string>
#include "Billing.h"
using namespace std;

void Billing::generateBill() {
    int patientID;
    string patientName;
    float treatmentCost, medicineCost, total;

    cout << "Enter Patient ID: ";
    cin >> patientID;
    cin.ignore();

    cout << "Enter Patient Name: ";
    getline(cin, patientName);

    cout << "Enter Treatment Cost: ";
    cin >> treatmentCost;

    cout << "Enter Medicine Cost: ";
    cin >> medicineCost;

    total = treatmentCost + medicineCost;

    ofstream file("data/bills.txt", ios::app);
    file << patientID << "|" << patientName << "|"
         << treatmentCost << "|" << medicineCost << "|" << total << endl;
    file.close();

    cout << "Total Bill: " << total << endl;
}
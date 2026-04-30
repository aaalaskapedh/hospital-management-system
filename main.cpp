#include <iostream>
#include "Patient.h"
#include "Doctor.h"
#include "Billing.h"
#include "Appointment.h"
#include "Authentication.h"
using namespace std; 

int main() {
    Authentication auth;

    if (!auth.login()) {
        cout << "Access Denied!\n";
        return 0;
    }

    Patient patient;
    Doctor doctor;
    Billing billing;
    Appointment appointment;

    int choice;

    do {
        cout << "\n===== HOSPITAL MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Add Doctor\n";
        cout << "4. Display Doctors\n";
        cout << "5. Generate Bill\n";
        cout << "6. Book Appointment\n";
        cout << "7. Display Appointments\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: patient.addPatient(); break;
            case 2: patient.displayPatients(); break;
            case 3: doctor.addDoctor(); break;
            case 4: doctor.displayDoctors(); break;
            case 5: billing.generateBill(); break;
            case 6: appointment.bookAppointment(); break;
            case 7: appointment.displayAppointments(); break;
            case 8: cout << "Exiting system...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 8);

    return 0;
}
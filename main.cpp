#include <iostream>
#include <vector>
#include "Person.h" 
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
        catch (const exception& e) {
        cerr << "Login error: " << e.what() << endl;
        return 1;
    }


    Patient patient;
    Doctor doctor;
    Billing billing;
    Appointment appointment;

    int choice;

    vector<Person*> persons;

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
            case 1: {
                Patient* p = new Patient(0, "", 0, "");
                try {
                    p->addPatient();
                    persons.push_back(p);
                } catch (const exception& e) {
                    cerr << "Error: " << e.what() << endl;
                    delete p;
                }
                break;
            }

            case 2:
                patient.displayPatients();
                break;

            case 3: {
                Doctor* d = new Doctor(0, "", "");
                try {
                    d->addDoctor();
                    persons.push_back(d);
                } catch (const exception& e) {
                    cerr << "Error: " << e.what() << endl;
                    delete d;
                }
                break;
            }

            case 4:
                doctor.displayDoctors();
                break;

            case 5:
                billing.generateBill();
                break;

            case 6:
                appointment.bookAppointment();
                break;

            case 7:
                appointment.displayAppointments();
                break;

            case 10: {  // new option
                cout << "\n--- Polymorphic List ---\n";
                for (const auto& p : persons) {
                    p->display();   // virtual call
                }
                break;
            }

            case 8:
            cout << "Exiting system...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 8);

    // cleanup
    for (auto* p : persons) {
        delete p;
    }

    return 0;
}

#include <iostream>
#include <string>
#include "Authentication.h"

using namespace std;

bool Authentication::login() {
    string username, password;

    cout << "===== ADMIN LOGIN =====\n";
    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    cout << "\nEntered Username: " << username;
    cout << "\nEntered Password: " << password << endl;

    if(username == "admin" && password == "admin123") {
        return true;
    }

    return false;
}
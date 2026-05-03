#ifndef RECORDMANAGER_H
#define RECORDMANAGER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

template <typename T>
class RecordManager {
public:
    vector<T> records;

    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);
    void displayAll() const;

    T* findById(int id) {
        for (auto& r : records) {
            if (r.getId() == id) {
                return &r;
            }
        }
        return nullptr;
    }
};

template <typename T>
void RecordManager<T>::saveToFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) return;

    for (const auto& r : records) {
        file << r.getId() << "|" << r.getName() << "|" << r.toFileString() << endl;
    }
    file.close();
}

template <typename T>
void RecordManager<T>::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        // This is a simplified sketch; you can refine later if needed.
        T obj(0, "", 0, ""); // or T obj; obj.fromString(ss);
        records.push_back(obj);
    }
    file.close();
}

template <typename T>
void RecordManager<T>::displayAll() const {
    cout << "\n--- All Records ---\n";
    for (const auto& r : records) {
        r.display();
    }
}

#endif

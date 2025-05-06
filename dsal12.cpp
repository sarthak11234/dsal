#include <iostream>
#include <fstream>
#include <cstdio>  // for remove() and rename()
using namespace std;

class Student {
public:
    int rollno;
    char name[50];
    char add[50];
    char div[5];

    void setData() {
        cout << "Enter Roll no: ";
        cin >> rollno;
        cin.ignore(); // clear input buffer
        cout << "Enter Name: ";
        cin.getline(name, 50);
        cout << "Address of student: ";
        cin.getline(add, 50);
        cout << "Division of student: ";
        cin.getline(div, 5);
    }

    void showData() {
        cout << "\n-------------------------------";
        cout << "\nRoll no.: " << rollno;
        cout << "\nName: " << name;
        cout << "\nAddress: " << add;
        cout << "\nDivision: " << div;
        cout << "\n-------------------------------";
    }

    int retrollno() {
        return rollno;
    }
};

// Function to add record
void write_record() {
    ofstream outfile("StudentData", ios::binary | ios::app);
    Student obj;
    obj.setData();
    outfile.write((char*)&obj, sizeof(obj));
    outfile.close();
}

// Function to display all records
void display_record() {
    ifstream infile("StudentData", ios::binary);
    Student obj;
    bool found = false;

    while (infile.read((char*)&obj, sizeof(obj))) {
        obj.showData();
        found = true;
    }

    if (!found)
        cout << "\nNo records found.";

    infile.close();
}

// Function to search for a specific student
void search_record(int n) {
    bool flag = false;
    ifstream infile("StudentData", ios::binary);
    Student obj;

    while (infile.read((char*)&obj, sizeof(obj))) {
        if (obj.retrollno() == n) {
            flag = true;
            cout << "\nRecord found!";
            obj.showData();
            break;
        }
    }

    if (!flag) {
        cout << "\nRecord for roll no. " << n << " not found.";
    }

    infile.close();
}

// Function to delete a record
void delete_record(int n) {
    Student obj;
    ifstream infile("StudentData", ios::binary);
    ofstream outfile("StudentNewData", ios::binary);

    bool deleted = false;

    while (infile.read((char*)&obj, sizeof(obj))) {
        if (obj.retrollno() != n) {
            outfile.write((char*)&obj, sizeof(obj));
        } else {
            deleted = true;
        }
    }

    infile.close();
    outfile.close();

    remove("StudentData");
    rename("StudentNewData", "StudentData");

    if (deleted)
        cout << "\nRecord Deleted Successfully!";
    else
        cout << "\nNo record found with that roll number.";
}

// Main menu
int main() {
    int ch;

    do {
        cout << "\n\n******** Student File Operations ********\n";
        cout << "1. Add Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Search Record by Roll Number\n";
        cout << "4. Delete Record by Roll Number\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                int n;
                cout << "Enter number of records to add: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "\nEnter details for student " << i + 1 << ":\n";
                    write_record();
                }
                break;
            }
            case 2:
                display_record();
                break;
            case 3: {
                int roll;
                cout << "Enter roll number to search: ";
                cin >> roll;
                search_record(roll);
                break;
            }
            case 4: {
                int roll;
                cout << "Enter roll number to delete: ";
                cin >> roll;
                delete_record(roll);
                break;
            }
            case 5:
                cout << "\nExiting program. Thank you!\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.";
        }

    } while (ch != 5);

    return 0;
}

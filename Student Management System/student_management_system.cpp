#include <iostream>
using namespace std;

// Global arrays to store student information
string arr1[20], arr2[20], arr3[20], arr4[20], arr5[20];
int total = 0;

// Function to enter student data
void enter() {
    int ch = 0;
    cout << "How many students do you want to enter?" << endl;
    cin >> ch;

    for (int i = total; i < total + ch; i++) {
        cout << "\nEnter the data of student " << i + 1 << endl;

        cout << "Enter name: ";
        cin >> arr1[i];
        cout << "Enter Roll no: ";
        cin >> arr2[i];
        cout << "Enter course: ";
        cin >> arr3[i];
        cout << "Enter class: ";
        cin >> arr4[i];
        cout << "Enter contact: ";
        cin >> arr5[i];
    }

    total += ch;
}

// Function to display all student data
void show() {
    if (total == 0) {
        cout << "No data is entered" << endl;
    } else {
        for (int i = 0; i < total; i++) {
            cout << "\nData of Student " << i + 1 << endl;
            cout << "Name: " << arr1[i] << endl;
            cout << "Roll no: " << arr2[i] << endl;
            cout << "Course: " << arr3[i] << endl;
            cout << "Class: " << arr4[i] << endl;
            cout << "Contact: " << arr5[i] << endl;
        }
    }
}

// Function to search for a student by roll number
void search() {
    if (total == 0) {
        cout << "No data is entered" << endl;
    } else {
        string rollno;
        cout << "Enter the roll no of the student" << endl;
        cin >> rollno;

        bool found = false;
        for (int i = 0; i < total; i++) {
            if (rollno == arr2[i]) {
                cout << "Name: " << arr1[i] << endl;
                cout << "Roll no: " << arr2[i] << endl;
                cout << "Course: " << arr3[i] << endl;
                cout << "Class: " << arr4[i] << endl;
                cout << "Contact: " << arr5[i] << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "No student found with the given roll number" << endl;
        }
    }
}

// Function to update student data
void update() {
    if (total == 0) {
        cout << "No data is entered" << endl;
    } else {
        string rollno;
        cout << "Enter the roll no of the student you want to update" << endl;
        cin >> rollno;

        bool found = false;
        for (int i = 0; i < total; i++) {
            if (rollno == arr2[i]) {
                cout << "\nPrevious data" << endl;
                cout << "Name: " << arr1[i] << endl;
                cout << "Roll no: " << arr2[i] << endl;
                cout << "Course: " << arr3[i] << endl;
                cout << "Class: " << arr4[i] << endl;
                cout << "Contact: " << arr5[i] << endl;

                cout << "\nEnter new data" << endl;
                cout << "Enter name: ";
                cin >> arr1[i];
                cout << "Enter Roll no: ";
                cin >> arr2[i];
                cout << "Enter course: ";
                cin >> arr3[i];
                cout << "Enter class: ";
                cin >> arr4[i];
                cout << "Enter contact: ";
                cin >> arr5[i];

                found = true;
                break;
            }
        }

        if (!found) {
            cout << "No student found with the given roll number" << endl;
        }
    }
}

// Function to delete student data
void deleterecord() {
    if (total == 0) {
        cout << "No data is entered" << endl;
    } else {
        int choice;
        cout << "Press 1 to delete all records" << endl;
        cout << "Press 2 to delete a specific record" << endl;
        cin >> choice;

        if (choice == 1) {
            total = 0;
            cout << "All records have been deleted" << endl;
        } else if (choice == 2) {
            string rollno;
            cout << "Enter the roll no of the student you want to delete" << endl;
            cin >> rollno;

            bool found = false;
            for (int i = 0; i < total; i++) {
                if (rollno == arr2[i]) {
                    for (int j = i; j < total - 1; j++) {
                        arr1[j] = arr1[j + 1];
                        arr2[j] = arr2[j + 1];
                        arr3[j] = arr3[j + 1];
                        arr4[j] = arr4[j + 1];
                        arr5[j] = arr5[j + 1];
                    }
                    total--;
                    cout << "The record has been deleted" << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "No student found with the given roll number" << endl;
            }
        } else {
            cout << "Invalid input" << endl;
        }
    }
}

int main() {
    while (true) {
        int value;
        cout << "\nPress 1 to enter data" << endl;
        cout << "Press 2 to show data" << endl;
        cout << "Press 3 to search data" << endl;
        cout << "Press 4 to update data" << endl;
        cout << "Press 5 to delete data" << endl;
        cout << "Press 6 to exit" << endl;
        cin >> value;

        switch (value) {
            case 1:
                enter();
                break;
            case 2:
                show();
                break;
            case 3:
                search();
                break;
            case 4:
                update();
                break;
            case 5:
                deleterecord();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid input" << endl;
                break;
        }
    }
}

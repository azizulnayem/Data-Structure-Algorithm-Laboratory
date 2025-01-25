#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int id;
    int physics;
    int chemistry;
    int mathematics;
    int totalMarks;

    Student(string n, int i, int p, int c, int m)
        : name(n), id(i), physics(p), chemistry(c), mathematics(m), totalMarks(p + c + m) {}
};

bool compareByTotalMarks(const Student& s1, const Student& s2) {
    return s1.totalMarks > s2.totalMarks;
}

int main() {
    vector<Student> students;

    while (true) {
        cout << "Actions List:" << endl;
        cout << "1. Add new student information" << endl;
        cout << "2. Show the information of the student" << endl;
        cout << "3. Kth positioned student" << endl;
        cout << "4. Show the standing of all the students" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            string name;
            int id, physics, chemistry, mathematics;

            cout << "Enter name: ";
            cin >> name;
            cout << "Enter id: ";
            cin >> id;
            cout << "Enter physics marks: ";
            cin >> physics;
            cout << "Enter chemistry marks: ";
            cin >> chemistry;
            cout << "Enter mathematics marks: ";
            cin >> mathematics;

            students.emplace_back(name, id, physics, chemistry, mathematics);
            cout << "Student information added successfully!" << endl;
        } else if (choice == 2) {
            int id;
            cout << "Enter student id: ";
            cin >> id;

            bool found = false;
            for (const Student& student : students) {
                if (student.id == id) {
                    cout << "Name: " << student.name << endl;
                    cout << "ID: " << student.id << endl;
                    cout << "Physics: " << student.physics << endl;
                    cout << "Chemistry: " << student.chemistry << endl;
                    cout << "Mathematics: " << student.mathematics << endl;
                    cout << "Total Marks: " << student.totalMarks << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student not found!" << endl;
            }
        } else if (choice == 3) {
            int position;
            cout << "Enter position: ";
            cin >> position;

            if (position >= 1 && position <= students.size()) {
                cout << "Position: " << position << endl;
                cout << "Name: " << students[position - 1].name << endl;
                cout << "ID: " << students[position - 1].id << endl;
            } else {
                cout << "Invalid position!" << endl;
            }
        } else if (choice == 4) {
            sort(students.begin(), students.end(), compareByTotalMarks);

            int position = 1;
            for (const Student& student : students) {
                cout << "Position: " << position << endl;
                cout << "Name: " << student.name << endl;
                cout << "ID: " << student.id << endl;
                position++;
            }
        } else if (choice == 5) {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid choice. Please choose again." << endl;
        }
    }

    return 0;
}

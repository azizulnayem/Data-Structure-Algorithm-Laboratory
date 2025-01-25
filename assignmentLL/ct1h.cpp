#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    int id;
    int physics;
    int chemistry;
    int mathematics;
    int total_marks;
};

bool compareStudents(const Student& s1, const Student& s2) {
    return s1.total_marks > s2.total_marks;
}

int main() {
    int N;
    std::cout << "Enter the number of students: ";
    std::cin >> N;

    std::vector<Student> students;

    for (int i = 0; i < N; ++i) {
        std::cout << "Student " << i + 1 << ":\n";
        Student student;
        std::cout << "Enter name: ";
        std::cin.ignore();
        std::getline(std::cin, student.name);
        std::cout << "Enter ID: ";
        std::cin >> student.id;
        std::cout << "Enter marks in Physics, Chemistry, and Mathematics: ";
        std::cin >> student.physics >> student.chemistry >> student.mathematics;
        student.total_marks = student.physics + student.chemistry + student.mathematics;
        students.push_back(student);
    }

    int choice;
    do {
        std::cout << "\nActions List:\n";
        std::cout << "1. Add new student information\n";
        std::cout << "2. Show the information of the student\n";
        std::cout << "3. Kth positioned student\n";
        std::cout << "4. Show the standing of all the students\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Student student;
                std::cout << "Enter name: ";
                std::cin.ignore();
                std::getline(std::cin, student.name);
                std::cout << "Enter ID: ";
                std::cin >> student.id;
                std::cout << "Enter marks in Physics, Chemistry, and Mathematics: ";
                std::cin >> student.physics >> student.chemistry >> student.mathematics;
                student.total_marks = student.physics + student.chemistry + student.mathematics;
                students.push_back(student);
                std::cout << "Student information added successfully!\n";
                break;
            }
            case 2: {
                int id;
                std::cout << "Enter student ID to show information: ";
                std::cin >> id;
                bool found = false;
                for (const auto& student : students) {
                    if (student.id == id) {
                        std::cout << "Name: " << student.name << "\n";
                        std::cout << "ID: " << student.id << "\n";
                        std::cout << "Physics: " << student.physics << "\n";
                        std::cout << "Chemistry: " << student.chemistry << "\n";
                        std::cout << "Mathematics: " << student.mathematics << "\n";
                        std::cout << "Total Marks: " << student.total_marks << "\n";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    std::cout << "Student with ID " << id << " not found!\n";
                }
                break;
            }
            case 3: {
                int k;
                std::cout << "Enter position (1-" << N << ") of the student to show: ";
                std::cin >> k;
                if (k >= 1 && k <= N) {
                    std::sort(students.begin(), students.end(), compareStudents);
                    std::cout << "Position " << k << " Student:\n";
                    std::cout << "Name: " << students[k - 1].name << "\n";
                    std::cout << "ID: " << students[k - 1].id << "\n";
                    std::cout << "Total Marks: " << students[k - 1].total_marks << "\n";
                } else {
                    std::cout << "Invalid position!\n";
                }
                break;
            }
            case 4: {
                std::sort(students.begin(), students.end(), compareStudents);
                std::cout << "Standing of all students based on total marks:\n";
                for (int i = 0; i < N; ++i) {
                    std::cout << "Position " << i + 1 << ":\n";
                    std::cout << "Name: " << students[i].name << "\n";
                    std::cout << "ID: " << students[i].id << "\n";
                    std::cout << "Total Marks: " << students[i].total_marks << "\n";
                }
                break;
            }
            case 5: {
                std::cout << "Exiting program.\n";
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}


#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// Structure to hold student details
struct Student {
    int rollNo;
    string name;
    float marks[3]; // Three subjects
    float average;
    char grade;

    void calculateGrade() {
        average = (marks[0] + marks[1] + marks[2]) / 3;
        if (average >= 90) grade = 'A';
        else if (average >= 75) grade = 'B';
        else if (average >= 50) grade = 'C';
        else grade = 'F';
    }
};

// Function declarations
void addStudent(vector<Student> &students);
void displayStudents(const vector<Student> &students);
void searchStudent(const vector<Student> &students);
void deleteStudent(vector<Student> &students);
void saveToFile(const vector<Student> &students);
void loadFromFile(vector<Student> &students);

int main() {
    vector<Student> students;
    int choice;

    // Load data from file
    loadFromFile(students);

    do {
        cout << "\n=== Student Report Card System ===" << endl;
        cout << "1. Add Student Record" << endl;
        cout << "2. Display All Records" << endl;
        cout << "3. Search Student by Roll Number" << endl;
        cout << "4. Delete Student Record" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(students); break;
            case 2: displayStudents(students); break;
            case 3: searchStudent(students); break;
            case 4: deleteStudent(students); break;
            case 5: saveToFile(students); cout << "Exiting... Data saved." << endl; break;
            default: cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

// Add a student record
void addStudent(vector<Student> &students) {
    Student s;
    cout << "Enter Roll Number: ";
    cin >> s.rollNo;
    cin.ignore(); // Ignore newline
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Marks for 3 Subjects: ";
    for (int i = 0; i < 3; i++) {
        cin >> s.marks[i];
    }
    s.calculateGrade();
    students.push_back(s);
    cout << "Student record added successfully!" << endl;
}

// Display all student records
void displayStudents(const vector<Student> &students) {
    if (students.empty()) {
        cout << "No records to display!" << endl;
        return;
    }

    cout << setw(10) << "Roll No" << setw(20) << "Name" << setw(10) << "Average" << setw(10) << "Grade" << endl;
    cout << "-----------------------------------------------------" << endl;
    for (const auto &s : students) {
        cout << setw(10) << s.rollNo << setw(20) << s.name << setw(10) << s.average << setw(10) << s.grade << endl;
    }
}

// Search for a student by roll number
void searchStudent(const vector<Student> &students) {
    int roll;
    cout << "Enter Roll Number to search: ";
    cin >> roll;

    for (const auto &s : students) {
        if (s.rollNo == roll) {
            cout << "Record Found!" << endl;
            cout << "Name: " << s.name << endl;
            cout << "Marks: " << s.marks[0] << ", " << s.marks[1] << ", " << s.marks[2] << endl;
            cout << "Average: " << s.average << endl;
            cout << "Grade: " << s.grade << endl;
            return;
        }
    }
    cout << "Record not found!" << endl;
}

// Delete a student record
void deleteStudent(vector<Student> &students) {
    int roll;
    cout << "Enter Roll Number to delete: ";
    cin >> roll;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->rollNo == roll) {
            students.erase(it);
            cout << "Record deleted successfully!" << endl;
            return;
        }
    }
    cout << "Record not found!" << endl;
}

// Save data to file
void saveToFile(const vector<Student> &students) {
    ofstream file("students.txt", ios::binary);
    if (!file) {
        cout << "Error saving data!" << endl;
        return;
    }
    for (const auto &s : students) {
        file.write((char*)&s, sizeof(Student));
    }
    file.close();
}

// Load data from file
void loadFromFile(vector<Student> &students) {
    ifstream file("students.txt", ios::binary);
    if (!file) {
        return; // File might not exist initially
    }
    Student s;
    while (file.read((char*)&s, sizeof(Student))) {
        students.push_back(s);
    }
    file.close();
}

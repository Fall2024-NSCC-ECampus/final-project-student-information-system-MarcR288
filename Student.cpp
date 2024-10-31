#include <iostream>
#include <vector>
#include <algorithm>
#include "Student.h"

using namespace std;

// 1) Print all Student data
void printAllStudents(const vector<Student>& students){
    cout << "----All Student Data----" << endl;
    for (const auto& student : students) {
        student.printOneStudent();
        cout << "--------------------" << endl;
    }
}

// 2) Sort the list of all students in alphabeitcal order of last name
void sortStudentsByLastName(vector<Student>& students) {
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        if (a.getLastName() == b.getLastName()) {
            return a.getFirstName() < b.getFirstName();
        }
        return a.getLastName() < b.getLastName();
    });
}

//3) Add a new student
Student addStudent() {
    string firstName;
    string lastName;
    int studentNumber;
    float midterm1Grade;
    float midterm2Grade;
    float finalGrade;

    cout << "Enter students first name "<< endl;
    cin >> firstName;
    cout << "Enter students last name " << endl;
    cin >> lastName;
    cout << "Enter student number" << endl;
    cin >> studentNumber;
    cout << "Enter students midterm 1 grade" << endl;
    cin >> midterm1Grade;
    cout << "Enter students midterm 2 grade" << endl;
    cin >> midterm2Grade;
    cout << "Enter students final grade" << endl;
    cin >> finalGrade;
    return Student(firstName, lastName, studentNumber, midterm1Grade, midterm2Grade, finalGrade);
}

//4) Calculate Letter Grade of all students
void CalculateLetterGradeOfAllStudents(vector<Student>& students) {
    for (auto& student : students) {
        float averageGrade =
            student.midterm1_grade() * student.midterm1_weight() +
            student.midterm2_grade() * student.midterm2_weight() +
            student.final_grade() * student.final_weight();
        // Determine letter grade
        string letterGrade;
        if (averageGrade >= 90) {
            letterGrade = "A";
        } else if (averageGrade >= 80) {
            letterGrade = "B";
        } else if (averageGrade >= 70) {
            letterGrade = "C";
        } else if (averageGrade >= 60) {
            letterGrade = "D";
        } else {
            letterGrade = "F";
        }
        student.setLetterGrade(letterGrade);
    }
}

//5) change the information of a previous student
void updateStudentInfo(vector<Student>& students) {
    int studentNumber;
    cout << "What is the Student Number of the student you would like to upate?: ";
    cin >> studentNumber;
    for (auto& student : students) {
        if (student.getStudentNumber() == studentNumber) {
            string newFirstName, newLastName;
            float newMidterm1, newMidterm2, newFinal;
            cout << "Enter new Student number" << endl;
            cin >> studentNumber;
            student.setStudentNumber(studentNumber);
            cout << "Enter new first name: ";
            cin >> newFirstName;
            student.setStudentName(newFirstName);
            cout << "Enter new last name: ";
            cin >> newLastName;
            student.setStudentLastName(newLastName);
            cout << "Enter new midterm 1 grade: ";
            cin >> newMidterm1;
            student.setMidterm1Grade(newMidterm1);
            cout << "Enter new midterm 2 grade: ";
            cin >> newMidterm2;
            student.setMidterm2Grade(newMidterm2);
            cout << "Enter new final grade: ";
            cin >> newFinal;
            student.setFinalGrade(newFinal);



            cout << "Student information updated successfully!" << endl;
            return; // Exit the function after updating
        }
    }
    cout << "Student with number " << studentNumber << " not found." << endl;
}

//6) Print the data of a specific student
void printSpecificStudent(vector<Student> students) {
    int inputStudentNumber;
    bool found = false;

    cout << "Entert Student Number: ";
    cin >> inputStudentNumber;

    for (auto& student : students) {
        if (student.getStudentNumber() == inputStudentNumber) {
            student.printOneStudent();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student number not found" << endl;
    }
}

//7) Remove a student from the list
void removeStudentById(std::vector<Student>& students) {
    int inputStudentNumber;
    std::cout << "Enter Student Number of student to be removed: ";
    std::cin >> inputStudentNumber;

    // Use std::remove_if to move the matching students to the end of the vector
    auto newEnd = std::remove_if(students.begin(), students.end(),
                                  [inputStudentNumber](const Student& student) {
                                      return student.getStudentNumber() == inputStudentNumber;
                                  });

    // Erase the "removed" students
    students.erase(newEnd, students.end());

    // Check if any students were removed
    if (newEnd != students.begin()) {
        std::cout << "Student with Student Number " << inputStudentNumber << " has been removed." << std::endl;
    } else {
        std::cout << "Student with number " << inputStudentNumber << " not found." << std::endl;
    }
}

//8) DELETE ALL student data
void deleteAllStudentData(vector<Student>& students){
    char choice;
    cout <<"---ARE YOU SURE YOU WANT TO DELETE ALL RECORDS--- (y/n) " << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        students.clear();
        if (students.empty()) {
            cout << "Student data is empty" << endl;
        } else {
            cout << "There are still students in the vector" << endl;
        }
    } else {
        cout <<"Records Retained" << endl;
    }

}

//9) Change Grading Scheme
void setGlobalWeights(float midterm1Weight, float midterm2Weight, float finalWeight, vector<Student>& students) {
    for (auto& student : students) {
        student.setWeights(midterm1Weight, midterm2Weight, finalWeight);
    }
    cout << "The following grading scheme is used for calculating the letter grades:" << endl;
    cout << "Midterm 1 Weight: " << midterm1Weight * 100 << "%" <<endl;
    cout << "Midterm 2 Weight: " << midterm2Weight * 100 << "%" <<endl;
    cout << "Final Weight:     " << finalWeight * 100 << "%" <<endl;
}

//9) Change Grading Scheme COMPLETE
void completeSetGlobalWeights(vector<Student>& students) {
    char schemeChoice;
    float midterm1Weight = students[0].getMidTerm1Weight();
    float midterm2Weight = students[0].getMidTerm2Weight();
    float finalWeight = students[0].getFinalWeight();
    cout << "The following grading scheme is used for calculating the letter grades: " << endl;
    cout << "Midterm 1: " << midterm1Weight * 100 << endl;
    cout << "Midterm 2: " << midterm2Weight * 100 << endl;
    cout << "Final:     " << finalWeight * 100 << endl;
    cout << "Do you want to change the grading scheme? (y/n) " << endl;
    cin >> schemeChoice;
    if (schemeChoice == 'y') {
        float newMidterm1Weight, newMidterm2Weight, newFinalWeight;
        cout <<"What would you like to set the weight of Midterm 1 to: " << endl;
        cin >> newMidterm1Weight;
        cout <<"What would you like to set the weight of Midterm 2 to: " << endl;
        cin >> newMidterm2Weight;
        cout <<"What would you like to set the weight of the Final to: " << endl;
        cin >> newFinalWeight;
        // Divide by 100 before storing
        midterm1Weight = newMidterm1Weight / 100.0;
        midterm2Weight = newMidterm2Weight / 100.0;
        finalWeight = newFinalWeight / 100.0;
        setGlobalWeights(midterm1Weight, midterm2Weight, finalWeight, students);
    }
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Student.h"

using namespace std;

void printMainMenu() {
    cout << "1) Print all Student data" << endl;
    cout << "2) Sort the list of all students in alphabetical order of last name" << endl;
    cout << "3) Add a new student" << endl;
    cout << "4) Calculate the letter grade of all students" << endl;
    cout << "5) Change the information of a previous student" << endl;
    cout << "6) Print the data of a specific student" << endl;
    cout << "7) Remove a student from the list" << endl;
    cout << "8) Delete ALL student data" << endl;
    cout << "9) Change grading scheme" << endl;
    cout << "0) Exit" << endl;
}


void start() {
    //Adding Students on Start for Testing
    vector<Student> students = {
        Student("Alice", "Brown", 9673, 18, 92, 35),
        Student("Alice", "William", 9421, 31, 23, 99),
        Student("Bob", "Rodriguez", 8547, 71, 39, 33),
        Student("Frank", "Martinez", 9035, 97, 19, 76),
        Student("George", "Martinez", 9723, 45, 57, 71),
        Student("Frank", "Miller", 6391, 60, 64, 52),
        Student("Zoe", "Miller", 6771, 24, 51, 15),
        Student("Grace", "Rodriguez", 9962, 22, 49, 67),
        Student("Jane", "Davis", 7334, 38, 80, 69),
        Student("Emma", "Davis", 1961, 87, 66, 24)
    };
    char choice;

    while (true) {
        Student student("AA", "AA", 0, 0, 0, 0);

        printMainMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            //1) Print All student data
            case '1':
                printAllStudents(students);
                break;
            //2) Sort the list of students in alphabetical order of last name
            case '2':
                sortStudentsByLastName(students);
                break;
            //3) Add a new student
            case '3':
                students.push_back(addStudent());
                break;
            //4) Calculate the letter grade of all students
            case '4':
                CalculateLetterGradeOfAllStudents(students);
                break;
            //5) Change the information of a previous student
            case '5':
                updateStudentInfo(students);
                break;
            //6) Print the data of a specific student
            case '6':
                printSpecificStudent(students);
                break;
            //7) Remove a student from the list
            case '7':
                removeStudentById(students);
                break;
            //8) Delete ALL student data
            case '8':
                deleteAllStudentData(students);
                break;
            //9) Change Grading scheme
            case '9':
                completeSetGlobalWeights(students);
                break;
            case '0': exit(0);
        }
    }
}

int main() {
    start();
    return 0;
}

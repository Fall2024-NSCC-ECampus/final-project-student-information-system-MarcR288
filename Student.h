//
// Created by Marc_ on 2024-10-30.
//
#include <chrono>
#include <iostream>
#include <string>

using namespace std;
#ifndef STUDENT_H
#define STUDENT_H

class Student {
private:
    string lastName;
    string firstName;
    int studentNumber;
    float midterm1Grade;
    float midterm2Grade;
    float finalGrade;
    string letterGrade;

public:
    float midterm1Weight;
    float midterm2Weight;
    float finalWeight;
    //constuctor
    Student(string first, string last, int number, float mid1, float mid2, float final,
        float mid1Weight = 0.25, float mid2Weight = 0.25, float finalWeight = 0.5):
        firstName(first), lastName(last), studentNumber(number),
        midterm1Grade(mid1), midterm2Grade(mid2), finalGrade(final),
        midterm1Weight(mid1Weight), midterm2Weight(mid2Weight), finalWeight(finalWeight){}

    // Method to display student information
    void printOneStudent() const {
        cout << "Student Name: " << firstName << " " << lastName << endl;
        cout << "Student Number: " << studentNumber << endl;
        cout << "Midterm 1 Grade: " << midterm1Grade << endl;
        cout << "Midterm 2 Grade: " << midterm2Grade << endl;
        cout << "Final Grade: " << finalGrade << endl;
        if (!letterGrade.empty()) {
            cout << "Letter Grade: " << letterGrade << endl;
        } else {
            cout << "Letter Grade has not been calculated" << endl;
        }
    }

    //9) Change Grading Scheme
    void setWeights(float mid1Weight, float mid2Weight, float finalWeight) {
        this->midterm1Weight = mid1Weight; // Use 'this->' to clarify the member variable
        this->midterm2Weight = mid2Weight;
        this->finalWeight = finalWeight;
    }
    //GETTERS AND SETTERS
    string getLastName() const {return lastName;}
    string getFirstName() const {return firstName;}
    float midterm1_grade() const { return midterm1Grade; }
    float midterm2_grade() const { return midterm2Grade; }
    float final_grade() const { return finalGrade; }
    float midterm1_weight() const { return midterm1Weight; }
    float midterm2_weight() const { return midterm2Weight; }
    float final_weight() const { return finalWeight; }
    [[nodiscard]] float getMidTerm1Weight() const {return midterm1Weight;}
    [[nodiscard]] float getMidTerm2Weight() const {return midterm2Weight;}
    [[nodiscard]] float getFinalWeight() const {return finalWeight;}
    void setLetterGrade(const string& grade) { letterGrade = grade; }
    string getletterGrade() const {return letterGrade;}
    int getStudentNumber() const {return studentNumber;}
    void setStudentName(string firstName) {
        this->firstName = firstName;
    }
    void setStudentLastName(string lastName) {
        this->lastName = lastName;
    }
    void setStudentNumber(int number) {
        this->studentNumber = number;
    }
    void setMidterm1Grade(float grade) {
        this->midterm1Grade = grade;
    }
    void setMidterm2Grade(float grade) {
        this->midterm2Grade = grade;
    }
    void setFinalGrade(float grade) {
        this->finalGrade = grade;
    }
};

//Function Declarations:
void printAllStudents(const std::vector<Student>& students);
void sortStudentsByLastName(std::vector<Student>& students);
Student addStudent();
void CalculateLetterGradeOfAllStudents(std::vector<Student>& students);
void updateStudentInfo(std::vector<Student>& students);
void printSpecificStudent(std::vector<Student> students);
void removeStudentById(std::vector<Student>& students);
void deleteAllStudentData(std::vector<Student>& students);
void setGlobalWeights(float midterm1Weight, float midterm2Weight, float finalWeight, vector<Student>& students);
void completeSetGlobalWeights(vector<Student>& students);


#endif //STUDENT_H

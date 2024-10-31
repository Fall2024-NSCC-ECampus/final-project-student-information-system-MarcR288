                        Student Information System
    Overview
The Student Information System is a C++ console application designed to manage student records,
allowing users to perform various operations such as adding students, calculating grades, and modifying student
information.

    Features
Print All Student Data: Displays information for all students in the system.
Sort Students: Sorts the list of students by last name in alphabetical order - Will sort by first name when lastnames
are identical.
Add New Student: Enables the user to add a new student to the system.
Calculate Letter Grades: Calculates and displays letter grades for all students based on their scores and weights of
midterm 1, midterm 2 and Final.
Update Student Information: Allows modification of details for existing students.
Print Specific Student Data: Displays information for a specific student based on their ID.
Remove Student: Deletes a specific student from the list.
Delete All Student Data: Clears all records from the system.
Change Grading Scheme: Updates the weights for midterm 1, midterm 2, and the final.

    Installation
Clone or download the repository.
Open the project in your preferred IDE or text editor.
Compile the code using your C++ compiler.
Run the compiled executable.

                            Student Class Header File
    Overview
The Student.h file defines the Student class for managing student information in a student management system.
This class includes attributes for personal details, grades, and grading weights, as well as various methods.


    Attributes:
firstName: The student's first name.
lastName: The student's last name.
studentNumber: A unique identifier for the student.
midterm1Grade, midterm2Grade, finalGrade: Grades for assessments.
letterGrade: The calculated letter grade based on scores.
midterm1Weight, midterm2Weight, finalWeight: Weighting for each assessment.
Constructor: Initializes a Student object with provided personal details and grades, with default weights
for assessments.

    Methods:

printOneStudent(): Displays the student's information.
setWeights(): Updates the grading weights for the assessments.
Getters & Setters

                            Student Management Functions
    Overview
This file contains a set of functions for managing student data in a student management system. These functions allow
for displaying, sorting, adding, updating, and removing student records, as well as calculating letter grades and
managing grading schemes.

    Functions
1. printAllStudents(const vector<Student>& students)
Prints the details of all students in the system.

2. sortStudentsByLastName(vector<Student>& students)
Sorts the list of students in alphabetical order based on their last names. If two students have the same last name,
it sorts them by their first names.

3. addStudent()
Prompts the user for student information (first name, last name, student number, midterm grades, and final grade)
and creates a new Student object.

4. CalculateLetterGradeOfAllStudents(vector<Student>& students)
Calculates the letter grade for each student based on their weighted average grade from midterms and final. The letter
grades are assigned as follows:
    A: 90 and above
    B: 80 to 89
    C: 70 to 79
    D: 60 to 69
    F: below 60

5. updateStudentInfo(vector<Student>& students)
Updates the information of an existing student identified by their student number. The user is prompted to enter new
values for the student's name and grades.

6. printSpecificStudent(vector<Student> students)
Prints the data of a specific student based on the provided student number. If the student is not found, an appropriate
message is displayed.

7. removeStudentById(std::vector<Student>& students)
Removes a student from the list based on their student number. If the student is found, they are removed from the vector;
otherwise, a message is displayed.

8. deleteAllStudentData(vector<Student>& students)
Clears all student records from the vector.

9. setGlobalWeights(float midterm1Weight, float midterm2Weight, float finalWeight, vector<Student>& students)
Updates the grading weights for all students in the system. Displays the new weights as percentages.

10. completeSetGlobalWeights(vector<Student>& students)
Prompts the user to change the grading scheme for all students. It first displays the current weights and then updates
them based on user input, storing the weights as decimals.
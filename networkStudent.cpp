/*
 * Project: C867 Performance Assessment
 * Name: Tim Smith
 * Student ID: #000865546
*/

/*
 * NetworkStudent class definitions
 */

#include <string>
#include <iostream>
#include "student.h"
#include "networkStudent.h"
#include "degree.h"
using namespace std;

// Print function
void NetworkStudent::print() {
    int* daysPtr = getDaysToCompleteCourses();
    
    cout << this->getStudentID() << "\t" 
         << "First Name: " << this->getFirstName() << "\t"
         << "Last Name: " << this->getLastName() << "\t"
         << "Age: " << this->getAge() <<"\t"
         << "daysInCourse:  {" << *daysPtr << ", " << *(daysPtr + 1) << ", "
         << *(daysPtr + 2) << "} Degree Program: Network" << endl;
}

// Accessor for degreeProgram
Degree NetworkStudent::getDegreeProgram() {
    return degreeProgram;
}

// Constructor using base class constructor and adding degreeProgram handling
NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName,
                 string emailAddress, int age, int course1, int course2,
                 int course3, Degree degreeProgram) : 
Student(studentID, firstName, lastName, emailAddress, age, course1, course2,
        course3) {
    this->degreeProgram = degreeProgram;
}
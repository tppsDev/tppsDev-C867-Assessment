/*
 * Project: C867 Performance Assessment
 * Name: Tim Smith
 * Student ID: #000865546
*/

/*
 * Student class definitions
 */

#include <string>
#include <iostream>
using namespace std;

#include "student.h"

// Accessor functions
string Student::getStudentID() const {
    return studentID;
}

string Student::getFirstName() const {
    return firstName;
}

string Student::getLastName() const {
    return lastName;
}

string Student::getEmailAddress() const {
    return emailAddress;
}

int Student::getAge() const {
    return age;
}

int* Student::getDaysToCompleteCourses() {
    return daysToCompleteCourses;
}

// Mutator functions
void Student::setStudentID(string studID) {
    studentID = studID;
}

void Student::setFirstName(string studFirstName) {
    firstName = studFirstName;
}

void Student::setLastName(string studLastName) {
    lastName = studLastName;
}

void Student::setEmailAddress(string studEmailAddress) {
    emailAddress = studEmailAddress;
}

void Student::setAge(int studAge) {
    age = studAge;
}

void Student::setDaysToCompleteCourses(int course1, int course2, int course3) {
    daysToCompleteCourses[0] = course1;
    daysToCompleteCourses[1] = course2;
    daysToCompleteCourses[2] = course3;
}

// Constructors
Student::Student(){}

Student::Student(string studentID, string firstName, string lastName,
                 string emailAddress, int age, int course1, int course2,
                 int course3) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysToCompleteCourses[0] = course1;
    this->daysToCompleteCourses[1] = course2;
    this->daysToCompleteCourses[2] = course3;
}

// Deconstructor
Student::~Student() {
    for (int i = 0; i < 3; ++i) {
        delete &daysToCompleteCourses[i];
    }
}






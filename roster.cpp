/*
 * Project: C867 Performance Assessment
 * Name: Tim Smith
 * Student ID: #000865546
*/

/*
 * Roster class definitions and main program function
*/

#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include "degree.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "roster.h"
using namespace std;


// Student table comma separated strings as an array
const string studentData[] =
 {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
 "A5,Timothy,Smith,tsmi684@wgu.edu,43,12,19,33,SOFTWARE"};

// Used to keep track of last record added to array
int lastRecordAdded = 0;

// add function takes the student table fields and creates correct Student obj in classRosterArray
void Roster::add(string studentID, string firstName, string lastName, 
            string emailAddress, int age, int daysInCourse1, int daysInCourse2,
            int daysInCourse3, Degree degreeProgram) {
    // Determine degree program
    switch(degreeProgram) {
        case SECURITY:
            *(classRosterArray + lastRecordAdded) = new SecurityStudent(studentID,
                   firstName, lastName, emailAddress, age, daysInCourse1,
                   daysInCourse2, daysInCourse3, degreeProgram);
            break;
        case NETWORK:
            *(classRosterArray + lastRecordAdded) = new NetworkStudent(studentID,
                   firstName, lastName, emailAddress, age, daysInCourse1,
                   daysInCourse2, daysInCourse3, degreeProgram);
            break;
        case SOFTWARE:
            *(classRosterArray + lastRecordAdded) = new SoftwareStudent(studentID,
                   firstName, lastName, emailAddress, age, daysInCourse1,
                   daysInCourse2, daysInCourse3, degreeProgram);
            break;
    }
    lastRecordAdded++;   // Increment last record variable
}

// remove function removes a student record and replaces with and empty Student obj
void Roster::remove(string studentID) {
    bool recFound = false;
    int i = 0;
    
    do {
        if ((*classRosterArray[i]).getStudentID() == studentID) {
            for (int j = i; j < numOfStudents - 1; ++j) {
                classRosterArray[j] = classRosterArray[j + 1]; // shift array elements
            }
            classRosterArray[numOfStudents - 1] = new Student; // replace last element with an empty
            cout << "Record deleted." << endl;
            recFound = true;
        } 
        i++;        
    } while (recFound == false && i < numOfStudents);
    
    // Alert no record found
    if (recFound == false) {
        cout << "Student record not found." << endl;
    }
}

// Print entire roster, using individual object's print method
void Roster::printAll() {
    for (int i = 0; i < numOfStudents; ++i) {
        (*classRosterArray[i]).print();
    }
}

// Prints student's average days in course
void Roster::printAverageDaysInCourse(string studentID) {
    bool recFound = false;
    int* avgPtr;
    int totalDays = 0;
    float avgDays = 0.0;
    int i = 0;
    
    do {
        if ((*classRosterArray[i]).getStudentID() == studentID) {
            avgPtr = (*classRosterArray[i]).getDaysToCompleteCourses();
            for (int j = 0; j < 3; ++j) {
                totalDays += *(avgPtr + j);
            }
            recFound = true;
            avgDays = static_cast<double>(totalDays) / 3.0;
            cout << avgDays << endl;
        } 
        i++;        
    } while (recFound == false && i < numOfStudents);
    
    if (recFound == false) {
        cout << "Student record not found." << endl;
    }
}

// Loops through roster and finds invalid email addresses
void Roster::printInvalidEmails() {
    for (int i = 0; i < numOfStudents; ++i) {
        bool invalidEmail = true;
        string emailStr = (*classRosterArray[i]).getEmailAddress();
        
        size_t found = emailStr.find('@');
        if (found != string::npos) {
            found = emailStr.find('.', found);
            if (found != string::npos) {
                found = emailStr.find(' ');
                if (found == string::npos) {
                    invalidEmail = false;
                }
            }
        }
        if (invalidEmail) {
            cout << emailStr << " Invalid email address!" << endl;
        }
    }
}

// Print all students in a degree program
void Roster::printByDegreeProgram(Degree degreeProgram) {
    for (int i = 0; i < numOfStudents; ++i) {
        if ((*classRosterArray[i]).getDegreeProgram() == degreeProgram) {
            (*classRosterArray[i]).print();
        }
    }
}

// Function to call individual printAverageDaysInCourse for whole roster
void Roster::printAllAvgDays() {
    for (int i = 0; i < numOfStudents; ++i) {
        this->printAverageDaysInCourse((*classRosterArray[i]).getStudentID());
    }
}

// Destructor
Roster::~Roster() {
  for (int i = 0; i < numOfStudents; ++i) {
      delete classRosterArray[i];
  } 
}

int main() {
    // Print course info and name to the screen
    cout << "Course: Scripting and Programming - Applications – C867" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: #000865546" << endl;
    cout << "Name: Tim Smith" << endl;
    
    Roster classRoster;
    
    /*
     * Loop through student records parsing data and adding to classRoster. It uses stringstream
     * to pull in each string and then stores them in an array of strings. The integers needed
     * are then cast from the strings.
    */
    for (int i = 0; i < numOfStudents; ++i) {
        Degree degreeProgram;
        string recFields[9];
        stringstream record(studentData[i]);
        
        for (int j = 0; j < 9; ++j) {
            string field;
            getline(record, field, ',');
            recFields[j] = field;
        }
        
        if (recFields[8] == "SECURITY") {
            degreeProgram = SECURITY;
        }
        else if (recFields[8] == "NETWORK") {
            degreeProgram = NETWORK;
        }
        else if (recFields[8] == "SOFTWARE") {
            degreeProgram = SOFTWARE;
        }
        classRoster.add(recFields[0], recFields[1], recFields[2], recFields[3], stoi(recFields[4]),
                stoi(recFields[5]), stoi(recFields[6]), stoi(recFields[7]), degreeProgram);
        
    }
    
    classRoster.printAll();
    classRoster.printInvalidEmails();
    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.remove("A3");
    
    delete &classRoster;
    
    return 0;
}
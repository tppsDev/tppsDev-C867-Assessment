/*
 * Project: C867 Performance Assessment
 * Name: Tim Smith
 * Student ID: #000865546
*/

/*
 * This is the header file for the class Roster
 */

#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include <iostream>
#include "degree.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

// Set constant integer for easy future modification if table size changes
const int numOfStudents = 5;

class Roster {
   public:
       void add(string studentID, string firstName, string lastName,
               string emailAddress, int age, int daysInCourse1,
               int daysInCourse2, int daysInCourse3, Degree degreeProgram);
       void remove(string studentID);
       void printAll();
       void printAverageDaysInCourse(string studentID);
       void printInvalidEmails();
       void printByDegreeProgram(Degree degreeProgram);
       void printAllAvgDays();
       ~Roster();

   private:
       Student* classRosterArray[numOfStudents];
};

#endif /* ROSTER_H */


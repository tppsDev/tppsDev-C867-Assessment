/*
 * Project: C867 Performance Assessment
 * Name: Tim Smith
 * Student ID: #000865546
*/

/*
 * This is the header for the class NetworkStudent, derived from Student class
 */

#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include <string>
#include <iostream>
#include "student.h"
#include "degree.h"
using namespace std;

class SecurityStudent : public Student {
   public:
       //Print function to override parent class
       void print();
       // Accessor for degreeProgram
       Degree getDegreeProgram();
       // Constructor
       SecurityStudent(string studentID, string firstName, string lastName,
                 string emailAddress, int age, int course1, int course2,
                 int course3, Degree degreeProgram);
          
   private:
       Degree degreeProgram;
};

#endif /* SECURITYSTUDENT_H */


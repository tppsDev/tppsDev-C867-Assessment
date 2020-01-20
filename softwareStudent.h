/*
 * Project: C867 Performance Assessment
 * Name: Tim Smith
 * Student ID: #000865546
*/

/*
 * This is the header for the class NetworkStudent, derived from Student class
 */

#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include <string>
#include <iostream>
#include "student.h"
#include "degree.h"
using namespace std;

class SoftwareStudent : public Student {
   public:
       // Print function to override parent class
       void print();
       // Accessor for degreeProgram
       Degree getDegreeProgram();
       // Constructor
       SoftwareStudent(string studentID, string firstName, string lastName,
                 string emailAddress, int age, int course1, int course2,
                 int course3, Degree degreeProgram);
          
   private:
       Degree degreeProgram;
};

#endif /* SOFTWARESTUDENT_H */


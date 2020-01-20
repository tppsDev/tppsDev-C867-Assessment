/*
 * Project: C867 Performance Assessment
 * Name: Tim Smith
 * Student ID: #000865546
*/

/*
 * This is the header file for the class Student
 */

#include <string>
using namespace std;

#include "degree.h"

#ifndef STUDENT_H
#define STUDENT_H

class Student {
   public: 
       // Accessor functions
       string getStudentID() const;
       string getFirstName() const;
       string getLastName() const;
       string getEmailAddress() const;
       int getAge() const;
       int* getDaysToCompleteCourses();
       
       // Mutator functions
       void setStudentID(string studID);
       void setFirstName(string studFirstName);
       void setLastName(string studLastName);
       void setEmailAddress(string studEmailAddress);
       void setAge(int studAge);
       void setDaysToCompleteCourses(int course1, int course2, int course3);
       
       // Constructors
       Student(); //Added default constructor to make place holder for removing records
       
       Student(string studentID, string firstName, string lastName,
                 string emailAddress, int age, int course1, int course2,
                 int course3);
       
       // Destructor
       ~Student();
       
       
       // Virtual print
       virtual void print(){};
       
       // Virtual getDegreeProgram to be defined in subclasses
       virtual Degree getDegreeProgram(){};
       
   private:
       string studentID;
       string firstName;
       string lastName;
       string emailAddress;
       int age;
       int daysToCompleteCourses[3];
};

#endif /* STUDENT_H */


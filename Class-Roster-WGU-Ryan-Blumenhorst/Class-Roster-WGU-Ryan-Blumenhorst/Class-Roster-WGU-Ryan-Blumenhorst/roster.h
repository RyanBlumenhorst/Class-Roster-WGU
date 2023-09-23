#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"
using namespace std;

class Roster {
public:

    //Default Constructor
    Roster();

    //Destructor
    ~Roster();

    //Add Student to Roster
    void add(string studentID, string firstName, string lastName, string emailAddress,
        int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree);

    //Remove Student From Roster
    void remove(string studentID);

    //Print Functions
    //Print Roster
    void printAll();

    //Print Average to Complete 3 Courses
    void printAverageDaysInCourse(string studentID);

    //Find and Print Invalid Emails
    void printInvalidEmails();

    //Print by Degree Program
    void printByDegreeProgram(int degreeProgram);


    //Array of Pointers
    Student* classRosterArray[5];
};

#endif
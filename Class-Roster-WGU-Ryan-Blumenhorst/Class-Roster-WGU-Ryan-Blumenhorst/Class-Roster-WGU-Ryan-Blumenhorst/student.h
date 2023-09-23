#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#include <string>
#include <iostream>
#include <array>
#include <vector>
using namespace std;

class Student {
public:
    //Default Constructor
    Student();

    //Constructor
    Student(string studentID, string fName, string lName, string emailAddr, int age,
        int numDays1, int numDays2, int numDays3, Degree degree);

    //Virtual Print
    virtual void print();

    //Destructor
    ~Student();

    //Accessors
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    vector<int> getnumDays();

    virtual Degree getDegreeProgram();

    //Mutators
    void setStudentID(string sID);
    void setFirstName(string fName);
    void setLastName(string lName);
    void setEmail(string email);
    void setAge(int age);
    void setNumDays(vector<int> days);
    void setDegree(Degree degree);

private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    vector<int> numDays;
    Degree degree;

};

#endif

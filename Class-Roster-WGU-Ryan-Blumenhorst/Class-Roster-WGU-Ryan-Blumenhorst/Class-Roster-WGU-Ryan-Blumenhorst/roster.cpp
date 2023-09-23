/*
 * Ryan Blumenhorst
 * Class Roster Project
 * 3/19/21
 */

#include <array>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <string>
#include "roster.h"
#include "degree.h"
using namespace std;

//Default Constructor
Roster::Roster() {

}

const int NUM_STUDENTS = 5;

//Add Function
void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
    int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree) {

    for (int i = 0; i < NUM_STUDENTS; i++) {
        int index = stoi(studentID.substr(1)) - 1;
        if (degree == Degree::NETWORK) {
            Student* student = new Student;
            vector<int> numDays;
            numDays.push_back(daysInCourse1);
            numDays.push_back(daysInCourse2);
            numDays.push_back(daysInCourse3);
            student->setStudentID(studentID);
            student->setFirstName(firstName);
            student->setLastName(lastName);
            student->setEmail(emailAddress);
            student->setAge(age);
            student->setNumDays(numDays);
            student->setDegree(degree);
            classRosterArray[index] = student;
        }
        if (degree == Degree::SECURITY) {
            Student* student = new Student;
            vector<int> numDays;
            numDays.push_back(daysInCourse1);
            numDays.push_back(daysInCourse2);
            numDays.push_back(daysInCourse3);
            student->setStudentID(studentID);
            student->setFirstName(firstName);
            student->setLastName(lastName);
            student->setEmail(emailAddress);
            student->setAge(age);
            student->setNumDays(numDays);
            student->setDegree(degree);
            classRosterArray[index] = student;
        }
        if (degree == Degree::SOFTWARE) {
            Student* student = new Student;
            vector<int> numDays;
            numDays.push_back(daysInCourse1);
            numDays.push_back(daysInCourse2);
            numDays.push_back(daysInCourse3);
            student->setStudentID(studentID);
            student->setFirstName(firstName);
            student->setLastName(lastName);
            student->setEmail(emailAddress);
            student->setAge(age);
            student->setNumDays(numDays);
            student->setDegree(degree);
            classRosterArray[index] = student;
        }
    }
}

//Remove Student From Roster
void Roster::remove(string studentID) {

    for (int i = 0; i < NUM_STUDENTS; ++i) {
        if (classRosterArray[i] == nullptr) {
            cout << "ERROR: Student with ID: " << studentID << " Not Found" << endl;
            break;
        }
        else if (studentID == classRosterArray[i]->getStudentID()) {
            classRosterArray[i] = nullptr;
            cout << "Student Removed" << endl;
        }
    }
}

//Print Functions

//Print Entire Roster
void Roster::printAll() {
    for (int i = 0; i < NUM_STUDENTS; i++) {
        if (classRosterArray[i] == nullptr) {
            cout << endl;
        }
        else {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}

//Print Average Days Spent in Courses
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        if (this->classRosterArray[i]->getStudentID() == studentID) {
            vector<int> days = classRosterArray[i]->getnumDays();
            int average = (days.at(0) + days.at(1) + days.at(2)) / 3;
            cout << "Average time for Student with ID: " << studentID << " to complete 3 courses: " << average << " days." << endl;
        }
    }
    cout << endl;
}



// Checking emails for @, no spaces, and that they contain a period
void Roster::printInvalidEmails() {
    bool at = false;
    bool space = false;
    bool period = false;

    cout << "Invalid Emails:" << endl;
    for (int i = 0; i < NUM_STUDENTS; i++) {
        string email = (classRosterArray[i])->getEmail();
        if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos)) {
            cout << "The Email Address for Student: " << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() <<
                " is invalid: " << email << endl;
        }
    }
}

void Roster::printByDegreeProgram(int degreeProgram) {

    if (degreeProgram == Degree::SECURITY) {

        cout << "Security Degree students: " << endl;
        classRosterArray[0]->print();
        classRosterArray[3]->print();
    }
    if (degreeProgram == Degree::NETWORK) {

        cout << "Networking Degree students: " << endl;
        classRosterArray[1]->print();
    }
    if (degreeProgram == Degree::SOFTWARE) {

        cout << "Software Degree students: " << endl;
        classRosterArray[2]->print();
        classRosterArray[4]->print();
    }
    cout << endl;
}

Roster::~Roster() {
}




#include <array>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <string>
#include "degree.h"
#include "roster.h"
#include "student.h"
using namespace std;


//Main Function
int main() {

    //Student Data String
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Ryan,Blumenhorst,rblum12@wgu.edu,25,20,30,25,SOFTWARE"
    };

    //Constant that sets total students
    const int NUM_STUDENTS = 5;


    //Course Title, Programming Language, StudentID, Name
    cout << "C867 - Scripting and Programming - Applications " << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: #002094804 " << endl;
    cout << "Name: Ryan Blumenhorst" << endl;
    cout << endl;

    const int CLASS_SIZE = 5;
    Roster classRoster;
    Degree myDegree;

    //Adding Each Student to Class Roster
    for (int i = 0; i < CLASS_SIZE; i++) {
        stringstream student(studentData[i]);

        vector<string> index;

        while (student.good()) {
            string substr;
            getline(student, substr, ',');
            index.push_back(substr);
        }
        if (index[8] == "SECURITY") {
            myDegree = Degree::SECURITY;
        }
        if (index[8] == "SOFTWARE") {
            myDegree = Degree::SOFTWARE;
        }
        if (index[8] == "NETWORK") {
            myDegree = Degree::NETWORK;
        }
        classRoster.add(index[0], index[1], index[2], index[3], stoi(index[4]), stoi(index[5]),
            stoi(index[6]), stoi(index[7]), myDegree);
    }

    //Print Roster
    cout << "Print All Students" << endl;
    classRoster.printAll();
    cout << endl;

    //Print Invalid Emails
    cout << "Print Invalid Emails" << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    //Print Average Time for Courses for All Students
    cout << "Print Average Times" << endl;
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        string id = classRoster.classRosterArray[i]->getStudentID();
        classRoster.printAverageDaysInCourse(id);
    }

    //Print by Degree Program
    cout << "Printing by Software Degree Program" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    //Remove Student from Roster
    cout << "Removing Student from Roster" << endl;
    classRoster.remove("A3");

    //Re-Print Roster with Student Removed
    cout << "New Roster with Student Removed" << endl;
    classRoster.printAll();
    cout << endl;

    //Testing Removing Non-Existant Student
    classRoster.remove("A3");

    //Release Roster memory
    classRoster.~Roster();

    return 0;
}
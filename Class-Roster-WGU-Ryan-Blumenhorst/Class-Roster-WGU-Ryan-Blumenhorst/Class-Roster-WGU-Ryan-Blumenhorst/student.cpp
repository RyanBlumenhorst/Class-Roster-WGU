/*
 * WGU Class Roster
 * Author: Ryan Blumenhorst
 * Date: 3/19/2021
 *
 */

#include "student.h"
using namespace std;


//Default Constructor
Student::Student() {

}

//Constructor
Student::Student(string studentID, string fName, string lName, string emailAddr, int age,
    int numDays1, int numDays2, int numDays3, Degree degree) {
    setStudentID(studentID);
    setFirstName(fName);
    setLastName(lName);
    setEmail(emailAddr);
    setAge(age);
    numDays.push_back(numDays1);
    numDays.push_back(numDays2);
    numDays.push_back(numDays3);
    setDegree(degree);
}


//Print Function
void Student::print() {
    string program;
    //Setting Program to Degree Type
    if (degree == SECURITY) {
        program = "Security";
    }
    else if (degree == NETWORK) {
        program = "Network";
    }
    else if (degree == SOFTWARE) {
        program = "Software";
    }
    cout << studentID << "\t";
    cout << "First Name: " << firstName << "\t" << "Last Name: " << lastName << "\t" << "Age: " << age << "\t" << "\t";
    cout << "Days in Course: " << numDays.at(0) << ", " << numDays.at(1) << ", " << numDays.at(2) << "\t";
    cout << "Degree Program: " << program << "\t" << endl;
}

//ACCESSORS

//ID
string Student::getStudentID() {
    return studentID;
}
//First Name
string Student::getFirstName() {
    return firstName;
}

//Last Name
string Student::getLastName() {
    return lastName;
}

//Email Address
string Student::getEmail() {
    return emailAddress;
}

//Age
int Student::getAge() {
    return age;
}

//Days to Complete 3 Courses
vector<int> Student::getnumDays() {
    return numDays;
}

//Degree Program
Degree Student::getDegreeProgram() {
    return degree;
}

//MUTATORS

//ID
void Student::setStudentID(string sID) {
    studentID = sID;
}

//First Name
void Student::setFirstName(string fName) {
    firstName = fName;
}

//Last Name
void Student::setLastName(string lname) {
    lastName = lname;
}

//Email Address
void Student::setEmail(string email) {
    emailAddress = email;
}

//Age
void Student::setAge(int age) {
    this->age = age;
}

//Days to Complete 3 Courses
void Student::setNumDays(vector<int> days) {
    numDays = days;
}

//Degree Program
void Student::setDegree(Degree degree) {
    this->degree = degree;
}


//Destructor

Student::~Student() {

}
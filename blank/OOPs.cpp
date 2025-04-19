#include <iostream>
#include <string>
using namespace std;


// inheritance
class person {
public:
    // string name;
    // int age;

    // person(string name, int age) {
    //     this->name = name;
    //     this->age = age;
    // }

    // person() {
    //     cout << "PARENT CONSTRUCTER" << endl;
    // }

    string name;
    int age;

};

class student : public person {
public:
    int rollno;

    // student() {
    //     cout << "CHILD CONSTRUCTER" << endl;
    // }

    // student(string name, int age, int rollno) : person(name, age) { // calling function of
    //     this->rollno = rollno;
    // }

    // void getInfo() {
    //     cout << "NAME : " << name << endl;
    //     cout << "AGE : " <<age << endl;
    //     cout << "ROLL NO : " << rollno << endl;
    // }

};

class gradStudent : public student {
    public:
    string researchArea;
};

int main() {
    // student s1("RAHUL KUMAR", 24, 2345);
    // // s1.age = 21;
    // // s1.name = "RAHUL KUMAR";
    // // s1.rollno = 2345;
    // s1.getInfo();

    gradStudent s1;
    s1.name = "tony stark";
    s1.researchArea = "quantumPhysics";

    cout << s1.name << s1.researchArea << endl; 


    return 0;
}





























// class Teacher
// {
// public:
//     // Teacher()
//     // {
//     //     // non parametric constructer
//     //     dept = "CSE";
//     // }
//     // Teacher(string n, string d, string sub, double s)
//     // {
//     //     // parameterized
//     //     name = n;
//     //     dept = d;
//     //     subject = sub;
//     //     salary = s;
//     // }
//     Teacher(string name, string dept, string subject, double salary)
//     {
//         // parameterized
//         this->name = name;
//         this->dept = dept;
//         this->subject = subject;
//         this->salary = salary;
//     }
//     // to access out side the class public is used
//     // properties or attributes
//     string name;
//     string dept;
//     string subject;
//     double salary;

//     // methods
//     void changeDept(string newDept)
//     {
//         dept = newDept;
//     }

//     //copy constructer
//     Teacher(Teacher &orgObj) { // pass by refernce
//     cout << "I am custom cop constructer" << endl;
//         this->name = orgObj.name;
//         this->dept = orgObj.dept;
//         this->subject = orgObj.subject;
//         this->salary = orgObj.salary;
//     }
// };

// class Account
// {
// private:
//     double balance;
//     string password; // datahiding

// public:
//     string accID;
//     string userID;
// };

// class student {  
// public:
//     string name;
//     double* cgpaPtr;

//     student(string name, double cgpa) {
//         this->name = name;
//         cgpaPtr = new double;
//         *cgpaPtr = cgpa;
//     }

//     // student(student &orgObj) {
//     //     this->name = orgObj.name;
//     //     cgpaPtr = new double;     // heap copy
//     //     *cgpaPtr = *orgObj.cgpaPtr;
//     // }

//     //destructer
//     ~student() {
//         cout << "HI, DELETED EVERYTHING";
//         delete cgpaPtr;
//     }

//     void getInfo() {
//         cout << "NAME : " << name << endl;
//         cout << "CGPA : " << *cgpaPtr << endl;
//     }
    
// };


// int main()
// {
//     // Teacher t1("ISHITA", "CSE-DS", "C++", 200000); // constructor is called
//     // // t1.name = "Ishita";
//     // // t1.dept = "CSE-DS";
//     // // t1.subject = "PPS";
//     // // t1.changeDept("hello");
//     // Teacher t2(t1); // defluat copy constructer
//     // cout << t2.name << endl;
//     // cout << t2.dept << endl;

//     // Teacher t3(t1);
//     // cout << t3.name << endl;
//     // cout << t3.dept << endl;

//     student s1("RAHUL KUMAR", 8.9);
//     // student s2(s1);
//     s1.getInfo();
//     // *(s2.cgpaPtr) = 9.7;
//     // s2.name = "NEHA";
//     // s2.getInfo();

//     return 0;
// }
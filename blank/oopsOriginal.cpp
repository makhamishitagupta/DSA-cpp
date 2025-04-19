#include <iostream>
#include <string>
using namespace std;

// Base class: Person
class Person {
public:
    string name;
    int age;

    // Parameterized Constructor
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    // Default Constructor
    Person() {
        cout << "PARENT CONSTRUCTOR" << endl;
    }

    // Method to display details
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class: Student (Inheritance from Person)
class Student : public Person {
public:
    int rollNo;

    // Default Constructor
    Student() {
        cout << "CHILD CONSTRUCTOR" << endl;
    }

    // Parameterized Constructor
    Student(string name, int age, int rollNo) : Person(name, age) {
        this->rollNo = rollNo;
    }

    // Method to display student info
    void getInfo() {
        display();
        cout << "ROLL NO: " << rollNo << endl;
    }
};

// Class: Teacher
class Teacher {
public:
    string name;
    string dept;
    string subject;
    double salary;

    // Parameterized Constructor
    Teacher(string name, string dept, string subject, double salary) {
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }

    // Copy Constructor (Shallow Copy)
    Teacher(const Teacher &orgObj) {
        cout << "I am a shallow copy constructor" << endl;
        this->name = orgObj.name;
        this->dept = orgObj.dept;
        this->subject = orgObj.subject;
        this->salary = orgObj.salary;
    }

    // Method to display teacher info
    void displayInfo() {
        cout << "Name: " << name << ", Department: " << dept << ", Subject: " << subject << ", Salary: " << salary << endl;
    }
};

// Encapsulation: Account Class
class Account {
private:
    double balance;
    string password;

public:
    string accID;
    string userID;
    
    // Constructor
    Account(string accID, string userID, double balance, string password) {
        this->accID = accID;
        this->userID = userID;
        this->balance = balance;
        this->password = password;
    }
    
    // Method to display account details
    void showAccount() {
        cout << "Account ID: " << accID << ", User ID: " << userID << ", Balance: " << balance << endl;
    }
};

// Dynamic Memory Allocation & Destructor Example: Student Class
class StudentCGPA {
public:
    string name;
    double *cgpaPtr;

    // Parameterized Constructor
    StudentCGPA(string name, double cgpa) {
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }

    // Copy Constructor (Deep Copy)
    StudentCGPA(const StudentCGPA &orgObj) {
        cout << "I am a deep copy constructor" << endl;
        this->name = orgObj.name;
        cgpaPtr = new double;
        *cgpaPtr = *orgObj.cgpaPtr;
    }

    // Destructor
    ~StudentCGPA() {
        cout << "Deleting dynamically allocated memory." << endl;
        delete cgpaPtr;
    }

    // Method to display info
    void getInfo() {
        cout << "NAME: " << name << endl;
        cout << "CGPA: " << *cgpaPtr << endl;
    }
};

int main() {
    // Demonstrating Inheritance
    Student s1("RAHUL KUMAR", 24, 2345);
    s1.getInfo();

    // Demonstrating Dynamic Memory Allocation & Destructor
    StudentCGPA s2("Rahul Kumar", 8.9);
    s2.getInfo();

    // Demonstrating Copy Constructors
    Teacher t1("ISHITA", "CSE", "C++", 200000);
    Teacher t2(t1); // Shallow Copy
    t2.displayInfo();

    StudentCGPA s3(s2); // Deep Copy
    s3.getInfo();

    // Demonstrating Encapsulation
    Account acc1("ACC123", "USR456", 5000.75, "pass123");
    acc1.showAccount();

    return 0;
}

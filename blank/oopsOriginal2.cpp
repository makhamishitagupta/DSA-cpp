#include <iostream>
#include <string>
using namespace std;

// Types of Inheritance in C++
/*
1. Single Inheritance - One class inherits from another class.
2. Multiple Inheritance - A class inherits from multiple base classes.
3. Multilevel Inheritance - A class is derived from another derived class.
4. Hierarchical Inheritance - Multiple classes inherit from a single base class.
5. Hybrid Inheritance - Combination of two or more types of inheritance.
*/

// Additional OOP Concepts
/*
6. Encapsulation - Wrapping data and methods into a single unit (class).
7. Abstraction - Hiding implementation details and exposing only necessary parts.
8. Polymorphism - Ability to take many forms (Function Overloading, Operator Overloading, Virtual Functions).
*/

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

// Single Inheritance: Student inherits from Person
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

// Multiple Inheritance: Teacher inherits from two classes
class Department {
public:
    string deptName;

    Department(string deptName) {
        this->deptName = deptName;
    }
};

class Teacher : public Person, public Department {
public:
    string subject;
    double salary;

    // Parameterized Constructor
    Teacher(string name, int age, string dept, string subject, double salary) 
        : Person(name, age), Department(dept) {
        this->subject = subject;
        this->salary = salary;
    }

    // Method to display teacher info
    void displayInfo() {
        display();
        cout << "Department: " << deptName << ", Subject: " << subject << ", Salary: " << salary << endl;
    }
};

// Multilevel Inheritance: ResearchStudent inherits from Student
class ResearchStudent : public Student {
public:
    string researchTopic;

    ResearchStudent(string name, int age, int rollNo, string topic) : Student(name, age, rollNo) {
        this->researchTopic = topic;
    }

    void showResearch() {
        getInfo();
        cout << "Research Topic: " << researchTopic << endl;
    }
};

// Hierarchical Inheritance: Multiple classes inherit from Person
class Staff : public Person {
public:
    string position;

    Staff(string name, int age, string position) : Person(name, age) {
        this->position = position;
    }

    void displayStaff() {
        display();
        cout << "Position: " << position << endl;
    }
};

// Example of Polymorphism (Function Overloading)
class MathOperations {
public:
    int add(int a, int b) {
        return a + b;
    }
    double add(double a, double b) {
        return a + b;
    }
};

// Example of Encapsulation
class BankAccount {
private:
    double balance;
public:
    BankAccount(double bal) { balance = bal; }
    void deposit(double amount) { balance += amount; }
    void displayBalance() { cout << "Balance: " << balance << endl; }
};

int main() {
    // Single Inheritance
    Student s1("RAHUL KUMAR", 24, 2345);
    s1.getInfo();

    // Multiple Inheritance
    Teacher t1("ISHITA", 35, "CSE", "C++", 200000);
    t1.displayInfo();

    // Multilevel Inheritance
    ResearchStudent rs1("Ananya", 27, 5678, "AI and ML");
    rs1.showResearch();

    // Hierarchical Inheritance
    Staff st1("Varun", 40, "Librarian");
    st1.displayStaff();

    // Demonstrating Polymorphism
    MathOperations math;
    cout << "Sum (int): " << math.add(5, 10) << endl;
    cout << "Sum (double): " << math.add(5.5, 10.2) << endl;

    // Demonstrating Encapsulation
    BankAccount acc(5000.75);
    acc.deposit(1000.25);
    acc.displayBalance();

    return 0;
}

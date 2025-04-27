#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(const string& name, int age) : name(name), age(age) {}
    virtual void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Student : virtual public Person { // Virtual inheritance here
protected:
    int rollNumber;
    string branch;
    float marks;

public:
    Student(const string& name, int age, int rollNumber, const string& branch, float marks)
        : Person(name, age), rollNumber(rollNumber), branch(branch), marks(marks) {}

    float calculateCGPA() const {
        return marks / 9.5; // Example CGPA calculation
    }

    void display() override {
        cout << "Student Details:" << endl;
        Person::display();
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Branch: " << branch << endl;
        cout << "Marks: " << marks << ", CGPA: " << fixed << setprecision(1) << calculateCGPA() << endl;
    }

    friend class Administration;
};

class Faculty : virtual public Person { // Virtual inheritance here
protected:
    int facultyID;
    string department;
    double salary;

public:
    Faculty(const string& name, int age, int facultyID, const string& department, double salary)
        : Person(name, age), facultyID(facultyID), department(department), salary(salary) {}

    void display() override {
        cout << "Faculty Details:" << endl;
        Person::display();
        cout << "Faculty ID: " << facultyID << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: ₹" << fixed << setprecision(0) << salary << endl;
    }

    friend class Administration;
};

class TeachingAssistant : public Student, public Faculty {
public:
    TeachingAssistant(const string& name, int age, int rollNumber, const string& branch, float marks,
                       int facultyID, const string& department, double salary)
        : Person(name, age), Student(name, age, rollNumber, branch, marks),
          Faculty(name, age, facultyID, department, salary) {}

    void display() override {
        cout << "Teaching Assistant Details:" << endl;
        Person::display();
        cout << "Roll Number: " << Student::rollNumber << endl;
        cout << "Branch: " << Student::branch << endl;
        cout << "Marks: " << Student::marks << ", CGPA: " << fixed << setprecision(1) << Student::calculateCGPA() << endl;
        cout << "Faculty ID: " << Faculty::facultyID << endl;
        cout << "Department: " << Faculty::department << endl;
        cout << "Salary: ₹" << fixed << setprecision(0) << Faculty::salary << endl;
    }
};

class Administration {
public:
    void displayStudentDetails(const Student& student) {
        cout << "Student " << student.name << " from " << student.branch << " scored " << student.marks << " marks." << endl;
    }

    void displayFacultyDetails(const Faculty& faculty) {
        cout << "Faculty " << faculty.name << " teaches " << faculty.department << "." << endl;
    }
};

int main() {
    Student student("Raj Malhotra", 20, 101, "CSE (AI-ML)", 89.0);
    Faculty faculty("Dr. A. Sharma", 75, 100, "Computer Science", 120000.0);
    TeachingAssistant ta("Priya Desai", 25, 105, "CSE (AI-ML)", 92.0, 2005, "Artificial Intelligence", 35000.0);

    student.display();
    cout << endl;
    faculty.display();
    cout << endl;
    ta.display();
    cout << endl;

    Administration admin;
    admin.displayStudentDetails(student);
    admin.displayFacultyDetails(faculty);

    return 0;
}
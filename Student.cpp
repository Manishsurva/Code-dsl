#include <iostream>
#include <string>

class Student;

class StudentDatabase {
public:
    void displayStudentInfo(const Student& student);
};

class Student {
private:
    std::string name;
    int rollNumber;
    std::string className;
    char division;
    std::string dob;
    std::string bloodGroup;
    std::string contactAddress;
    std::string telephoneNumber;
    std::string drivingLicenseNumber;

public:
    // Constructors
    Student() {
        // Default constructor
        name = "Unknown";
        rollNumber = 0;
        className = "Unknown";
        division = 'A';
        dob = "Unknown";
        bloodGroup = "Unknown";
        contactAddress = "Unknown";
        telephoneNumber = "Unknown";
        drivingLicenseNumber = "Unknown";
    }

    Student(std::string n, int roll, std::string cls, char div, std::string dob, std::string blood,
            std::string addr, std::string phone, std::string license)
        : name(n),
          rollNumber(roll),
          className(cls),
          division(div),
          dob(dob),
          bloodGroup(blood),
          contactAddress(addr),
          telephoneNumber(phone),
          drivingLicenseNumber(license) {}

    // Destructor
    ~Student() {
        std::cout << "Destructor called for student: " << name << std::endl;
    }

    // Friend class
    friend class StudentDatabase;

    // Member functions
    void acceptStudentInfo();
    void displayStudentInfo();
};

void Student::acceptStudentInfo() {
    std::cout << "Enter student information:" << std::endl;
    std::cout << "Name: ";
    std::getline(std::cin, name);

    std::cout << "Roll Number: ";
    std::cin >> rollNumber;
    std::cin.ignore(); // Clear the newline character from the input buffer

    std::cout << "Class: ";
    std::getline(std::cin, className);

    std::cout << "Division: ";
    std::cin >> division;
    std::cin.ignore();

    std::cout << "Date of Birth: ";
    std::getline(std::cin, dob);

    std::cout << "Blood Group: ";
    std::getline(std::cin, bloodGroup);

    std::cout << "Contact Address: ";
    std::getline(std::cin, contactAddress);

    std::cout << "Telephone Number: ";
    std::getline(std::cin, telephoneNumber);

    std::cout << "Driving License Number: ";
    std::getline(std::cin, drivingLicenseNumber);
}

void Student::displayStudentInfo() {
    std::cout << "\nStudent Information:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Roll Number: " << rollNumber << std::endl;
    std::cout << "Class: " << className << std::endl;
    std::cout << "Division: " << division << std::endl;
    std::cout << "Date of Birth: " << dob << std::endl;
    std::cout << "Blood Group: " << bloodGroup << std::endl;
    std::cout << "Contact Address: " << contactAddress << std::endl;
    std::cout << "Telephone Number: " << telephoneNumber << std::endl;
    std::cout << "Driving License Number: " << drivingLicenseNumber << std::endl;
}

void StudentDatabase::displayStudentInfo(const Student& student) {
    std::cout << "\nStudent Information (accessed from friend class):" << std::endl;
    std::cout << "Name: " << student.name << std::endl;
    std::cout << "Roll Number: " << student.rollNumber << std::endl;
    std::cout << "Class: " << student.className << std::endl;
    std::cout << "Division: " << student.division << std::endl;
    std::cout << "Date of Birth: " << student.dob << std::endl;
    std::cout << "Blood Group: " << student.bloodGroup << std::endl;
    std::cout << "Contact Address: " << student.contactAddress << std::endl;
    std::cout << "Telephone Number: " << student.telephoneNumber << std::endl;
    std::cout << "Driving License Number: " << student.drivingLicenseNumber << std::endl;
}

int main() {
    Student student1; // Default constructor
    student1.displayStudentInfo(); // Display default information

    Student student2("John Doe", 101, "Physics", 'B', "01/01/2000", "O+", "123 Main St", "555-1234", "DL12345");
    student2.displayStudentInfo(); // Display provided information

    student2.acceptStudentInfo(); // Accept new information
    student2.displayStudentInfo(); // Display updated information

    // Using friend class to display student information
    StudentDatabase studentDatabase;
    studentDatabase.displayStudentInfo(student2);

    return 0;
}

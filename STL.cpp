#include <iostream>
#include <vector>
#include <algorithm>

// Structure to represent a personal record
struct PersonalRecord {
    std::string name;
    std::string dob;
    std::string phoneNumber;

    // Constructor to initialize the record
    PersonalRecord(std::string n, std::string d, std::string phone)
        : name(n), dob(d), phoneNumber(phone) {}
};

// Function to display a personal record
void displayRecord(const PersonalRecord& record) {
    std::cout << "Name: " << record.name << ", DOB: " << record.dob
              << ", Phone Number: " << record.phoneNumber << std::endl;
}

int main() {
    // Vector to store personal records
    std::vector<PersonalRecord> records;

    // Adding some sample records to the vector
    records.emplace_back("huli", "1990-05-15", "123-456-7890");
    records.emplace_back("pit", "1985-08-22", "987-654-3210");
    records.emplace_back("Char", "1998-03-10", "555-123-4567");

    // Displaying the unsorted records
    std::cout << "Unsorted Records:" << std::endl;
    for (const auto& record : records) {
        displayRecord(record);
    }

    // Sorting the records based on names
    std::sort(records.begin(), records.end(),
              [](const PersonalRecord& a, const PersonalRecord& b) {
                  return a.name < b.name;
              });

    // Displaying the sorted records
    std::cout << "\nSorted Records (by Name):" << std::endl;
    for (const auto& record : records) {
        displayRecord(record);
    }

    // Searching for a record by name
    std::string searchName;
    std::cout << "\nEnter a name to search: ";
    std::getline(std::cin, searchName);

    auto it = std::find_if(records.begin(), records.end(),
                           [&searchName](const PersonalRecord& record) {
                               return record.name == searchName;
                           });

    // Displaying the search result
    if (it != records.end()) {
        std::cout << "Record Found:" << std::endl;
        displayRecord(*it);
    } else {
        std::cout << "Record not found." << std::endl;
    }

    return 0;
}

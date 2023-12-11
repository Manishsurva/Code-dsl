#include <iostream>
#include <string>

// Base class Publication
class Publication {
protected:
    std::string title;
    float price;

public:
    Publication() : title(""), price(0.0) {}

    // Function to accept data for the publication
    void getData() {
        std::cout << "Enter title: ";
        std::getline(std::cin, title);

        std::cout << "Enter price: $";
        std::cin >> price;
        std::cin.ignore(); // Clear the newline character from the input buffer
    }

    // Function to display data for the publication
    void displayData() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Price: $" << price << std::endl;
    }
};

// Derived class Tape
class Tape : public Publication {
private:
    float playingTime;

public:
    Tape() : playingTime(0.0) {}

    // Function to accept data for the tape
    void getData() {
        Publication::getData(); // Call the base class function to get common data

        std::cout << "Enter playing time (in minutes): ";
        std::cin >> playingTime;
        std::cin.ignore(); // Clear the newline character from the input buffer
    }

    // Function to display data for the tape
    void displayData() const {
        Publication::displayData(); // Call the base class function to display common data
        std::cout << "Playing Time: " << playingTime << " minutes" << std::endl;
    }
};

int main() {
    // Instantiate the Tape class
    Tape myTape;

    // Allow the user to enter data for the tape
    myTape.getData();

    // Display the entered data for the tape
    std::cout << "\nTape Information:" << std::endl;
    myTape.displayData();

    return 0;
}

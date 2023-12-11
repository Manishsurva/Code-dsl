#include <iostream>
#include <string>

class Publication {
protected:
    std::string title;
    float price;

public:
    Publication() : title(""), price(0.0) {}

    void getData() {
        std::cout << "Enter title: ";
        std::getline(std::cin, title);

        std::cout << "Enter price: $";
        std::cin >> price;
        std::cin.ignore(); // Clear the newline character from the input buffer
    }

    void displayData() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Price: $" << price << std::endl;
    }
};

class Book : public Publication {
private:
    int pageCount;

public:
    Book() : pageCount(0) {}

    void getData() {
        Publication::getData(); // Call the base class function to get common data
        std::cout << "Enter page count: ";
        std::cin >> pageCount;
        std::cin.ignore(); // Clear the newline character from the input buffer
    }

    void displayData() const {
        Publication::displayData(); // Call the base class function to display common data
        std::cout << "Page Count: " << pageCount << " pages" << std::endl;
    }
};

int main() {
    Book myBook;

    std::cout << "Enter information for the book:" << std::endl;
    myBook.getData();

    std::cout << "\nBook Information:" << std::endl;
    myBook.displayData();

    return 0;
}

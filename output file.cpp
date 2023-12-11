#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Creating an output file
    std::ofstream outputFile("example.txt");

    // Check if the file is successfully opened
    if (!outputFile.is_open()) {
        std::cerr << "Error opening the output file." << std::endl;
        return 1;
    }

    // Writing information to the file
    outputFile << "Hello, this is a sample text.\n";
    outputFile << "This is another line in the file.\n";
    outputFile << "12345\n";

    // Closing the output file
    outputFile.close();

    // Opening the file again as an input file
    std::ifstream inputFile("example.txt");

    // Check if the file is successfully opened
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the input file." << std::endl;
        return 1;
    }

    // Reading information from the file
    std::string line;
    std::cout << "Contents of the file:" << std::endl;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    // Closing the input file
    inputFile.close();

    return 0;
}

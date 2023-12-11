#include <iostream>
#include <map>
#include <string>

int main() {
    // Creating a map to store state populations in India
    std::map<std::string, long long> statePopulationsIndia;

    // Adding some sample state populations to the map
    statePopulationsIndia["Maharashtra"] = 112374333;
    statePopulationsIndia["Uttar Pradesh"] = 199812341;
    statePopulationsIndia["Bihar"] = 104099452;
    statePopulationsIndia["West Bengal"] = 91276115;
    statePopulationsIndia["Madhya Pradesh"] = 72597565;

    // Prompting the user to enter the name of a state
    std::string stateName;
    std::cout << "Enter the name of a state in India: ";
    std::getline(std::cin, stateName);

    // Looking up the population using the entered state name
    auto it = statePopulationsIndia.find(stateName);

    // Displaying the result
    if (it != statePopulationsIndia.end()) {
        std::cout << "Population of " << stateName << " in India: " << it->second << std::endl;
    } else {
        std::cout << "State not found in India." << std::endl;
    }

    return 0;
}

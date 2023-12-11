#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    // Constructors
    Complex() : real(0.0), imaginary(0.0) {} // Default constructor

    Complex(double r, double i) : real(r), imaginary(i) {}

    // Getter functions
    double getReal() const {
        return real;
    }

    double getImaginary() const {
        return imaginary;
    }

    // Overloaded operator+
    Complex operator+(const Complex& other) const {
        Complex result;
        result.real = real + other.real;
        result.imaginary = imaginary + other.imaginary;
        return result;
    }
};

// Overloaded << operator to print Complex numbers
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.getReal() << " + " << c.getImaginary() << "i";
    return os;
}

int main() {
    // Example usage
    Complex c1(2.5, 3.0);
    Complex c2(1.5, 2.0);

    Complex sum = c1 + c2;

    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}

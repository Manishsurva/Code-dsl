#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    // Constructors
    Complex() : real(0.0), imaginary(0.0) {}
    Complex(double r, double i) : real(r), imaginary(i) {}

    // Overloaded operator* for multiplication of complex numbers
    Complex operator*(const Complex& other) const {
        Complex result;
        result.real = (real * other.real) - (imaginary * other.imaginary);
        result.imaginary = (real * other.imaginary) + (other.real * imaginary);
        return result;
    }

    // Overloaded operator<< for output
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << " + " << c.imaginary << "i";
        return os;
    }

    // Overloaded operator>> for input
    friend std::istream& operator>>(std::istream& is, Complex& c) {
        std::cout << "Enter real part: ";
        is >> c.real;
        std::cout << "Enter imaginary part: ";
        is >> c.imaginary;
        return is;
    }
};

int main() {
    Complex c1, c2, result;

    // Input complex numbers
    std::cout << "Enter the first complex number:" << std::endl;
    std::cin >> c1;

    std::cout << "Enter the second complex number:" << std::endl;
    std::cin >> c2;

    // Multiply complex numbers
    result = c1 * c2;

    // Display the result
    std::cout << "Result of multiplication: " << result << std::endl;

    return 0;
}

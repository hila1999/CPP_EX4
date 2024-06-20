#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

    double getReal() const {
        return real;
    }

    double getImaginary() const {
        return imaginary;
    }

    void setReal(double real) {
        this->real = real;
    }

    void setImaginary(double imaginary) {
        this->imaginary = imaginary;
    }

    friend std::ostream& operator<<(std::ostream& out, const Complex& c) {
        out << c.real << " + " << c.imaginary << "i";
        return out;
    }
};
#endif // COMPLEX_HPP
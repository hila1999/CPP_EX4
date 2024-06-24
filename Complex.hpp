#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
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
    bool operator==(const Complex &c) const {
        return real == c.real && imaginary == c.imaginary;}
       std::string to_string() const {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(1) << real << " + " << imaginary << "i";
        return oss.str();
       }
      
    
    friend std::ostream& operator<<(std::ostream& out, const Complex& c) {
        out << c.real << " + " << c.imaginary << "i";
        return out;
    }
};
inline std::string to_string(const Complex &c){
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(1) << c.getReal() << " + " << c.getImaginary() << "i";
            return oss.str();
}

    
#endif // COMPLEX_HPP
#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex {
  private:
    double real;
    double imag;
    // Default Constructor (3)
    Complex();

  public:
    // Custom Constructor (4)
    Complex(double a, double b);

    // Copy Constructor Deep (5)
    Complex(const Complex &obj);

    // Assignment Operator (6)
    Complex &operator=(const Complex &obj);

    // Destructor (7)
    ~Complex();

    // Norm (8)
    double norm();

    // Conjugate (9)
    
    // Sobrecargas (10)
    Complex operator+(const Complex &obj) const;
    Complex operator-(const Complex &obj) const;
    Complex operator*(const Complex &obj) const;
    Complex operator/(const Complex &obj) const;
};

#endif

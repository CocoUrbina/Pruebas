#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex {
  private:
    double real;
    double imag;

  public:
    //Default Constructor (3)
    Complex();

    // Custom Constructor (4)
    Complex(double a, double b);

    // Copy Constructor Deep (5)
    Complex(const Complex &obj);

    // Assignment Operator (6)
    Complex &operator=(const Complex &obj);

    // Destructor (7)
    ~Complex();

    // Norm (8)
    double norm() const;

    // Conjugate (9)
    Complex conjugate() const;

    // Sobrecargas (10)
    Complex operator+(const Complex &obj) const;
    Complex operator-(const Complex &obj) const;
    Complex operator*(const Complex &obj) const;
    Complex operator/(const Complex &obj) const;

    // Getters
    double get_real() const;
    double get_imag() const;

};

#endif

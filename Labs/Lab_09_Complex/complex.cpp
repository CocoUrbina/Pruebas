#include <iostream>
#include <cmath>

#include "complex.hpp"

// Default Constructor(3)
Complex::Complex(){
  real = 0.0;
  imag = 0.0;
}

// Custom Constructor (4)
Complex::Complex(double a, double b){
  real = a;
  imag = b;
}

// Copy Constructor Deep (5)
Complex::Complex(const Complex &obj){
  real = obj.real;
  imag = obj.imag;
}

// Assignment Operator (6)
Complex &Complex::operator=(const Complex &obj){
  std::cout << "Assignment operator invoked!" << std::endl;
  real = obj.real;
  imag = obj.imag;

  return *this;
}

// Destructor (7)
Complex::~Complex(){
}

// Norm (8)
double Complex::norm() const {
  return std::sqrt(real * real + imag * imag) ;
}

// Conjugate (9)
Complex Complex::conjugate() const {
  return Complex(real, -imag);
}

// Sobrecargas (10)
Complex Complex::operator+(const Complex &obj) const {
  Complex result(real, imag);
  result.real = real + obj.real;
  result.imag = imag + obj.imag;

  return result;
}

Complex Complex::operator-(const Complex &obj) const {
  Complex result(real, imag);
  result.real = real - obj.real;
  result.imag = imag - obj.imag;

  return result;
}

Complex Complex::operator*(const Complex &obj) const {
  Complex result(real, imag);
  result.real = real * obj.real - imag * obj.imag;
  result.imag = real * obj.imag + imag * obj.real;

  return result;
}

Complex Complex::operator/(const Complex &obj) const {
  Complex result(real, imag);
  double denom = obj.real * obj.real + obj.imag * obj.imag;

  result.real = (real * obj.real + imag * obj.imag) / denom;
  result.imag = (imag * obj.real - real * obj.imag) / denom;

  return result;
}

// Getters
double Complex::get_real() const {
    return real;
}

double Complex::get_imag() const {
    return imag;
}


#include <iostream>

#include "matrix.hpp"

// Default Constructor (1)
Matrix::Matrix(){
}

// Custom Constructor (2)
Matrix::Matrix(int n, int m){
  n_rows = n;
  n_cols = m;
  data = new double[n_rows * n_cols];
}

// Destructor (3)
Matrix::~Matrix(){
  delete [] data;
}

// Copy Constructor Deep (4)
Matrix::Matrix(const Matrix &obj){
  n_rows = obj.n_rows;
  n_cols = obj.n_cols;
  data = new double[n_rows * n_cols];
  for(int i = 0; i < n_rows * n_cols; ++i){
    data[i] = obj.data[i];
  }
}

// Asignment Operator (5)
Matrix &Matrix::operator=(const Matrix &obj){
  std::cout << "Assignment operator invoked!" << std::endl;

  if (this == &obj) return *this; // auto-asignación
  delete[] data; // liberar memoria actual

  n_rows = obj.n_rows;
  n_cols = obj.n_cols;
  data = new double[n_rows * n_cols];

  for(int i = 0; i < n_rows * n_cols; ++i){
    data[i] = obj.data[i];
  }

  return *this;
}

// Getters (6)
int Matrix::get_rows(){
  return n_rows;
}

int Matrix::get_cols(){
  return n_cols;
}

// Print Matrix (7)
void print_matrix(const Matrix &m){
    for(int i = 0; i < m.get_rows(); ++i){
        for(int j = 0; j < m.get_cols(); ++j)
            std::cout << m.data[i * m.get_cols() + j] << " ";
        std::cout << std::endl;
    }
}

// Sobrecargas (8)
// Sobercarga Suma
Matrix Matrix::operator+(const Matrix &other) const {
    if (n_rows != other.n_rows || n_cols != other.n_cols) {
        std::cerr << "Error: dimensiones incompatibles para suma de matrices" << std::endl;
        exit(EXIT_FAILURE);
    }

    Matrix result(n_rows, n_cols); // matriz resultado

    for (int i = 0; i < n_rows * n_cols; ++i) {
        result.data[i] = data[i] + other.data[i];
    }

    return result;
}

//Sobrecarga Resta
Matrix Matrix::operator-(const Matrix &other) const {
    if (n_rows != other.n_rows || n_cols != other.n_cols) {
        std::cerr << "Error: dimensiones incompatibles para resta de matrices" << std::endl;
        exit(EXIT_FAILURE);
    }

    Matrix result(n_rows, n_cols);

    for (int i = 0; i < n_rows * n_cols; ++i) {
        result.data[i] = data[i] - other.data[i];
    }

    return result;
}

// Sobrecarga Multiplicacion
Matrix Matrix::operator*(const Matrix &other) const {
    if (n_cols != other.n_rows) {
        std::cerr << "Error: dimensiones incompatibles para multiplicación de matrices" << std::endl;
        exit(EXIT_FAILURE);
    }

    Matrix result(n_rows, other.n_cols);

    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < other.n_cols; ++j) {
            double sum = 0.0;
            for (int k = 0; k < n_cols; ++k) {
                sum += data[i * n_cols + k] * other.data[k * other.n_cols + j];
            }
            result.data[i * other.n_cols + j] = sum;
        }
    }

    return result;
}


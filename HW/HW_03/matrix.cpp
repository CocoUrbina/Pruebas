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
  n_cols = ojb.n_cols;
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

// Gets (6)
int Matrix::get_rows(){
  return n_rows;
}

int Matrix::get_cols(){
  return n_cols;
}

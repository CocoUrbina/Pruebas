#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix {
  private:
    int n_rows;
    int n_cols;
    Matrix(); // Default Constructor (1)

  public:
    double *data;
    int get_rows(); // (6)
    int get_cols(); // (6)
    Matrix(int n, int m); // Custom Constructor (2)
    ~Matrix(); // Destructor (3)
    Matrix(const Matrix &obj); // Copy Constructor Deep (4)
    Matrix &operator=(const Matrix &obj); // Assignment Operator (5)
};

#endif

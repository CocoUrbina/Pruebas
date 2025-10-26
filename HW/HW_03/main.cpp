#include <iostream>
#include "matrix.hpp"

int main() {
    try {
        // Matrices
        Matrix A(2, 3);
        Matrix B(2, 3);

        //  A
        for (int i = 0; i < A.get_rows() * A.get_cols(); ++i)
            A.data[i] = i + 1;  // 1,2,3,4,5,6

        // B
        for (int i = 0; i < B.get_rows() * B.get_cols(); ++i)
            B.data[i] = 10 * (i + 1); // 10,20,30,40,50,60

        std::cout << "Matriz A:" << std::endl;
        print_matrix(A);
        std::cout << "Matriz B:" << std::endl;
        print_matrix(B);

        // Suma
        Matrix C = A + B;
        std::cout << "A + B:" << std::endl;
        print_matrix(C);

        // Resta
        Matrix D = B - A;
        std::cout << "B - A:" << std::endl;
        print_matrix(D);

        // Multiplicación
        Matrix E(3, 2); 
        for (int i = 0; i < E.get_rows() * E.get_cols(); ++i)
            E.data[i] = i + 1; // 1,2,...,6

        std::cout << "Matriz E:" << std::endl;
        print_matrix(E);

        Matrix F = A * E; 
        std::cout << "A * E:" << std::endl;
        print_matrix(F);

        // Operador de asignación
        Matrix G = F;  // Copy constructor
        Matrix H(2,2);
        H = F;         // Assignment operator
        std::cout << "H (después de H = F):" << std::endl;
        print_matrix(H);

        // Excepciones
        try {
            Matrix bad = A + E;
        } catch (const std::invalid_argument &e) {
            std::cerr << "Excepción atrapada: " << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << "Error inesperado: " << e.what() << std::endl;
    }

    return 0;
}


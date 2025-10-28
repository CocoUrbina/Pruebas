#include <iostream>
#include "complex.hpp"

int main() {
    std::cout << "=== Pruebas de la clase Complex ===" << std::endl;

    // (3) Constructor por defecto
    Complex c0;
    std::cout << "c0 (por defecto) = " << c0.get_real() << " + i(" << c0.get_imag() << ")" << std::endl;

    // (4) Constructor personalizado
    Complex c1(3.0, 4.0);
    Complex c2(1.0, -2.0);
    std::cout << "c1 (personalizado) = " << c1.get_real() << " + i(" << c1.get_imag() << ")" << std::endl;
    std::cout << "c2 (personalizado) = " << c2.get_real() << " + i(" << c2.get_imag() << ")" << std::endl;

    // (5) Constructor copia
    Complex c3(c1);
    std::cout << "c3 (copia de c1) = " << c3.get_real() << " + i(" << c3.get_imag() << ")" << std::endl;

    // (6) Operador de asignación
    Complex c4;
    c4 = c2;  // Debe imprimir mensaje del operador de asignación
    std::cout << "c4 (asignado de c2) = " << c4.get_real() << " + i(" << c4.get_imag() << ")" << std::endl;

    // (8) Norma
    std::cout << "Norma de c1 = " << c1.norm() << std::endl;

    // (9) Conjugado
    Complex c5 = c1.conjugate();
    std::cout << "Conjugado de c1 = " << c5.get_real() << " + i(" << c5.get_imag() << ")" << std::endl;

    // (10) Sobrecarga de operadores
    Complex suma = c1 + c2;
    Complex resta = c1 - c2;
    Complex mult = c1 * c2;
    Complex div = c1 / c2;

    std::cout << "\n--- Operaciones ---" << std::endl;
    std::cout << "c1 + c2 = " << suma.get_real() << " + i(" << suma.get_imag() << ")" << std::endl;
    std::cout << "c1 - c2 = " << resta.get_real() << " + i(" << resta.get_imag() << ")" << std::endl;
    std::cout << "c1 * c2 = " << mult.get_real() << " + i(" << mult.get_imag() << ")" << std::endl;
    std::cout << "c1 / c2 = " << div.get_real() << " + i(" << div.get_imag() << ")" << std::endl;

    std::cout << "\n=== Fin de las pruebas ===" << std::endl;
    return 0;
}


#include <iostream>
#include <cmath>

// Función que contiene el integrando
double integrando(double x) {
    return 4.0 / (1.0 + x * x);
}

// Función que calcula la suma de Riemann
double riemann(double (*func)(double), int numeroParticiones, double lim_inf, double lim_sup) {
    double paso = (lim_sup - lim_inf) / numeroParticiones; // base de los rectángulos
    double areaTotal = 0.0;

    for (int i = 0; i < numeroParticiones; ++i) {
        double x = i * paso + paso / 2.0; // punto medio del subintervalo
        areaTotal += func(x);
    }

    return areaTotal * paso; // suma de áreas
}

int main() {
    std::cout << riemann(integrando, 1000, 0.0, 1.0) << std::endl;
    return 0;
}

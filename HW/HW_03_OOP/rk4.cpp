#include <iostream>
#include <cmath>

// Step RK4
double step_rk4(double (*func)(double, double), double x, double y, double h){
  double k_1 = func(x, y);
  double k_2 = func(x + h/2.0, y + h*k_1/2.0);
  double k_3 = func(x + h/2.0, y + h*k_2/2.0);
  double k_4 = func(x + h, y + h*k_3);

  return y + (h/6.0)*(k_1 + 2*k_2 + 2*k_3 + k_4);
}

// EDO
double fInt(double x, double y){
    return 2*(1 - y) - std::exp(-4*x);
}

// MAIN
int main() {
    double x_0 = 0.0; // lower limit
    double x_1 = 2.0; // upper limit
    double y_0 = 1.0; // Initial condition
    int N = 100;
    double hval = (x_1 - x_0) / N;
    std::cout.precision(8);
    for(int i = 0; i < N; ++i){

      std::cout << x_0 << " " << y_0 << std::endl;

      double yN = step_rk4(fInt, x_0, y_0, hval);
      x_0 = x_0 + hval;
      y_0 = yN;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <omp.h>

// Note que la rutina acepta referencia a vectores con componentes complejos
void dft(std::vector< std::complex<double> > &input, std::vector< std::complex<double> > &output){
  
  // Tamaño del vector de entrada
  int N = input.size();
  
  double pi = std::acos(-1.0);
  // Note que std::complex acepta números complejos usando la notación {real, imaginario}
  // donde la primera entrada es la parte real y la segunda entrada es la parte imaginaria
  // Rutina principal
  for(int k = 0; k < N; ++k){
    std::complex<double> sum = {0.0, 0.0};
    for(int n = 0; n < N; ++n){
      double girus = -2.0 * pi * k * n / N;
      sum += input[n] * std::exp(std::complex<double>(0, girus)) * (1.0 / N);
    }
    output[k] = sum;
  }
}

int main() {
  int N = 8192;
  double pi = std::acos(-1.0);

  std::vector< std::complex<double> > in(N, 0.0);
  std::vector< std::complex<double> > out(N, 0.0);

  // Función de la cual queremos la transformada de Fourier, discretizada en los
  // puntos de colocación
  // Ejemplo: la función sin(2.0 * x) vista en clase
  std::vector<double> x_vals(N, 0.0);
  for(int n = 0; n < N; ++n){
    x_vals[n] = 12.0 * pi * n / N;
    in[n] = std::sin(2.0 * x_vals[n]);
  }

  // La función omp_get_wtime() funciona de la misma forma que la función seconds() 
  // vista en clase.
  double start = omp_get_wtime();
  dft(in, out);
  double end = omp_get_wtime();
  
  // Puede visualizar la transformada mediante los elementos del vector "out"

  std::cout << "Tiempo de la DFT: " << (end - start) << " seconds." << std::endl;
  
  return 0;
}

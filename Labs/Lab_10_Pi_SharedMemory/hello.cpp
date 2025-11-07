#include <iostream>
#include <omp.h> // Biblioteca que contiene OpenMP!

int main(){

  omp_set_num_threads(4); // Incluimos el número de hilos mediante
                          // la directiva del API
  // El #pragma es la directiva de compilador que inicia la región en paralelo
  #pragma omp parallel
  {
    int my_proc = omp_get_thread_num(); // Ahora my_proc es una variable que identifica
                                        // al hilo
    std::cout << "Hello! From thread #: " << my_proc << std::endl;
  }

  return 0;
}

// =========== #include <omp.h> ==============
// Biblioteca con OpenMP
//
// ========= omp_set_num_threads(4); =========
// Con esto se, puede decir con cuantos hilos trabajar
//
// ====== #pragma omp parallel ==============
// Inicia la región en paralelo
//
// ========= omp_get_thread_num() ===========
//retorna el id del hilo
//
//Para ejecutar
// g++ hello.cpp -o hello.x -fopenmp

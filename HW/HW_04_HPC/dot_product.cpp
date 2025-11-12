// Compile: mpicxx dot_product.cpp -o dot_product.x
// Execute: mpirun -np 4 ./dot_product.x

#include <iostream>
#include <vector>
#include <mpi.h>

int main(){

  int N = 20;
  int size; 
  int rank;
  // int N = 20;
  // tama~o de los vectores a multiplicar
  // int size;
  // número de procesos en (MPI_COMM_WORLD).
  // int rank;
  // ID del proceso (0, 1, 2, …, size - 1).

  // 1-Inicialice el ambiente de MPI como vimos en clase (0.25%)
  MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   // MPI_Init(NULL, NULL);
   // Inicializa la region para MPI.

   //  MPI_Comm_size(MPI_COMM_WORLD, &size);
   //  Determina cuántos procesos están participando en el comunicador MPI_COMM_WORLD.
   // Ej: mpirun -np 4 ./dot_product.x
   // Entonces size = 4

   // MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   // Cada proceso obtiene su  ID (rank)  dentro del comunicador.
   //El proceso 0 tiene rank = 0
   //El proceso 1 tiene rank = 1
   //etc.


  // 2-Declare 4 vectores usando std::vector como arreglos de datos: a, b, local_a y local_b (0.25%)
  std::vector<double> a;
  std::vector<double> b;
  std::vector<double> local_a;
  std::vector<double> local_b;

  // 3-En el proceso 0, utilice el método resize() para asignar suficiente memoria para N elementos para los vectores a y b (0.25%)
  if (rank == 0) { // proceso 0
    a.resize(N);
    b.resize(N);
  }

  // 4-Para todos los procesos, utilice el método resize() para asignar suficiente memoria para nlocal elementos para los vectores local_a y local_b. Defina nlocal como lo hicimos en clase. Puede asumir que el número de elementos N es un múltiplo del número de procesos size (i.e., no hay rest) (0.5%)
  int nlocal = N / size; // Para nuestro caso: 20 / 4 = 5.
  local_a.resize(nlocal); 
  local_b.resize(nlocal);

  // 5-En el proceso 0, asigne distintos valores a las entradas de los vectores a y b. Asigne estos valores de manera tal que a = b = [1, 2, 3, · · · N ] (0.25%)
  if(rank == 0){ // proceso 0
    for(int i = 1; i <= N; i++){
      a[i-1] = i;
      b[i-1] = i;
    }
  }

  // 6-Investigue y utilice la función MPI_Scatter para distribuir las secciones de los vectores a y b a sus respectivos procesos (0.5%) 
  MPI_Scatter(
      a.data(),
      nlocal,
      MPI_DOUBLE,
      local_a.data(),
      nlocal,
      MPI_DOUBLE,
      0,
      MPI_COMM_WORLD);

  MPI_Scatter(
      b.data(),
      nlocal,
      MPI_DOUBLE,
      local_b.data(),
      nlocal,
      MPI_DOUBLE,
      0,
      MPI_COMM_WORLD);

  // 7-Calcule el producto interno de cada sección de tamaño nlocal en cada proceso (0.25%)
  double local_result = 0.0;
  for(int i = 0; i < nlocal; i++){
    local_result += local_a[i] * local_b[i];
  }

  // 8-Utilice MPI_Reduce para calcular el producto interno total con base en los productos internos de cada proceso (0.5%)
  double total_result = 0.0;
  MPI_Reduce(
      &local_result,
      &total_result,
      1,
      MPI_DOUBLE,
      MPI_SUM,
      0,
      MPI_COMM_WORLD);

  // 9-Imprima el resultado usando el proceso 0 (0.25%)
  if(rank == 0){ // proceso 0
    std::cout << "a * b = " << total_result << std::endl;
  }


  MPI_Finalize(); // cierra la region MPI.

  return 0;
}

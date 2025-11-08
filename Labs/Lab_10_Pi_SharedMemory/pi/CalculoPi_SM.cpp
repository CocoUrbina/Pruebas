#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <omp.h>

   // Esta función se utiliza para calcular el tiempo que tarda
   // la ejecución de ciertas funciones
   // Está basada en el uso de una función primitiva que evalúa al tiempo
   // transcurrido desde cierto valor de referencia
double seconds() {
  struct timeval tmp;
  double sec;
  gettimeofday( &tmp, (struct timezone *)0 );
  sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;

  return sec;
}

// Funcion que calcula la suma de Riemann
double riemann(double (*func)(double), double  lower_limit, double  upper_limit, int partitions){
  double tA = 0.0;
  double mesh = (upper_limit - lower_limit) / partitions;
 
  // para saber cuantos hilos tenemos
  int num_procs;

  // tiempo antes de iniciar los calculo
  double time_1 = seconds();

  //veamos cuanto es el  maximo de hilos disponibles
  std::cout << "Default Threads: " << omp_get_max_threads() << std::endl;

  // inicializa la region paralela
  #pragma omp parallel
  {
    #pragma omp master // para que solo lo ejecute un hilo
    num_procs = omp_get_num_threads(); // number of threads

    #pragma omp for reduction(+: tA) // to avoid race conditions
    for (int  i = 1; i <= partitions; i++){
      tA += func(lower_limit +  mesh * i - mesh/2);
    }
  }

  // tiempo despues de finalizar los calculos
  double time_2 = seconds(); 
  double elapsed = time_2 - time_1;

  std::cout << "Used Threads: " << num_procs << std::endl;
  std::cout << "Time: " << elapsed << std::endl;

  // Exportar los resultados al archivo scaling.dat
  std::ofstream outfile("scaling.dat", std::ios::app);
  if (!outfile) {
    std::cerr << "Error al abrir el archivo de salida.\n";
  } else {
    outfile << num_procs << " " << elapsed << "\n";
    outfile.close();
  }

  return tA * mesh;
}

// Funcion integrando
double integrand(double x){
  return 4.0 / (1 + x*x);
}

// main
int  main (){
  double result = riemann(integrand, 0.0, 1.0, 1000000000);
  std::cout << "Aproximacion = " << result << std::endl; 
  return 0;
}


// ===============COMO CREAR EL MAIN===================
// El main siempre retorna un int
// El main va con ()
// En el main se ejecutan las otras funciones
// el main se cierra con un return 0
//int main(){
//contenido
//return 0;
//}
//
// ================COMO CREAR FUNCIONES===================
// Se especifica el tipo de dato que retornan (int, double, float, etc)
// Se especifican el tipo del parametro que reciben
// float integrand(float x){
// return expresion
// }
// el primer float: indica que la integrand retorna un float
// el segundo float: indica que el insumo de integrand es un float
//
// ======COMO UNA FUNCION RECIBE A OTRA COMO PARAMETRO=====
// float riemann(float (*func)(float)){
// contenido
// }
// el primer float: indica el tipo de retorno de riemann
// el segundo float: indica el tipo de retorno de func
// el tercer float: indica el tipo de insumo de func
//
// ===============COMO CREAR VARIABLES=======================
// Se indica el tipo.
// int a = 0:
//
// =================COMO CREAR UN FOR========================
// se inicializa el contador
// se separan con ;
// for (int  i = 1; i <= partitions; i++){
//
// =======================OTRAS NOTAS========================
// Cada instruccion se cierra con ;
// return 4.0 / (1 + x*x);

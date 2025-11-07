#include <iostream>
#include <sys/time.h>

#include <omp.h>

double seconds()
{
  struct timeval tmp;
  double sec;
  gettimeofday( &tmp, (struct timezone *)0 );
  sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;

  return sec;
}

double fInt(double x) {
  return 4.0 / (1.0 + x*x);
}

double sumRiemann( double limInf, double limSup, int numRect, double (*func)(double)) {
 
  

  double ancho = (limSup - limInf) / numRect;
  double area_total = 0.0;
  
  int num_procs;
  double time_1 = seconds();
  #pragma omp parallel
  {
    num_procs = omp_get_num_threads();
    #pragma omp for reduction (+: area_total)
    for(int i = 0; i < numRect; ++i){
    
       double puntoMedio = limInf + (ancho / 2.0) + (ancho * i);
       double altura = func(puntoMedio);
       area_total += altura * ancho;

    }
  }

  double time_2 = seconds();
  
  std::cout << "Number of Threads: " << num_procs << std::endl;
  std::cout << "Time to complete loop: " << time_2 - time_1 << std::endl;

  return area_total;
}

int main(){

  std::cout << sumRiemann(0, 1, 100000000, fInt) << std::endl;

}

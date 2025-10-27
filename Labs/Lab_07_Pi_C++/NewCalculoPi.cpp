#include <iostream>


float riemann(float (*func)(float), float  lower_limit, float  upper_limit, int partitions){
  float tA = 0.0;
  float mesh = (upper_limit - lower_limit) / partitions;
  for (int  i = 1; i <= partitions; i++){
    tA += func(lower_limit +  mesh * i - mesh/2);
  }

  return tA * mesh;
}


float integrand(float x){
  return 4.0 / (1 + x*x);
}

int  main (){
  float result = riemann(integrand, 0.0, 1.0, 1000);
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

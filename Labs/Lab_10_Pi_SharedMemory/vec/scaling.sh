#!/bin/bash

#============= Obtener numero de hilos maximo ==========
echo "Compilando maxThreads.cpp..."
g++ maxThreads.cpp -o maxThreads.x -fopenmp

if [ $? -ne 0 ]; then
  # $? : Codigo de salida del ultimo comando ejecutado
  # -ne 0 : not equal 0
  # Si un codigo de salida es cero, fue exitoso. Si no es cero, fue error
  # Entonces esa condicion verifica si fallo o fue exitoso
    echo "Error al compilar maxThreads.cpp"
    exit 1 # termina el script con codigo de salida 1 (error porque no es cero)
fi

echo "Ejecutando maxThreads.x..."
MAX_THREADS=$(./maxThreads.x | awk '{print $3}')
# $(...) ejecuta lo que esta dentro de los () y guarda la salida como texto
# el pipe | redirige la salida al siguiente comando
# awk procesa texto por columnas
# {print $3}, la tercera columna, ya que la salida de maxThreads.x es : "Maximo posible: <num>"
# col1:"Maximo"
# col2:" posible:"
# col3: <num>
echo "Máximo número de hilos (OpenMP): $MAX_THREADS"

#================= Compilar el cpp ======================
echo "Compilando vector.cpp..."
g++ vector.cpp -o vector.x -fopenmp

if [ $? -ne 0 ]; then
    echo "Error al compilar vector.cpp"
    exit 1
fi
echo "Compilación exitosa: vector.x generado"

#============= Blanquear el archivo ====================
if [ -f speedupVector.dat ]; then
  # -f : file
  # -d : directorio
  # -e : cualquier tipo
  # -r : readable
  # -w : writable
  # -x : executable
    echo "Eliminando archivo previo speedupVector.dat..."
    rm speedupVector.dat
fi

#============ Ejecutar el ejecutable! ================
echo "Ejecutando pruebas de escalabilidad..."
for (( t=1; t<=${MAX_THREADS}; t++ )); do
    echo "Ejecutando con $t hilos..."
    OMP_NUM_THREADS=$t ./vector.x
done

#================== Graficar ==========================
if [ -f fig.plt ]; then
    echo "Generando figura con gnuplot..."
    gnuplot fig.plt
    echo "Figura generada correctamente."
else
    echo "No se encontró el archivo fig.plt. Saltando paso de graficado."
fi

echo "Rutina de escalabilidad completada."

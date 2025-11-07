#!/bin/bash

#============= Obtener numero de hilos maximo ==========
echo "Compilando maxThreads.cpp..."
g++ maxThreads.cpp -o maxThreads.x -fopenmp

if [ $? -ne 0 ]; then
    echo "Error al compilar maxThreads.cpp"
    exit 1
fi

echo "Ejecutando maxThreads.x..."
MAX_THREADS=$(./maxThreads.x | awk '{print $3}')
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
    echo "Eliminando archivo previo scaling.dat..."
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

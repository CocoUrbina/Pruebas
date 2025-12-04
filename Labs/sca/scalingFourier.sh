#!/bin/bash

echo "Compilando maxThreads.cpp..."
g++ maxThreads.cpp -o maxThreads.x -fopenmp || { echo "Error"; exit 1; }

MAX_THREADS=$(./maxThreads.x | awk '{print $3}')
echo "Máximo número de hilos: $MAX_THREADS"

echo "Compilando fourier.cpp..."
g++ fourier.cpp -o fourier.x -fopenmp || { echo "Error"; exit 1; }

[ -f scaling.dat ] && rm scaling.dat

echo "Ejecutando pruebas..."
for (( t=1; t<=${MAX_THREADS}; t++ )); do
    echo "Con $t hilos..."

    # Ejecutar el programa y extraer SOLO la línea del tiempo
    TIEMPO=$(OMP_NUM_THREADS=$t ./fourier.x --li 0 --ls 1 --d 3 --n 10000000 \
             | grep "Tiempo:" | awk '{print $2}')

    # Guardar en el formato esperado: "P T"
    echo "$t $TIEMPO" >> scaling.dat
done

# Tiempo con 1 hilo (primera línea)
T1=$(head -n 1 scaling.dat | awk '{print $2}')

# Calcular speedup
awk -v T1="$T1" '{printf "%d %.6f\n", $1, T1/$2}' scaling.dat > speedupFourier.dat

if [ -f fig.plt ]; then
    echo "Generando figura..."
    gnuplot fig.plt
fi

echo "Finalizado."

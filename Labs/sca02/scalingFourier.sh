#!/bin/bash

echo "Compilando MPI..."
mpic++ fourier_mpi.cpp -o fourier_mpi.x || { echo "Error al compilar"; exit 1; }

# Número máximo de procesos a probar
MAX_PROCS=8

[ -f scaling_mpi.dat ] && rm scaling_mpi.dat

echo "Ejecutando pruebas MPI..."
for (( p=1; p<=${MAX_PROCS}; p++ )); do
    echo "Con $p procesos..."

    # Ejecutar con mpirun y extraer la línea "Tiempo:"
    TIEMPO=$(mpirun -np $p ./fourier_mpi.x --li 0 --ls 1 --d 3 --n 10000000 \
              | grep "Tiempo:" | awk '{print $2}')

    # Guardar en formato "P T"
    echo "$p $TIEMPO" >> scaling_mpi.dat
done

# Tiempo con 1 proceso (primera línea)
T1=$(head -n 1 scaling_mpi.dat | awk '{print $2}')

# Calcular speedup S(P) = T(1)/T(P)
awk -v T1="$T1" '{printf "%d %.6f\n", $1, T1/$2}' scaling_mpi.dat > speedupMPI.dat

echo "Listo: speedupMPI.dat generado."

# Generar figura usando fig.plt pero redirigiendo archivo de velocidad
if [ -f fig.plt ]; then
    echo "Generando figura..."
    sed 's/speedupFourier.dat/speedupMPI.dat/' fig.plt | gnuplot
fi

echo "Finalizado."

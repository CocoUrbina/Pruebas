#!/bin/bash

#============= Obtener numero de hilos maximo ==========
echo "Compilando maxThreads.cpp..."
g++ maxThreads2.cpp -o maxThreads2.x -fopenmp

if [ $? -ne 0 ]; then
  # $? : Codigo de salida del ultimo comando ejecutado
  # -ne 0 : not equal 0
  # Si un codigo de salida es cero, fue exitoso. Si no es cero, fue error
  # Entonces esa condicion verifica si fallo o fue exitoso
    echo "Error al compilar maxThreads.cpp"
    exit 1 # termina el script con codigo de salida 1 (error porque no es cero)
fi

echo "Ejecutando maxThreads.x..."
MAX_THREADS=$(./maxThreads2.x | awk '{print $3}')
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
g++ vector2.cpp -o vector2.x -fopenmp

if [ $? -ne 0 ]; then
    echo "Error al compilar vector2.cpp"
    exit 1
fi
echo "Compilación exitosa: vector2.x generado"

#============= Remover el archivo ====================
if [ -f scaling.dat ]; then
  # -f : file
  # -d : directorio
  # -e : cualquier tipo
  # -r : readable
  # -w : writable
  # -x : executable
    echo "Eliminando archivo previo scaling.dat..."
    rm scaling.dat
fi

#============ Ejecutar el ejecutable! ================
echo "Ejecutando pruebas de escalabilidad..."
for (( t=1; t<=${MAX_THREADS}; t++ )); do
    echo "Ejecutando con $t hilos..."
    OMP_NUM_THREADS=$t ./vector2.x
done

#=================== Speedup =========================
T1=$(head -n 1 scaling.dat | awk '{print $2}')
awk -v T1="$T1" '{printf "%d %.6f\n", $1, T1/$2}' scaling.dat > speedupVector2.dat
# head -n 1 scaling.dat : toma la primera fila de scaling.dat
# | el pipe pasa ese outcome al siguiente comando
# awk '{print $2}' : awk explora por tablulaciones. En este caso, toma col2
# Con eso, ya tomamos el tiempo para thread = 1 y se guarda en T1
#
# Con -v pasamos la variable de shell T1 al programa awk como la variable awk T1. De ese modo awk puede usar el valor de T1 dentro de su programa

# '{printf "%d %.6f\n", $1, T1/$2}'
# por cada línea de scaling.dat, awk hace:
# $1 es la primera columna (número de hilos).
# $2 es la segunda columna (el tiempo T_p).
# T1/$2 calcula el speedup.
# printf "%d %.6f\n", $1, T1/$2 imprime dos columnas: primera como entero (%d) y segunda como float con 6 decimales (%.6f), y un salto de línea.

# scaling.dat > speedupVec.dat
# awk lee scaling.dat y la salida formateada se redirige a speedupVec.dat.

#================== Graficar ==========================
if [ -f fig2.plt ]; then
    echo "Generando figura con gnuplot..."
    gnuplot fig2.plt
    echo "Figura generada correctamente."
else
    echo "No se encontró el archivo fig2.plt. Saltando paso de graficado."
fi

echo "Rutina de escalabilidad completada."

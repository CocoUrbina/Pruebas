set terminal epslatex color size 6.0in,5.0in standalone font "" 14
# color: activa salida color (en vez de b/n)
# size 6.0in,5.0in : dimensiones
# standalone: doc independiente
# font "" 14: font vacia (predeterminada entonces), tama~o 14

set output 'Figure.tex'

set border linewidth 6 
# grosor del marco

set ylabel '\textbf{Speedup} $S$'
# etiqueta en y

set xlabel '\textbf{Número de hilos} $P$'
# etiqueta en x

set ytics scale 2
set xtics scale 2
# las marquitas en el eje. Cada 2 las hace mas grandes o visibles


f(x) = x
# hace una nueva funcion

plot 'speedupVector.dat' u 1:2 w p pt 7 ps 2.5 lc rgb "red" t 'Escalabilidad \texttt{vector.cpp}',\
     f(x) w l lw 3 lc rgb "red" t 'Escalabilidad Lineal'

# plot 'speedup.dat' : plotea la data de speedup.dat
# u 1:2 : using column 1 for x and column 2 for y
# w p : with points (no va trazar linea, solamente marcar puntos)
# pt 7 : point type 7 (de los diferentes tipos que hay)
# ps 2.5 : point size 2.5 (tama~o de las marcas)
# lc rgb "red" : line color
# t 'Escalabilidad \texttt{vector.cpp}' : titulo/leyenda para la serie
# ,\ : que continua en la siguiente linea
# f(x) : ahora va a plotear la funcion previamente definida
# w l : with line
# lw 3 : line width 3
# lc rgb "red" : line color
# t 'Escalabilidad Lineal' : titulo/leyenda

set output
system('latex Figure.tex')
system('dvips Figure.dvi')
system('ps2pdf Figure.ps')
system('rm Figure.tex Figure.log Figure.aux Figure-inc.eps Figure.dvi Figure.ps')

# rk4_plot.gp
set terminal pdfcairo size 10cm,7cm enhanced color lw 2
set output "rk4_comparacion.pdf"

set title "Solución RK4 con distintos pasos h"
set xlabel "x"
set ylabel "y(x)"
set grid
set key bottom right

plot "n020.dat"  using 1:2 with linespoints lw 0.6 pt 7 ps 0.2 lc rgb "#1f77b4" title "h = 0.1", \
     "n050.dat" using 1:2 with linespoints lw 0.6 pt 5 ps 0.2 lc rgb "#ff7f0e" title "h = 0.04", \
     "n100.dat" using 1:2 with linespoints lw 0.6 pt 9 ps 0.2 lc rgb "#2ca02c" title "h = 0.02"

set output


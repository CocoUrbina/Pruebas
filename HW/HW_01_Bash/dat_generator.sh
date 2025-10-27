#!/bin/bash

residuo=$((${2}%10))
parteEntera=$((${2}/10))

#echo $residuo
#echo $parteEntera
  
for ((j=1;j<=residuo;j++));do #agrega numeros de 1 en 1
  ./random.sh | head -n 4 | tail -n 1 >> rand_${1}_${2}.dat
done

for ((i=1; i<=parteEntera;i++));do #agrega numeros de 10 en 10
  ./random.sh | head -n 13 | tail -n 10  >> rand_${1}_${2}.dat
done            

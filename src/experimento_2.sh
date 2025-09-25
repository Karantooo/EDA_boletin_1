#!/bin/bash

# Cambiar directorio de trabajo al padre
cd ..

OUTPUT="resultados_experimentos/resultados_experimento_2.csv"

# Añadir encabezado al archivo
echo "posicion,tiempo_lineal,tiempo_binaria,tiempo_galopante" > $OUTPUT

# Número de repeticiones
REPS=32
N=1000000   # tamaño fijo del vector

# Bucle de repeticiones
for ((r=1; r<=REPS; r++)); do
    echo "Repetición $r de $REPS"
    # Percentiles de 0 a 95 en pasos de 5
    for i in $(seq 0 5 95); do
        pos=$(( (i * N) / 100 ))   # calcular posición absoluta
        ./experimento_2.out $pos >> $OUTPUT
    done
    # Agregar último caso explícito (posición 999999)
    ./experimento_2.out $((N - 1)) >> $OUTPUT
done

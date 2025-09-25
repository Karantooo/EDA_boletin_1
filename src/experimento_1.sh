#!/bin/bash

# Cambiar directorio de trabajo al padre
cd ..

OUTPUT="resultados_experimentos/resultados_experimento_1.csv"

# Añadir encabezado al archivo
echo "n,tiempo_lineal,tiempo_binaria,tiempo_galopante" > $OUTPUT

# Número de repeticiones
REPS=32

# Bucle de repeticiones
for ((r=1; r<=REPS; r++)); do
    echo "Repetición $r de $REPS"
    # Bucle de tamaños
    for ((n=1; n<=1000001; n+=10000)); do
        ./experimento_1.out $n >> $OUTPUT
    done
done

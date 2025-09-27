# Boletín 1 – Estructuras de Datos Avanzadas

Este proyecto corresponde al **Boletín 1** del curso *Estructuras de Datos Avanzadas*.  
El objetivo es **comparar algoritmos de búsqueda en arreglos ordenados**:

- **Búsqueda lineal**  
- **Búsqueda binaria**  
- **Búsqueda galopante (Exponential Search)**  

Se incluyen tanto el **informe en PDF** como el **código en C++** y los **datasets generados**.

---

## ⚙️ Requisitos

- **Compilador C++17 o superior** (probado con `g++` en Linux).  
---

## ▶️ Cómo ejecutar

1. **Compilar el proyecto**
   Desde la carpeta raíz, simplemente correr:

   ```bash
   make
   ```

   Esto generará dos ejecutables:

   * `experimento_1.out`
   * `experimento_2.out`

---

2. **Ejecutar experimentos manualmente**

   * **Experimento 1 (búsqueda en arreglo ordenado):**

     ```bash
     ./experimento_1.out <tamaño_del_arreglo>
     ```

     Ejemplo:

     ```bash
     ./experimento_1.out 100000
     ```

     > **Nota:** este ejecutable tiene una variante **aleatorizada** si se añade la bandera `-a` al final:
     >
     > ```bash
     > ./experimento_1.out 100000 -a
     > ```

   * **Experimento 2 (búsqueda en posición específica):**

     ```bash
     ./experimento_2.out <posición_del_elemento>
     ```

     Ejemplo:

     ```bash
     ./experimento_2.out 50000
     ```

---

3. **Recrear los experimentos completos**

   Una vez compilados los ejecutables, se pueden usar los scripts `.sh` incluidos en el proyecto para automatizar la ejecución de múltiples corridas y generar los archivos `.csv` en la carpeta `resultados_experimentos/`.

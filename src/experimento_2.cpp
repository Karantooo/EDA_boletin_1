#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

#include "metodos_de_busqueda.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " <posicion_target>" << std::endl;
        return 1;
    }

    // Leer posición del target desde argumentos
    size_t target_pos = std::stoul(argv[1]);

    // Tamaño fijo de 1 millón de elementos
    size_t n = 1'000'000;

    // Generador de números aleatorios uniformes
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, static_cast<int>(n * 10));

    // Crear vector con valores aleatorios
    std::vector<int> vec(n);
    for (size_t i = 0; i < n; i++) {
        vec[i] = dist(gen);
    }

    // Ordenar en orden creciente
    std::sort(vec.begin(), vec.end());

    // Asegurar que la posición sea válida
    if (target_pos >= n) {
        std::cerr << "Error: la posición debe estar entre 0 y " << (n - 1) << std::endl;
        return 1;
    }

    // Escoger el elemento en la posición indicada
    int target = vec[target_pos];

    // Búsqueda lineal
    auto start = std::chrono::high_resolution_clock::now();
    busqueda::linear_search(vec, target);
    auto end = std::chrono::high_resolution_clock::now();
    auto tiempo_lineal = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    // Búsqueda binaria
    start = std::chrono::high_resolution_clock::now();
    busqueda::binary_search(vec, target);
    end = std::chrono::high_resolution_clock::now();
    auto tiempo_binaria = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    // Búsqueda galopante (base 2)
    start = std::chrono::high_resolution_clock::now();
    busqueda::exponential_search(vec, target, 2);
    end = std::chrono::high_resolution_clock::now();
    auto tiempo_galopante = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    // Imprimir resultados en formato CSV
    std::cout << target_pos << ","
              << tiempo_lineal << ","
              << tiempo_binaria << ","
              << tiempo_galopante << std::endl;

    return 0;
}

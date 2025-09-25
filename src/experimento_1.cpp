#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>

#include "metodos_de_busqueda.h"


// Experimento para verificar como afecta a la busqueda el tamaño del vector
// Tiene modo aleatorizado para el target sino este va a ser siempre el ultimo (para forzar peor caso en busqueda lineal)


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " <tamano_vector> [-a]" << std::endl;
        return 1;
    }

    // Leer tamaño del vector desde argumentos
    size_t n = std::stoul(argv[1]);

    // Revisar si se pasa el flag -a
    bool aleatorio = false;
    if (argc >= 3 && std::string(argv[2]) == "-a") {
        aleatorio = true;
    }

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

    // Escoger un elemento a buscar
    int target;
    if (aleatorio) {
        std::uniform_int_distribution<size_t> dist_index(0, n - 1);
        target = vec[dist_index(gen)];
    } else {
        target = vec.back(); // peor caso para lineal
    }

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
    std::cout << n << ","
              << tiempo_lineal << ","
              << tiempo_binaria << ","
              << tiempo_galopante << std::endl;

    return 0;
}

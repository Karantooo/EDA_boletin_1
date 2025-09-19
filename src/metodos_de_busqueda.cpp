#include <cmath>
#include <vector>
#include "metodos_de_busqueda.h"
using namespace busqueda;

int linear_search(const std::vector<int>& vec, int elem){
    for (size_t i = 0; i < vec.size(); i++){
        if (vec[i] == elem)
            return i;
    }
    return -1;
}

int binary_search(const std::vector<int>& vec, int elem){
    int start = 0, end = vec.size() - 1;
    int middle;
    while (start <= end){
        middle = start + (end - start) / 2;
        if (vec[middle] == elem)
            return middle;
        
        else if (vec[middle] < elem)
            start = middle + 1;
        
        else
            end = middle - 1;
        
    }

    return -1;
}
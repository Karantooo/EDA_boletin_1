#include <cmath>
#include <vector>
#include "metodos_de_busqueda.h"

int binary_search_index(const std::vector<int>& vec, int elem,
                        unsigned long start, unsigned long end){
    if (start > end) return -1;
    unsigned long middle;
    while (start <= end){
        middle = start + (end - start) / 2;
        if (vec[middle] == elem) return static_cast<int>(middle);
        else if (vec[middle] < elem) {
            start = middle + 1;
        } else {
            if (middle == 0) break;      
            end = middle - 1;
        }
    }
    return -1;
}
namespace busqueda {

    int linear_search(const std::vector<int>& vec, int elem){
        for (size_t i = 0; i < vec.size(); i++){
            if (vec[i] == elem)
                return i;
        }
        return -1;
    }
    
    
    int binary_search(const std::vector<int>& vec, int elem){
        if (vec.empty())
            return -1;
        return binary_search_index(vec, elem, 0, vec.size() - 1);
    }
    
    int exponential_search (const std::vector<int>& vec, int elem, int base){
        if (!vec.size())
            return -1;
        if (vec[0] == elem)
            return 0;
        if (base < 2)
            base = 2;

        unsigned long index = 1, previous_index = 0;
        while (index < vec.size()){
            if (vec[index] == elem)
                return index;
            if (vec[index] > elem)
                return binary_search_index(vec, elem, previous_index, index);
            
            previous_index = index;
            index *= base;
        } 
        return binary_search_index(vec, elem, previous_index, vec.size() - 1);
    }
}
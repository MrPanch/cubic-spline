//
// Created by panch on 14.05.2020.
//
#include <vector>
#include "Sole.hpp"

template<size_t width, size_t height>

void get_a(Sole<width, height>& sole, std::vector<double>& a){
    for (int i = 0; i < sole.GetHeight(); i++ ){
        a[i] = sole.GetMatrix()[i+1][i]
    }
}

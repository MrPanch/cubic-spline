#pragma once
#include <vector>
#include <iostream>
#include <mpi.h>

template <size_t width, size_t height>
class Sole {
    public:
        Sole();

        size_t GetWidth() const {return width; } //возвращает количество столбцов
        size_t GetHeight() const {return height; } // возвращает количество строк

        std::vector<std::vector<double>>& GetMatrix() { return matrix_;  };
        std::vector<double>& GetFreeVariables() {return free_variables_; };

        double& GetA(int i)  { return matrix_[i+1][i]; };
        double& GetB(int i)  { return matrix_[i][i];   };
        double& GetC(int i)  { return matrix_[i][i+1]; };


        template <size_t m, size_t n>
        friend std::istream &operator>>(std::istream& stream, Sole<m, n>& sole);

        std::vector<double> SeqThomas();
    private:
        std::vector<std::vector<double>> matrix_;
        std::vector<double> free_variables_; // Столбец свободных коэффициентов
};

template <size_t width, size_t height>
std::istream& operator>>(std::istream& stream, Sole<width, height>& system);
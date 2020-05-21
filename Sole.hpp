#pragma once
#include <vector>
#include <iostream>
#include <thread>


class Sole {
    public:
        Sole();
        Sole(size_t size);
        size_t GetWidth() const {return size; } //возвращает количество столбцов
        size_t GetHeight() const {return size; } // возвращает количество строк

        std::vector<std::vector<double>>& GetMatrix() { return matrix_;  };
        std::vector<double>& GetFreeVariables() {return free_variables_; };

//        double& GetA(int i)  { return matrix_[i+1][i]; };
//        double& GetB(int i)  { return matrix_[i][i];   };
//        double& GetC(int i)  { return matrix_[i][i+1]; };
        double& GetA(int i)  { return matrix_[i][i]; };
        double& GetB(int i)  { return matrix_[i+1][i];   };
        double& GetC(int i)  { return matrix_[i][i+1]; };

        friend std::istream &operator>>(std::istream& stream, Sole& sole);
        std::vector<double> SeqThomas();
        std::vector<double> ParThomas();

    private:
        std::vector<std::vector<double>> matrix_;
        std::vector<double> free_variables_; // Столбец свободных коэффициентов
        size_t  size;
};


std::istream& operator>>(std::istream& stream, Sole& system);

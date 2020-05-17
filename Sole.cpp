#include "Sole.hpp"


Sole::Sole(size_t size):
    size(size),
    matrix_(size, std::vector<double>(size, 0)),
    free_variables_(size)
    {}

std::istream& operator>>(std::istream& stream, Sole& system) {
    std::cout << "Enter coefficient matrix" << std::endl; // читаем слау
    for (size_t i = 0; i < system.GetHeight(); ++i) {
        for(size_t j = 0; j < system.GetWidth(); ++j) {
          stream >> system.GetMatrix()[i][j];
        }
    }

    std::cout << "Enter right part of the Sole" << std::endl;
    for (int i = 0; i < system.GetHeight(); ++i) {
        stream >> system.GetFreeVariables()[i];
    }

  return stream;
}



std::vector<double> Sole::SeqThomas(){
    std::vector<double> gamma(GetHeight(), 0);
    std::vector<double> alpha(GetHeight() - 1, 0);
    std::vector<double> beta(GetHeight(), 0);
    std::vector<double> x(GetHeight(), 0);

    gamma[0] =   matrix_[0][0];           //нулевые коэффициенты
    alpha[0] = - matrix_[0][1] / gamma[0];
    beta[0]  =   free_variables_[0] / gamma[0];

    for(int i = 1; i < GetHeight(); ++i) {  // от 1 до N
        if ( i == GetHeight() - 1){ // конкретно для N-го случая
            gamma[i] = GetB(i) + GetA(i -1) * alpha[i - 1];
            beta[i] = (free_variables_[i] - GetA(i-1) * beta[i - 1]) / gamma[i];
            break;
        }
        gamma[i] = GetB(i) + GetA(i -1) * alpha[i - 1];
        alpha[i] = -GetC(i) / gamma[i];
        beta[i] = (free_variables_[i] - GetA(i-1) * beta[i - 1]) / gamma[i];
    }

    x[GetWidth() - 1] = beta[GetWidth() - 1];
    for(size_t i = GetWidth() - 2; i > 0; --i) { //size_t не может становится равной нулю
        x[i] = alpha[i] * x[i + 1] + beta[i];
    }
    x[0] = alpha[0] * x[1] + beta[0]; // считаем отдельно для нулевого икса

    std::cout << "The solution of the Sole is:" << std::endl;
    for(int i = 0; i < GetWidth(); i++) {
        std::cout << x[i] << "   ";
    }

    return x;
}


std::vector<double> Sole::ParThomas(){


}
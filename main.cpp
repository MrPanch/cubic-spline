#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include "Sole.cpp"
// Потому что разрешение темплейтов, подробней https://www.codeproject.com/Articles/48575/How-to-Define-a-Template-Class-in-a-h-File-and-Imp


int main() {
    Sole<5, 5> system;
    std::cin >> system;
    std::vector<double> gamma(system.GetHeight(), 0);
    std::vector<double> alpha(system.GetHeight() - 1, 0);
    std::vector<double> beta(system.GetHeight(), 0);
    std::vector<double> x(system.GetHeight(), 0);

    gamma[0] =   system.GetMatrix()[0][0];           //нулевые коэффициенты
    alpha[0] = - system.GetMatrix()[0][1] / gamma[0];
    beta[0]  =   system.GetFreeVariables()[0] / gamma[0];

    for(int i = 1; i < system.GetHeight(); ++i) {  // от 1 до N
        if ( i == system.GetHeight() - 1){ // конкретно для N-го случая
            gamma[i] = system.GetB(i) + system.GetA(i -1) * alpha[i - 1];
            beta[i] = (system.GetFreeVariables()[i] - system.GetA(i-1) * beta[i - 1]) / gamma[i];
            break;
        }
        gamma[i] = system.GetB(i) + system.GetA(i -1) * alpha[i - 1];
        alpha[i] = -system.GetC(i) / gamma[i];
        beta[i] = (system.GetFreeVariables()[i] - system.GetA(i-1) * beta[i - 1]) / gamma[i];

    }

    x[system.GetWidth() - 1] = beta[system.GetWidth() - 1];
    for(size_t i = system.GetWidth() - 2; i > 0; --i) { //size_t не может становится равной нулю
        x[i] = alpha[i] * x[i + 1] + beta[i];
    }
    x[0] = alpha[0] * x[1] + beta[0]; // считаем отдельно для нулевого икса

    std::cout << "The solution of the Sole is:" << std::endl;
    for(int i = 0; i < system.GetWidth(); i++) {
        std::cout << x[i] << "   ";
    }

}
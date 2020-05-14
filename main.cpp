#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include "Sole.cpp" // Потому что разрешение темплейтов, подробней https://www.codeproject.com/Articles/48575/How-to-Define-a-Template-Class-in-a-h-File-and-Imp


int main() {
  Sole<3, 3> system;
  std::cin >> system;
  std::cout << "I've read matrix!!" << std::endl;

  std::vector<double> y(system.GetHeight(), 0);
  std::vector<double> alpha(system.GetHeight(), 0);
  std::vector<double> beta(system.GetHeight(), 0);
  std::vector<double> x(system.GetHeight(), 0);

  y[0] =   system.GetMatrix()[0][0];           //нулевые коэффициенты
  alpha[0] = - system.GetMatrix()[1][0] / y[0];
  beta[0]  =   alpha[0] / y[0];

  std::cout << "I'm going to enter the 1_st cycle!!" << std::endl;

  for(int i = 1; i < system.GetHeight(); ++i) {  // от 1 до N-1
    for (int j = 1; j < system.GetWidth(); ++j) {
      y[i] = system.GetMatrix()[i - 1][j - 1] + system.GetMatrix()[i - 1][j] * alpha[i - 1];
      alpha[i] = -system.GetMatrix()[i][j - 1] / y[i];
      beta[i] = (system.GetFreeVariables()[i] - system.GetMatrix()[i - 1][j] * beta[i - 1]) / y[i];
      std::cout << "I'm in 1_st cycle!!" << std::endl;

      if(i == system.GetWidth() - 1) { // для N коэффициента считаем отдельно
        y[i]     =   system.GetMatrix()[i - 1][j - 1] + system.GetMatrix()[i - 1][j] * alpha[i - 1];
        beta[i]  =   (system.GetFreeVariables()[i] - system.GetMatrix()[i - 1][j] * beta[i - 1]) / y[i];
        std::cout << "I finished first part!!" << std::endl;
      }
    }
  }

  x[system.GetWidth()] = beta[system.GetWidth()]; // ТУТ ОШИБКА!
  for(size_t i = system.GetWidth() - 1; i > 0; --i) {
    x[i] = alpha[i] * x[i + 1] + beta[i];
  }

  for(int i = 1; i < system.GetWidth(); i++) {
    std::cout << x[i] << "   ";
  }

}
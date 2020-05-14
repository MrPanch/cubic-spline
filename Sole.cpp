#include "Sole.hpp"

template <size_t width, size_t height>
Sole<width, height>::Sole():
  matrix_(width, std::vector<double>(height, 0)),
  free_variables_(height) {}

template <size_t width, size_t height>
std::istream& operator>>(std::istream& stream, Sole<width, height>& system) {
  std::cout << "give me a system matrix" << std::endl; // читаем слау
  for (size_t i = 0; i < system.GetHeight(); ++i) {
    for(size_t j = 0; j < system.GetWidth(); ++j) {
      stream >> system.GetMatrix()[i][j];
    }
  }

  std::cout << "give me a free odds column" << std::endl;
  for (int i = 0; i < system.GetHeight(); ++i) {
    stream >> system.GetFreeVariables()[i];
  }

  return stream;
}
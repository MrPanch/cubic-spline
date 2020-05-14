#pragma once
#include <vector>
#include <iostream>

template <size_t width = 3, size_t height = 3>
class Sole {
 public:
  Sole();

  size_t GetWidth() const {return width; }
  size_t GetHeight() const {return height; }

  std::vector<std::vector<double>>& GetMatrix() { return matrix_; };
  std::vector<double>& GetFreeVariables() {return free_variables_; };

  template <size_t m, size_t n>
  friend std::istream &operator>>(std::istream& stream, Sole<m, n>& sole);
 private:
  std::vector<std::vector<double>> matrix_;
  std::vector<double> free_variables_; // Столбец свободных коэффициентов
};

template <size_t width, size_t height>
std::istream& operator>>(std::istream& stream, Sole<width, height>& system);
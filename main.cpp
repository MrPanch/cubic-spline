#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include "Sole.cpp"
// Потому что разрешение темплейтов, подробней https://www.codeproject.com/Articles/48575/How-to-Define-a-Template-Class-in-a-h-File-and-Imp


int main(int argc, char** argv) {
//    const size_t size = 30;
    Sole<3, 3> system;
    std::cin >> system;
    auto x = system.SeqThomas();
    return 0;

}
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include "Sole.hpp"
#include "file_write.h"



int main(int argc, char** argv) {
    //const size_t size = 30;
    Sole system(3);
    std::cin >> system;
    auto x = system.SeqThomas();
    //NodesConditions(-2., 2., 10);
    return 0;
    /*
     * to test Thomas A = 2 -1 0 5 4 2 0 1 -3 , f = 3 6 2
     * */
}
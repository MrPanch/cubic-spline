#include <iostream>
#include <sstream>
#include <math.h>
#include <fstream>


void NodesConditions(double x1, double x2, int N_points)
{
    std::ofstream file("NodesConditions.txt");
    if (!file.is_open())
            std::cout << "File wasn't open!\n";

    file << N_points << std::endl;
    double x;
    double y, y1, y2;
    double d = (abs(x1) + abs(x2))/N_points;
    for (int i = 0; i <= N_points; ++i)
    {
        x = x1 + d*i;
        y  = (x*x*x*x + x*x*x + x*x + x) * cos(x);
        y1 = (4*x*x*x + 3*x*x + 2*x + 1)*cos(x) - x*(x*x*x + x*x + x + 1)*sin(x);
        y2 = -2*(4*x*x*x + 3*x*x + 2*x + 1)*sin(x) - (x*x*x*x + x*x*x - 11*x*x - 5*x - 2)*cos(x);
        if((i == 0) || (i == N_points)){y2 = 0;}
        file << x << "      " << y << "  "<< y1 << "  " << y2 << std::endl;
    }
}

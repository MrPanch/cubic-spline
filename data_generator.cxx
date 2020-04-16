#include <iostream>
#include <fstream>
#include <cmath>
#include <sys/stat.h>
int main(){
int a = 0,b = 0,c = 0,d = 1;
int length = 31;
int range = 5;
int iterator = 0;
double step = 0.3;
double * grid = new double[length];
double * node_value = new double[length];
for ( int i = 0; i < length; i++){
	grid[i] = i * step;
	}
char file_name[40] ;
std::ofstream out;
for (d; d < range; d++){
	for (c = 0; c < range; c++){
		for (b = 0; b < range; b++){
			for (a = 0; a < range; a++){
				sprintf(file_name, "./test_data/%d_%d_%d_%d_%d.txt", iterator,d,c,b,a);
				std::ofstream oFile (file_name);
				out.open(file_name);
				for (int i = 0; i < length; i++){
					node_value[i] = a + b*grid[i] + c*pow(grid[i],2) + d*pow(grid[i],3);
					out << node_value[i] << "\n";
					}
				out.close();
				iterator++;
				}
			}
		}
	}

delete [] grid;
delete [] node_value;
return 0;
}

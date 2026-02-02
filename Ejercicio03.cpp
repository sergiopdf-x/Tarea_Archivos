#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int k = 5;
    int arreglo[5] = {10,20,30,40,50};

    ofstream archivo("productoEscalar.txt");

    for (int i = 0; i < 5; i++) {
        archivo<<k*arreglo[i]<<" ";
    }

    archivo.close();
    return 0;
}

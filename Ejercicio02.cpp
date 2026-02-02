#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream archivo("materias.txt", ios::app);
    string materia;

    cout << "Ingrese materia (FIN para terminar): ";
    while (true) {
        getline(cin, materia);
        if (materia == "FIN") break;
        archivo << materia << endl;
    }
    archivo.close();
    return 0;
}

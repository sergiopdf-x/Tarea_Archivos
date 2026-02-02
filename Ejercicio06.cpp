#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
struct Prestamo {
    char nombre[30];
    float capital;
    float interes;
    float total;
};

int main() {
    Prestamo p;
    ofstream archivo;
    archivo.open("intereses.h", ios::binary);

    if (!archivo) {
        cout << "Error al crear el archivo." << endl;
        return 1;
    }

    cout<<"INGRESO DE DATOS DEL PRESTAMO\n";
    cout<<"Nombre del cliente: ";
    cin.getline(p.nombre, 30);

    cout<<"Capital del prestamo: ";
    cin>>p.capital;

    p.interes = p.capital * 0.15;
    p.total = p.capital + p.interes;
    archivo.write((char*)&p, sizeof(Prestamo));
    archivo.close();
    cout<<"\n--- RESULTADOS ---\n";
    cout<<"Interes generado: $"<<p.interes<<endl;
    cout<<"Monto total a cancelar: $"<<p.total<<endl;

    cout<<"\nArchivo 'intereses.h' generado correctamente."<<endl;

    return 0;
}

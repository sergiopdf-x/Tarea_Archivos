#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


struct Helado {
    int codigo;
    char sabor[20];
    float precio;
};

int main() {
    Helado h;
    ofstream archivoS;
    ifstream archivoE;

    archivoS.open("helados.txt", ios::binary);

    if (!archivoS) {
        cout << "Error al crear el archivo." << endl;
        return 1;
    }

    cout << "INGRESO DE DATOS DE HELADOS\n";
    for (int i = 0; i < 10; i++) {
        cout<<"\nHelado " << i + 1 << endl;
        cout<<"Codigo: ";
        cin>>h.codigo;
        cin.ignore();

        cout<<"Sabor helado: ";
        cin.getline(h.sabor, 20);

        cout<<"Precio: $";
        cin>>h.precio;

        archivoS.write((char*)&h, sizeof(Helado));
    }

    archivoS.close();

    archivoE.open("helados.txt", ios::binary);

    if (!archivoE) {
        cout<<"Error al abrir el archivo."<<endl;
        return 1;
    }

    Helado heladoB;
    bool primero = true;
    bool encontradoMora = false;
    float sumaPrecios = 0;

    cout<<"\nLISTA DE HELADOS REGISTRADOS\n";

    while (archivoE.read((char*)&h, sizeof(Helado))) {
        cout<<"\nCodigo: "<< h.codigo
            <<"\nSabor:  "<<h.sabor
            <<"\nPrecio: $"<<h.precio<<endl;

        sumaPrecios += h.precio;


        if (primero || h.precio < heladoB.precio) {
            heladoB = h;
            primero = false;
        }
        if (strcmp(h.sabor, "mora") == 0) {
            cout << "\n*** Helado de sabor MORA encontrado ***\n";
            encontradoMora = true;
        }
    }

    archivoE.close();
    cout<<"\nHELADO CON EL PRECIO MAS BAJO\n";
    cout<<"Codigo: "<<heladoB.codigo
        <<"\nSabor: "<<heladoB.sabor
        <<"\nPrecio: $"<<heladoB.precio<<endl;

    if (!encontradoMora) {
        cout<<"\nNo se encontro ningun helado de sabor mora."<<endl;
    }

    cout<<"\nSUMA TOTAL DE PRECIOS: $"<<sumaPrecios<<endl;
    return 0;
}

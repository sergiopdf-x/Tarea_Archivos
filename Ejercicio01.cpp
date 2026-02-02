#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream archivo("factura.txt");

    int cantidad;
    string detalle;
    float valor, totalProducto, subtotal, iva, totalPagar;

    cout<<"Cantidad: ";
    cin>>cantidad;
    cin.ignore();
    cout<<"Detalle: ";
    getline(cin, detalle);
    cout<<"Valor: $";
    cin>>valor;

    totalProducto = cantidad * valor;
    subtotal = totalProducto;
    iva = subtotal * 0.12;
    totalPagar = subtotal + iva;

    archivo<<"Cantidad: "<<cantidad << endl;
    archivo<<"Detalle: "<<detalle << endl;
    archivo<<"Valor unitario: $"<<valor << endl;
    archivo<<"Total producto: $"<<totalProducto << endl;
    archivo<<"IVA: "<<iva<<endl;
    archivo<<"Total a pagar: $"<<totalPagar<<endl;

    archivo.close();
    return 0;
}

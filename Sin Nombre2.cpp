#include <iostream>
#include <string>
using namespace std;

  int main() {
    const int tam = 100; // Definir capacidad máxima de productos
    string productos[tam];
    float precio[tam];
    int codigo[tam];
    int pos = 0;
    int bus; // Variable para la búsqueda
    int opc;

    // Supongamos que tienes algunos productos capturados:
    productos[0] = "Producto A"; precio[0] = 10.5; codigo[0] = 1;
    productos[1] = "Producto B"; precio[1] = 20.5; codigo[1] = 2;
    productos[2] = "Producto C"; precio[2] = 15.0; codigo[2] = 3;
    pos = 3; // Número de productos capturados

    // Búsqueda de un producto por código
    cout << "Introduce el código del producto a buscar: ";
    cin >> bus; // Obtener código a buscar

    bool encontrado = false;

    // Usar un ciclo for para buscar el código en el arreglo
    for (int i = 0; i < pos; i++) {
        if (bus == codigo[i]) { // Comparar el valor de bus con codigo[i]
            cout << "Producto encontrado: " << productos[i] << endl;
            cout << "Precio: $" << precio[i] << endl;
            cout << "Codigo: " << codigo[i] << endl;
            encontrado = true;
            break; // Salir del ciclo si se encuentra el producto
        }
    }

    if (!encontrado) {
        cout << "Producto con código " << bus << " no encontrado." << endl;
    }

    return 0;
}


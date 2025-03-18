#include <iostream>
#include <string>
using namespace std;

int main() {
    const int tam = 100; // Definir capacidad máxima de productos
    string productos[tam];
    float precio[tam];
    int codigo[tam];
    int pos = 0;
    string np;
    int opc, bus;

    do {
        system("cls");  // Limpiar la pantalla
        cout << "1. CAPTURAR PRODUCTOS" << endl;
        cout << "2. REPORTE DE PRODUCTOS" << endl;
        cout << "3. menu 3" << endl;
        cout << "4. SALIR" << endl;
        cout << "Selecciona opcion del menu: ";
        cin >> opc;

        switch (opc) {
            case 1:
                system("cls");
                cout << "MODULO DE CAPTURA DE PRODUCTOS\n" << endl;
                // Captura de productos
                do {
                    if (pos < tam) {
                        cout << "PRODUCTO # [ " << (pos + 1) << " ]" << endl;
                        cout << "PRODUCTO..............: ";
                        cin >> productos[pos];
                        cout << "PRECIO................$ ";
                        cin >> precio[pos];
                        codigo[pos] = (pos + 1);
                    } else {
                        cout << "El almacen se lleno." << endl;
                    }
                    // Incrementar pos
                    pos++;

                    cout << "INGRESAR OTRO PRODUCTO [S] OTRA TECLA PARA SALIR..: ";
                    cin >> np;
                } while (np == "S" || np == "s");
                system("pause");
                break;

            case 2:
                system("cls");
                cout << "MODULO REPORTE DE PRODUCTOS\n" << endl;
                // Salida de datos
                for (int n = 0; n < pos; n++) {
                    cout << "PRODUCTO # [ " << (n + 1) << " ]" << endl;
                    cout << "REFERENCIA..: " << codigo[n] << endl;
                    cout << "PRODUCTO....: " << productos[n] << endl;
                    cout << "PRECIO......$ " << precio[n] << endl;
                    cout << endl;
                }
                system("pause");
                break;

            case 3:
                system("cls");
                cout << "Modulo 3 en proceso" << endl;
                /* 
                    Aquí va el código para el módulo 3
                */
                system("pause");
                break;

            case 4:
                system("cls");
                cout << "Salir" << endl;
                system("pause");
                break;

            default:
                system("cls");
                cout << "Opcion seleccionada no valida" << endl;
                system("pause");
                break;
        }

        // Aquí realizamos la comparación con el código que mencionabas:
        cout << "Introduce un código para buscar: ";
        cin >> bus;

        // Realizamos la búsqueda en el arreglo codigo[]
        bool encontrado = false;

        for (int i = 0; i < pos; i++) {
            if (bus == codigo[i]) {
                cout << "Producto encontrado:\n";
                cout << "Producto: " << productos[i] << endl;
                cout << "Precio: $" << precio[i] << endl;
                cout << "Código: " << codigo[i] << endl;
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            cout << "Producto con código " << bus << " no encontrado." << endl;
        }

    } while (opc != 4);

    return 0;
}


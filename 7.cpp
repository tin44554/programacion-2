#include<iostream>
#include<conio.h>

using namespace std;

// Estructura para los datos de contacto del empleado
struct contacto {
    char direccion[30];
    char ciudad[20];
    char departamento[20];
};

// Estructura del empleado
struct empleado {
    int cod_emp;
    char nom_emp[30];
    float sueldo;
    struct contacto datos_contacto;
} trabajadores[2];

int main() {
    // Captura de datos
    cout << "Captura de datos de los empleados\n";
    for (int i = 0; i < 2; i++) {
        cout << "Codigo empleado...: ";
        cin >> trabajadores[i].cod_emp;
        fflush(stdin);

        cout << "Nombre empleado...: ";
        cin.getline(trabajadores[i].nom_emp, 30, '\n');

        cout << "Sueldo...: ";
        cin >> trabajadores[i].sueldo;
        fflush(stdin);

        cout << "Direccion...: ";
        cin.getline(trabajadores[i].datos_contacto.direccion, 30, '\n');

        cout << "Ciudad...: ";
        cin.getline(trabajadores[i].datos_contacto.ciudad, 20, '\n');

        cout << "Departamento...: ";
        cin.getline(trabajadores[i].datos_contacto.departamento, 20, '\n');

        cout << endl;
    }

    // Salida de datos
    cout << "\nDatos ingresados:\n";
    for (int i = 0; i < 2; i++) {
        cout << "Codigo Empleado: " << trabajadores[i].cod_emp << endl;
        cout << "Nombre Empleado: " << trabajadores[i].nom_emp << endl;
        cout << "Sueldo: $" << trabajadores[i].sueldo << endl;
        cout << "Direccion: " << trabajadores[i].datos_contacto.direccion << endl;
        cout << "Ciudad: " << trabajadores[i].datos_contacto.ciudad << endl;
        cout << "Departamento: " << trabajadores[i].datos_contacto.departamento << endl;
        cout << "---------------------------\n";
    }

    getch();
    return 0;
}


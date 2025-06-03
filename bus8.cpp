#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <conio.h>

using namespace std;

// Estructura para Conductor
    struct Conductor {
    string id;
    string nombre;
    string matricula;
    int edad;
    string genero;
    float horas;
    float horas_disponibles;
    bool available;
};

// Estructura para Bus
    struct Bus {
    string id;
    string modelo;
    int capacidad;
};

// Estructura para Ruta
    struct Ruta {
    string origen;
    string destino;
    string hora_llegada;
    int id_buses[3];
    int total_buses;
    int id_guia;
    int total_pasajeros;
    int distancia;
};

// Arreglos globales y contadores
const int MAX_GUIAS = 10;
const int MAX_BUSES = 10;
Conductor guias[MAX_GUIAS];
Bus buses[MAX_BUSES];
int total_guias = 0;
int total_buses = 0;

// Función para posicionar el cursor
    void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Función para centrar texto
    void centerText(const string& text, int y, int consoleWidth = 80) {
    int x = (consoleWidth - text.length()) / 2;
    gotoxy(x, y);
    cout << text;
}

// Función para establecer color en la consola
    void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Función para calcular la disponibilidad del conductor
    void actualizaDisponibilidad(Conductor &conductor) {
    const float HORAS_MAX_DIA = 8.0;
    conductor.horas_disponibles = HORAS_MAX_DIA - conductor.horas;
    conductor.available = conductor.horas_disponibles > 0;
}

// Funcion para inicializar conductores por defecto
    void initGuias(Conductor guias[], int &total_guias) {
    total_guias = 5;

    guias[0].id = "G001";
    guias[0].nombre = "Juan Perez";
    guias[0].edad = 35;
    guias[0].genero = "M";
    guias[0].horas = 4.5;
    guias[0].horas_disponibles = 0;
    guias[0].available = true;

    guias[1].id = "G002";
    guias[1].nombre = "Maria Gomez";
    guias[1].edad = 42;
    guias[1].genero = "F";
    guias[1].horas = 6.0;
    guias[1].horas_disponibles = 0;
    guias[1].available = true;

    guias[2].id = "G003";
    guias[2].nombre = "Carlos Lopez";
    guias[2].edad = 28;
    guias[2].genero = "M";
    guias[2].horas = 8.0;
    guias[2].horas_disponibles = 0;
    guias[2].available = false;

    guias[3].id = "G004";
    guias[3].nombre = "Ana Laura";
    guias[3].edad = 39;
    guias[3].genero = "F";
    guias[3].horas = 2.0;
    guias[3].horas_disponibles = 0;
    guias[3].available = true;

    guias[4].id = "G005";
    guias[4].nombre = "Luis Rodriguez";
    guias[4].edad = 45;
    guias[4].genero = "M";
    guias[4].horas = 3.5;
    guias[4].horas_disponibles = 0;
    guias[4].available = true;

    for (int i = 0; i < total_guias; i++) {
    actualizaDisponibilidad(guias[i]);
    }
}

// Función para inicializar buses por defecto
    void initBuses(Bus buses[], int &total_buses) {
    total_buses = 5;

    buses[0].id = "BUS001";
    buses[0].modelo = "Volvo B8R";
    buses[0].capacidad = 40;

    buses[1].id = "BUS002";
    buses[1].modelo = "Mercedes Citaro";
    buses[1].capacidad = 35;

    buses[2].id = "BUS003";
    buses[2].modelo = "Scania K310";
    buses[2].capacidad = 60;

    buses[3].id = "BUS004";
    buses[3].modelo = "MAN Lion City";
    buses[3].capacidad = 45;

    buses[4].id = "BUS005";
    buses[4].modelo = "Iveco Crossway";
    buses[4].capacidad = 30;
}

// Funcion para inicializar rutas por defecto con ubicaciones
    void initRutas(Ruta rutas[], int &total_rutas, Conductor guias[], Bus buses[]) {
    total_rutas = 5;

    rutas[0].origen = "Plaza de Bolivar";
    rutas[0].destino = "Usaquen";
    rutas[0].hora_llegada = "08:30";
    rutas[0].id_buses[0] = 0; // BUS001
    rutas[0].id_buses[1] = 1; // BUS002
    rutas[0].total_buses = 2;
    rutas[0].id_guia = 0;
    rutas[0].total_pasajeros = 28;
    rutas[0].distancia = 10;

    rutas[1].origen = "Fontibon";
    rutas[1].destino = "Suba";
    rutas[1].hora_llegada = "09:15";
    rutas[1].id_buses[0] = 2; // BUS003
    rutas[1].total_buses = 1;
    rutas[1].id_guia = 1;
    rutas[1].total_pasajeros = 60;
    rutas[1].distancia = 15;

    rutas[2].origen = "Kennedy";
    rutas[2].destino = "Chapinero";
    rutas[2].hora_llegada = "07:45";
    rutas[2].id_buses[0] = 3; // BUS004
    rutas[2].id_buses[1] = 4; // BUS005
    rutas[2].total_buses = 2;
    rutas[2].id_guia = 2;
    rutas[2].total_pasajeros = 50;
    rutas[2].distancia = 8;

    rutas[3].origen = "Engativa";
    rutas[3].destino = "Teusaquillo";
    rutas[3].hora_llegada = "10:00";
    rutas[3].id_buses[0] = 0; // BUS001
    rutas[3].total_buses = 1;
    rutas[3].id_guia = 3;
    rutas[3].total_pasajeros = 43;
    rutas[3].distancia = 12;

    rutas[4].origen = "Bosa";
    rutas[4].destino = "Zona Rosa";
    rutas[4].hora_llegada = "08:00";
    rutas[4].id_buses[0] = 1; // BUS002
    rutas[4].id_buses[1] = 2; // BUS003
    rutas[4].id_buses[2] = 3; // BUS004
    rutas[4].total_buses = 3;
    rutas[4].id_guia = 0;
    rutas[4].total_pasajeros = 83;
    rutas[4].distancia = 20;
}

// Funcion para insertar bus
void insertar_bus(Bus buses[], int &total_buses, const int MAX_BUSES) {
    if (total_buses >= MAX_BUSES) {
        cout << "No se pueden registrar mas buses (maximo: " << MAX_BUSES << ")\n";
        return;
    }
    
    Bus nuevo_bus;
    cout << "Id del bus: ";
    cin.ignore();
    getline(cin, nuevo_bus.id);
    
    for (int i = 0; i < total_buses; i++) {
        if (buses[i].id == nuevo_bus.id) {
            cout << "El bus ya existe\n";
            return;
        }
    }
    
    cout << "Modelo del Bus: ";
    getline(cin, nuevo_bus.modelo);
    cout << "Capacidad: ";
    cin >> nuevo_bus.capacidad;
    
    buses[total_buses++] = nuevo_bus;
    cout << "\nBus registrado\n";
}

// Función para insertar ruta
void insertar_ruta(Ruta rutas[], int &total_rutas, const int MAX_RUTAS, Conductor guias[], int total_guias, Bus buses[], int total_buses) {
    if (total_rutas >= MAX_RUTAS) {
        cout << "Excedio el numero maximo de rutas (" << MAX_RUTAS << ").\n";
        return;
    }
    
    Ruta nueva;
    cout << "Nombre del Origen: ";
    cin.ignore();
    getline(cin, nueva.origen);
    cout << "Nombre del Destino: ";
    getline(cin, nueva.destino);
    
    for (int i = 0; i < total_rutas; i++) {
        if (rutas[i].origen == nueva.origen && rutas[i].destino == nueva.destino) {
            cout << "La ruta de " << nueva.origen << " a " << nueva.destino << " ya existe\n";
            return;
        }
    }
    
    cout << "Hora de llegada (HH:MM): ";
    getline(cin, nueva.hora_llegada);
    
    cout << "Numero de buses (1-3): ";
    cin >> nueva.total_buses;
    if (nueva.total_buses < 1 || nueva.total_buses > 3) {
        cout << "Numero de buses debe ser entre 1 y 3\n";
        return;
    }
    
    cout << "\nBuses disponibles:\n";
    for (int i = 0; i < total_buses; i++) {
        cout << i + 1 << ". Id: " << buses[i].id << ", Modelo: " << buses[i].modelo << ", Capacidad: " << buses[i].capacidad << "\n";
    }
    for (int i = 0; i < nueva.total_buses; i++) {
        cout << "Seleccione el numero del bus " << i + 1 << " (1-" << total_buses << "): ";
        int id_bus;
        cin >> id_bus;
        if (id_bus < 1 || id_bus > total_buses) {
            cout << "Bus no valido.\n";
            return;
        }
        nueva.id_buses[i] = id_bus - 1;
    }
    
    cout << "\nGuias disponibles:\n";
    for (int i = 0; i < total_guias; i++) {
        cout << i + 1 << ". " << guias[i].nombre << " (Disponible: " 
             << (guias[i].available ? "Si" : "No") << ")\n";
    }
    cout << "Seleccione el numero del guia: ";
    int id_guia;
    cin >> id_guia;
    if (id_guia < 1 || id_guia > total_guias || !guias[id_guia - 1].available) {
        cout << "Guia no valido o no disponible.\n";
        return;
    }
    nueva.id_guia = id_guia - 1;
    
    cout << "Total Pasajeros: ";
    cin >> nueva.total_pasajeros;
    cout << "Distancia (km): ";
    cin >> nueva.distancia;
    
    rutas[total_rutas++] = nueva;
    cout << "\nRuta registrada\n";
}

// Función para buscar ruta
    void buscar_ruta(const Ruta rutas[], int total_rutas, const Conductor guias[], const Bus buses[]) {
    cout << "\nMODULO BUSCAR RUTA\n";
    cout << "Nombre del Origen: ";
    string origen;
    cin.ignore();
    getline(cin, origen);
    cout << "Nombre del Destino: ";
    string destino;
    getline(cin, destino);
    
    bool found = false;
    for (int i = 0; i < total_rutas; i++) {
        if (rutas[i].origen == origen && rutas[i].destino == destino) {
            cout << "\nRuta Encontrada\n";
            cout << "Ruta: " << rutas[i].origen << " a " << rutas[i].destino << endl;
            cout << "Hora de llegada: " << rutas[i].hora_llegada << endl;
            cout << "Flota de Buses:\n";
            for (int j = 0; j < rutas[i].total_buses; j++) {
                int id_bus = rutas[i].id_buses[j];
                cout << "  Bus " << j + 1 << ": Id: " << buses[id_bus].id 
                     << ", Modelo: " << buses[id_bus].modelo 
                     << ", Capacidad: " << buses[id_bus].capacidad << endl;
            }
            const Conductor &c = guias[rutas[i].id_guia];
            cout << "Guia: " << c.nombre << endl;
            cout << "Id: " << c.id << endl;
            cout << "Edad: " << c.edad << endl;
            cout << "Género: " << c.genero << endl;
            cout << "Horas: " << c.horas << endl;
            cout << "Horas Disponibles: " << c.horas_disponibles << endl;
            cout << "Disponible: " << (c.available ? "Sí" : "No") << endl;
            cout << "Pasajeros: " << rutas[i].total_pasajeros << endl;
            cout << "Distancia: " << rutas[i].distancia << " km" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\nRuta de " << origen << " a " << destino << " no existente\n";
    }
}

// Función para modificar ruta
    void modificar_ruta(Ruta rutas[], int total_rutas, Conductor guias[], int total_guias, Bus buses[], int total_buses) {
    cout << "\nMODULO MODIFICAR RUTA\n";
    cout << "Nombre del Origen a Modificar: ";
    string origen;
    cin.ignore();
    getline(cin, origen);
    cout << "Nombre del Destino a Modificar: ";
    string destino;
    getline(cin, destino);
    
    for (int i = 0; i < total_rutas; i++) {
        if (rutas[i].origen == origen && rutas[i].destino == destino) {
            cout << "\nRuta Encontrada\n";
            cout << "Ingrese los Nuevos Datos\n";
            
            cout << "Nuevo Nombre del Origen: ";
            getline(cin, rutas[i].origen);
            cout << "Nuevo Nombre del Destino: ";
            getline(cin, rutas[i].destino);
            cout << "Nueva Hora de llegada (HH:MM): ";
            getline(cin, rutas[i].hora_llegada);
            
            cout << "Numero de buses a modificar (1-3): ";
            int num_buses;
            cin >> num_buses;
            if (num_buses >= 1 && num_buses <= 3) {
                rutas[i].total_buses = num_buses;
                cout << "\nBuses disponibles:\n";
                for (int j = 0; j < total_buses; j++) {
                    cout << j + 1 << ". Id: " << buses[j].id 
                         << ", Modelo: " << buses[j].modelo 
                         << ", Capacidad: " << buses[j].capacidad << "\n";
                }
                for (int j = 0; j < num_buses; j++) {
                    cout << "Seleccione el numero del bus " << j + 1 << " (1-" << total_buses << "): ";
                    int id_bus;
                    cin >> id_bus;
                    if (id_bus < 1 || id_bus > total_buses) {
                        cout << "Bus no valido.\n";
                        return;
                    }
                    rutas[i].id_buses[j] = id_bus - 1;
                }
            } else {
                cout << "Numero de buses no valido.\n";
                return;
            }
            
            cout << "\nGuias disponibles:\n";
            for (int j = 0; j < total_guias; j++) {
                cout << j + 1 << ". " << guias[j].nombre << " (Disponible: " 
                     << (guias[j].available ? "Sí" : "No") << ")\n";
            }
            cout << "Seleccione el numero del guia: ";
            int id_guia;
            cin >> id_guia;
            if (id_guia < 1 || id_guia > total_guias || !guias[id_guia - 1].available) {
                cout << "Guia no valido o no disponible.\n";
                return;
            }
            rutas[i].id_guia = id_guia - 1;
            
            cout << "Total Pasajeros Nuevo: ";
            cin >> rutas[i].total_pasajeros;
            cout << "Distancia Nueva (km): ";
            cin >> rutas[i].distancia;
            
            cout << "\nRUTA MODIFICADA\n";
            return;
        }
    }
    cout << "\nRuta de " << origen << " a " << destino << " no existente\n";
}

// Función para eliminar ruta
    void eliminar_ruta(Ruta rutas[], int &total_rutas) {
    cout << "\nMODULO ELIMINAR RUTA\n";
    cout << "Nombre del Origen a Eliminar: ";
    string origen;
    cin.ignore();
    getline(cin, origen);
    cout << "Nombre del Destino a Eliminar: ";
    string destino;
    getline(cin, destino);
    
    for (int i = 0; i < total_rutas; i++) {
        if (rutas[i].origen == origen && rutas[i].destino == destino) {
            for (int j = i; j < total_rutas - 1; j++) {
                rutas[j] = rutas[j + 1];
            }
            total_rutas--;
            cout << "\nRuta Eliminada\n";
            return;
        }
    }
    cout << "\nRuta de " << origen << " a " << destino << " no existente\n";
}

// Función para mostrar una sola ruta
void mostrar_ruta(const Ruta &ruta, int index, const Conductor guias[], const Bus buses[]) {
    cout << "\nRuta " << index + 1 << ": " << ruta.origen << " a " << ruta.destino << endl;
    cout << "Hora de llegada: " << ruta.hora_llegada << endl;
    cout << "Flota de Buses:\n";
    for (int j = 0; j < ruta.total_buses; j++) {
        int id_bus = ruta.id_buses[j];
        cout << "  Bus " << j + 1 << ": Id: " << buses[id_bus].id 
             << ", Modelo: " << buses[id_bus].modelo 
             << ", Capacidad: " << buses[id_bus].capacidad << endl;
    }
    const Conductor &c = guias[ruta.id_guia];
    cout << "Guia: " << c.nombre << endl;
    cout << "Id: " << c.id << endl;
    cout << "Edad: " << c.edad << endl;
    cout << "Genero: " << c.genero << endl;
    cout << "Horas: " << c.horas << endl;
    cout << "Horas Disponibles: " << c.horas_disponibles << endl;
    cout << "Disponible: " << (c.available ? "Sí" : "No") << endl;
    cout << "Pasajeros: " << ruta.total_pasajeros << endl;
    cout << "Distancia: " << ruta.distancia << " km" << endl;
}

// Función para listar todas las rutas disponibles
void listar_rutas(const Ruta rutas[], int total_rutas, const Conductor guias[], const Bus buses[]) {
    cout << "\nMODULO LISTAR RUTAS DISPONIBLES\n";
    if (total_rutas == 0) {
        cout << "No hay Rutas en el sistema\n";
        return;
    }
    for (int i = 0; i < total_rutas; i++) {
        mostrar_ruta(rutas[i], i, guias, buses);
    }
}

// Función para comprar boleto
void comprar_boleto(Ruta rutas[], int total_rutas, const Bus buses[], int total_buses, int consoleWidth) {
    cout << "\nMODULO COMPRAR BOLETO\n";
    if (total_rutas == 0) {
        cout << "No hay rutas disponibles en el sistema\n";
        return;
    }

    // Mostrar rutas disponibles
    cout << "\nRutas disponibles:\n";
    for (int i = 0; i < total_rutas; i++) {
        int capacidad_total = 0;
        for (int j = 0; j < rutas[i].total_buses; j++) {
            capacidad_total += buses[rutas[i].id_buses[j]].capacidad;
        }
        cout << i + 1 << ". " << rutas[i].origen << " a " << rutas[i].destino 
             << " (Hora: " << rutas[i].hora_llegada 
             << ", Pasajeros: " << rutas[i].total_pasajeros 
             << ", Capacidad Total: " << capacidad_total << ")\n";
    }

    // Seleccionar ruta
    cout << "\nSeleccione el numero de la ruta (1-" << total_rutas << "): ";
    int ruta_seleccionada;
    cin >> ruta_seleccionada;
    if (ruta_seleccionada < 1 || ruta_seleccionada > total_rutas) {
        cout << "Ruta no valida.\n";
        return;
    }
    ruta_seleccionada--; // Ajustar al índice del arreglo

    // Calcular capacidad total de la ruta
    int capacidad_total = 0;
    for (int j = 0; j < rutas[ruta_seleccionada].total_buses; j++) {
        capacidad_total += buses[rutas[ruta_seleccionada].id_buses[j]].capacidad;
    }

    // Verificar si hay asientos disponibles
    if (rutas[ruta_seleccionada].total_pasajeros >= capacidad_total) {
        cout << "No hay asientos disponibles en esta ruta.\n";
        return;
    }

    // Ingresar datos del pasajero
    string nombre_pasajero;
    cout << "Nombre del pasajero: ";
    cin.ignore();
    getline(cin, nombre_pasajero);

    // Incrementar el número de pasajeros
    rutas[ruta_seleccionada].total_pasajeros++;

    // Confirmar compra
    setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    centerText("Boleto comprado Exitosamente ", 10, consoleWidth);
    
    cout << "\nDetalles del boleto:\n"<< endl;
    cout << "Pasajero: " << nombre_pasajero << endl;
    cout << "Ruta: " << rutas[ruta_seleccionada].origen << " a " << rutas[ruta_seleccionada].destino << endl;
    cout << "Hora de llegada: " << rutas[ruta_seleccionada].hora_llegada << endl;
    cout << "Asientos ocupados: " << rutas[ruta_seleccionada].total_pasajeros << "/" << capacidad_total << endl;
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

    int main() {
    const int MAX_RUTAS = 10;
    Ruta rutas[MAX_RUTAS];
    int total_rutas = 0;
    int opc;

    // Inicializar consola
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    initGuias(guias, total_guias);
    initBuses(buses, total_buses);
    initRutas(rutas, total_rutas, guias, buses);

    do {
        system("cls"); // Limpiar pantalla
        setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY); // Azul brillante
        centerText("===========================================", 2, consoleWidth);
        centerText("SISTEMA DE GESTION DE TRANSPORTE URBANO", 3, consoleWidth);
        centerText("===========================================", 4, consoleWidth);
        setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Verde brillante
        centerText("1. Insertar Ruta", 6, consoleWidth);
        centerText("2. Buscar Ruta", 7, consoleWidth);
        centerText("3. Modificar Ruta", 8, consoleWidth);
        centerText("4. Eliminar Ruta", 9, consoleWidth);
        centerText("5. Mostrar Rutas Disponibles", 10, consoleWidth);
        centerText("6. Insertar Bus", 11, consoleWidth);
        centerText("7. Comprar Boleto", 12, consoleWidth); // Nueva opción
        centerText("0. Salir", 13, consoleWidth);
        setColor(FOREGROUND_RED | FOREGROUND_INTENSITY); // Rojo brillante
        centerText("Seleccione una opcion: ", 15, consoleWidth);
        gotoxy(consoleWidth / 2 + 10, 15); // Posicionar cursor después del mensaje
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restablecer a blanco
        cin >> opc;

        switch (opc) {
            case 1: insertar_ruta(rutas, total_rutas, MAX_RUTAS, guias, total_guias, buses, total_buses); break;
            case 2: buscar_ruta(rutas, total_rutas, guias, buses); break;
            case 3: modificar_ruta(rutas, total_rutas, guias, total_guias, buses, total_buses); break;
            case 4: eliminar_ruta(rutas, total_rutas); break;
            case 5: listar_rutas(rutas, total_rutas, guias, buses); break;
            case 6: insertar_bus(buses, total_buses, MAX_BUSES); break;
            case 7: comprar_boleto(rutas, total_rutas, buses, total_buses, consoleWidth); break; // Llamar a la nueva función
            case 0: 
                system("cls");
                setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                centerText("GRACIAS POR USAR EL SISTEMA :)", 10, consoleWidth);
                setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                Sleep(1000); // Pausa para efecto
                break;
            default:
                system("cls");
                setColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
                centerText("OPCION NO VALIDA", 10, consoleWidth);
                setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                Sleep(1000);
                break;
        }
        if (opc != 0) {
            cout << "\nPresione una tecla para continuar...";
            _getch();
        }
    } while (opc != 0);

    return 0;
}

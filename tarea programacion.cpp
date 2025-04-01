#include <iostream>
#include <conio.h>
#include <windows.h>  // para añadir los colores
using namespace std;
void SetColor(int textColor, int bgColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgColor << 4) | textColor);
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void DrawBox(int x, int y, int width, int height) {
    for (int i = 0; i < width; i++) {
        gotoxy(x + i, y); cout << "-";
        gotoxy(x + i, y + height - 1); cout << "-";
    }
    for (int i = 0; i < height; i++) {
        gotoxy(x, y + i); cout << "|";
        gotoxy(x + width - 1, y + i); cout << "|";
    }
    gotoxy(x, y); cout << "+";
    gotoxy(x + width - 1, y); cout << "+";
    gotoxy(x, y + height - 1); cout << "+";
    gotoxy(x + width - 1, y + height - 1); cout << "+";
}

void DrawTable(int x, int y, int columns, int rows, int cellWidth) {
    int totalWidth = columns * cellWidth + columns + 1;
    int totalHeight = rows + 2;
    for (int i = 0; i < totalWidth; i++) {
        gotoxy(x + i, y); cout << "-";
        gotoxy(x + i, y + totalHeight - 1); cout << "-";
    }
    for (int i = 0; i < totalHeight; i++) {
        gotoxy(x, y + i); cout << "|";
        gotoxy(x + totalWidth - 1, y + i); cout << "|";
    }
    for (int i = 1; i <= columns; i++) {
        for (int j = 0; j < totalHeight; j++) {
            gotoxy(x + i * (cellWidth + 1), y + j); cout << "|";
        }
    }
    for (int i = 1; i < totalHeight - 1; i++) {
        for (int j = 0; j < totalWidth; j++) {
            gotoxy(x + j, y + i); cout << " ";
        }
    }
}

int main() {
    int opc, tam = 4, pos = 0, bus, pr;
    string np;
    bool bandera;
    string productos[tam];
    int codigo[tam];
    int precio[tam];

    do {
        SetColor(15, 0);
        system("cls");
        int centerX = 40;
        DrawBox(centerX - 20, 2, 40, 4);
        SetColor(11, 0);
        gotoxy(centerX - 7, 3); cout << "   Almacen de cadena   ";
        SetColor(15, 0);

        gotoxy(centerX - 10, 7); SetColor(10, 0); cout << "1. Capturar productos";
        gotoxy(centerX - 10, 8); cout << "2. Reportes de productos";
        gotoxy(centerX - 10, 9); cout << "3. Buscar producto";
        gotoxy(centerX - 10, 10); cout << "4. Modificar producto";
        gotoxy(centerX - 10, 11); cout << "5. Cancelar producto";
        gotoxy(centerX - 10, 12); cout << "6. Salir";

        gotoxy(centerX - 20, 14); SetColor(15, 0); cout << "-----------------------------------------";
        gotoxy(centerX - 20, 15); cout << "| Selecciona una opcion del menu:       |";
        gotoxy(centerX - 20, 16); cout << "-----------------------------------------";
        gotoxy(centerX - 20, 17); cout << "| Opcion: ";
        cin >> opc;
        cin.ignore();

        switch (opc) {
            case 1:
                system("cls");
                SetColor(10, 0);
                gotoxy(20, 2); cout << "MODULO DE CAPTURA DE PRODUCTOS";
                DrawTable(10, 4, 3, tam, 15);
                gotoxy(12, 4); cout << "Codigo";
                gotoxy(28, 4); cout << "Producto";
                gotoxy(44, 4); cout << "Precio";
                for (int i = 0; i < tam; i++) {
                    gotoxy(12, 6 + i); cout << (i + 1);
                    cout << "                ";
                    gotoxy(28, 6 + i); cin >> productos[i];
                    gotoxy(44, 6 + i); cin >> precio[i];
                    codigo[i] = (i + 1);
                }
                system("pause");
                break;
            case 2:
                system("cls");
                SetColor(14, 0);
                cout << "MODULO DE REPORTE DE PRODUCTOS" << endl;
                for (int i = 0; i < pos; i++) {
                    cout << "Producto #" << (i + 1) << endl;
                    cout << "Referencia: " << codigo[i] << endl;
                    cout << "Producto: " << productos[i] << endl;
                    cout << "Precio: $" << precio[i] << endl;
                    cout << endl;
                }
                system("pause");
                break;
            case 6:
                system("cls");
                SetColor(15, 0);
                cout << "Salir" << endl;
                system("pause");
                break;
            default:
                system("cls");
                SetColor(12, 0);
                cout << "Opcion no valida" << endl;
                system("pause");
                break;
        }
    } while (opc != 6);

    return 0;
}


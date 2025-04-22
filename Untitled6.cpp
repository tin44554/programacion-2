#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    //matriz 3*3
    string raya[3][3];
    int f,c;
    
    raya[0][0] = "1";
    raya[0][1] = "2";
    raya[0][2] = "3";

    raya[1][0] = "4";
    raya[1][1] = "5";
    raya[1][2] = "6";

    raya[2][0] = "7";
    raya[2][1] = "8";
    raya[2][2] = "9";

    //Imprimir la matriz 
    for (int i=0;i<3;i++)
    {
        for (int j=0; j<3;j++)
        {
            cout<<raya[i][j]<< " ";
        }
        cout<<endl;
    }

    //Jugador1
    cout << "Indique fila para Jugador 1: ";
    cin >> f;
    cout << "Indique columna para Jugador 1: ";
    cin >> c;

    // Validación de entrada
    if (f < 0 ||f>2||c < 0||c > 2||raya[f][c] == "X"|| raya[f][c] == "O")
    {
        cout << "Movimiento inválido, intenta de nuevo!" << endl;
        return 0;
    }

    raya[f][c] ="O"; // Marca"O" para el jugador 1

    // Imprimir la matriz después del turno de Jugador 1
    for (int i=0; i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            cout << raya[i][j] << " ";
        }
        cout << endl;
    }

    // Jugador 2
    cout << "Indique fila para Jugador 2: ";
    cin >> f;
    cout << "Indique columna para Jugador 2: ";
    cin >> c;

    // Validación de entrada
    if (f <0||f>2||c<0||c>2||raya[f][c] == "X" || raya[f][c] == "O")
    {
        cout << "Movimiento invalido, intenta de nuevo!" << endl;
        return 0;
    }

    raya[f][c] = "X"; // Marca "X" para el jugador 2

    // Imprimir la matriz después del turno de Jugador 2
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << raya[i][j] << " ";
        }
        cout << endl;
    }

    getch();
    return 0;
}


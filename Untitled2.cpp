#include <iostream>
#include <conio.h>
using namespace std;

//estructura producto
struct producto {
    string nombre;
    float precio;
    int cantidad;
};

//estructura categoria
struct categoria {
    string nom_categoria;
    producto producto[3];
    int total_productos;
};

//crear la funcion insertar producto
void insertar_producto(categoria &cat)
{
    cout << "Modulo insertar producto \n";
    
    //validar cantidad de productos 
    if (cat.total_productos >= 3)
    {
        cout << "Se llenó el almacén de productos\n";
        return;
    } //fin if

    //insertar producto
    producto nuevo;
    cout << "Nombre del producto: ";
    cin.ignore();
    getline(cin, nuevo.nombre);

    cout << "Precio $: ";
    cin >> nuevo.precio;
    cout << "Cantidad: ";
    cin >> nuevo.cantidad;

    //autoincrementar total productos
    cat.producto[cat.total_productos++] = nuevo;
    cout << "PRODUCTO INSERTADO CORRECTAMENTE" << endl;
}//fin de la funcion insertar productos

int main()
{
    //declarar variables 
    //alias a categoria
    categoria categoria_pan;
    categoria_pan.nom_categoria = "Bizcochos";
    categoria_pan.total_productos = 0;

    int opc;
    //menu
    do
    {
        system("cls");
        cout << "MENU PANADERIA\n";
        cout << "1 Insertar producto\n";
        cout << "2 Buscar producto\n";
        cout << "3 Modificar producto\n";
        cout << "4 Eliminar producto\n";
        cout << "5 Mostrar productos\n";
        cout << "0 Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opc;

        //validar opcion
        switch (opc)
        {
            case 1:
                system("cls"); insertar_producto(categoria_pan);system("pause");break;
            case 2:system("cls");cout << "Modulo Buscar producto\n";system("pause");break;
            case 3:system("cls");cout << "Modulo Modificar producto\n";system("pause");break;
            case 4:system("cls");cout << "Modulo Eliminar producto\n";system("pause");break;
            case 5:system("cls");cout << "Modulo Mostrar producto\n";system("pause");break;
            case 0: system("cls"); cout << "Salir del ejercicio\n";system("pause"); break;
            default: system("cls");cout << "Opcion seleccionada no valida \n";system("pause"); break;
        }
    } while (opc != 0);

    return 0;
}
//crear funcion modificar
//crear funcuin buscar producto
void modificar_producto(categoria &cat)
{
	cout<<"modificar producto\n";
	string bus;
	bool encontrado=false;
	cout<<"producto a buscar nodificar....:";
	cin.ignore();
	getline(cin,bus);
	//recorrer structura categoria
	for (int i=0; i<cat.total_productos;i++)
	{
	   cout<<"\n PRODUCTO ENCONTRADO\n"	;
	   cout<<"ingrese los nuevos datos/n";
	   cout<<"Nombre producto nuevo....:";
	   cin>>cat.producto[i].nombre;
	   
	   cout<<"precio nuevo.....:";
	   cin>>cat.producto[i].precio;
	   
	   cout<<"Cantidad nuevo....:";
	   cin>>cat.producto[i].cantidad;
	   //romper el ciclo de busqueda
	   cout<<"Producto actualizado correctamente..\n";
	   encontrado=true;
	   break;
     }	
	}//fin for
	//validar si no existe
	if(!encontrado)
   }
   
}//fin for 
//validar si no existe 

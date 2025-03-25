#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	//declara variables
	int opc,tam=2,pos=0;
	string np;//nuevo producto
	
	//declarar el vector
	string productos[tam];
	int codigo [tam];
	int precio[tam];
	
	
	
	do
	{
		system("cls");
		cout<<("ALMACEN DE CADENA")<<endl;
		cout<<("1. CAPTURAR PRODUCTOS")<<endl;
		cout<<("2. REPORTE DE PRODUCTOS")<<endl;
		cout<<("3. menu 3")<<endl;
		cout<<("4. SALIR")<<endl;
		cout<<("selecciones opcion del menu..: ");
		cin>>opc;
		switch(opc)
		{
			case 1: system("cls");
					cout<<"MODULO DE CAPTURA DE PRODUCTOS\n"<<endl;
					//captura de productos
					do
					{
						if(pos<tam)
						{
							cout<<"PRODUCTO # [ "<<(pos+1)<<" ]"<<endl;
							cout<<"PRODUCTO..............: ";
							cin>>productos[pos];
							cout<<"PRECIO................$ ";
							cin>>precio[pos];
							codigo[pos]=(pos+1);								
						}//fin if
						else
						{
							cout<<"el almacen se lleno "<<endl;
						}//fin else
						//incremento de pos
						pos++;
												
						cout<<"INGRESAR OTRO PRODUCTO [S] OTRA TECLA PARA SALIR..: ";
						cin>>np;	
					}while(np=="S" || np=="s" );
					
					system("pause");
					break;
					
			case 2: system("cls");
					cout<<"MODULO REPORTE DE PRODUCTOS\n"<<endl;
					//salida de datos
					for(int n=0; n<pos;n++)
					{
						cout<<"PRODUCTO # [ "<<(n+1)<<" ]"<<endl;
						cout<<"REFERENCIA..: "<<codigo[n]<<endl;
						cout<<"PRODUCTO....: "<<productos[n]<<endl;
						cout<<"PRECIO......$ "<<precio[n]<<endl;
						cout<<endl;
					}//fin for
					system("pause");
					break;
					
			case 3: system("cls");
					cout<<"modulo 3 en proceso"<<endl;
					/* 
						aca codigo
					*/
					system("pause");
					break;
			case 4: system("cls");
					cout<<"salir"<<endl;
					system("pause");
					break;
					
			default: system("cls"); 
					 cout<<"opcion seleccionada no valida"<<endl;
					 system("pause");
					 break;	
		}//fin switch
	
	}while(opc!=4);
	
	
	
	
	getch();
	return 0;	
}//fin main

#include<iostream>
#include<conio.h>


using namespace std;
//creacion de struct
struct Estudiante
{	
  int cod;	
  char nombre[10];
} estu_1;





int main()
{
    //capturar datos
	cout<<"ingrese el codigo.....:"	;
	cin>>estu_1.cod;
	cout<<"ingrese el nombre del estudinte...:";
	cin>>estu_1.nombre;
	
	//salida de datos
	cout<<"codigo...:"<<estu_1.cod<<endl;
	cout<<"estudiante...:"<<estu_1.nombre<<endl;
	
	
	
	
		
	getch();
	return 0;
	
}

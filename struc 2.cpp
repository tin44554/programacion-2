#include<iostream>
#include<conio.h>


using namespace std;
//creacion de struct
struct Estudiante
{	
  
  int cod;	
  char nombre[10];
  int edad;
} estu_1;





int main()
{
    //capturar datos
	cout<<"ingrese el codigo.....:"	;
	cin>>estu_1.cod;
	fflush(stdin);
	cout<<"ingrese el nombre del estudinte...:";
	cin.getline (estu_1.nombre,10,'\n');
	
	cout<<"edad del estudiante...:";
	cin>>estu_1.edad;
	
	//salida de datos
	cout<<"codigo...:"<<estu_1.cod<<endl;
	cout<<"estudiante...:"<<estu_1.nombre<<endl;
		cout<<"edad...:"<<estu_1.edad<<endl;
	
	
	
		
	getch();
	return 0;
	
}

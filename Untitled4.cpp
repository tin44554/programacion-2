#include<iostream>
#include<conio.h>

using namespace std;
//creacion de struct
struct Estudiante
{	
  int cod;	
  char nombre[10];
  int edad;
} estu[3];

int main()
{
    //capturar datos
    for(int i=0;i<3;i++)
    {
    cout<<"ingrese el codigo.....:"	;
	cin>>estu[i].cod;
	fflush(stdin);
	
	cout<<"ingrese el nombre del estudinte...:";
	cin.getline (estu[i].nombre,10,'\n');
	
	cout<<"edad del estudiante...:";
	cin>>estu[i].edad;	
	}
    
    
	//salida de datos
	for(int i=0;i<3;i++)
	{
	cout<<"codigo...:"<<estu[i].cod<<endl;
	cout<<"estudiante...:"<<estu[i].nombre<<endl;
	cout<<"edad...:"<<estu[i].edad<<endl;			
	}
	
	
		
		
	getch();
	return 0;
	
}

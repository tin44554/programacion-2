/*
pedir al usuario ingresar 5 numeros en la funcion vacia muestre los datos en una funcion parametrisada
calcule el promedio y devuelva el promedio, funcion retorno
se debe usar array
*/


#include<iostream>
#include<conio.h>

using  namespace std;
//declarar variables globales 
const int TAM=5;
int numeros[TAM];

//defnir funciones
//capturar datos 
void capturar();
void mostrar(int num[],int tam);
float calcular_promedio(int num[],int tam);

int main()
{
	//llamar funciones 
	capturar();
    mostrar(numeros,TAM);	
   float pro=calcular_promedio(numeros,TAM); 
   cout<<"promedio es "<<pro<<endl;
	
	getch();
	return 0;
}//fin main
//definir funcion
void capturar()
{
	cout<<"ingrese"<<TAM<<"numeros enteros"<<endl;
	for(int i=0;i<TAM;i++)
	{
		cout<<"["<<(i+1)<<"ingrese el numero.......";
		cin>>numeros[i];
		
	}//fin for
	
};//fin de la funcion 
/*------------------------------------------------------------*/
void mostrar(int num[],int tam)
{
	cout<<"\t\tREPORTE DE DATOS\n";
	for(int i=0;i<tam;i++)
	{
		cout<<num[i]<<" ";
	}
}
/*----------------------------------------------------------------*/
float calcular_promedio(int num[],int tam)
{
	int suma=0;
	for(int i=0;i<tam;i++)
	{
		suma+=num[i];
	}
	return static_cast<float>(suma)/tam;
}

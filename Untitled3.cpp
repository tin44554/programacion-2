#include <iostream>
#include <conio.h>
using namespace  std;
int main()
{
	//crear mitriz 3,3
	int v1[2][2];
	
	//captura de datos
	for(int i=0;i<2;i++)
	   {
	  	 	for(int j=0;j<2;j++)
	  	
	  		{
			  	cout<<"ingrese un valor numerico....:"	;
			  	cin>>v1[i][j];
			  	/*
			  	cout<<"ingrese un valor numerico....:"	;
			  	cin>dato;
			  	cin>>v1[i][j];
			  	*/		  		
			}
	  }
	//mostrar la informaion
	for(int i=0;i<2;i++)
	{  
		
		for(int j=0;j<2;j++)
	  	
	  		{
			  		cout<<"valor ingresado:  "<<v1[i][j]<<endl;
		   }
	  
	} 
		
	
	
	
    getch();
    return 0;
  	
}

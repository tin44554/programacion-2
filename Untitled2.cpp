#include <iostream>
#include <conio.h>
using namespace  std;
int main()
{
 //matriz 3,3
 int v1[3][3];
 int z=1;
 
 //captura de los datos 
	for(int f=0;f<3;f++)	
	{
		for(int c=0;c<3;c++)	
	{  
	     v1[f][c]=(c+1);
	     
      }//fin de las colomnas
	}//fin for filas 
	
	//mostrar los datos 
		for(int f=0;f<3;f++)	
	{
		for(int c=0;c<3;c++)	
	{  
	    cout<<v1[f][c]<<" ";
      }//fin de las colomnas
      cout<<endl;
	}//fin for filas 
	
	
    getch();
    return 0;
  	
}

#include <iostream>
#include <conio.h>
using namespace  std;
int main()
	{
	//crear matriz 8,4
	int v=4,d=8;//v -> vendedoes d->dias 
	int ventas[v][d];
	//llamar la matriz de ceros 
	for(int i=0;i<v;i++)
		{
		for(int j=0;j<d;j++)
		{
		ventas [i][j]=0;
			
     }

   }
    //llamar la matrix
 for(int i=0;i<v;i++)	
{

   for (int j=0;j<d;j++)	
	{
	cout<<ventas[i][j]<<" ";
	
    }

    cout<<endl;
}




	
    getch();
    return 0;
  	
}

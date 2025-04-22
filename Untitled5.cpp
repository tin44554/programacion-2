#include <iostream>
#include <conio.h>
using namespace  std;
int main()
{
    //matriz 3*3
	string raya	[3][3];
	int f,c;
	
	raya[0][0]="1";
	raya[0][1]="2";
	raya[0][2]="3";
	
  	raya[1][0]="4";
  	raya[1][1]="5";
  	raya[1][2]="6";
  	
    raya[2][0]="7";
  	raya[2][1]="8";
  	raya[2][2]="9";
 
  	//imprimir matrix
  	for(int i=0;i<3;i++)
  	{
  	
      cout<<raya[i][j]<<" ";
	  }
	  cout<<endl;
    }
  
   //j_1
   cout<<"indique fila......: ";
  cin>>f;
  cout<<"indique columna......";
  cin>>c;
  raya[f][c]="0";
  
  
  //imprimir matrix
  for(int i=0;i<3;i++)
  {
  	for(int j=0;j<3;j++)
  	{
  		cout<<raya[i][j]<<" ";
	  }
	cout<<endl;
  }
  
  
  
  
  
  //*****j2
  cout<<"JUGADOR 2/n";
  cout<<"indique fila......: ";
  cin>>f;
  cout<<"indique columna......";
  cin>>c;
  raya[f][c]="x";
  
  //imprimir matrix
 for(int i=0;i<3;i++)
  {
  	for(int j=0;j<3;j++)
  	{
  		cout<<raya[i][j]<<" ";
	  }
	cout<<endl;
  }
  
  
  
  
  
  
  
    getch();
    return 0;
  	
}
		
		
		
		
		
		
		
		

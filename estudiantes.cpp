#include <iostream>
#include <conio.h>
using namespace std;

int main()
{

	
    	//crear array estudiantes 
	    string estudiantes[]={"jose","maria","nico","pepe","mijo"};	
    	int cod,reg=0;
    	string conf;
	    float notas[5][3];
	    float nota;
	    
	    
	     //llenar la matrix
	     
	    /* 
    	    for(int i=0;i<4;i++)
	    {
		    	for(int j=0;j<3;i++)
    			{
			
		          notas[i][j]=0;
		       }//notas 
	    }//estudiantes*/
		
    //ver la  matrix
    for(int i=0;i<5;i++)
    {
    	//cout<<(i+1)<<". "<<estudiantes[i]<<"\t";
	    for(int j=0;j<3;j++)
    	{
		
	       notas[i][j]=0;
	       //cout<<notas[i][j]<<"\t";
	    }//notas 
	    cout<<endl;
    }//estudiantes<<<<
    //captura de notas 
    cout<<"listado de los estudiantes\n";
    for (int i=0;i<5;i++)
    {
    	cout<<(i+1)<<" - "<<estudiantes[i]<<endl;	
	}//fin estudiantes
	
	
	//capturar estudiante
	cout<<"ingrese el codigo de el estudiante....:";
	cin>>cod;
	cout<<"selecciono a "<<estudiantes[cod-1];
	
	cout<<"si es este el estudiante[s] si no otra tecla...:";
	   cin>>conf;
	   
	   while ((conf=="S" || conf=="s") && (reg<3))
	   {
	   	cout<<"ingrese la nota["<<(reg+1)<<"].....:";
	   	cin>>nota;
	   	//asignar notas a la matrix notas
	   	notas[cod-1][reg]=nota;
	   	reg++;
	   }//fin ciclo
	   
	   //imprimir matrix con cambios
	   
	    for(int i=0;i<5;i++)
        {
    	
       	    cout<<(i+1)<<". "<<estudiantes[i]<<"\t";
       	    for(int j=0;j<3;j++)
		   {
		
	             cout<<notas[i][j]<<"\t";
		       
		       }//notas
		        cout<<endl;
	    } //estudiantes<<<
		       
	
	
		 getch();
		return 0;
}//fin main


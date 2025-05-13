#include<iostream>
#include<conio.h>

using namespace std;
//estructura curso
struct curso
{
  int cod_cur;
  char nom_cur[15];	
};

//estructura estudiante
struct estudiante
{
	int cod_est;
	char nom_est[20];
	int edad;
	struct curso cursito;		
} alumno[2];
	
int main()
{

	
 //captura de datos
 cout<<"captura de datos e los estudiantes\n";
 for(int i=0; i<2; i++)

 {
	cout<<"codigo...:";
	cin>>alumno[i].cod_est;
	fflush(stdin);
	cout<<"nombre..:";
	cin.getline(alumno[i].nom_est,20,'\n');
	cout<<"edad......:";
	cin>>alumno[i].edad;
	//captura curso
	cout<<"codigo curso.....:";
	cin>>alumno[i].cursito.cod_cur;
	cout<<"curso...:";
	fflush(stdin);
	cin.getline(alumno[i].cursito.nom_cur,15,'\n');
	cout<<endl; 	
 }
 
 //salida  de datos
 for(int i=0; i<2;i++)
 {
 	cout<<"codigo Estudiante..."<<alumno[i].cod_est<<endl;
 	cout<<"nombre Estudiante..."<<alumno[i].nom_est<<endl;
 	cout<<"edad Estudiante..."<<alumno[i].edad<<endl;
 	cout<<"codigo curso..."<<alumno[i].cursito.cod_cur<<endl;
 	cout<<"nombre curso..."<<alumno[i].cursito.cod_cur<<endl;
 	cout<<"**********************\n";
 }
 
  
	getch();
	return 0;
		
}

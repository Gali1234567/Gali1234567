/************************************
Primer ejercicio - programación avanzada -Estructuras de datos 
Problema: Registro de ususarios en un Gym ,los datos se deben dar al inicio y deben ser exhautivos ,La finalidad es 
imprimir los nombres de los ususarios con registro satisfactorio.

-Datos a solicitar
*nombres
* edad
* genero
* fecha de inscripcion
* hijos
* masa muscular
* plan
* franja horario
* lesiones 
* altura 

-Tips solucion : 
*Para la solucion se recomienda hacer uso de una estructura de datos 

***********************************/
#include <iostream>

using namespace std;

int main()
{
 // se toman 3 lecturas solamente
 // se crea la estructura de datos 
  struct Datospersonas{
       string nombres;
       int edad;
       char genero;
       string fecha_inscripcion;
       int hijos;
       float masa_muscular;
       string plan;
       string franja_horario;
       string lesiones; 
       float altura; 
     
 } ;
 //Bienvenida a la app 
  cout<<"**************" <<endl;
  cout<<"**Bienvenidos al Gym******" <<endl;
  cout<<"**************" <<endl;
 
 // se crean las variables contadores y auxiliares necesarios 
 int i;
 int cantidad_personas ;
 
 // se pide al usuario cuantas personas se van a registrar 
 cout<< "cuantas personas se van a registrar ";
  cin>> cantidad_personas ;
 //Se crea estructura de datos personas 
 //Se crea el vector de personas con la cantidad de personas 
 
 Datospersonas persona[cantidad_personas];
 
 //Se hace un bucle para capturar los datos de la personas 
  cout<<"Ingreso de datos"<<endl;
  
 for(i=0; i< cantidad_personas ;i++){

 // se presenta la pregunta para la captura de cada dato
  cout<< "Ingrese nombre "<<endl;
  cin>> persona[i].nombres ;
  
  cout<< "Ingrese edad "<<endl;
  cin>> persona[i].edad ;
  
  cout<< "Ingrese genero "<<endl;
  cin>> persona[i].genero ;
  
  cout<< "Ingrese fecha de inscripcion "<<endl;
  cin>> persona[i].fecha_inscripcion ;
  
  cout<< "Ingrese hijos "<<endl;
  cin>> persona[i].hijos ;
  
  cout<< "Ingrese masa muscular "<<endl;
  cin>> persona[i].masa_muscular ;
  
  cout<< "Ingrese plan "<<endl;
  cin>> persona[i].plan ;
  
  cout<< "Ingrese franja horario "<<endl;
  cin>> persona[i].franja_horario ;
  
  cout<< "Ingrese lesiones "<<endl;
  cin>> persona[i].lesiones;
  
  cout<< "Ingrese altura "<<endl;
  cin>> persona[i].altura ;
  
 }
  
 //Presentar los usuarios registrados 
 
 cout<<"\n\n\n *****"<<endl;
 cout<< "Usuario registrado satisfactoriamente"<<endl;
 
 for(i=0; i< cantidad_personas ;i++){
 cout<<persona[i].nombres<<endl;
    
}}

/*************************
Fecha: 3-2-2023
Autor: Paula Galindo
Tema: Bibliotecas "fstream"

Problema: 
Se necesita crear una aplicacion que solicite datos de usuarios, 
para posteriormente ser almacenados en un fichero. El almacenamento ha de ser cada dato en una linea.
No se desea o permite que se almacene mas de una palabra por linea(No espacios en blanco).

Solucion: 
*Se hace uso de la biblioteca fstream
*Se crea un TDA para la coleccion de datos
*Se almacen los datos de TDA en el fichero
*Finalmente se leen los datos del fichero y se presentan por pantalla
**************************/


#include<fstream>
#include <iostream>

using namespace std;

//Se hace un TDA simple de captura de nombre, apellido y edad

struct persona{
	string nombre;
	string apellido;
	int edad;
	
};

// Se crea la funcion principal 
int main()  {
	
	//Se declara variables a usar
	int i, j, cantidad_usuarios;
	// Variable auxiliar para cada linea como lectura
	string linea;
	
	//Se crea el fichero con la biblioteca fstream para escritura
	ofstream miarchivo("usuarios.txt");
	
	
	
	//Se hace la bienvenida
	
	cout<<"\n********************\n";
	cout<<"\n***** ESCRITURA-LECTURA DE ARCHIVOS*****\n";
	cout<<"\n********************\n";
	
	
	//Se solicita cantidad de usuarios a ingresar en el fichero
	cout<<"¿Cuantos usuarios desea registrar? : ";
	cin>>cantidad_usuarios;
	
	// Se crea el objeto TDA tipo vector  de tamaño cantidad_usuarios
	persona usuarios[cantidad_usuarios];
	
	
	//Se abre el archivo para escritura (si se puede)
	
	if (miarchivo.is_open()){
		
		//Se crea un bucle para la captura de datos
		//se almacena en el fichero
		
	for (i=0; i < cantidad_usuarios; i++){
		cout<<"\n Ingrese nombre de usuario ["<<i+1<<"]";
		cin>>usuarios[i].nombre;
		miarchivo<<usuarios[i].nombre;
		
		cout<<"\n Ingrese apellido de usuario ["<<i+1<<"]";
		cin>>usuarios[i].apellido;
		miarchivo<<usuarios[i].apellido;
		
		cout<<"\n Ingrese edad de usuario ["<<i+1<<"]";
		cin>>usuarios[i].edad;
		miarchivo<<usuarios[i].edad;
		
	}
		miarchivo.close();
		
	}else{
		cout<<"No se puede abrir el archivo :("<<endl;
		
	}
	
	//Se crea el fichero con la biblioteca fstream para lectura
	ifstream milectura("usuarios.txt");
	
	//Se lee los datos del fichero
	
	if(milectura.is_open()) {
		
		//Se hace un buble para iterar por cada linea a leer
		while (getline(milectura, linea)){
			cout<<linea<<endl;
		}
		milectura.close();
		
	}
	cout<<"Fin del programa con exito";
	
	return 0;
}

/**************************
Autor : Paula Galindo
Taller # 3  10/02/23
Tema : PUNTEROS en C++

*PUNTEROS en C++

***************************/
// Se crea el dominio de la biblioteca Global
#include <iostream>

using namespace std;

int main (){
// Se crea una variable y se le asigna un valor 
int variable_a = 27;
//Se crea un puntero
int*puntero;
// Se señala el puntero a la dirección de la variable 
puntero = &variable_a;
//Se imprime la variable_a
cout<<"la variable tiene el valor :"<<variable_a<<endl;
//Se imprime el puntero
cout<<"valor del puntero :"<< puntero<< endl;
//Se imprime la referencia o dirección
cout<<"la variable tiene el valor :" <<puntero << endl;


}
    


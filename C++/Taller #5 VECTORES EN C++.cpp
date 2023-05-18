/**************************
Autor : Paula Galindo
Taller # 5  08/02/23
Tema : Vectores en C++
Ejercicio vectores en C++

***************************/
// Se crea el dominio de la biblioteca Global
//Se crea la biblioteca que añade las funciones de vectores
#include<iostream>
#include <vector>
using namespace std;
//Se crea la función principal 
int main()
{
    //Se declara el objeto del tipo , vector tipo entero
    vector<int> num;
    int i,j,k ;
    //Se asigna el tamaño 5 al vector y se inicializa en 1
    num.assign(7,4);
    cout<<"\t El tamaño del vector 1 es  \t"<< num.size()<<endl;
    for(i=0; i<num.size();i++)
    cout<<num[i]<<endl;
    //Se le añade al final de vector un valor (push_back TIENE ESA FUNCIÓN)
    num.push_back(8);
    num.push_back(6);

    //Se imprimen los valores del vector 
    for(i=0; i<num.size();i++)
    cout<<num[i]<<endl;
    // Se saca el tamaño del vector 
    cout<<"\t El tamaño del vector es  \t"<< num.size()<<endl;
    
    return 0;
}

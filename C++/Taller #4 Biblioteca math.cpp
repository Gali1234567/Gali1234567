/**************************
Autor : Paula Galindo
Taller # 4  08/02/23
Tema : biblioteca cmath en C++
Ejercicio sobre bibliotecacmath en C++

***************************/
// Se crea el dominio de la biblioteca Global
//Se crea la biblioteca que añade las funciones matemáticas
#include <iostream>
#include<cmath>
using namespace std;
//Se crea la función principal 
int main()
{
    //Se asiganan variables , añadí una cuarta variable para preguntarle al usuario 
    double x1=4.0 ,x2=12.25,x3=0.0121,x4=0;
    //Se toman los valores asignados para sacar su raíz
    cout<<"\n Numero \t raíz cuadrada "<<endl;
    cout<<"\n" <<x1<<"\t Su raiz cuadrada es" << sqrt(x1);
    cout<<"\n" <<x2<<"\t Su raiz cuadrada es" << sqrt(x2);
    cout<<"\n" <<x3<<"\t Su raiz cuadrada es" << sqrt(x3) <<endl;
    
    //Se le solicita al usuario el valor al cual le quiere sacar la raíz
    cout<<"Ingrese el número del cual quiere la raíz"<<endl; 
    cin>> x4;
    cout<<"\n" <<x4<<"\t Su raiz cuadrada es \t " << sqrt(x4) <<endl;
    
    return 0;
}

/**************************
Autor : Paula Galindo
Taller # 3  08/02/23
Tema : tipos de variables y constantes en C++
Ejercicio sobre los tipos funadamentales de datos en C++

*Primitivos en C++

***************************/
// Se crea el dominio de la biblioteca Global

#include <iostream>

using namespace std;
//Se crea la función principal 
int main()
{
    cout<<"\n*****************"<<endl;
    cout<<"\n****TIPOS FUNDAMENTALES EN C++*****"<<endl;
    cout<<"\n*****************"<<endl;
    cout<<"\nTipo de dato \t Numero de Bytes"<<endl;
    cout<<"\n*****************"<<endl;
    
    //El sizeof me muestra la capacidad de memoria que puede tener un tipo de dato
    cout<<"\t char \t"<< sizeof(char)<<endl;
    cout<<"\t short \t"<< sizeof(short)<<endl;
    cout<<"\t int \t"<< sizeof(int)<<endl;
    cout<<"\t long \t"<< sizeof(long)<<endl;
    cout<<"\t float \t"<< sizeof(float)<<endl;
    cout<<"\t double \t"<< sizeof(double)<<endl;
    cout<<"\t long double \t"<< sizeof(long double)<<endl;
    return 0;
}

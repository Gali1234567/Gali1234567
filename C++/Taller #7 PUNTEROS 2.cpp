/**************************
Autor : Paula Galindo
Taller # 3  10/02/23
Tema : PUNTEROS en C++

*PUNTEROS en C++

***************************/
// Se crea el dominio de la biblioteca Global

#include <iostream>
  //Se crea la biblioteca para usar la funcion sqrt
#include<cmath>
   
//Se crea la biblioteca de vector
#include<vector>
//Se crea el dominio de la biblioteca "GLOBAL"
//Se crea un arreglo de 3 pocisiones de tipo float 
using namespace std;
int main(){
float vector[3]; 

cout<<"dijite los elementos del vector";
for(int i=0; i<vector[3]; i++)
cin>>vector[3]; 

//Se crea el puntero del tipo float 
float *puntero; 
//Se imprime la direccion de vada valor del arreglo 
for(int i=0;i<3;i++){ 
cout<<"valor direccion del vector[<<i>>] =" << &vector[i]<<endl; 

} 
 
//Se apunta al vector(primer elemento) 
for( int i=0;i<3;i++){ 
cout<<"valor direccion "<<puntero+i<<endl; 

}
return 0;
}

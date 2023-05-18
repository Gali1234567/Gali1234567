/*************************
Fecha: 17-02-2023
Autor: Paula Galindo
Tema: Taller 02

Problema: 
Se desea hacer un aplicación que genere un conjunto de números aleatorios entre 0 y 
20. En caso que el usuario quiera, se debe presentar un histograma sobre la frecuencia 
de los números del conjunto de números aleatorios. 
La aplicación deberá presentar un menú, que identifique en dos partes: 

a) presentar la generación del conjunto de números aleatorios 

b) presentar el histograma del conjunto de números aleatorios.
**************************/
#include <iostream>
#include <cstdlib>
using namespace std;

int generarNumerosAleatorios(int *numeros, int tamano) {
    for (int i = 0; i < tamano; i++) {
        numeros[i] = rand() % 10; // Generar un número aleatorio entre 0 y 20
    }
}

int imprimirHistograma(int *numeros, int tamano) {
    int frecuencias[10] = {0}; // arreglo de frecuencias
    for (int i = 0; i < tamano; i++) {
        frecuencias[numeros[i]]++; // Incrementar la frecuencia del número
    }
    for (int i = 0; i <= 10; i++) {
        cout << i << ": ";
        for (int j = 0; j < frecuencias[i]; j++) {//Se toma j para saber cuantos asteriscos se añaden a la frcuencia
            cout << "*"; // Imprimir asteriscos para representar la frecuencia
        }
        cout << endl;
    }
}
int main() {
    int tamano;
    cout << "Ingrese la cantidad de numeros a generar: ";
    cin >> tamano;//Así se sabe la cantidad de números que se va a generar 
    int numeros[tamano];//el tamaño de la variable de numeros es lo que está dentro de este arreglo
    bool salir = false;// Se declara para poder dar la opción de salir 
    while (!salir) {
    	
    	//Se crea el menú para el usuario 
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Generar conjunto de numeros aleatorios" << endl;
        cout << "2. Imprimir histograma" << endl;
        cout << "3. Salir" << endl;
        int opcion;
        cin >> opcion;
        switch (opcion) {
            case 1: //Se llama a la función y se imprimen los valores 
                generarNumerosAleatorios(numeros, tamano);
                cout << "Estos son los numeros aleatorios:" << endl;
                for (int i = 0; i < tamano; i++) {
                    cout << numeros[i] << " ";
                }
                cout << endl;
                break;
            case 2://Se llama a la función y se imprime el histograma
                imprimirHistograma(numeros, tamano);
                cout << "Este es el histograma." << endl;
                break;
            case 3:
                salir = true;
                cout << "Usted ha salido del programa" << endl;
                break;
            default:
                cout << "Opción invalida." << endl;
                break;
        }
    }
    return 0;
}

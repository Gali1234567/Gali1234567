/*************************
Fecha: 15-02-2023
Autor: Paula Galindo
Tema: Taller 01

Problema: 
Se desea capturar los datos de los clientes para ser impreso en la factura. Se requiere
crear una estructura de datos, que encapsule los datos de los usuarios. Se requiere que
el uso de la estructura sea a través de punteros. Se requiere imprimir las facturas en
un fichero de texto.
**************************/
#include <iostream>
#include <fstream>
using namespace std;

struct Cliente {
  string nombre;
  string ciudad;
  string telefono;
  float total;
};

int main() {
  // Crear un arreglo dinámico de clientes
  int contadorClientes = 0;
  Cliente *sCliente = new Cliente[10]; 
  // Agregar un cliente al arreglo
  sCliente[contadorClientes].nombre = "Juan";
  sCliente[contadorClientes].ciudad = "Bogota";
  sCliente[contadorClientes].telefono = "32569781";
  sCliente[contadorClientes].total = 2050;
  contadorClientes++;

  // Acceder a los datos del último cliente agregado utilizando el índice "contadorClientes-1"
  cout << "Nombre: " << sCliente[contadorClientes-1].nombre << endl;
  cout << "Ciudad: " << sCliente[contadorClientes-1].ciudad << endl;
  cout << "Telefono: " << sCliente[contadorClientes-1].telefono << endl;
  cout << "Total: " << sCliente[contadorClientes-1].total << endl;

  // Imprimir la factura del último cliente agregado en un fichero de texto
  ofstream archivoFactura;
  archivoFactura.open("factura.txt");
  archivoFactura << "Nombre: " << sCliente[contadorClientes-1].nombre << endl;
  archivoFactura << "Ciudad: " << sCliente[contadorClientes-1].ciudad << endl;
  archivoFactura << "Telefono: " << sCliente[contadorClientes-1].telefono << endl;
  archivoFactura << "Total: " << sCliente[contadorClientes-1].total << endl;
  archivoFactura.close();



  return 0;
}

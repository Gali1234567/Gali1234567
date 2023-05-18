/******************************************************************************
C�rculo , diametro y area

*******************************************************************************/
#include <iostream>
using namespace std;

double pi = 3.1415;
//se declara la clase del c�rculo 
class Circulo {
	public:
    float radio; //se declara el radio 
    //se declara el constructor 
    Circulo(float r) {
        radio = r;
    }
   //se declaran los m�todos para poder encontrar el �rea , per�metro y di�metro
    void area() {
        float area;
        area = pi * radio * radio;
        cout << "El area del circulo es " << area << endl;
    }

    void perimetro() {
        float perimetro;
        perimetro = 2 * pi * radio;
        cout << "El perimetro del circulo es " << perimetro << endl;
    }

    void diametro() {
        float diametro;
        diametro = radio * 2;
        cout << "El diametro del circulo es " << diametro << endl;
    }
};

int main() {
	//se le pide el radio al usuario 
    float radio;
    cout << "Ingrese el radio del circulo: ";
    cin >> radio;
    //Se declara el objeto nuevo
    Circulo circulo(radio);
    //Se llama a los m�todos creados 
    circulo.area();
    circulo.perimetro();
    circulo.diametro();

    return 0;
}

/******************************************************************************
Tri�ngulo altura, perimetro , hipotenusa

*******************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

class Triangulo {
    
        double lado1, lado2, lado3;
    //se declara la clase del triangulo
    public:
        Triangulo(double l1, double l3) {
            lado1 = l1;
            lado2 = 0; // Ya que no se usa, podemos inicializarlo en 0
            lado3 = l3;
        }
       //Se declaran los m�todos para calcular la altura , el per�metro y la hipotenusa con las respectivas f�rmulas 
        double calcularAltura() {
            double s = (lado1 + lado3 + lado3) / 2.0;
            double area = sqrt(s * (s - lado1) * (s - lado3) * (s - lado3));
            double altura = (2 * area) / lado1;
            return altura;
        }

        double calcularPerimetro() {
            double perimetro = lado1 + lado3 + lado3;
            return perimetro;
        }

        double calcularHipotenusa() {
            double hipotenusa = sqrt(lado1 * lado1 + lado3 * lado3);
            return hipotenusa;
        }
};

int main() {
    double l1, l3; //se piden los lados 
    cout << "Ingrese los lados del triangulo: ";
    cin >> l1 >> l3;
    //se declara el objeto nuevo
    Triangulo triangulo(l1, l3);
   
    //se llaman los m�todos 
    double altura = triangulo.calcularAltura();
    double perimetro = triangulo.calcularPerimetro();
    double hipotenusa = triangulo.calcularHipotenusa();

    cout << "La altura del triangulo es: " << altura << endl;
    cout << "El perimetro del triangulo es: " << perimetro << endl;
    cout << "La hipotenusa del triangulo es: " << hipotenusa << endl;

    return 0;
}

/******************************************************************************
Estudiante , Profesor y Persona

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

// Clase base "Persona" de esta estudiante y profesor van a heredar 
class Persona {
    string nombre;
    int edad;

public:
    // Constructor de la clase Persona
    Persona(string n, int e) : nombre(n), edad(e) {}

    // M�todo de presentarse
  void presentarse() {
        cout << "Mi nombre es " << nombre << " y tengo " << edad << " a�os." << endl;
    }
};

// Clase "Profesor" que hereda de "Persona"
class Profesor : public Persona { //profesor hereda lo que esta p�blico en la clase persona 
    string materia;

public:
    // Constructor de la clase Profesor (tiene los m�todos de la base y tambi�n tiene uno propio que es la materia )
    Profesor(string n, int e, string m) : Persona(n, e), materia(m) {}

    // M�todo presentarse de la clase Persona
    void presentarse() {
        cout << "Soy el profesor " << nombre << ", tengo " << edad << " a�os y doy la materia de " << materia << "." << endl;
    }
};

// Clase "Estudiante" que hereda de "Persona"
class Estudiante : public Persona { //estudante hereda lo p�blico de la clase persona 
    int grado;

public:
    // Constructor de la clase Estudiante (tiene los m�todos de la base y tambi�n tiene uno propio que es el grado )
    Estudiante(string n, int e, int g) : Persona(n, e), grado(g) {}

    // M�todo presentarse de la clase base "Persona"
    void presentarse() {
        cout << "Soy el estudiante " << nombre << ", tengo " << edad << " a�os y estoy en " << grado << "� grado." << endl;
    }

    // M�todo que indica si el estudiante puede inscribirse al curso de programaci�n
    bool puedeProgramacion() {
        return grado >= 9;
    }
};

// Funci�n principal "main"
int main() {
    // Creaci�n de objetos de las clases
    Persona persona("Juan", 30);
    Profesor profesor("Pedro", 45, "Matem�ticas");
    Estudiante estudiante("Mar�a", 14, 8);

    // Llamada al m�todo "presentarse" de cada objeto
    persona.presentarse();
    profesor.presentarse();
    estudiante.presentarse();

    // Verificaci�n si el estudiante puede inscribirse al curso de programaci�n y muestra un mensaje correspondiente
    if (estudiante.puedeProgramacion()) {
        cout << "El estudiante " << estudiante.nombre << " puede inscribirse al curso de programaci�n." << endl;
    } else {
        cout << "El estudiante " << estudiante.nombre << " no puede inscribirse al curso de programaci�n." << endl;
    }

    return 0;
}


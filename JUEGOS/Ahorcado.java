import java.util.Scanner;
/* La clase Scanner es parte de la biblioteca estándar de Java y se   ***DEFINICIÓN PARA MÍ
utiliza para leer la entrada del usuario desde la consola .Acá se crea un 
objeto de esa clase para poder leer y procesar la entrada del usuario tiene 
varios métodos que serán usados . */
//Se define la clase ahorcado

public class Ahorcado {
    //Se declara el arreglo de palabras que será usado en el juego
    private static final String[] palabras = {"computadora", "java", "codigo", "atributo", "metodo", "clase", "arreglo"};

    public static void main(String[] args) {
        // Se escoge una palabra aleatoria del arreglo de palabras ,math random es para elegir un número aleatorio
        String palabra = palabras[(int) (Math.random() * palabras.length)];
         // Crear un objeto Scanner para leer la entrada del jugador
        Scanner scanner = new Scanner(System.in);
        //Se crea el número de vidas y se inicializa
        int vidas = 6;
        String letrasAdivinadas = "";
        //Bucle para determinar mientras que no se acaben las vidas 
        while (vidas > 0) {
            /*Se llama el método obtener palabra y se imprime la palabra con las letras 
            actualizada de acuerdo a lo que puso el usuario*/
            System.out.println("La palabra es: " + obtenerPalabra(palabra, letrasAdivinadas));
            System.out.println("Ingresa una letra: ");
            /*scanner.next() es un método de scanner que permite almacenar la letra que puso el usuario 
            para poder revisar si está en la palabra*/
            String letra = scanner.next();
//Se revisa si la letra ingresada está en la palabra si es así se agrega a la letras adivinadas
            if (palabra.contains(letra)) {
                letrasAdivinadas += letra;
//En cada intento revisa si el usuario ya adivinó toda la palabra 
                if (letrasAdivinadas.length() == palabra.length()) {
                    System.out.println("¡Felicidades! ¡Adivinaste la palabra!");
                    break;
                }
            } else {
//Si el caso es diferente quiere decir que no adivinó una letra portanto se quita una vida
                vidas--;
//Se llama el método que tiene las vidas como parámtro 
                mostrarAhorcado(vidas);
                System.out.println("Incorrecto. Te quedan " + vidas + " vidas.");
            }
        }
/*Al terminar el juego si aún tiene vidas quiere decir que adivinó la palabra de lo contrario se 
se muestra que perdió junto con la palabra correcta*/
        if (vidas > 0) {
            System.out.println("¡Ganaste!");
        } else {
            System.out.println("¡Perdiste! La palabra era: " + palabra);
        }

        scanner.close();//se cierra la consola del usuario
    }
    
  /*Método para ir mostrando la palabra con las letras adivinadas : es un bucle que evalúa el 
  condicional para determinar si la letra que pone el usuario está presente en las letras adivinadas 
  (letrasAdivinadas). Si es así, se agrega la letra para mostrar al usuario.De lo contrario, se 
  agrega un guion bajo a la pista indicando que esa letra aún no hace parte de la palabra*/
    
    private static String obtenerPalabra(String palabra, String letrasAdivinadas) {
        StringBuilder pista = new StringBuilder();
        for (char c : palabra.toCharArray()) {
            if (letrasAdivinadas.contains(String.valueOf(c))) {
                pista.append(c);
            } else {
                pista.append("_");
            }
        }
        return pista.toString();
    }
/* método que recibe el número de vidas restantesy muestra por consola la representación
gráfica del ahorcado correspondiente .*/
    private static void mostrarAhorcado(int vidas) {
        String[] ahorcado = {
                "  +---+",
                "  |   |",
                (vidas < 6 ? "  O   |" : "      |"),
                (vidas < 4 ? " /|\\  |" : (vidas < 5 ? " /|   |" : "      |")),
                (vidas < 2 ? " / \\  |" : (vidas < 3 ? " /    |" : "      |")),
                "      |",
                "========="
        };

        for (String line : ahorcado) {
            System.out.println(line);
        }
    }
}

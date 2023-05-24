import java.util.ArrayList;
import java.util.Scanner;
//Se declara la clase abstracta con su respectivo constructor , será inicializada en las clases hijas 
abstract class ProductoElectronico {
    protected String nombre;
    protected double precio;
    protected int garantia;

    public ProductoElectronico(String nombre, double precio, int garantia) {
        this.nombre = nombre;
        this.precio = precio;
        this.garantia = garantia;
    }
//métodos get correspondientes 
    public String getNombre() {
        return nombre;
    }

    public double getPrecio() {
        return precio;
    }

    public int getGarantia() {
        return garantia;
    }
//método cargar solicitado **todos se inicializan en las hijas 
    public abstract void cargar();
}
//Clase hija "Celular" junto a sus atributitos creados y constructor 
class Celular extends ProductoElectronico {
    private String modelo;
    private String sistemaOperativo;

    public Celular(String nombre, double precio, int garantia, String modelo, String sistemaOperativo) {
        super(nombre, precio, garantia);
        this.modelo = modelo;
        this.sistemaOperativo = sistemaOperativo;
    }
//Método de cargar  
    public void cargar() {
        System.out.println("Cargando el celular " + getNombre() + " - Modelo: " + modelo);
        // Lógica específica de carga para el celular
    }
//Métodos para enviar un mensaje y tomar foto
    public void enviarMensaje() {
        System.out.println("Enviando un mensaje con el celular " + getNombre() + " - Modelo: " + modelo);
        
    }

    public void tomarFoto() {
        System.out.println("Tomando una foto con el celular " + getNombre() + " - Modelo: " + modelo);
        
    }
}
//Clase hija "Computadora" junto a sus atributitos creados y constructor 
class Computadora extends ProductoElectronico {
    private String marca;
    private int capacidadRAM;

    public Computadora(String nombre, double precio, int garantia, String marca, int capacidadRAM) {
        super(nombre, precio, garantia);
        this.marca = marca;
        this.capacidadRAM = capacidadRAM;
    }
//Método cargar 
    public void cargar() {
        System.out.println("Cargando la computadora " + getNombre() + " - Marca: " + marca);
    }
//Método para mostrar notificaciones 
    public void mostrarNotificaciones() {
        System.out.println("Mostrando notificaciones en la computadora " + getNombre() + " - Marca: " + marca);
        // Lógica específica para mostrar notificaciones en la computadora
    }
//Método para aumentar ram
    public void aumentarRAM(int cantidad) {
        capacidadRAM += cantidad;
        System.out.println("Se ha aumentado la RAM de la computadora " + getNombre() + " - Marca: " + marca + " - Nueva capacidad de RAM: " + capacidadRAM + " GB");
    }
}
//SE CREA EL MAIN ,se instancia la lista correpondiente para que guarde los productos creados 
public class Main {
    public static void main(String[] args) {
        ArrayList<ProductoElectronico> productos = new ArrayList<>();
//Se crea el menú 
Scanner scanner = new Scanner(System.in); //LEER LO QUE PONE EL USUARIO
        int opcion;

        do {
            System.out.println("----- MENÚ -----");
            System.out.println("1. Crear celular");
            System.out.println("2. Crear computadora");
            System.out.println("3. Recorrer lista de productos");
            System.out.println("4. Salir");
            System.out.print("Ingrese una opción: ");
            opcion = scanner.nextInt();

            switch (opcion) {
                case 1:
                    crearCelular(productos, scanner);
                    break;
                case 2:
                    crearComputadora(productos, scanner);
                    break;
                case 3:
                    recorrerLista(productos);
                    break;
                case 4:
                    System.out.println("Saliendo del programa...");
                    break;
                default:
                    System.out.println("Opción inválida. Intente nuevamente.");
            }

            System.out.println();
        } while (opcion != 4);
    }
// De acuerdo a lo elegido se le va a pedir los datos al usuario para agregar el objeto según su clase 
    private static void crearCelular(ArrayList<ProductoElectronico> productos, Scanner scanner) {
        System.out.println("----- CREAR CELULAR -----");
        System.out.print("Ingrese el nombre: ");
        String nombre = scanner.next();
        System.out.print("Ingrese el precio: ");
        double precio = scanner.nextDouble();
        System.out.print("Ingrese la garantía (en años): ");
        int garantia = scanner.nextInt();
        System.out.print("Ingrese el modelo: ");
        String modelo = scanner.next();
        System.out.print("Ingrese el sistema operativo: ");
        String sistemaOperativo = scanner.next();

        productos.add(new Celular(nombre, precio, garantia, modelo, sistemaOperativo));
        System.out.println("Celular creado y agregado a la lista.");
    }

    private static void crearComputadora(ArrayList<ProductoElectronico> productos, Scanner scanner) {
        System.out.println("----- CREAR COMPUTADORA -----");
        System.out.print("Ingrese el nombre: ");
        String nombre = scanner.next();
        System.out.print("Ingrese el precio: ");
        double precio = scanner.nextDouble();
        System.out.print("Ingrese la garantía (en años): ");
        int garantia = scanner.nextInt();
        System.out.print("Ingrese la marca: ");
        String marca = scanner.next();
        System.out.print("Ingrese la capacidad de RAM: ");
        int capacidadRAM = scanner.nextInt();

        productos.add(new Computadora(nombre, precio, garantia, marca, capacidadRAM));
        System.out.println("Computadora creada y agregada a la lista.");
    }
//Se recorre la lista de profuctos se usa instance of para determibar si es celular o computadora 
    private static void recorrerLista(ArrayList<ProductoElectronico> productos) {
        if (productos.isEmpty()) {
            System.out.println("La lista de productos está vacía.");
        } else {
            System.out.println("----- LISTA DE PRODUCTOS -----");
            for (ProductoElectronico producto : productos) {
                System.out.println("Nombre: " + producto.getNombre());
                System.out.println("Precio: $" + producto.getPrecio());
                System.out.println("Garantía: " + producto.getGarantia() + " años");
                producto.cargar();

                if (producto instanceof Celular) {
                    ((Celular) producto).enviarMensaje();
                    ((Celular) producto).tomarFoto();
                } else if (producto instanceof Computadora) {
                    ((Computadora) producto).mostrarNotificaciones();
                    ((Computadora) producto).aumentarRAM(4);
                }

//Se añaden/crean los productos de su respectiva clase 
        productos.add(new Celular("iPhone", 1000.0, 1, "X", "iOS"));
        productos.add(new Celular("Samsung", 800.0, 2, "S21", "Android"));
        productos.add(new Computadora("Dell", 1500.0, 3, "Insp", 8));
        productos.add(new Computadora("Asus", 1200.0, 2, "Ps", 16));

// En el bucle recorre el ArrayList productos y se obtiene cada objeto de tipo ProductoElectronico 
//se imprimen en pantalla el nombre, precio y garantía del producto
        for (ProductoElectronico producto : productos) {
            System.out.println("Nombre: " + producto.getNombre());
            System.out.println("Precio: $" + producto.getPrecio());
            System.out.println("Garantía: " + producto.getGarantia() + " años");
            producto.cargar();
// Se utiliza instanceof para identificar si un objeto es una instancia de Celular o Computadora y llamar a los métodos de la clase que corresponda 
            if (producto instanceof Celular) {
                ((Celular) producto).enviarMensaje();
                ((Celular) producto).tomarFoto();
            } else if (producto instanceof Computadora) {

                ((Computadora) producto).mostrarNotificaciones();
                ((Computadora) producto).aumentarRAM(4);
            }

            System.out.println();
        }
            }
        }
    }

    


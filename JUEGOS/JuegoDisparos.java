import javax.swing.*; // Esta librería proporciona componentes y clases para crear interfaces gráficas
import java.awt.*; //Métodos de la interfaz gráfica
import java.awt.event.MouseAdapter; // Detectar los clicks que realiza el usuario
import java.awt.event.MouseEvent; //Ubica el click del usuario
import java.util.ArrayList;//listas de arreglos
import java.util.List;//Listas en general
import java.util.Random;// Genera números aleatorios ,en este caso se hacen las coordenadas aleatorias de los puntos
//Se declara la clase del juego junto con la posibilidad de mostar una interfaz
public class JuegoDisparos extends JFrame {
    //Se declaran los atributos que son el tamaño de la interfaz gráfica , el número de vidas , el tiempo en el que salen los nuevos objetivos , el puntaje
    private final int ANCHO = 400;
    private final int ALTO = 400;
    private final int TIEMPO_NUEVO_OBJETIVO = 1000;
    private final int VIDAS_INICIALES = 3;

    private int puntaje;
    private int vidas;
    private List<Objetivo> objetivos;
    private Random random;

    public JuegoDisparos() {
        setTitle("Juego de Disparos");
        setSize(ANCHO, ALTO);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
        setLocationRelativeTo(null);
       //se inicializa el valor de puntaje , de las vidas iniciales y la lista de objetivos junto su obicación que se dará de manera aleatoria
        puntaje = 0;
        vidas = VIDAS_INICIALES;
        objetivos = new ArrayList<>();
        random = new Random();
        // Se usa MouseAdapter para detectar los clics del jugador
        addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                int mouseX = e.getX();
                int mouseY = e.getY();
//se recorre la lista de objetivos si se detecta que se hizo un click se va a eliminar el objetivo y se va a sumar puntaje
                boolean objetivoImpactado = false;
                for (int i = 0; i < objetivos.size(); i++) {
                    Objetivo objetivo = objetivos.get(i);
                    if (objetivo.contienePunto(mouseX, mouseY)) {
                        puntaje++;
                        objetivos.remove(i);
                        objetivoImpactado = true;
                        break;
                    }
                }
//Se aclara que si no se impacta se resta una vida
                if (!objetivoImpactado) {
                    vidas--;
                    if (vidas == 0) { // Si se acaban las vidas se pierde  **** Apunte para mí (Se imprime así por la interfaz)
                        JOptionPane.showMessageDialog(null, "¡Perdiste! Puntaje final: " + puntaje);
                        System.exit(0); //Salir si pierde
                    }
                }
            }
        });
       //Se hace un temporizador para ir creando objetivos                   ***revisar más a profundo los timers
        Timer timer = new Timer(TIEMPO_NUEVO_OBJETIVO, e -> generarObjetivoAleatorio());
        timer.start();

        setVisible(true);
    }

    private void generarObjetivoAleatorio() { //Se generan las coordenadas aleatorias para los objetivos
        int radioObjetivo = 15;
        int x = random.nextInt(ANCHO - 2 * radioObjetivo) + radioObjetivo;
        int y = random.nextInt(ALTO - 2 * radioObjetivo) + radioObjetivo;
        Objetivo objetivo = new Objetivo(x, y, radioObjetivo);
        objetivos.add(objetivo);
        repaint(); //Se vuelve a dibujar el juego con los objetivos nuevos
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);
       //Se pon de negro el fondo de la pantalla , se establecen los respctivos colores de cada cosa
        g.setColor(Color.BLACK);
        g.fillRect(0, 0, ANCHO, ALTO);
       //Acá se dibuja cada objetivo
        g.setColor(Color.RED);
        for (Objetivo objetivo : objetivos) { //Se obtienen las cordenadas generadas aleatoriamente
            g.fillOval(objetivo.getX() - objetivo.getRadio(), objetivo.getY() - objetivo.getRadio(),
                    2 * objetivo.getRadio(), 2 * objetivo.getRadio());
        }
//Acá se muestran las vidas y el puntaje con la fuente de letra seleccionada
        g.setColor(Color.WHITE);
        g.setFont(new Font("Arial", Font.BOLD, 16));
        g.drawString("Puntaje: " + puntaje, 10, 20);
        g.drawString("Vidas: " + vidas, 10, 40);
    }

    public static void main(String[] args) { //Se llama el main
        SwingUtilities.invokeLater(JuegoDisparos::new);//Permite que la interfaz funcione
    }

    private static class Objetivo { //clase  estática que representa un objetivo en el juego
        private int x;
        private int y;
        private int radio;

        public Objetivo(int x, int y, int radio) { //Constructor que inicializa los atributos de los objtivos
            this.x = x;
            this.y = y;
            this.radio = radio;
        }

        public int getX() {  //GETTERS Y SETTERS PARA OBTENER ATRIBUTOS
            return x;
        }

        public int getY() {
            return y;
        }

        public int getRadio() {
            return radio;
        }

        public boolean contienePunto(int x, int y) { // verifica el click sacando el tamaño del objetivo para saber si fue dentro o fuera
            int distanciaX = x - this.x;
            int distanciaY = y - this.y;
            double distancia = Math.sqrt(distanciaX * distanciaX + distanciaY * distanciaY);
            return distancia <= radio;
        }
    }
}

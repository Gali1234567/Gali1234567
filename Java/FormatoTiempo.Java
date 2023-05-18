// ejercicio 3 FormatoTiempo.java
import java.util.Calendar;
import java.util.Formatter; 
import java.text.SimpleDateFormat;
import java.util.Date;

public class FormatoTiempo{
  public static void main(String args[]){
    //formato fecha
    Formatter fecha = new Formatter();
    Calendar cal = Calendar.getInstance();
    fecha= new Formatter();
    fecha.format("%tB,%tb,%tm",cal,cal,cal);
    //formato hora
    Date hora =new Date();
    String strFormatoHora= "HH:mm:ss a";
    SimpleDateFormat forma =new SimpleDateFormat(strFormatoHora);
    System.out.print("Presentacion 1 de fecha y hora ");// se imprime 
    System.out.println(fecha + "" +forma.format(hora)+ "\n"); 

      //Otra forma 
      fecha.format("%tc",cal);
    System.out.print("Presentacion 2 de fecha y hora ");// se imprime 
    System.out.println(fecha + "\n");

    //Otra forma 
    Date d =new Date();
    System.out.print("Presentacion 3 de fecha y hora ");// se imprime 
    System.out.println(d.toString());
    
}
}

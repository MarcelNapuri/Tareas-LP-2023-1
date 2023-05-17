package JavaHack;

import java.util.Scanner;

public class JavaHack {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.print("Ingrese un nombre: ");
        String nombre = input.nextLine();
        Jugador jugador = new Jugador(nombre);
        jugador.verEstadisticas();

        System.out.println("Ingrese el alto del mapa : ");
        int alto = input.nextInt();
        System.out.println("Ingrese el ancho del mapa : ");
        int ancho = input.nextInt();


        Mundo mundo = new Mundo(alto, ancho);
        mundo.reiniciarPosicion(jugador);

        System.out.println("--------------------------");
        mundo.mostrar();

        input.close();
    }
}

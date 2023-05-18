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



        while (jugador.getHp() > 0) {
            System.out.println("--------------------------");
            mundo.mostrar();
            System.out.println("--------------------------");
            System.out.println("¿Qué acción deseas realizar?");
            System.out.println("1. Ver estadísticas");
            System.out.println("2. Mover");
            System.out.println("3. Ver inventario");
            int opcion = input.nextInt();

            switch (opcion) {
                case 1:
                    jugador.verEstadisticas();
                    break;
                
                case 2:
                    System.out.println("Ingrese hacia donde se quiere mover:");
                    /* 
                    System.out.print("coordenada x: ");
                    int x = input.nextInt();
                    System.out.print("coordenada y:");
                    int y = input.nextInt();
                    */
                    String direccion = input.next(); 
                    mundo.moverJugador(jugador, direccion);
                    break;

                case 3:
                    jugador.verInventario();
                    break;
                    
                default:
                    System.out.println("opcion invalida");
                    break;
            }
        }



        input.close();
    }
}

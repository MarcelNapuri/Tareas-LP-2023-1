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
            if (mundo.getEnemigos() <= 0) {
                System.out.println("Felicidades, has derrotado a todos los enemigos de esta zona\n ¿Quieres continuar? presiona cualquier tecla para continuar");
                input.nextLine();
                mundo.nuevoNivel();
                mundo.reiniciarPosicion(jugador);
            }            
            System.out.println("--------------------------\n Enemigos en el mapa: " + mundo.getEnemigos());
            mundo.mostrar();
            System.out.println("--------------------------");

            System.out.println("¿Qué acción deseas realizar?");
            System.out.println("1. Ver estadísticas");
            System.out.println("2. Mover");
            System.out.println("3. Ver inventario");
            System.out.println("4. Salir del Juego");
            int opcion = input.nextInt();

            input.nextLine();

            switch (opcion) {
                case 1:
                    jugador.verEstadisticas();
                    break;
                
                case 2:
                    System.out.println("Ingrese hacia donde se quiere mover:\n(arriba, abajo, derecha, izquierda)");
                    String direccion = input.nextLine(); 
                    mundo.moverJugador(jugador, direccion, input);
                    break;

                case 3:
                    jugador.verInventario();
                    break;
                
                case 4:
                    System.out.println("Gracias por jugar");
                    jugador.setHp(0);
                    break;

                default:
                    System.out.println("opcion invalida");
                    break;
            }
        }
        input.close();
    }
}

package JavaHack;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class Mundo{
    private int nivel;
    private int alto;
    private int ancho;
    private int enemigos;
    private List<List<Visible>> mapa;
    private int x;
    private int y;

    /**
     * Constructor de la clase Mundo, forma el mapa que se vera por pantalla.
     * los atributos X e Y sirven para mover al personaje por el mundo
     * @param alto: alto del mapa
     * @param ancho: ancho del mapa
     */
    public Mundo(int alto,int ancho){
        this.nivel = 1;    
        this.alto = alto;
        this.ancho = ancho;
        this.enemigos = 0;      
        this.x = 0;
        this.y = 0;
        this.mapa = new ArrayList<>();
        for (int i = 0; i < alto; i++) {
            List<Visible> fila = new ArrayList<>();
            for (int j = 0; j < ancho; j++) {
                double r = Math.random();
                if (r <= Math.min(0.05 + 0.01 * getNivel(), 20)) {
                    if (Math.random() < 0.5) {
                        // Crear un objeto Equipamiento aleatorio
                        Random random = new Random();
                        if (random.nextInt(3) + 1 == 1 ) { //Armadura

                            String [] armaduras = {"Armadura de bronce" , "Armadura de plata" , "Armadura de oro"};
                            Random randomArm = new Random();
                            int indice = randomArm.nextInt(armaduras.length); 
                            fila.add(new Equipamiento('e' , armaduras[indice] , "Armadura" , getNivel()*random.nextInt(15 - 3 + 1) + 3,getNivel()*random.nextInt(15 - 3 + 1) + 3 ));
                        }
                        else if(random.nextInt(3) + 1 == 2 ){ //Botas
                            String [] botas = {"Botas de bronce" , "Botas de plata" , "Botas de oro"};
                            Random randomBot = new Random();
                            int indice = randomBot.nextInt(botas.length); 
                            fila.add(new Equipamiento('e' , botas[indice] , "Botas" , getNivel()*random.nextInt(15 - 3 + 1) + 3,getNivel()*random.nextInt(15 - 3 + 1) + 3 ));
                        }
                        else{ //Amuleto
                            String [] amuletos = {"Fuego de cristal","Manzana dorada" , "Sellos espirituales" , "Dientes de dragon" , "Lycoris"};
                            Random randomArm = new Random();
                            int indice = randomArm.nextInt(amuletos.length); 
                            fila.add(new Equipamiento('e' , amuletos[indice] , "Amuletos" , getNivel()*random.nextInt(15 - 3 + 1) + 3,getNivel()*random.nextInt(15 - 3 + 1) + 3 ));
                        }

                    } else {
                        // Crear un objeto Arma aleatorio
                        fila.add(new Arma('a'));
                    }
                    
                } else if (r > Math.min(0.05 + 0.01 * getNivel(), 20) && r <= Math.min(0.2 + 0.01 * getNivel(), 55)) {
                    fila.add(new Personaje(getNivel()*5 + 80 ,getNivel()));     //enemigo
                    enemigos+=1;
                } else {
                    Visible vacio = new CasillaVacia(); //casilla vacoa
                    fila.add(vacio);
                }
            }
            mapa.add(fila);  
        }
        this.mapa.get(this.y).set(this.x, null);
    }

    /**
     * Muestra por pantalla el Mundo creado
     */
    public void mostrar() {
        for (int i = 0; i < alto; i++) {
            for (int j = 0; j < mapa.get(i).size(); j++) {
                Visible v = mapa.get(i).get(j);
                char c = (v != null) ? v.getRepresentacion() : ' ';
                System.out.print(" [" + c + "] ");
            }
            System.out.println(); // Agrega un salto de línea después de cada fila
        }
    }
    
    /**
     * Crea un nuevo nivel, aumentando el nivel del mundo y reiniciando los objetos del mapa
     */
    public void nuevoNivel() {
        setNivel(getNivel() + 1);
        setEnemigos(0);
        mapa = new ArrayList<>();
        for (int i = 0; i < alto; i++) {
            List<Visible> fila = new ArrayList<>();
            for (int j = 0; j < ancho; j++) {
                double r = Math.random();
                if (r <= Math.min(0.05 + 0.01 * getNivel(), 20)) {
                    if (Math.random() < 0.5) {
                        // Crear un objeto Equipamiento aleatorio
                        Random random = new Random();
                        if (random.nextInt(3) + 1 == 1 ) { //Armadura

                            String [] armaduras = {"Armadura de bronce" , "Armadura de plata" , "Armadura de oro"};
                            Random randomArm = new Random();
                            int indice = randomArm.nextInt(armaduras.length); 
                            fila.add(new Equipamiento('e' , armaduras[indice] , "Armadura" , getNivel()*random.nextInt(15 - 3 + 1) + 3,getNivel()*random.nextInt(15 - 3 + 1) + 3 ));
                        }
                        else if(random.nextInt(3) + 1 == 2 ){ //Botas
                            String [] botas = {"Botas de bronce" , "Botas de plata" , "Botas de oro"};
                            Random randomBot = new Random();
                            int indice = randomBot.nextInt(botas.length); 
                            fila.add(new Equipamiento('e' , botas[indice] , "Botas" , getNivel()*random.nextInt(15 - 3 + 1) + 3,getNivel()*random.nextInt(15 - 3 + 1) + 3 ));
                        }
                        else{ //Amuleto
                            String [] amuletos = {"Fuego de cristal","Manzana dorada" , "Sellos espirituales" , "Dientes de dragon" , "Lycoris"};
                            Random randomArm = new Random();
                            int indice = randomArm.nextInt(amuletos.length); 
                            fila.add(new Equipamiento('e' , amuletos[indice] , "Amuletos" , getNivel()*random.nextInt(15 - 3 + 1) + 3,getNivel()*random.nextInt(15 - 3 + 1) + 3 ));
                        }

                    } else {
                        // Crear un objeto Arma aleatorio
                        fila.add(new Arma('a'));
                    }
                    
                } else if (r > Math.min(0.05 + 0.01 * getNivel(), 20) && r <= Math.min(0.2 + 0.01 * getNivel(), 55)) {
                    fila.add(new Personaje(getNivel()*5 + 80 ,getNivel()));     //enemigo
                    enemigos+=1;
                } else {
                    Visible vacio = new CasillaVacia(); //casilla vacoa
                    fila.add(vacio);
                }
            mapa.add(fila);
            }
            setMapa(mapa);
        }
    }
    
    /**
     * Reinicia al jugador a la posicion (0,0)
     * @param jugador: jugador que se mueve a (0,0)
     */
    public void reiniciarPosicion(Jugador jugador){
        this.mapa.get(this.y).set(this.x, null);
        this.mapa.get(0).set(0,jugador);
        this.x = 0;
        this.y = 0;
    }

    /**
     * Mueve al jugador a una casilla, usa los atributos x e y para moverse por el mapa.
     * Dependiendo donde vaya el jugador, es decir, a una casilla vacia, hacia un enemigo o a un objeto, ejecutara 
     * determinadas acciones
     * @param jugador: jugador que se mueve
     * @param direccion: direccion que se mueve el jugador
     * @param input: input que sirve para el combate entre personajes
     */
    public void moverJugador(Jugador jugador, String direccion, Scanner input) {
        int nuevaX = getX();
        int nuevaY = getY();
    
        // Calcular las nuevas coordenadas según la dirección
        if (direccion.equalsIgnoreCase("arriba")) {
            nuevaY--;
        } else if (direccion.equalsIgnoreCase("abajo")) {
            nuevaY++;
        } else if (direccion.equalsIgnoreCase("izquierda")) {
            nuevaX--;
        } else if (direccion.equalsIgnoreCase("derecha")) {
            nuevaX++;
        } else {
            System.out.println("Dirección inválida");
            return;
        }
    
        if (nuevaX >= 0 && nuevaX < ancho && nuevaY >= 0 && nuevaY < alto) {
            if (mapa.get(nuevaY).get(nuevaX) instanceof CasillaVacia) {
                this.mapa.get(getY()).set(getX(), null);
                this.mapa.get(getY()).set(getX(), new CasillaVacia());
                this.mapa.get(nuevaY).set(nuevaX, jugador);
                setPosicion(nuevaX, nuevaY);

            }else if (mapa.get(nuevaY).get(nuevaX) instanceof Personaje) {
                Personaje enemigo = (Personaje)mapa.get(nuevaY).get(nuevaX);
                System.out.println("enemigo encontrado");
                boolean flag = jugador.combate(jugador, enemigo, input);
                if(flag == true){
                    jugador.ganarXp(10*(getAlto() + getAncho()) /(1 - getEnemigos()/getAncho()*getAlto()));
                    System.out.print("ingrese cualquier tecla para continuar : ");
                    setEnemigos(getEnemigos() - 1);
                    jugador.setHp(jugador.getHp() + 30);
                    input.nextLine();
                } 
                this.mapa.get(getY()).set(getX(), null);
                this.mapa.get(getY()).set(getX(), new CasillaVacia());
                this.mapa.get(nuevaY).set(nuevaX, jugador);
                setPosicion(nuevaX, nuevaY);

            }else if (mapa.get(nuevaY).get(nuevaX) instanceof Item) {
                Item item = (Item)mapa.get(nuevaY).get(nuevaX);
                System.out.println("Item encontrado: " + item.getNombre());
                System.out.println("¿Deseas recoger el item? (s/n)");
                String respuesta = input.next();

                if (respuesta.equalsIgnoreCase("s")) {
                    if (item instanceof Arma) {
                        Arma arma = (Arma)item;
                        jugador.getInventario().add(arma);
                        System.out.println("Arma recogida y guardada en el inventario");
                        System.out.println(arma.getNombre() + "\n Fuerza: " + arma.getMul_str() + "\n Inteligencia: " + arma.getMul_int());
                        jugador.equipar(arma);
                    }
                    else if (item instanceof Equipamiento) {
                        Equipamiento equipo = (Equipamiento)item;
                        jugador.getInventario().add(equipo);
                        System.out.println("Objeto recogido y guardado en el inventario");
                        System.out.println(equipo.getNombre() + "\n Fuerza: " + equipo.getStr() + "\n Inteligencia: " + equipo.getIntel());
                        jugador.equipar(equipo);
                    }
                }
                else{
                    System.out.println("No se ha recogido el item");
                }


            } else {
                System.out.println("Error, no se puede mover al jugador");
            }
        } else {
            System.out.println("Fuera de la pantalla");
        }
    }
    
    /**
     * Coloca nuevas coordenadas a X e Y
     * @param x: coordenada x
     * @param y: coordenada y
     */
    public void setPosicion(int x , int y){
        this.x = x;
        this.y = y;
    }

    public int getNivel() {
        return nivel;
    }
    public void setNivel(int nivel) {
        this.nivel = nivel;
    }
    public int getAlto() {
        return alto;
    }
    public void setAlto(int alto) {
        this.alto = alto;
    }
    public int getAncho() {
        return ancho;
    }
    public void setAncho(int ancho) {
        this.ancho = ancho;
    }
    public int getEnemigos() {
        return enemigos;
    }
    public void setEnemigos(int enemigos) {
        this.enemigos = enemigos;
    }
    public List<List<Visible>> getMapa() {
        return mapa;
    }
    public void setMapa(List<List<Visible>> mapa) {
        this.mapa = mapa;
    }

    public int getX(){
        return x;
    } 

    public int getY(){
        return y;
    }
    


    
}

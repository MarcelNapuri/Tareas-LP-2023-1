package JavaHack;

import java.util.ArrayList;
import java.util.List;

public class Mundo{
    private int nivel;
    private int alto;
    private int ancho;
    private int enemigos;
    private List<List<Visible>> mapa;
    private int x;
    private int y;


    public Mundo(int alto,int ancho){
        this.nivel = 1;    //puede cambiar
        this.alto = alto;
        this.ancho = ancho;
        this.enemigos = 0;      //puede cambiar
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
                        fila.add(new Equipamiento("Nombre del equipamiento", 'r'));

                    } else {
                        // Crear un objeto Arma aleatorio
                        fila.add(new Arma("Nombre del arma", 1.5f, 0.5f, 'a'));
                    }
                    
                } else if (r > Math.min(0.05 + 0.01 * getNivel(), 20) && r <= Math.min(0.2 + 0.01 * getNivel(), 55)) {
                    fila.add(new Personaje(getNivel()*5 + 80 ,getNivel()));
                    enemigos+=1;
                } else {
                    Visible vacio = new CasillaVacia();
                    fila.add(vacio);
                }
            }
            mapa.add(fila);
            
        }
        
    }

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
                        fila.add(new Equipamiento("Nombre del equipamiento", 'r'));

                    } else {
                        // Crear un objeto Arma aleatorio
                        fila.add(new Arma("Nombre del arma", 1.5f, 0.5f, 'a'));
                    }
                    
                } else if (r > Math.min(0.05 + 0.01 * getNivel(), 20) && r <= Math.min(0.2 + 0.01 * getNivel(), 55)) {
                    fila.add(new Personaje(getNivel()*5 + 80 ,getNivel()));
                    enemigos+=1;
                } else {
                    Visible vacio = new CasillaVacia();
                    fila.add(vacio);
                }
            }
            mapa.add(fila);
        }
        setMapa(mapa);
    }
    
    public void reiniciarPosicion(Jugador jugador){
        this.mapa.get(this.y).set(this.x, null);
        this.mapa.get(0).set(0,jugador);
        this.x = 0;
        this.y = 0;
    }
    /* 
    public void moverJugador(Jugador jugador, int x, int y) {
        // Verificar si la nueva posición está dentro del mapa
        if (x >= 0 && x < ancho && y >= 0 && y < alto) {

            if (mapa.get(y - 1).get(x - 1) instanceof CasillaVacia) {
                this.mapa.get(getY()).set(getX(), null);      
                this.mapa.get(y -1).set(x - 1, jugador);
                setPosicion(x -1 , y - 1);
            }
            else{
                System.out.println("Error, no se puede mover al jugador");
            }
    
        } 
        else{
            System.out.println("Fuera de la pantalla");
        }
    }
    */
    public void moverJugador(Jugador jugador, String direccion) {
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
    
        // Verificar si la nueva posición está dentro del mapa
        if (nuevaX >= 0 && nuevaX < ancho && nuevaY >= 0 && nuevaY < alto) {
            if (mapa.get(nuevaY).get(nuevaX) instanceof CasillaVacia) {
                this.mapa.get(getY()).set(getX(), null);
                this.mapa.get(getY()).set(getX(), new CasillaVacia());
                this.mapa.get(nuevaY).set(nuevaX, jugador);
                setPosicion(nuevaX, nuevaY);
            } else {
                System.out.println("Error, no se puede mover al jugador");
            }
        } else {
            System.out.println("Fuera de la pantalla");
        }
    }
    
    

    

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

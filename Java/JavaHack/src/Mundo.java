import java.util.ArrayList;
import java.util.List;

public class Mundo{
    private int nivel;
    private int alto;
    private int ancho;
    private int enemigos;
    private List<List<Visible>> mapa;


    public Mundo(int alto,int ancho){
        this.nivel = 1;    //puede cambiar
        this.alto = alto;
        this.ancho = ancho;
        this.enemigos = 1;      //puede cambiar
        this.mapa = new ArrayList<List<Visible>>();
        
    }

    public void mostrar() {
        for (int i = 0; i < alto; i++) {
            for (int j = 0; j < ancho; j++) {
                char c = mapa.get(i).get(j).getRepresentacion();
                System.out.print(c);
            }
            
        }
    }

    public void nuevoNivel() {
        this.nivel++;
        mapa = new ArrayList<>();
        for (int i = 0; i < alto; i++) {
            List<Visible> fila = new ArrayList<>();
            for (int j = 0; j < ancho; j++) {
                // Agregar entidades aleatorias al mapa
                
            }
            mapa.add(fila);
        }
    
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

    
}

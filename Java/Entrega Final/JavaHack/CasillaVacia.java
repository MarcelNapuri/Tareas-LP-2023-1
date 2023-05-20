package JavaHack;

public class CasillaVacia implements Visible {

    private char representacion;

    /**
     * Constructor de clase CasillaVacia, sirve para la creacion del mapa, asociandolo a un objeto 
     */
    public CasillaVacia() {
        this.representacion = ' ';
    }
    
    /**
     * representacion char de CasillaVacia
     * @return: char del CasillaVacia
     */
    @Override
    public char getRepresentacion() {
        return representacion;
    }
    
}
    

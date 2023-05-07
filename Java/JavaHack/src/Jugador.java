import java.util.List;
import java.util.Map;

public class Jugador extends Personaje{
    private String nombre;
    private int xp;
    private List<Item> inventario;
    private Map<String,Equipamiento> equipamiento;
    private Arma arma;
    
    public Jugador(String nombre){
        super();
        this.nombre = nombre;
        this.xp = 0;
        this.arma = new Arma();
    }

    @Override
    public char getRepresentacion(){
        return 'J';
    }

    public float calcularAtaque(){
        // nivel * 3 * ataq_arma
        return xp;
    }

    public void ganarXp(int xp){
        if (this.xp + xp >= 10 ) {  //buscar forma de hacer niveles
            
        }
    }
}

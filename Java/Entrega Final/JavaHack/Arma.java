package JavaHack;

import java.util.Random;

public class Arma extends Item {

    private float mul_str;
    private float mul_int;
    
    /**
     * Constructor de la clase Arma
     * @param nombre : nombre del arma
     * @param mul_str: fuerza del arma
     * @param mul_int: inteligencia del arma
     * @param representacion: representacion char del arma
     */
    public Arma(String nombre, float mul_str, float mul_int, char representacion) {
        super(representacion, nombre);
        this.mul_str = mul_str;
        this.mul_int = mul_int;
    }

    /**
     * Constructor de la clase Arma, el arma es aleatoria
     * @param representacion: representacion char del arma
     */
    public Arma(char representacion){
        super(representacion, generarNombreAleatorio());
        Random random = new Random();
        this.mul_str = (random.nextInt(3) + 2);
        this.mul_int = (random.nextInt(3) + 2);
    }
    
    /**
     * Calcula el ataque del arma, toma en cuenta el equipamiento usado por el jugador
     * @param str: fuerza 
     * @param inte: inteligencia
     * 
     * @return: ataque del arma
     */
    public float calcularAtaqueArma(Integer str, Integer inte ){
        return (str*getMul_str() + inte*getMul_int());
    }

    /**
     * Metodo que escoge al azar un nombre para el arma
     * @return nombres[indice]: nombre de algun arma
     */
    private static String generarNombreAleatorio(){
        String [] nombres = {"Espada" , "Hacha" , "Lanza" , "Arco" , "Vara" , "Manoplas" };
        Random random = new Random();
        int indice = random.nextInt(nombres.length);

        return nombres[indice];
    }

    public float getMul_str() {
        return mul_str; 
    }

    public float getMul_int() {
        return mul_int;
    }

}

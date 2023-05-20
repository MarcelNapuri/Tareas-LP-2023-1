package JavaHack;

public class Equipamiento extends Item{

    private String tipo;
    private int str;
    private int intel;  //en pdf sale int 

    /**
     * Constructor de la clase Equipamiento
     * @param nombre: nombbre del equipo
     * @param representacion: char del equipo
     */
    public Equipamiento(String nombre, char representacion) {
        super(representacion, nombre);
        this.tipo = "";
        this.str = 1;
        this.intel = 1;
    }

    /**
     * Constructor de la clase Equipamiento
     * @param representacion: char del equipo
     * @param nombre: nombre del objeto
     * @param tipo: tipo del objeto, puede ser Botas,Armadura o Amuleto
     * @param str: fuerza del objeto
     * @param intel: inteligencia del objeto
     */
    public Equipamiento(char representacion, String nombre, String tipo, int str, int intel) {
        super(representacion, nombre);
        this.tipo = tipo;
        this.str = str;
        this.intel = intel;
    }

    public String getTipo() {
        return tipo;
    }

    public int getStr() {
        return str;
    }

    public int getIntel() {
        return intel;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public void setStr(int str) {
        this.str = str;
    }

    public void setIntel(int intel) {
        this.intel = intel;
    }

}

public class Equipamiento extends Item{

    private String tipo;
    private int str;
    private int intel;  //en pdf sale int 

    public Equipamiento(String nombre, String tipo, int fuerza, int inteligencia, char representacion) {
        super(representacion, nombre);
        this.tipo = tipo;
        this.str = fuerza;
        this.intel = inteligencia;
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

    

}

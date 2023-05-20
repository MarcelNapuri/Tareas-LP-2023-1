package JavaHack;

public abstract class Item implements Visible{

    private char representacion;
    private String nombre;

    /**
     * Constructor de la clase Item
     * @param representacion: char que representa el item
     * @param nombre: nombre del item
     */
    public Item(char representacion, String nombre){
        this.representacion = representacion;
        this.nombre = nombre;
    }
    
    /**
     * Representacion char de Item
     * @return representacion: char del Item
     */
    public char getRepresentacion(){
        return representacion;
    }

    
    public void setRepresentacion(char representacion) {
        this.representacion = representacion;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
}

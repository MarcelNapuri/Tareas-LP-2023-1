package JavaHack;

public abstract class Item implements Visible{

    private char representacion;
    private String nombre;


    public Item(char representacion, String nombre){
        this.representacion = representacion;
        this.nombre = nombre;
    }
    
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

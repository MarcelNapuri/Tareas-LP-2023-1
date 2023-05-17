package JavaHack;

public class Texto implements Visible {
    private String texto;

    public Texto(String texto) {
        this.texto = texto;
    }
    
    @Override
    public char getRepresentacion() {
    // Devuelve el primer carácter de la cadena de texto
        return texto.charAt(0);
    }
    }
    

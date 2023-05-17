package JavaHack;

public class Arma extends Item {

    private float mul_str;
    private float mul_int;
    
    public Arma(String nombre, float mul_str, float mul_int, char representacion) {
        super(representacion, nombre);
        this.mul_str = mul_str;
        this.mul_int = mul_int;
    }
    
    public float calcularAtaqueArma(Integer str, Integer inte ){
        return (str*getMul_str() + inte*getMul_int());
    }

    public float getMul_str() {
        return mul_str; 
    }

    public float getMul_int() {
        return mul_int;
    }

}

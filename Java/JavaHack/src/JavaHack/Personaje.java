package JavaHack;

public class Personaje implements Visible{

    private float hp;
    private int nivel;

    /**
     * Constructor de la clase Personaje
     */
    public Personaje(){
        this.hp = 100;
        this.nivel = 1;
    }

    /**
     * Constructor de la clase personaje
     * @param hp: vida del personaje
     * @param nivel: nivel del personaje
     */
    public Personaje(int hp, int nivel){
        this.hp = hp;
        this.nivel = nivel;
    }
    
    /**
     * Representacion char de Personaje
     * @return "O" :  char de personaje
     */
    @Override
    public char getRepresentacion() {       
        return 'O' ;
    }

    /**
     * Calcula la nueva cantidad de vida del personaje, si la vida es 0 el personaje muere
     * @param dmg: reduce la cantidad de hp del ppersonaje
     */
    public void recibirDanio(Float dmg){ 
        this.hp = getHp() - dmg;
        if (this.hp <= 0) {
            System.out.println("ha muerto.");     
        }
    }

    /**
     * Calcula la cantidad de dano que hace el personaje al atacar. Se calcula como 3 · nivel.
     * @return atq : retorna el ataque  que debe hacer el personaje
     */
    public float calcularAtaque(){     
        float atq = 3 * getNivel();
        return atq;
    }

    public float getHp() {
        return hp;
    }

    public void setHp(float hp) {
        this.hp = hp;
    }

    public int getNivel() {
        return nivel;
    }

    public void setNivel(int nivel) {
        this.nivel = nivel;
    }

    
}

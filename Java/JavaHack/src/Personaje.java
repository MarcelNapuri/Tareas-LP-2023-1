public class Personaje implements Visible{

    private float hp;
    private int nivel;


    @Override
    public char getRepresentacion() {       //se representa por la letra 'O'
        return 'O' ;
    }

    public Personaje(){
        this.hp = 100;
        this.nivel = 1;
    }

    public Personaje(int hp, int nivel){
        this.hp = hp;
        this.nivel = nivel;
    }

    public void recibirDanio(int dmg){  //reduce la cantidad de hp del ppersonaje
        this.hp = getHp() - dmg;
        if (this.hp <= 0) {
            System.out.println(" ha muerto.");      //this.getClass().getSimpleName() + 
        }
    }

    public float calcularAtaque(){      //Retorna la cantidad de dano que hace el personaje al atacar. Se calcula como 3 · nivel.
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

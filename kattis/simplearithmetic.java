public class simplearithmetic {
    public static void main(String args[]){
        Kattio io = new Kattio(System.in);
        double a = io.getDouble(); double b = io.getDouble(); double c = io.getDouble();
        io.println(a*b/c);
        io.close();
    }
}

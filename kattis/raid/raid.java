import java.util.*;
public class raid {
    public static void main(String[] args){
        Kattio io = new Kattio(System.in);
        int p = io.getInt();
        TreeSet<Player> f = new TreeSet<>((c1,c2)-> (c2.i-c1.i == 0) ? (c2.j-c1.j  == 0)? (c2.k-c1.k == 0)? c2.name.compareTo(c1.name) : c2.k-c1.k : c2.j-c1.j : c2.i-c1.i);
        TreeSet<Player> s = new TreeSet<>((c1,c2)-> (c2.j-c1.j  == 0)?  (c2.i-c1.i == 0) ? (c2.k-c1.k == 0)? c2.name.compareTo(c1.name) : c2.k-c1.k : c2.i-c1.i : c2.j-c1.j);
        TreeSet<Player> t = new TreeSet<>((c1,c2)-> (c2.k-c1.k == 0)? (c2.i-c1.i == 0) ? (c2.j-c1.j  == 0)?  c2.name.compareTo(c1.name) : c2.j-c1.j : c2.i-c1.i: c2.k-c1.k);
        while (p>0){
            Player curr = new Player(io.getWord(), io.getInt(), io.getInt(),io.getInt());
            f.add(curr);
            s.add(curr);
            t.add(curr);
            p--;
        }
        while (f.size()>2){
            ArrayList<String> names = new ArrayList<>();
            Player fp=f.pollFirst();
            s.remove(fp);
            t.remove(fp);
            names.add(fp.name);
            fp=s.pollFirst();
            f.remove(fp);
            t.remove(fp);
            names.add(fp.name);
            fp=t.pollFirst();
            f.remove(fp);
            s.remove(fp);
            names.add(fp.name);
            Collections.sort(names);
            io.print(names.get(0));
            for (int i =1; i<3; i++){
                io.print(" ");
                io.print(names.get(i));
            }
            io.println();
        }
        io.close();
    }
}
class Player {
    String name;
    int i;
    int j;
    int k;
    Player(String name,int i , int j , int k) { this.name = name; this.i = i ; this.j = j ; this.k =k;}
}

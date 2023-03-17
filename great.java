import java.util.*;
public class great {
    public static LinkedList<Integer> dr(TreeMap<Integer,Moves> vertex,ArrayList<Edge> pos,ArrayList<Edge> neg,int t){
        vertex.put(0,new LinkedList<>());
        while (true){
            Map.Entry<Integer,Moves> curr =vertex.pollFirstEntry();
            for (Edge e:pos){
                
            }
        }
    }
    public static void main(String args[]){
        Kattio io = new Kattio(System.in);
        int n = io.getInt(); int t = io.getInt();
        ArrayList<Edge> pos = new ArrayList<Edge>();
        ArrayList<Edge> neg = new ArrayList<Edge>();
        TreeMap<Integer,Moves> vertex = new TreeMap<>();
        int idx=2;
        pos.add(new Edge(1,1,1,1));
        while (n>0){
            int c = io.getInt(); int d = io.getInt();
            double eff = (double) c/ (double) d;
            idx++;
            if (eff>=1){
                continue;
            }
            if (c<0){
                neg.add(new Edge(idx,c,d,eff));
            } else{
                pos.add(new Edge(idx,c,d,eff));
            }
        }
        Collections.sort(neg,(c1,c2)-> Double.compare(c2.eff, c1.eff));
        Collections.sort(pos,(c1,c2)-> Double.compare(c1.eff, c2.eff));
        dr(vertex, pos, neg, t);
    }
}
class Edge {
    int change;
    int cost;
    double eff;
    int idx;
    Edge(int idx,int change, int cost,double eff){ this.idx = idx;this.change = change; this.cost = cost; this.eff = eff;}
}
class Moves {
    int d;
    LinkedList<Integer> move;
    Moves(int d,LinkedList<Integer> move){ this.d =d; this.move =move;}
}

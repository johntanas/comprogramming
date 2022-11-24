import java.util.HashSet;
import java.util.zip.Adler32;
import java.util.*;
public class chess {
    public static boolean isCycle(int i, boolean[] visited, boolean[] visiting,ArrayList<ArrayList<Integer>> adjList){
        if (visiting[i]){
            return true;
        }
        if (visited[i]){
            return false;
        }
        visited[i] =true;
        visiting[i] = true;
        ArrayList<Integer> edges = adjList.get(i);
        for (Integer e : edges){
            if (isCycle(e, visited, visiting, adjList)){
                return true;
            }
        }
        visiting[i] =false;
        return false;
    }
    public static void main(String[] args){
        Kattio io = new Kattio(System.in);
        int n = io.getInt(), m = io.getInt();
        int[] p = new int[n];
        for (int i =0; i<n;i++){
            p[i] =i;
        }
        Union un = new Union(p);
        ArrayList<Edge> arr = new ArrayList<>();
        while (m>0){
            int u = io.getInt(); String cmd = io.getWord(); int v = io.getInt();
            if (cmd.equals("=")){
                un.unionSet(u,v);
            } else {
                arr.add(new Edge(u,v));
            }
            m--;
        }
        HashMap<Integer,Integer> map = new HashMap<>();
        ArrayList<ArrayList<Integer>> adjList = new ArrayList<>();
        int size =0;
        for (int i=0;i<n;i++){
            int actual = un.findSet(i);
            if (map.get(actual) == null){
                map.put(actual,size);
                size++;
            }
        }
        for (int i =0; i<size;i++){
            adjList.add(new ArrayList<>());
        }
        for (Edge i: arr){
            int x = map.get(un.findSet(i.u));
            int y = map.get(un.findSet(i.v));
            adjList.get(x).add(y);
        }
        boolean[] visiting = new boolean[n];
        boolean[] visited = new boolean[n];
        boolean cond = true;
        for (int i =0; i<size;i++)
            if (isCycle(i, visited, visiting, adjList)){
                cond =false;
                break;
            }
        if (cond){
            io.println("consistent");
        } else {
            io.println("inconsistent");
        }
        io.close();
    }
}
class Union {
    int[] p;
    int[] rank;
    Union(int[] p){this.p =p; this.rank = new int[p.length];}
    public int findSet(int i){
        if (p[i] == i){
            return i;
        } else {
            p[i] = findSet(p[i]);
            return p[i];
        }
    }
    public boolean isSameSet(int i , int j){
        return findSet(i) == findSet(j);
    }

    public void unionSet(int i , int j){
        if (!isSameSet(i, j)){
            int x= findSet(i);int y = findSet(j);
            if  (rank[x] > rank[y]){
                p[y] =x;
            } else {
                p[x] =y;
                if (rank[x] == rank[y]){
                    rank[y] = rank[y] +1;
                }
            }
        }
    }
}
class Edge {
    int v;
    int u;
    Edge(int u, int v) {this.u =u; this.v=v;}
    @Override
    public int hashCode()
    {
        return 50001 * u + v;
    }
    public String toString(){
        return u +" " +v;
    }
}
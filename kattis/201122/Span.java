import java.util.ArrayList;
import java.util.LinkedList;
import java.util.PriorityQueue;

public class Span {
    public static int prim(ArrayList<ArrayList<Integer>> adjList,int[] size){
        boolean[] visited = new boolean[size.length];
        PriorityQueue<Integer> q = new PriorityQueue<>();
        PriorityQueue<Pair> q2 =  new PriorityQueue<>((c1,c2)->c1.j-c2.j);
        int max =size[0];
        visited[0] =true;
        q.add(0);
        while (!q.isEmpty()){
            int min =q.poll();
            if (q2.size()>0 && max>q2.peek().j){
                q.add(q2.poll().i);
            }
            for (int i : adjList.get(min)){
                if (!visited[i]){
                    if (max>size[i]){
                        max+=size[i];
                        q.add(i);
                        visited[i] =true;
                    } else {
                        q2.add(new Pair(min,size[i]));
                    }
                }
            }
        }
        return max;
    }
    public static void main(String[] args){
        Kattio io = new Kattio(System.in);
        int n =io.getInt(), m =io.getInt();
        ArrayList<ArrayList<Integer>> adjList = new ArrayList<>();
        for (int i =0;i<n;i++){
            adjList.add(new ArrayList<>());
        }
        for (int i =0;i<m;i++){
            int u = io.getInt()-1,v =io.getInt()-1;
            adjList.get(u).add(v);
            adjList.get(v).add(u);
        }
        int[] size = new int[n];
        for (int i =0;i<n;i++){
            size[i] =io.getInt();
        }
        io.println(prim(adjList, size));
        io.close();
    }
}
class Pair {
    int i;
    int j;
    Pair(int i, int j){this.i = i; this.j =j;}
}
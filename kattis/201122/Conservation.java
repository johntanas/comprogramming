
import java.util.*;
public class Conservation {
    static int count=0;
    static int ans =1;
    public static int topo (ArrayList<ArrayList<Integer>> adjList,int[] in,int[] place,int start){
        ArrayList<LinkedList<Integer>> q = new ArrayList<LinkedList<Integer>>();
        q.add(new LinkedList<>());
        q.add(new LinkedList<>());
        for (int i=0; i<in.length;i++){
            if (in[i] ==0){
                q.get(place[i]).add(i);
            }
        }
        int curr = start;
        int swaps =0;
        while (!q.get(0).isEmpty() || !q.get(1).isEmpty()){
            while (!q.get(curr).isEmpty()){ 
                int min = q.get(curr).poll();
                for (int i : adjList.get(min)){
                    in[i]--;
                    if (in[i]==0){
                        q.get(place[i]).add(i);
                    }
                }
            }
            curr = (curr ==1 ) ? 0 :1;
            swaps++;
        }
        return swaps-1;
    }
    public static void main(String[] args){
        Kattio io = new Kattio(System.in);
        int t = io.getInt();
        while (t-->0){
            int n =io.getInt(), m = io.getInt();
            int[] place = new int[n];
            ArrayList<ArrayList<Integer>> adjList= new ArrayList<>();
            int[] in = new int[n];
            int[] in2 = new int[n];
            for (int i=0; i<n;i++){
                place[i] =io.getInt()-1;
                adjList.add(new ArrayList<>());
            }
            for (int i =0; i<m; i++){
                int u = io.getInt(); int v = io.getInt();
                u--;v--;
                adjList.get(u).add(v);
                in[v] ++;
                in2[v] ++;
            }
            int ans = Math.min(topo(adjList, in2, place, 0),topo(adjList, in, place, 1));
            io.println(ans);
        }
        io.close();
    }
}
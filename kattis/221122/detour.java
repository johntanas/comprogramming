import java.io.*;
import java.util.*;

public class detour {
    public static int dr(int[] parent,ArrayList<ArrayList<Edge>> adjList){
        Edge min = new Edge(-1,-1);
        LinkedList<Edge> q= new LinkedList<>();
        for (Edge e: adjList.get(0)){
            if (min.w<e.w){
                min = e;
            }
        }
        parent[0] = 0;
        q.offerLast(min);
        while (!q.isEmpty()){
            min = q.poll();
            Edge ee = new Edge(-1,-1);
            int cmp =0;
            for (Edge e: adjList.get(min.v)){
                if (parent[e.v] == -1){
                    cmp++;
                    if (ee.w<e.w){
                        ee = e;
                    }
                }
            }
            parent[ee.v] = min.v;
            q.add(ee);
        }
        return 1;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);
        String[] l = br.readLine().split(" ");
        int n =Integer.parseInt(l[0]),m = Integer.parseInt(l[1]);
        ArrayList<ArrayList<Edge>> adjList = new ArrayList<>();
        for (int i =0; i<n;i++){
            adjList.add(new ArrayList<>());
        }
        while (m-->0){
            l = br.readLine().split(" ");
            int u =Integer.parseInt(l[0]),v = Integer.parseInt(l[1]),w = Integer.parseInt(l[2]);
            adjList.get(u).add(new Edge(v,w));
            adjList.get(v).add(new Edge(u,w));
        }
        int[] parent = new int[n];
        for (int i =0; i<n; i++){
            parent[i] =-1;
        }
        int res = dr(parent, adjList);
        if (res ==-1){
            writer.println("impossible");
        } else {
            ArrayList<Integer> p = new ArrayList<>();
            int par =1;
            p.add(par);
            while (par !=0){
                par = parent[par];
                p.add(par);
            }
            writer.print(p.size()+" ");
            writer.print(p.get(0));
            for (int i =1; i<p.size();i++){
                writer.print(" ");
                writer.print(p.get(i));
            }
            writer.println();
        }
        writer.close();
    }
}
class Edge {
    int v;
    int w;
    int dist =0;
    Edge(int v, int w){this.v =v; this.w =w;}
    public String toString() {
        return v+ " " +w+" ";
    }
}
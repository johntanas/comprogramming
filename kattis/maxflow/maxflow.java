import java.io.*;
import java.util.*;

public class maxflow {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);
        String[] l = br.readLine().split(" ");
        int n = Integer.parseInt(l[0]), m = Integer.parseInt(l[1]), s = Integer.parseInt(l[2]), t = Integer.parseInt(l[3]);
        ArrayList<ArrayList<Edge>> adjList = new ArrayList<>();
        for (int i =0; i<n;i++){
            adjList.add(new ArrayList<>());
        }
        while (m>0){
            l = br.readLine().split(" ");
            int u = Integer.parseInt(l[0]), v = Integer.parseInt(l[1]), w = Integer.parseInt(l[2]);
            adjList.get(u).add(new Edge(u,v, w));
        }
        int distances[] = new int[n];
        for (int i =0; i<n;i++){
            distances[i] = Integer.MAX_VALUE;
        }
        Queue<Edge> q = new LinkedList<>();
        Edge[] parent = new Edge[n];
        for (Edge e:adjList.get(s)){
            parent[e.v] = e;
            q.add(e);
        }
        while (q.size()>0){
            Edge min = q.poll();
            if (distances[min.v] == Integer.MAX_VALUE || distances[min.v] < Math.min(distances[min.u],min.w)){
                distances[min.v] = Math.min(distances[min.u],min.w);
                parent[min.v] = min;
                for (Edge e:adjList.get(min.v)){
                    q.add(e);
                }
            }
        }
    }
}
class Edge {
    int u;
    int v;
    int w;
    Edge(int u,int v, int w){
        this.u =u;
        this.v = v;
        this.w =w;
    }
}
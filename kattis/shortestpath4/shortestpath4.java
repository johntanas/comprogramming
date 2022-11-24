
import java.util.*;

import icpc.Kattio;

public class shortestpath4 {
    public static int dr(ArrayList<ArrayList<Edge>> adjList, int s, int t,int k){
        int[][] distances = new int[k][adjList.size()];
        for (int[] arr: distances){
            Arrays.fill(arr,Integer.MAX_VALUE);
        }
        distances[0][s] =0;
        LinkedList<Vertex> pq = new  LinkedList<Vertex>();
        pq.add(new Vertex(s,0,0));
        while (!pq.isEmpty()){
            Vertex min = pq.poll();
            if (min.w == distances[min.jun][min.v] && min.jun<k-1){
                for (Edge e:adjList.get(min.v)){
                    if (distances[min.jun+1][e.v]> e.w + min.w ||  distances[min.jun+1][e.v] ==0){
                        for (int i =min.jun+1;i<k;i++){
                            if (distances[i][e.v] > e.w + min.w || distances[i][e.v] ==0) {
                                distances[i][e.v] = e.w + min.w;
                            } else{
                                break;
                            }
                        }
                        pq.add(new Vertex(e.v,e.w + min.w,min.jun+1));
                    }
                }
            }
        }
        int min = Integer.MAX_VALUE;
        for (int i =0; i<k;i++){
            min =Integer.min(min,distances[i][t]);
        }
        return min;
    }
    public static void main(String args[]){
        Kattio io = new Kattio(System.in);
        int t = io.getInt();
        while (t>0){
            ArrayList<ArrayList<Edge>> adjList = new ArrayList<>();
            int vs = io.getInt();
            for (int i =0; i<vs;i++){
                int idx =io.getInt();
                ArrayList<Edge> edges = new ArrayList<>();
                while (idx>0){
                    int v = io.getInt(); int w = io.getInt();
                    edges.add(new Edge(v,w));
                    idx--;
                }
                adjList.add(edges);
            }
            int q = io.getInt();
            while (q>0){
                int res =dr(adjList, io.getInt(), io.getInt(), io.getInt());
                io.println(res == Integer.MAX_VALUE ? -1 : res); 
                q--;
            }
            io.println();
            t--;
        }
        io.close();
    }
}
class Edge {
    int v;
    int w;
    Edge(int v, int w){ this.v =v; this.w = w;}
}
class Vertex {
    int v;
    int w;
    int jun;
    Vertex(int v, int w,int jun){ this.v =v; this.w = w; this.jun = jun;}
}
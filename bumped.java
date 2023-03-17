import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class bumped {
    public static int dr(ArrayList<ArrayList<Edge>> adjList ,ArrayList<LinkedList<Integer>> flights,int s, int t){
        ArrayList<Parent> parent =new ArrayList<>();
        PriorityQueue<Vertex> pq = new PriorityQueue<>((p1,p2)-> p1.dist == p2.dist ? p1.tun -p2.tun : p1.dist-p2.dist);
        for (int i=0;i<adjList.size();i++){
            parent.add(new Parent(Integer.MAX_VALUE,Integer.MAX_VALUE));
        }
        parent.set(s,new Parent(Integer.MAX_VALUE,0));
        pq.add(new Vertex(s,0,0));
        while (pq.size()>0){
            Vertex min = pq.poll();
            Parent p = parent.get(min.a);
            if (min.dist ==p.dist){
                for (Edge e:adjList.get(min.a)){
                    int curr = min.dist + e.d;
                    Parent currDest = parent.get(e.b);
                    boolean cond= false;
                    if (curr<currDest.dist){
                        currDest.dist = curr;
                        cond = true;
                    }
                    if (min.tun+e.d<currDest.tun){
                        currDest.tun = min.tun +e.d;
                        cond = true;
                    }
                    if (cond){
                        pq.add(new Vertex(e.b,currDest.dist, currDest.tun));
                    }
                }
                for (int flight:flights.get(min.a)){
                    Parent currDest = parent.get(flight);
                    if (min.dist<currDest.tun){
                        currDest.tun = min.tun;
                        pq.add(new Vertex(flight,currDest.dist, currDest.tun));
                    }
                }
            }
        }
        return Math.min(parent.get(t).dist,parent.get(t).tun);
    }
    public static void main(String args[]) throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int[] numbers= Arrays.stream(input.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int n = numbers[0]; int m = numbers[1]; int f = numbers[2];
        ArrayList<ArrayList<Edge>> adjList = new ArrayList<ArrayList<Edge>>();
        int idx =0;
        while (idx<=n){
            adjList.add(new ArrayList<Edge>());
            idx++;
        }
        idx =0;
        ArrayList<LinkedList<Integer>> flights = new ArrayList<LinkedList<Integer>>();
        while (idx<=n){
            flights.add(new LinkedList<Integer>());
            idx++;
        }
        while (m>0){
            int[] ns= Arrays.stream(input.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int a= ns[0];int b= ns[1];int d= ns[2];
            adjList.get(a).add(new Edge(b,d));
            adjList.get(b).add(new Edge(a,d));
            m--;
        }
        while (f>0) {
            int[] ne= Arrays.stream(input.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            flights.get(ne[0]).add(ne[1]);
            f--;
        }
        System.out.println(dr(adjList,flights,numbers[3],numbers[4]));
    }
}
class Vertex {
    int dist;
    int a;
    int tun;
    Vertex(int a,int dist,int tun) {this.a =a;this.dist=dist;this.tun = tun;}
  }
  class Edge{
    int b;
    int d;
    Edge(int b, int d) { this.b =b ; this.d =d;}
  }
  class Parent{
    int tun;
    int dist;
    Parent(int tun, int dist) { this.tun =tun; this.dist =dist;}
    public String toString(){
      return tun + " " + dist;
    }
  }
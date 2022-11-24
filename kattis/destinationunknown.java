
import java.util.*;
public class destinationunknown {
  public static ArrayList<Parent> dr(ArrayList<ArrayList<Edge>> adjList,int g,int h,int s){
    adjList.get(g);
    PriorityQueue<Vertex> pq = new PriorityQueue<>((p1,p2)-> p1.dist==p2.dist ? p1.tun-p2.tun : p1.dist-p2.dist);
    ArrayList<Parent> vertexList = new ArrayList<>();
    for (int i =0; i<adjList.size();i++){
      vertexList.add(new Parent(1,Integer.MAX_VALUE));
    }
    vertexList.add(s,new Parent(1,0));
    pq.offer(new Vertex(s, 0,1));
    while (pq.size()>0){
      Vertex min =pq.poll();
      Parent parent = vertexList.get(min.a);
      if (min.dist == parent.dist && min.tun ==parent.tun){
        ArrayList<Edge> neighbours = adjList.get(min.a);
        for (int i =0; i<neighbours.size();i++){
          Edge currEdge =neighbours.get(i);
          Parent currNeighbour = vertexList.get(currEdge.b);
          int currDist =currEdge.d+parent.dist;
          boolean visitingTun =((min.a == g && currEdge.b == h) || (min.a == h && currEdge.b == g) || parent.tun !=1);
          if (currNeighbour.dist>currDist){
            if (visitingTun){
              pq.add(new Vertex(currEdge.b,currDist,0));
              vertexList.set(currEdge.b,new Parent(0, currDist));
            } else {
              pq.add(new Vertex(currEdge.b,currDist, 1));
              vertexList.set(currEdge.b,new Parent(1, currDist));
            }
          }
          if (currNeighbour.dist==currDist){
            if (visitingTun){
              pq.add(new Vertex(currEdge.b,currDist,0));
              vertexList.set(currEdge.b,new Parent(0, currDist));
            }
          }
        }
      }
    }
    return vertexList;
  }
  public static void main(String args[]) {
    Kattio io = new Kattio(System.in);
    int t = io.getInt();
    while (t>0){
    int n= io.getInt();int m= io.getInt();int f= io.getInt();
    int s= io.getInt();int g= io.getInt();int h= io.getInt();
    int idx =0;
    ArrayList<ArrayList<Edge>>  adjList = new ArrayList<ArrayList<Edge>>();
    ArrayList<Integer> friends = new ArrayList<>();
    while (idx<=n){
      adjList.add(new ArrayList<Edge>());
      idx++;
    }
    while (m>0){
      int a= io.getInt();int b= io.getInt();int d= io.getInt();
      adjList.get(a).add(new Edge(b,d));
      adjList.get(b).add(new Edge(a,d));
      m--;
    }
    while (f>0){
      int fri= io.getInt();
      friends.add(fri);
      f--;
    }
    ArrayList<Parent> stuff = dr(adjList, g, h, s);
    ArrayList<Integer> friendsToPrint = new ArrayList<>();
    for (int i =0;i<friends.size();i++){  
      int currFriend = friends.get(i);
      Parent currPlace=stuff.get(currFriend);
      if (currPlace.tun ==1){
        continue;
      }
      friendsToPrint.add(currFriend);
    }
    Collections.sort(friendsToPrint);
    int i=0;
    io.print(friendsToPrint.get(i++));
    while(i<friendsToPrint.size()){
      io.print(" " +friendsToPrint.get(i));
      i++;
    }
    io.println();
    t--;
  }
    io.close();
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

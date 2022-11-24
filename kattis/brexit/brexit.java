import java.io.*;
import java.util.*;

public class brexit {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);
        String[] var = br.readLine().split(" ");
        int c=Integer.parseInt(var[0]),p = Integer.parseInt(var[1]),x= Integer.parseInt(var[2]),l=Integer.parseInt(var[3]);
        ArrayList<Country> adjList = new ArrayList<>();
        for (int i =0; i<=c; i++){
            adjList.add(new Country());
        }
        while (p-->0){
            var=br.readLine().split(" ");
            int u=Integer.parseInt(var[0]),v = Integer.parseInt(var[1]);
            adjList.get(u).neighbours.add(v);
            adjList.get(u).incoming ++;
            adjList.get(v).neighbours.add(u);
            adjList.get(v).incoming++;
        }
        adjList.get(l).left = true;
        Queue<Integer> q = new LinkedList<>();
        for (int i:adjList.get(l).neighbours){
            adjList.get(i).incoming--;
            q.add(i);
        }
        while (q.size()>0){
            int curr = q.poll();
            Country currCountry = adjList.get(curr);
            if (currCountry.left) { continue;}
            if (currCountry.neighbours.size()/2 >=currCountry.incoming){
                currCountry.left = true;
                for (int i: currCountry.neighbours){
                    adjList.get(i).incoming--;
                    q.add(i);
                }
            }
        }
        if (adjList.get(x).left){
            writer.println("leave");
        } else {
            writer.println("stay");
        }
        writer.close();
    }
}
class Country {
    boolean left =false;
    int incoming;
    ArrayList<Integer> neighbours;
    Country(){this.incoming = 0; this.neighbours = new ArrayList<>();}
}
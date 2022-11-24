import java.io.*;
import java.util.*;

public class internet {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);
        String[] v =br.readLine().split(" ");
        int n = Integer.parseInt(v[0]), m = Integer.parseInt(v[1]);
        boolean[] visited = new boolean[n+1];
        visited[1] = true;
        ArrayList<ArrayList<Integer>> adjList = new ArrayList<>();
        for (int i =0; i<= n;i++){
            adjList.add(new ArrayList<>());
        }
        while (m-->0){
            v =br.readLine().split(" ");
            int u = Integer.parseInt(v[0]), w = Integer.parseInt(v[1]);
            adjList.get(u).add(w);
            adjList.get(w).add(u);
        }
        Queue<Integer> q = new LinkedList<>();
        for (int i: adjList.get(1)){
            q.add(i);
        }
        while (q.size()>0){
            int curr = q.poll();
            if (visited[curr]) continue;
            visited[curr] =true;
            for (int i: adjList.get(curr)){
                q.add(i);
            }
        }
        boolean cond = true;
        for (int i =1; i<=n;i++){
            if (!visited[i]){
                writer.println(i);
                cond =false;
            }
        }
        if (cond){
            writer.println("Connected");
        }
        writer.close();
    }
}
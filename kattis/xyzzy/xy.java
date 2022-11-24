import java.io.*;
import java.util.*;

public class xy {
    public static boolean dfs(int i, boolean[] seen, ArrayList<ArrayList<Integer>> adjMat){
        if (seen[i]) return false;
        seen[i] = true;
        if (i+1==seen.length) return true;
        for (int j : adjMat.get(i)){
            if (dfs(j, seen, adjMat)){
                return true;
            }
        }
        return false;
    }
    public static boolean relax(int[] distances,ArrayList<ArrayList<Integer>> adjMat,int[] cost,boolean[] reach){
        boolean ans = false;
        for (int i =1; i<adjMat.size();i++){
            if (distances[i] >=0){
                for (int j: adjMat.get(i)){
                    if (distances[j] < distances[i] +cost[j]){
                        distances[j] = distances[i] +cost[j];
                        ans |= reach[j];
                    }
                }
            }
        }
        return ans;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);
        String t = br.readLine();
        while (! (t.equals("-1"))){
            int  n = Integer.parseInt(t);
            ArrayList<ArrayList<Integer>> adjMat = new ArrayList<>();
            for (int i =0;i<=n;i++){
                adjMat.add(new ArrayList<>());
            }
            int[] cost = new int[n+1];
            int[] distance = new int[n+1];
            for (int j=0; j<=n;j++){
                distance[j] = 0;
            }
            distance[1] =100;
            for (int j =0; j< n;j++){
                String[] l = br.readLine().split(" ");
                cost[j] = Integer.parseInt(l[0]);
                for (int i =2; i<l.length;i++){
                    adjMat.get(j).add(Integer.parseInt(l[i]));
                }
            }
            boolean[] reach = new boolean[n+1];
            for (int i =1; i<n; i++){
                boolean[] seen = new boolean[n+1];
                reach[i] = dfs(i, seen, adjMat);
            }
            for (int i=0; i<n; i++){ relax(distance, adjMat, cost, reach);}
            if (relax(distance, adjMat, cost, reach) || distance[n-1] >0){
                writer.println("winnable");
            } else {
                writer.println("hopeless");
            }
            t=br.readLine();
        }
        writer.close();
    }
}
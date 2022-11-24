import java.io.*;
import java.util.*;

public class topic {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);
        String line = br.readLine();
        HashMap<String,Integer> map = new HashMap<>();
        LinkedList<String> q = new LinkedList<>();
        int d=0;
        while (line != null){
            if (line.equals("<text>")){
                String curr = br.readLine();
                while (!curr.equals("</text>")){
                    for (String c:curr.split(" ")){
                        q.add(c);
                        map.compute(c, (k,v)-> (v==null) ? 1: v+1);
                    }
                }
                q.add("</text>");
                if (d>6){
                    String c = q.poll();
                    while (!c.equals("</text>")){
                        map.compute(c, (k,v)-> v-1);
                        c=q.poll();
                    }
                }
                d++;
            } else {
                ArrayList<Entry<String,Integer>> = new ArrayList<>(map.entrySet());
                
            }
            br.readLine();
            line = br.readLine();
        }
    }
}
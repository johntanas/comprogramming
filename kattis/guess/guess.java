import java.io.*;
import java.util.*;

public class guess {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);
        String l = br.readLine();
        while (l != null){
            int n = Integer.parseInt(l);
            Queue<Integer> q = new LinkedList<>();
            PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
            LinkedList<Integer> stack = new LinkedList<Integer>();
            int qt = 1;
            int pqt= 1;
            int st = 1;
            boolean cond = false;
            while (n-->0){
                String[] e =br.readLine().split(" ");
                int cmd = Integer.parseInt(e[0]), curr = Integer.parseInt(e[1]);
                if (cmd == 1){
                    q.offer(curr);
                    pq.add(curr);
                    stack.addLast(curr);
                }
                if (cmd == 2){
                    if (pq.isEmpty() || cond){
                        pqt = 0;
                        qt=0;
                        st =0;
                        cond = true;
                        continue;
                    }
                    if (curr != pq.poll()){
                        pqt = 0;
                    }
                    if (curr != q.poll()){
                        qt = 0;
                    }
                    if (curr != stack.removeLast()){
                        st = 0;
                    }
                }
            }
            if (qt + pqt + st >0){
                if (qt +pqt+st>1){
                    writer.println("not sure");
                } else {
                    if (qt ==1){
                        writer.println("queue");
                    }
                    if (pqt ==1){
                        writer.println("priority queue");
                    }
                    if (st ==1){
                        writer.println("stack");
                    }
                }
            } else {
                writer.println("impossible");
            }
            l = br.readLine();
        }
        writer.close();
    }
}
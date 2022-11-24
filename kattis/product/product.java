import java.util.Collections;
import java.util.PriorityQueue;

public class product {
    public static void main(String[] args){
        Kattio io = new Kattio(System.in);
        int t = io.getInt();
        int cass=1;
        while( cass <t+1){
            int n = io.getInt();
            int idx =0;
            PriorityQueue<Long> min = new PriorityQueue<>();
            PriorityQueue<Long> max = new PriorityQueue<>(Collections.reverseOrder());
            while (idx<n){
                min.add(io.getLong());
                idx++;
            }
            while (n>0){
                max.add(io.getLong());
                n--;
            }
            long sum =0;
            while (min.size()>0){
                sum += min.poll() * max.poll();
            }
            io.print("Case #");
            io.print(cass +": ");
            io.println(sum);
            cass++;
        }
        io.close();
    }
}

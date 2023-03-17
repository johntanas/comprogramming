import java.util.LinkedList;

public class downtime {
    public static void main(String args[]){
        Kattio io = new Kattio(System.in);
        int n = io.getInt(); int k = io.getInt();
        LinkedList<Integer> queue =  new LinkedList<>();
        int max =0;
        queue.offer(-1000);
        while (n>0){
            int curr =io.getInt();
            queue.offer(curr);
            while (queue.peek()+1000<=curr){
                queue.poll();
            }
            max = Math.max(queue.size(),max);
            n--;
        }
        io.println((max+k-1)/k);
        io.close();
    }
}

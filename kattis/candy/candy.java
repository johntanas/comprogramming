import java.io.*;
import java.util.TreeSet;
public class candy {
    public static void main(String[] args) throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        long t=Long.parseLong(input.readLine());
        BufferedWriter o = new BufferedWriter(new OutputStreamWriter(System.out));
        TreeSet<Long> tree= new TreeSet<>();
        for (long i=1;i<=Math.sqrt(t);i++){
            if (t % i ==0){
                tree.add(i);
                tree.add(t/i);
            }
        }
        o.write(Long.toString(tree.pollFirst()-1));
        while (!tree.isEmpty()){
            o.write(" ");
            o.write(Long.toString(tree.pollFirst()-1));
        }
        o.close();
    }
}

import java.io.*;
public class thought {
    public static void main(String args[]) throws IOException {
        final int MOD = 1_000_000_007;
        BufferedReader io = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out));
        int n =Integer.parseInt(io.readLine());
        while (n>0){
            String count=Integer.toString(Integer.parseInt(io.readLine(), 10), 4);
            log.write(count+"\n");
            n--;
        }
        log.close();
    }
}

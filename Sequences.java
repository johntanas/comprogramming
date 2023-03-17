import java.nio.channels.SeekableByteChannel;

import java.lang.Math;
import java.io.*;
public class Sequences {
    public static void main(String args[]) throws IOException {
        final int MOD = 1_000_000_007;
        BufferedReader io = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out));
        String sentence = io.readLine();
        long count =0;
        int zeros = 0;
        for (int i=0;i<sentence.length();i++){
            if (sentence.charAt(i)=='1') {
                ones++;
            }
            else if (sentence.charAt(i)=='0'){ 
                zeros++;}
            else if (sentence.charAt(i)=='?'){ 
                count+= (long) ones; ones++;}
            count = count % MOD;
        }
        log.write(count+"\n");
        log.close();
    }
}

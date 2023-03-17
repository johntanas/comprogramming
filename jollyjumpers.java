import java.io.*;
import java.util.HashSet;
import java.util.Arrays;
public class jollyjumpers {
    public static String p(String line){
        String[] test =line.split(" ");
        int[] ints = Arrays.stream(test).mapToInt(Integer::parseInt).toArray();
        HashSet<Integer> diff = new HashSet<>();
        int size = ints[0];
        for (int i=1;i<size-1;i++) {
            int f=ints[i];
            int s = ints[i+1];
            int curr =Math.abs(f-s);
            if (diff.contains(curr) || curr>size-1) {
                return "Not jolly";
            } else {
                diff.add(curr);
            }
        }
        return "Jolly";
    }
    public static void main(String args[]) throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String line = input.readLine();
        while (line != null){
            System.out.println(p(line));
            line = input.readLine();
        }
    }
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.*;

public class Baloni {
    public static void main(String[] args) throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        input.readLine();
        HashMap<Integer,Integer> arrows = new HashMap<>();
        String[] test = input.readLine().split(" ");
        int[] ints = Arrays.stream(test).mapToInt(Integer::parseInt).toArray();
        int sum =0;
        for (int i:ints){
            Integer curr = arrows.get(i);
            if (curr == null) {
                sum+=1;
            } else {
                arrows.compute(i,(k,v)-> (v==1) ? null :v-1);
            }
            arrows.compute(i-1,(k,v)-> (v==null) ? 1 :v+1);
        }
        System.out.println(sum);
    }
}

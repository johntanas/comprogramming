import java.io.*;
import java.util.*;

public class kings {
    public static void main(String[] args) throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int[] e =Arrays.stream(input.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int k = e[0];
        int n= e[1];
        int[] d =Arrays.stream(input.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        ArrayList<Mouse> mouses = new ArrayList<>();
        mouses.add(new Mouse(d[0],d[1],1));
        int idx =0;
        while (idx<n+k-2){
            d =Arrays.stream(input.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            mouses.add(new Mouse(d[0],d[1],0));
            idx++;
        }
        Collections.sort(mouses);
        PriorityQueue<Mouse> pq = new PriorityQueue<>((c1,c2)-> c2.s-c1.s);
        int year = mouses.get(0).year;
        idx =0;
        boolean cond = true;
        while (year<2011+n){
            while (idx<mouses.size() && mouses.get(idx).year == year){
                pq.add(mouses.get(idx));
                idx++;
            }
            if (pq.poll().m ==1){
                System.out.println(year);
                cond= false;
                break;
            }
            year++;         
        }
        if (cond){
            System.out.println("unknown");
        }
    }
}
class Mouse implements Comparable<Mouse>{
    int year;
    int s;
    int m;
    Mouse(int year, int s, int m){ this.year = year; this.s = s; this.m = m;}
    public int compareTo(Mouse other){
        return this.year - other.year;
    }
}

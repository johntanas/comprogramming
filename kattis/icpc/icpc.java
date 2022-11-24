import java.util.*;
public class icpc {
    public static void main(String[] args){
        Kattio io = new Kattio(System.in);
        int t= io.getInt();
        while (t>0){
            int n =io.getInt();
            ArrayList<Long> l = new ArrayList<>();
            long idx =0;
            while (idx<3*n){
                l.add(io.getLong());
                idx++;
            }
            Collections.sort(l);
            idx=0;
            long sum=0;
            while (l.size()>0){
                sum+= l.get(l.size()-2);
                l.remove(0);
                l.remove(l.size()-1);
                l.remove(l.size()-1);
            }
            io.println(sum);
            t--;
        }
        io.close();
    }
}

import java.util.HashMap;

public class sred {
    public static void main(String[] args){
        Kattio io = new Kattio(System.in);
        int n = io.getInt(), b = io.getInt();
        int s=0;
        int[] items = new int[n];
        for (int i =0; i<n;i++){
            int curr= io.getInt();
            if (curr == b){
                s=i;
            }
            items[i] =curr;
        }
        HashMap<Integer,Integer> map = new HashMap<>();
        map.put(0,1);
        int sum=0;
        for (int i = s+1;i<n;i++){
            if (items[i]>b){
                sum++;
            } else sum --;
            map.compute(sum, (k,v)-> (v==null) ? 1 : v+1);
        }
        int ans =map.get(0);
        sum =0;
        for (int i = s-1;i >=0; i--){
            if (items[i]>b) sum++;
            else sum--;
            ans += (map.get(-sum) == null) ? 0 : map.get(-sum) ;
        }
        io.println(ans);
        io.close();
    }
}
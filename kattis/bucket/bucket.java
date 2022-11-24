import java.util.Arrays;

public class bucket {
    public static int calc(int[] mi, int[] m){
        int[] min = mi.clone();
        int[] max = m.clone();
        int me=0;
        int l =0;
        int r =min.length-1;
        boolean side = false;
        while (true){
            while (min[l] ==0){
                l++;
                if (l>min.length-1){
                    side = true;
                    break;
                }
            }
            while (max[r] ==0){
                r--;
                if (r<0){
                    side = true;
                    break;
                }
            }
            if (side){
                break;
            }
            me = Math.max(l+r,me);
            int ms = Math.min(min[l],max[r]);
            min[l]-=ms;
            max[r]-=ms;
        }
        return me;
    }
    public static void main(String[] args){
        Kattio io = new Kattio(System.in);
        int n = io.getInt();
        int[] min = new int[101];
        int[] max = new int[101];
        while (n>0){
            min[io.getInt()] +=1;
            max[io.getInt()] +=1;
            io.println(calc(min, max));
            n--;
        }
        io.close();
    }
}

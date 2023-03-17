import java.io.*;
import java.util.*;
public class cocktail {
    public static void main(String[] args) throws IOException{
        BufferedReader io = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out));
        String line=io.readLine();
        int n = Integer.parseInt(line.split(" ")[0]);
        int time = Integer.parseInt(line.split(" ")[1]);
        ArrayList<Integer> list = new ArrayList<>();
        while (n>0){
            list.add(Integer.parseInt(io.readLine()));
            n--;
        }
        Collections.sort(list,(v1,v2)->v2.compareTo(v1));
        if (list.size()==1) log.write("YES");
        else{
        int start=list.get(0);
        start-=time;
        boolean cond=true;
        for (int i=1;i<list.size();i++){
            if (start<list.get(i)){
                log.write("NO\n");
                cond=false;
                break;
            }
            start-=time;
        }
        if (cond) log.write("YES\n");
        }
        log.close();
    }
}
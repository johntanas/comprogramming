import java.io.*;
import java.util.*;
public class nicknames {
    public static void main(String[] args) throws IOException{
        BufferedReader i = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter o = new BufferedWriter(new OutputStreamWriter(System.out));
        String line=i.readLine();
        HashMap<String,Integer> names= new HashMap<>();
        int a=Integer.parseInt(line);
        while (a>0){
            line=i.readLine();
            for (int j=0;j<line.length()+1;j++){
                names.compute(line.substring(0,j),(k, v) -> (v == null) ? 1 : v+1);
            }
            a--;
        }
        int b=Integer.parseInt(i.readLine());
        while (b>0){
            String nick=i.readLine();
            Integer no=names.get(nick);
            if (no == null) {o.write(0+"\n");}
            else o.write(no+"\n");
            b--;
        }
        o.close();
    }
}
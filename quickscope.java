import java.io.*;
import java.util.*;
import java.lang.*;
public class quickscope {
    public static void main(String[] args) throws IOException{
        BufferedReader i = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter o = new BufferedWriter(new OutputStreamWriter(System.out));
        HashMap<String,String> vars= new HashMap<>();
        int c=0;
        int N = Integer.parseInt(i.readLine());
        while (N>0){
            String line =i.readLine();
            if (line.equals("{")){
                c++;
            } else if (line.equals("}")){
                c--;
            } else{
                String[] cmd=line.split(" ");
                String b = new StringBuilder(cmd[1]).append(c).toString();
                if (cmd[0].equals("DECLARE")){
                    if (vars.get(b) != null){
                        o.write("MULTIPLE DECLARATION\n");
                        break;
                    } 
                    vars.put(b,cmd[2]);
                } else {
                    int d=c;
                    while (d>=0){
                        String type= vars.get(b);
                        if (type ==null && d==0){
                            o.write("UNDECLARED \n");
                        } else if (type !=null) {
                            o.write(type+"\n");
                        }
                        d--;
                        b = new StringBuilder(cmd[1]).append(d).toString();
                    }
                }
            }
            N--;
        }
        o.close();
    }
    
}

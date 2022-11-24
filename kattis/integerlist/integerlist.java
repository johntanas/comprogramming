import java.io.*;
import java.util.*;

public class integerlist {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        int t = Integer.parseInt(in.readLine());
        while (t>0){
            String cmd = in.readLine();
            int n = Integer.parseInt(in.readLine());
            String temp = in.readLine();
            String[] e;
            if (n>1){
                e= temp.substring(1, temp.length() - 1).split(",");
            } else{
                if (n ==1){
                    e = new String[1];
                    e[0] =temp;
                } else {
                    e = new String[0];
                }
            }
            boolean front = true;
            boolean error = false;
            LinkedList<String> deque = new LinkedList<>();
            for (String s: e){
                deque.addLast(s);
            }
            for (int i =0; i<cmd.length(); i++){
                if (deque.isEmpty()){
                    error = true;
                    break;
                }
                if (cmd.charAt(i) == 'R'){
                    front = !front;
                } else {
                    if (front){
                        deque.removeFirst();
                    } else {
                        deque.removeLast();
                    }
                }
            }
            if (error){
                out.write("error\n");
            } else {
                out.write("[");
                if (!deque.isEmpty()){ 
                    if (front){
                        out.write(deque.poll());
                        while (deque.size()>0){
                            out.write(",");
                            out.write(deque.poll());
                        }
                    } else {
                        out.write(deque.removeLast());
                        while (deque.size()>0){
                            out.write(",");
                            out.write(deque.removeLast());
                        }
                    }
                }
                out.write("]\n");
            }
            t--;
        }
        out.close();

    }
}
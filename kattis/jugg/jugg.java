import java.io.BufferedReader;
import java.util.*;
import java.io.*;
public class jugg {
    public static void main(String[] args) throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String line = input.readLine();
        while (line != null){       
            System.out.print(line+": ");
            int sum =0;
            for (int i =0; i<line.length();i++){
                sum+= (line.charAt(i)-'0');
            }
            if (sum % line.length() !=0){
                System.out.println("invalid # of balls");
            }
            else {
                int balls = sum/ line.length();
                HashSet<Integer> st = new HashSet<>();
                for (int i =0; i<line.length();i++){
                    st.add(((line.charAt(i)-'0')+i)%line.length()) ;
                }
                if (st.size() == line.length()){
                    System.out.println("valid with "+balls+" balls");
                } else {
                    System.out.println("invalid pattern");
                }
            }

            line = input.readLine();
        }
    }
}
class Ball {
    int l;
    int t;
    boolean seen =false;
    Ball(int l, int t){this.l = l; this.t =t;}
}
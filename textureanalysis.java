import java.io.*;
public class textureanalysis {
    public static void main(String[] args) throws IOException{
        BufferedReader io = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out));
        int c=1;
        while (true) {
            String curr=io.readLine();
            if (curr.equals("END")){
                break;
            }
            log.write(c);
            int j=1;
            if (curr.length() == 1){
                c++;
                log.write(" EVEN\n");
                continue;
            }
            while (curr.charAt(j) != '*'){
                j++;
            }
            int c2=j;
            boolean cond = true;
            for (int i=j+1;i<curr.length();i++){
                if (c2>1){
                    if (curr.charAt(i) !='.'){
                        log.write(" NOT EVEN\n");
                        cond=false;
                        break;
                    }
                }
                else{
                    if (curr.charAt(i) =='.'){
                        log.write(" NOT EVEN\n");
                        cond=false;
                        break;
                    }
                    c2=j+1;
                }
                c2--;

            }
            if (cond) log.write(" EVEN\n");
            c++;
        }
        log.close();
    }
}
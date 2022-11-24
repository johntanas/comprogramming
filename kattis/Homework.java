import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Homework {
    private static int process(String problems){
        int i=0;
        int prevNo =0;
        int currNo =0;
        int count=0;
        int countAmt=1;
        while (i<problems.length()){
            char curr=problems.charAt(i);
            if (curr==';'){
                if (prevNo !=0){
                    countAmt=currNo-prevNo;
                }
                count+=countAmt;
                prevNo=0;
                currNo=0;
                countAmt=1;
            }else if (curr=='-'){
                prevNo=currNo;
                currNo=0;
            } else {
                currNo+=(int) curr;
            }
            i++;
        }
        return count;
    }
    public static void main(String[] args) throws IOException{
        BufferedReader io = new BufferedReader(new InputStreamReader(System.in));
        String problems=io.readLine();
        System.out.println(process(problems));
    }
}
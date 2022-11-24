import java.io.*;
import java.util.*;

public class Jetpack {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);
        int n = Integer.parseInt(br.readLine());
        char[][] mat = new char[10][n];
        for (int i =0; i<10; i++){
            mat[i]= br.readLine().toCharArray();
        }
        int[][] mat2 = new int[10][n];
        for (int i =0;i<10;i++){
            for (int j =0;j<n;j++){
                mat2[i][j]=-1;
            }
        }
        mat2[9][0]=9;
        for (int j =0;j<n-1;j++){
            for (int i =0;i<10;i++){
                if (mat2[i][j] !=-1){
                    if (i==9){
                        if (mat[i][j+1] == '.'){
                            mat2[i][j+1] =i;
                        }
                        if  (mat[i-1][j+1]== '.'){
                            mat2[i-1][j+1] =i;
                        }
                    } else if (i==0){
                        if  (mat[i+1][j+1]== '.'){
                            mat2[i+1][j+1] =i;
                        }
                        if (mat[i][j+1] == '.'){
                            mat2[i][j+1] =i;
                        }
                    } else {
                        if  (mat[i+1][j+1]== '.'){
                            mat2[i+1][j+1] =i;
                        }
                        if  (mat[i-1][j+1]== '.'){
                            mat2[i-1][j+1] =i;
                        }
                    }
                }
            }
        }
        ArrayList<Integer> moves = new ArrayList<>();
        int start=0;
        for (int i =0; i<10;i++){
            if (mat2[i][n-1] != -1){
                start =i;
            }
        }
        moves.add(start);
        for (int j =n-1;j>0;j--){
            start = mat2[start][j];
            moves.add(start);
        }
        int prev = moves.get(n-1);
        ArrayList<Pair> printto = new ArrayList<>();
        for (int i =n-2; i>=0; i--){
            int curr = moves.get(i);
            if (prev>curr || (prev ==  0 && curr ==0)){
                if (printto.isEmpty()){
                    printto.add(new Pair(n-i-2, 1));
                } else {
                    if ((printto.get(printto.size()-1).i + printto.get(printto.size()-1).j) == n-i-2){
                        printto.get(printto.size()-1).j++;
                    }  else {
                        printto.add(new Pair(n-i-2, 1));
                    }
                }
            }
            prev =curr;
        }
        writer.println(printto.size());
        for (Pair p: printto){
            writer.println(p);
        }
        writer.close();
    }
}
class Pair {
    int i;
    int j;
    Pair(int i, int j){this.i =i; this.j =j;}
    public String toString(){
        return i+ " "+j;
    }
}
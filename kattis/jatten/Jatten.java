import java.io.*;
import java.util.*;

public class Jatten{
    static int dr[] = {1,0,-1,0};
    static int dc[] = {0,1,0,-1};
    static int ddr[] = {1,1,-1,-1};
    static int ddc[] = {-1,1,1,-1};
    public static Pair floodfill(Pair p1, Pair p2,int R, int C) {
        if (p1.x ==p2.x){
            for (int d =0; d<4;d++){
                int r = p1.x +ddr[d];
                int c = p1.y +ddc[d];
                if (r<0 || r>= R || c<0 || c>= C) continue;
                if (c>p1.y && c> p2.y){
                    return new Pair(r,c);
                }
                if (c<p1.y && c< p2.y){
                    return new Pair(r,c);
                }
            }
        }
        if (p1.y ==p2.y){
            for (int d =0; d<4;d++){
                int r = p2.x +ddr[d];
                int c = p2.y +ddc[d];
                if (r<0 || r>= R || c<0 || c>= C) continue;
                if (r>p1.x && r> p2.x){
                    return new Pair(r,c);
                }
                if (r<p1.x && r< p2.x){
                    return new Pair(r,c);
                }
            }
        }
        for (int d =0; d<4;d++){
            int r = p1.x +dr[d];
            int c = p1.y +dc[d];
            if (r<0 || r>= R || c<0 || c>= C) continue;
            double g1 = (p1.y -p2.y)/(p1.x -p2.x);
            double g2 = (c -p2.y)/(r-p2.x);
            if (Math.abs(g2)<Math.abs(g1)){
                return new Pair(r,c);
            }
        }
        for (int d =0; d<4;d++){
            int r = p2.x +dr[d];
            int c = p2.y +dc[d];
            if (r<0 || r>= R || c<0 || c>= C) continue;
            double g1 = (p1.y -p2.y)/(p1.x -p2.x);
            double g2 = (p1.y  -c)/(p1.x -r);
            if (Math.abs(g2)<Math.abs(g1)){
                return new Pair(r,c);
            }
        }
        return new Pair(0,10);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);
        int R= br.read(); int C = br.read();
        int x1 = br.read(), y1 = br.read(), x2 = br.read(), y2 = br.read();
        writer.println(floodfill(new Pair(x1,y1),new Pair(x2,y2),R,C));
        writer.close();
        
    }
}
class Pair {
    int x;
    int y;
    Pair(int x, int y){this.x =x;this.y =y;}
    public String toString(){
        return x+" "+y;
    }
}
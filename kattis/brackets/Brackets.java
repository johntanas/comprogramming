/**
 * Name:
 * Matric. No:
 */
import java.util.*;
public class Brackets {
  final static int MOD = 1_000_000_007;
  private static long evaluate(LinkedList<String> stack,boolean mup){
      long sum =0;
      if (mup){
          sum=1;
      }
      boolean cond = true;
      while (!stack.peek().equals("(")){
          long curr = Long.parseLong(stack.pop());
          if (mup){
              sum*=curr;
              cond = false;
          }else {
              sum += curr;
              cond =false;
          }
          sum = sum % MOD;
      }
      stack.pop();
      if (cond){
          return (long) 0;
      }
      return sum;

  }
  public static void main(String args[]) {
     Kattio io = new Kattio(System.in);
     LinkedList<String> stack = new LinkedList<>();
     int N = io.getInt();
     boolean mup = false;
     while (N>0){
         String token = io.getWord();
         if (token.equals(")")){
            long num=evaluate(stack,mup);
            token = Long.toString(num);
            mup = !mup;
         }
         if (token.equals("(")){
             mup =  !mup;
         }
         stack.push(token);
         N--;
    }
    long result =0;
    while (stack.size()>0){
        result += Long.parseLong(stack.pop());
        result = result% MOD;
    }
    io.println(result);
    io.close();
    }  
}

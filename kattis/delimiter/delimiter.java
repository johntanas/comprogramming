import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class delimiter {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        in.readLine();
        String e = in.readLine();
        Stack<Character> stack = new Stack<>();
        boolean cond = true;
        for (int i =0; i<e.length();i++){
            char curr = e.charAt(i);
            if (curr == '[' | curr == '{' | curr =='('){
                stack.push(curr);
            } else if ( curr ==']'){
                if (stack.isEmpty() || stack.peek() != '['){
                    System.out.print(curr+" ");
                    System.out.println(i);
                    cond = false;
                    break;
                }
                stack.pop();
            } else if ( curr == '}'){
                if (stack.isEmpty() || stack.peek() != '{'){
                    System.out.print(curr+" ");
                    System.out.println(i);
                    cond = false;
                    break;
                }
                stack.pop();
            } else if ( curr == ')'){
                if (stack.isEmpty() || stack.peek() != '('){
                    System.out.print(curr+" ");
                    System.out.println(i);
                    cond = false;
                    break;
                }
                stack.pop();
            }
        }
        if (cond){
            System.out.println("ok so far");
        }
    }
}

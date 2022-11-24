import java.util.*;
public class joinstrings {
    public static void main(String[] args){
        Kattio io = new Kattio(System.in);
        int n=io.getInt();
        int idx=0;
        ArrayList<lis> words= new ArrayList<>();
        words.add(new lis(new Node("e",null)));
        while (idx<n){
            lis e= new lis(new Node(io.getWord(),null));
            words.add(e);
            idx++;
        }
        int i=1;
        while (n-1>0){
            i=io.getInt(); int j =io.getInt();
            lis l=words.get(i);
            l.tail.next = words.get(j).head;
            l.tail = words.get(j).tail;
            n--;
        }
        lis curr = words.get(i);
        Node currNode = curr.head;
        while (currNode !=null){
            io.print(currNode.val);
            currNode =currNode.next;
        }
        io.println();
        io.close();
    }
}
class lis {
    Node tail;
    Node head;
    lis(Node head){ this.tail = head; this.head = head;}
}
class Node {
    Node next;
    String val;
    Node(String val, Node next){ this.next = next; this.val =val;}
}
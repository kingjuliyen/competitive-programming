// 1062 - Containers
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=245&page=show_problem&problem=3503
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;

public class Main {
  class Ctr { // Containers
    String arrvOrder; // arrival order
    Vector<Character> vi;
    Ctr(String s) {
      arrvOrder = s;
      vi = new Vector<Character>();
    }

    void solve(int count) {
      for(int i=0; i<arrvOrder.length(); i++) {
        int found = -1;
        char c = arrvOrder.charAt(i);
        for(int j=0; j<vi.size(); j++) {
          if(c <= vi.get(j)) {
            found = j;
            break;
          }
        }
        if(found != -1)
          vi.set(found, c);
        else
          vi.add(c);
      }
      System.out.println("Case "+count+": "+vi.size());
    }
  } // class Ctr

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int count = 1;
    while(true) {
      String s = sc.nextLine();
      if(s.equals("end"))
        break;
      Ctr ctr = new Main(). new Ctr(s);
      ctr.solve(count++);
    }
  }
}

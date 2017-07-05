// 10812 - Beat the Spread!
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=20&page=show_problem&problem=1753
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;
import java.math.*;

public class Main {
  void calculate(BigInteger s, BigInteger d) {
    BigInteger a = s.add(d).divide(new BigInteger("2", 10));
    BigInteger b = s.subtract(a);

    BigInteger _s = a.add(b);
    BigInteger _d = a.subtract(b);

    boolean reconstruct = false;
    if(_s.equals(s) && _d.equals(d)){
      reconstruct = true;
    }

    do {
      if((a.compareTo(BigInteger.ZERO) == -1) ||
         (b.compareTo(BigInteger.ZERO) == -1))
         break;
      if(!reconstruct)
        break;
      System.out.println(a+" "+b);
      return;
    } while(false);

    System.out.println("impossible");
  }

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for(int i=0; i<T; i++) {
      BigInteger s = sc.nextBigInteger();
      BigInteger d = sc.nextBigInteger();
      new Main().calculate(s,d);
    }
  }
}

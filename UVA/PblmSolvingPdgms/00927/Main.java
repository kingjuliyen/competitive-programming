// 927 - Integer Sequences from Addition of Terms
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=11&page=show_problem&problem=868
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;
import java.lang.*;
import java.math.*;

public class Main {
    class IntSeq {
      private int coeff[];
      private int d, k;

      IntSeq(int _coeff[], int _d, int _k) {
        coeff = _coeff; d = _d; k = _k;
      }

      void solve() {
        int x = 0, acc = 0; // accumulator
        BigInteger acbig = new BigInteger("0");

        for (int i=1; i<=1000000; i++) {
          int oldAcc = acc;
          acc += d * i;
          if(k > oldAcc && k <= acc) {
            x = i;
            break;
          }
        }

        for(int i=0; i<coeff.length; i++) {
          BigInteger cf = new BigInteger(Integer.toString(coeff[i]));
          BigInteger x1 = new BigInteger(Integer.toString(x));
          acbig = acbig.add(cf.multiply(x1.pow(i)));
        }
       System.out.println(acbig);
      }
    }

    public static void main(String args[]) {
      Scanner sc = new Scanner(System.in);
      int count = Integer.parseInt(sc.next());

      for(int i=0; i<count; i++) {
        int num = Integer.parseInt(sc.next()) + 1; // +1 for constant in polynomial
        int coef[] = new int[num];

        for(int j=0; j<num; j++) {
          coef[j] = Integer.parseInt(sc.next());
        }

        int d = Integer.parseInt(sc.next());
        int k = Integer.parseInt(sc.next());

        IntSeq isq = new Main(). new IntSeq(coef, d, k);
        isq.solve();
      }
    }
}

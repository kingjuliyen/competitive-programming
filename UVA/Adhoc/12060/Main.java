// 12060 - All Integer Average
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=242&page=show_problem&problem=3212
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

// This program can be simplified even more, I may do it in the future

import java.util.*;
import java.math.*;

public class Main {
    class Avg {
      Vector<Integer> vi;
      int caseN;
      Avg() {
        vi = new Vector<Integer> ();
        caseN = -1;
      }

      void addElement(int i) {
        vi.add(i);
      }

      void printPureInt(int avg) {
        System.out.println("Case "+caseN+":");
        if(avg<0) {
          System.out.println("- "+Math.abs(avg));
          return;
        }
        System.out.println(avg);
      }

      String rightJustify(String s, int l) {
        int r = l - s.length();
        StringBuffer sb = new StringBuffer();
        for(int i=0; i<r; i++) {
          sb.append(" ");
        }
        sb.append(s);
        return new String(sb);
      }

      String getMiddle(String m, boolean isNegative, int ml) {
        StringBuffer sb = new StringBuffer();
        int l = m.length();
        if(isNegative) {
          l += 2;
          sb.append("- ");
        }
        sb.append(m);
        int numDash = ml - l;
        for(int i=0; i<numDash; i++){
          sb.append("-");
        }
        return new String(sb);
      }

      void print(String upper, String middle, String lower, boolean isNegative) {
        System.out.println("Case "+caseN+":");
        int lu = upper.length();
        int lm = middle.length();
        int ll = lower.length();

        Vector<Integer> vi = new Vector<Integer>();
        vi.add(lu); vi.add(ll);
        Collections.sort(vi);
        int ml = lm+vi.get(vi.size()-1);
        if(isNegative)
          ml += 2;
        String up = rightJustify(upper, ml);
        String low = rightJustify(lower, ml);
        String mid  = getMiddle(middle, isNegative, ml);

        System.out.println(up);
        System.out.println(mid);
        System.out.println(low);
      }

      void printFracBelowOne(int acc, int n) {
        BigInteger biAcc = new BigInteger(new Integer(acc).toString());
        BigInteger biN = new BigInteger(new Integer(n).toString());

        BigInteger gcd = biAcc.gcd(biN);
        biAcc = biAcc.divide(gcd);
        biN = biN.divide(gcd);

        boolean negative = false;
        if(biAcc.compareTo(BigInteger.ZERO) == -1) {
          negative = true;
        }

        BigInteger minusOne = new BigInteger(new Integer("-1").toString());
        if(biAcc.compareTo(BigInteger.ZERO) == -1)
          biAcc = biAcc.multiply(minusOne);
        print(biAcc.toString(), "", biN.toString(), negative);
      }

      void printFracAboveOne(int acc, int n) {
        BigInteger biAcc = new BigInteger(new Integer(acc).toString());
        BigInteger biN = new BigInteger(new Integer(n).toString());

        boolean negative = false;
        if(biAcc.compareTo(BigInteger.ZERO) == -1) {
           negative = true;
        }
        biAcc =   biAcc.abs();

        BigInteger gcd = biAcc.gcd(biN);
        boolean handleAfter = false;

        if(gcd.compareTo(BigInteger.ONE)!=0) {
          handleAfter = true;
        }
        BigInteger low = biN;
        BigInteger mid = biAcc.divide(low);
        BigInteger t = mid.multiply(low);
        BigInteger up = biAcc.subtract(t);

        if(handleAfter) {
          while(true){
            BigInteger _gcd = up.gcd(low);
            if(_gcd.compareTo(BigInteger.ONE)==0){
              break;
            }
            low = low.divide(_gcd);
            up = up.divide(_gcd);
          }
        }
        print(up.toString(), mid.toString(),low.toString(), negative);
      }

      void solve(int caseNum) {
        caseN = caseNum;
        int acc = 0;
        int n = vi.size();
        for(int i=0; i<n; i++) {
          acc += vi.get(i);
        }

        int avg = acc/n;
        if(avg*n == acc){
          printPureInt(avg);
          return;
        }

        int absAcc = Math.abs(acc);
        if(absAcc<n){
          printFracBelowOne(acc, n);
        }
        else if(absAcc > n) {
          printFracAboveOne(acc, n);
        }
      }
    } //   class Avg
    public static void main(String args[]) {
      Scanner sc = new Scanner(System.in);
      int caseNum = 1;
      while(true) {
        int T = sc.nextInt();

        if(T==0)
          break;

        Avg avg = new Main(). new Avg();
        for(int i=0; i<T; i++) {
          avg.addElement(sc.nextInt());
        }
        avg.solve(caseNum++);
      }
    }
}

// 401 - Palindromes
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=342
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;

public class Main {

  class MP { // mirrored palindrome
    String os; // original string

    MP(String s, HashMap<Character, Character> h) {
      os = s;

    }

    char getMirrorChar(char a) {
      Character c = hm.get(a);
      if(c==null)
        return '-';
      return c;
    }

    void solve() {
      int len = os.length();
      int half_limit = len/2;
      boolean isMirrored = false;
      boolean isOnlyMirror = true;
      boolean isPalin = true;

      if(os.length()==1){
        if(os.charAt(0) != getMirrorChar(os.charAt(0)))
          System.out.println(os+" -- is a regular palindrome.");
        else
          System.out.println(os+" -- is a mirrored palindrome.");
        return;
      }

      for(int i=0; i<half_limit; i++) {
        char a = os.charAt(i);
        char b = os.charAt(len-i-1);
        char c = getMirrorChar(a);

        if(a == b) {
          if(a != c) {
            isOnlyMirror = false;
          }
          continue;
        }

        if(b == c) {
          isMirrored = true;
          continue;
        }

        isPalin = false;
        break;
      }

      if(len%2 != 0){
        if(os.charAt(half_limit) != getMirrorChar(os.charAt(half_limit)))
        isOnlyMirror = false;
      }

      if(!isPalin) {
        System.out.println(os+" -- is not a palindrome." );
        return;
      }

      if(!isMirrored && isOnlyMirror == false) {
        System.out.println(os+" -- is a regular palindrome.");
        return;
      }

      if(!isMirrored && isOnlyMirror == true) {
        System.out.println(os+" -- is a mirrored palindrome.");
        return;
      }

      if(isMirrored) {
        System.out.println(os+" -- is a mirrored string.");
        return;
      }
    } //void solve()
  } // class MP

  static HashMap<Character, Character> hm;
  static void setMirrorChars() {
    hm = new HashMap<Character, Character>();
    hm.put('A', 'A');
    hm.put('E', '3');
    hm.put('H', 'H');
    hm.put('I', 'I');
    hm.put('J', 'L');
    hm.put('L', 'J');
    hm.put('M', 'M');
    hm.put('O', 'O');
    hm.put('S', '2');
    hm.put('T', 'T');
    hm.put('U', 'U');
    hm.put('V', 'V');
    hm.put('W', 'W');
    hm.put('X', 'X');
    hm.put('Y', 'Y');
    hm.put('Z', '5');
    hm.put('1', '1');
    hm.put('2', 'S');
    hm.put('3', 'E');
    hm.put('5', 'Z');
    hm.put('8', '8');
  }

  public static void main(String s[]) {
    Scanner sc = new Scanner(System.in);
    setMirrorChars();
    while(sc.hasNext()) {
      String is = sc.next();
      MP mp = new Main(). new MP(is, hm);
      mp.solve();
      System.out.println("");
    }
  }
}

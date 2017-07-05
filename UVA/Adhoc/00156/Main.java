// 156 - Ananagrams
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=92
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;

public class Main {
    class Agm { // Anagram
      Vector<String> avs; // anagram vector strings
      HashMap<String, String> ulm; // upper to lower mapping
      HashMap<String, Integer> sc; // string count
      Agm(Vector<String> _vs) {
        avs = _vs;
        ulm = new HashMap<String, String> ();
        sc = new HashMap<String, Integer>();
      }

      String getSortedchars(String s) {
        Vector<Character> vc = new Vector<Character>();
        for(int i=0; i<s.length(); i++) {
          vc.addElement(s.charAt(i));
        }
        Collections.sort(vc);
        StringBuffer sb = new StringBuffer();
        for(int i=0; i<s.length(); i++) {
          sb.append(vc.elementAt(i));
        }
        return new String(sb);
      }

      void setMapUpperLower(String u, String l){
        if(u==null || l==null)
          return;
        ulm.put(u, l);
      }

      void incrMapDigestCount(String ls) {
        Integer x = sc.get(ls);
        if(x==null) {
          sc.put(ls,1);
        } else {
          if(ls.length()==1)
            return;
          int i = x+1;
          sc.put(ls, i);
        }
      }

      void solve() {
        Collections.sort(avs);
        for(int i=0; i<avs.size();i++) {
          String s = avs.elementAt(i);
          String dg = getSortedchars(s.toLowerCase()); // digest
          setMapUpperLower(avs.elementAt(i),dg);
          incrMapDigestCount(dg);
        }

        for(int i=0; i<avs.size();i++) {
          String os = avs.elementAt(i); // original string
          String dg = ulm.get(os);
          Integer x = sc.get(dg);
          if(x==1 || os.length()==1) {
            System.out.println(os);
          }
        }

      }
    }
    static Vector<String> vs;

    public static void main(String args[]) {
      Scanner sc = new Scanner(System.in);
      vs = new Vector<String>();
      while(sc.hasNext()) {
        String s = sc.next();
        if(s.equals("#"))
          break;
        vs.add(s);
      }
      Agm agm = new Main(). new Agm(vs);
      agm.solve();
    }
}

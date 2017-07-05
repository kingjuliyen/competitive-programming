// 454 - Anagrams
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=395
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;

public class Main {
  class AGM {
     Scanner sc;
     Vector <String> vsi;
     HashMap<String, Vector <String> > hmvs;
     HashMap<String, String> dgMap;

     AGM (Scanner _sc){
       sc = _sc;
       vsi = new Vector <String>();
     }
     void readInputs() {
       while(true) {
         if(!sc.hasNextLine())
          break;
         String s = sc.nextLine();
         if(s.length() ==  0)
          break;
         vsi.add(s);
       }
       Collections.sort(vsi);
     }

     String getDigest(String s) {
       Vector <Character> vc = new Vector <Character>();
       for(int i=0; i<s.length(); i++) {
         char c = s.charAt(i);
         if(c==' ')
          continue;
          vc.add(c);
       }
       Collections.sort(vc);
       StringBuffer sb = new StringBuffer();
       for(int i=0; i<vc.size(); i++) {
         sb.append(vc.elementAt(i));
       }
       return new String(sb);
     }

     void addToHashSet(String s, String dg) {
       dgMap.put(s, dg);
       Vector <String> vs = hmvs.get(dg);
       if(vs == null) {
         vs = new Vector <String> ();
         hmvs.put(dg, vs);
       }
       vs.add(s);
     }

     void solve() {
       hmvs = new HashMap<String, Vector <String> > ();
       dgMap = new HashMap<String, String> ();

       for(int i=0; i<vsi.size(); i++) {
         String s = vsi.elementAt(i);
         String dg = getDigest(s);
         addToHashSet(s, dg);
       }
       printOutput();
     }

     boolean isDuplicate(Vector<String> vs, int pos) {
       int prev = pos -1;
       if(prev<0||prev>=vs.size()) {
         return false;
       }
       if(pos<0||pos>=vs.size()) {
         return false;
       }
       String p = vs.elementAt(prev);
       String cur = vs.elementAt(pos);
      return p.equals(cur);
    }

     void printOutput() {
       for(int i=0; i<vsi.size(); i++) {
         String s = vsi.elementAt(i);
         String dg = dgMap.get(s);
         Vector<String> vs = hmvs.get(dg);
         int start = vs.indexOf(s) +1;
         if(isDuplicate(vsi, i)) {
           continue;
         }
         for(int j=start; j<vs.size(); j++) {
           String anagram = vs.elementAt(j);
           System.out.println(s+" = "+anagram);
         }
       }
     }


  } // class AGM

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    String num = sc.nextLine();
    int T = new Integer(num);
    sc.nextLine();
    for(int i=0; i<T; i++) {
      AGM agm = new Main(). new AGM(sc);
      agm.readInputs();
      agm.solve();
      if(!(i==T-1))
        System.out.println();
    }
  }
}

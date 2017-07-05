// 00195 - Anagram
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=131

// This solution gets time limit exceeded

import java.util.*;

public class Main {

  class WG { // word generator
    Vector<Character> vc;
    WG(String s) {
      vc = new Vector<Character>(s.length());
      for(int i=0; i<s.length(); i++) {
        vc.add(s.charAt(i));
      }
    }

    Vector<StringBuffer> baseCase(Vector<Character> cc){
      Vector<StringBuffer> combinations = new Vector<StringBuffer>();
      if(cc.size()==1){
        StringBuffer sb1 = new StringBuffer();
        sb1.append(cc.elementAt(0));
        combinations.add(sb1);
      }
      if(cc.size()==2) {
        StringBuffer sb1 = new StringBuffer();
        sb1.append(cc.elementAt(0));
        sb1.append(cc.elementAt(1));

        StringBuffer sb2 = new StringBuffer();
        sb2.append(cc.elementAt(1));
        sb2.append(cc.elementAt(0));

        combinations.add(sb1);
        combinations.add(sb2);
      }
      return combinations;
    }

    Vector<Character> getInputForLowerCombo(Vector<Character> cc) {
      Vector<Character> vsb = new Vector<Character> ();
      for(int i=1; i<cc.size(); i++){
        vsb.add(cc.elementAt(i));
      }
      return vsb;
    }

    StringBuffer insert(StringBuffer baseStr, int pos, char nc) { // nc new char
      //System.out.println(" baseStr: "+baseStr+ " pos "+pos+" nc "+nc);
      int len = baseStr.length()+1;
      StringBuffer sb = new StringBuffer(len);
      int di = 0; // dest index
      int si = 0; // source index

      while(di<pos && si<baseStr.length()) {
        //System.out.println(" si "+si);
        char c = baseStr.charAt(si++);
        sb.append(c);
        di++;
      }
      //System.out.println(sb);
      sb.append(nc);
      di++;

      while(di<len && si<baseStr.length()) {
        char c = baseStr.charAt(si++);
        sb.append(c);
        di++;
      }
      //System.out.println("|"+sb+"|");
      return sb;
    }

    Vector<StringBuffer> getNextHigherCombo(char c, Vector<StringBuffer> lowerCombo) {
      Vector<StringBuffer> vsb = new Vector<StringBuffer> ();
      int len = lowerCombo.elementAt(0).length()+1;

      for(int i=0; i<lowerCombo.size()+1; i++) {
        for(int j=0; j<lowerCombo.size(); j++){
          //System.out.println(" lowerCombo "+lowerCombo+" i "+i+" c "+c);
          StringBuffer sb = insert(lowerCombo.elementAt(j), i, c);
          vsb.add(sb);
        }
      }
      return vsb;
    }

    Vector<StringBuffer> generateCombinations(Vector<Character> cc) {
      if(cc.size() <= 2) {
        //System.out.println("cc.size() == 2");
        return baseCase(cc);
      }
      Vector<Character> lowerCombo = getInputForLowerCombo(cc);
      Vector<StringBuffer> lowerComboTemplate = generateCombinations(lowerCombo);
      Vector<StringBuffer> combinations = getNextHigherCombo(cc.elementAt(0), lowerComboTemplate);
      return combinations;
    }

    void printResults(Vector<StringBuffer> vsb) {
      Vector<String> vs = new Vector<String>();
      HashMap<String, Integer> m = new HashMap<String, Integer>();

      for(int i=0; i<vsb.size(); i++) {
        String s = new String(vsb.elementAt(i));
        Integer x = m.get(s);
        if(x == null) {
          vs.add(s);
          m.put(s, 1);
        }
      }
      Collections.sort(vs);
      for(int i=0; i<vs.size(); i++) {
        System.out.println(vs.elementAt(i));
      }
    }

    void solve() {
      Vector<StringBuffer> vsb = generateCombinations(vc);
      printResults(vsb);
    }
  }

  public static void main(String args[]) {
      Scanner sc = new Scanner(System.in);
      int T = sc.nextInt();
      for(int i=0; i<T; i++) {
        String s = sc.next();
        WG wg = new Main(). new WG(s);
        wg.solve();
      }
  }
}

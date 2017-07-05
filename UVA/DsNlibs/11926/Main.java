// 11926 Multitasking
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3077
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;

public class Main {

  class MT {
    final static int MAXBITS = 1000000;
    BitSet bst;
    Vector<Integer> otT;
    Vector<Integer> repT;
    int maxValidBitIndex(){
      return MAXBITS - 1;
    }

    MT() {
      bst = new BitSet(MAXBITS);
      otT = new Vector<Integer>();
      repT = new Vector<Integer>();
    }

    boolean set(int beg, int end) {
        int nxt = bst.nextSetBit(beg);
        if(nxt> 0 && nxt <end) {
          return false;
        }
        if(end>maxValidBitIndex())
          end = maxValidBitIndex();
        bst.set(beg, end);
        //System.out.println("set return true");
        return true;
    }

    void addOneTimeTask(int start, int end) {
      //System.out.println("addOneTimeTask start "+start+" end "+end);
      otT.add(start);
      otT.add(end);
    }

    void addRepeatingTask(int start, int end, int duration) {
      //System.out.println("addRepeatingTask start "+start+" end "+end+" duration "+duration);
      repT.add(start);
      repT.add(end);
      repT.add(duration);
    }

    void printResult(boolean b){
      if(b)
        System.out.println("NO CONFLICT");
      else
        System.out.println("CONFLICT");
    }

    boolean addOneTimeTasks(){
      for(int i=0; i<otT.size(); i += 2){
        int start = otT.get(i);
        int end = otT.get(i+1);
        //System.out.println("Adding one time task start "+start+" end "+end);
        if(!set(start, end)) {
          return false;
        }
      }
      //System.out.println("addOneTimeTasks returning true");
      return true;
    }

    boolean setRepTask(int start, int end, int duration) {
      int _start = start;
      int _end = end;
      //System.out.println("setRepTask start "+start+" end "+end+" duration "+duration);

      while(true) {
        if(_start>maxValidBitIndex() /*|| _end >=maxValidBitIndex()*/)
          break;
        //System.out.println("setRepTask _start "+_start+" _end "+_end+" duration "+duration);
        boolean b = set(_start, _end);
        if(!b) {
          //System.out.println("setRepTask got false");
          return false;
        }
        _start += duration;
        _end += duration;
        //System.out.println("new _start "+_start+" _end "+_end+" duration "+duration);
      }
      //System.out.println(" return true setRepTask start "+_start+" end "+_end+" duration "+duration);
      return true;
    }

    boolean addRepeatingTasks() {
      for(int i=0; i<repT.size(); i += 3){
        int start = repT.get(i);
        int end = repT.get(i+1);
        int duration = repT.get(i+2);
        //System.out.println("Adding rep time task start "+start+" end "+end+" duration "+duration);
        if(!setRepTask(start, end, duration))
          return false;
      }
      return true;
    }

    void solve(){
      boolean b = false;
      do {
        if(!addOneTimeTasks())
          break;
        if(!addRepeatingTasks())
          break;
        b = true;
      } while(false);
      printResult(b);
    }
  }

  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int count = 1;
    while(true) {
      int n = sc.nextInt();
      int m = sc.nextInt();

      if(n==0 && m==0)
        break;
      int i1, i2, i3;
      MT mt = new Main(). new MT();
      // System.out.println("count "+count);

      for(int i=0; i<n; i++){
        i1 = sc.nextInt();
        i2 = sc.nextInt();
        // if(count == 55 || count ==60 )
        //   System.out.println("i1 "+i1+" i2 "+i2);
        mt.addOneTimeTask(i1, i2);
      }

      for(int i=0; i<m; i++){
        i1 = sc.nextInt();
        i2 = sc.nextInt();
        i3 = sc.nextInt();
        // if(count == 55 || count ==60 )
        //   System.out.println("i1 "+i1+" i2 "+i2+" i3 "+i3);
        mt.addRepeatingTask(i1, i2, i3);
      }
      mt.solve();
      count++;
    }
  }
}

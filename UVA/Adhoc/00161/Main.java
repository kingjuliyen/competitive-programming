// 161 - Traffic Lights
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=97
// Some notes at the end
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;

public class Main {

  class CT {

    static final int GREEN = 3;
    static final int ORANGE = 8;
    static final int RED = 5;

    int cycleTime;
    int greenCycle;
    int orangeCycle;
    int redCycle;
    int counter;
    int curColor;
    int greenLimit;
    int orangeLimit;
    int redLimit;
    String red;
    String green;
    String orange;

    CT(int t) {
      cycleTime = t*2;
      orangeCycle = 5;
      greenCycle = t - orangeCycle;
      redCycle = t;

      greenLimit = greenCycle;
      orangeLimit = greenCycle + orangeCycle;
      redLimit = greenCycle + orangeCycle + redCycle;

      counter = 0;
      curColor = GREEN;
      red = new String("RED");
      green = new String("GREEN");
      orange = new String("ORANGE");
    }

    int getColor() {
      if(counter >= 1 && counter <=greenLimit)
        return GREEN;
      if(counter > greenLimit && counter <= orangeLimit)
        return ORANGE;
      if(counter > orangeLimit && counter <= redLimit)
        return RED;
      return -1;
    }

    void setNext() {
      counter++;
      if(counter == (cycleTime+1))
        counter = 1;
      curColor = getColor();
    }

    String getCurColorName() {
      return getColorName(curColor);
    }

    String getColorName(int color) {
      switch(color) {
        case GREEN:
          return green;
        case ORANGE:
          return orange;
        case RED:
          return red;
      }
      return null;
    }

  } // class CT

  class TL {
    Vector<Integer> vi;
    Vector<CT> vct;
    int minCutOff;

    TL(Vector<Integer> _vi) {
      vct = new Vector<CT> ();
      minCutOff = Collections.min(_vi) - (5+1);
      for(int i=0; i<_vi.size(); i++) {
        vct.add(new CT(_vi.elementAt(i)));
      }
    }

    int max_wait_time() {
      return (5 * 60 * 60);
    }

    String twoDigits(int v) {
      String x = ""+v;
      StringBuffer sb = new StringBuffer();
      if(x.length()==1){
        sb.append("0");
      }
      sb.append(x);
      return new String(sb);
    }

    void printResult(int cumSeconds) {
      if(cumSeconds > max_wait_time()){
        System.out.println("Signals fail to synchronise in 5 hours");
        return;
      }
      int hour = cumSeconds / (60*60);
      int minutes = (cumSeconds - (hour*(60*60))) / 60;
      int seconds = cumSeconds - ((hour*(60*60))  + (minutes*60));
      System.out.println(twoDigits(hour)+":"+ twoDigits(minutes)+ ":"+twoDigits(seconds));
    }

    void solve() {
      int FIVE_HOURS = max_wait_time();
      for(int ct=0; ct<=FIVE_HOURS; ct++) {
        int greenCounter = 0;
        for(int i=0; i<vct.size();i++) {
          CT ctObj = vct.elementAt(i);
          ctObj.setNext();
          if(ctObj.getColor() == CT.GREEN){
            greenCounter++;
          }
        }
        if(greenCounter == vct.size() && ct > minCutOff) {
          printResult(ct);
          return;
        }
      } // for(int ct=0; ct<FIVE_HOURS; ct++)
      printResult(max_wait_time()+5);
    }
  } // class TL

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int zeros = 0;
    Vector<Integer> vi = new Vector<Integer>();

    while(true) {
      int v = sc.nextInt();

      if(v == 0) {
        zeros++;
        if(zeros >= 3) {
          TL tl = new Main(). new TL(vi);
          tl.solve();
          break;
        }
        continue;
      }

      if(zeros > 0) {
        zeros--;
        TL tl = new Main(). new TL(vi);
        tl.solve();
        vi = new Vector<Integer>();
      }
      vi.add(v);
    }
  }
}

/*
  Just simulate the events for max five hours if all lights turn green at any point stop and print result
  Start with green as start signal for simulation
  Order of signal: GREEN -> ORANGE -> RED
*/

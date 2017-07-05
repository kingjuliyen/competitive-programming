// 579 - Clock Hands
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=520

import java.util.*;

public class Main {

static String  getFormattedResult(float v) {
      String s = null;
      Float fv = v;
      StringBuffer sb = new StringBuffer(fv.toString());
      int counter =0;
      boolean flag = false;
      int l = -1;
      for(int i=0; i<sb.length(); i++) {
        if(flag){
          counter++;
        }
        if(sb.charAt(i) == '.') {
          flag = true;
          l = i;
        }
      }
      if(counter>3) {
        int j = counter -3;
        int last = sb.length()-1;
        for(int k=last; j>0; k--) {
          sb.deleteCharAt(k);
          j--;
        }
      }
      else if(counter<3) {
        int j = 3 - counter;
        for(int i=0; i<j;i++) {
          sb.append('0');
        }
      }
      s = new String(sb);
      return s;
    }

  public static void main(String args[]) {
      Scanner sc = new Scanner(System.in);
      while(sc.hasNext()) {
        String s = sc.next();
        String v[] = s.split(":");
        float hour = Float.parseFloat(v[0]);
        float minute = Integer.parseInt(v[1]);

        if(hour == 0 && minute == 0)
          break;

        float d = Math.abs((minute * 6) - (((minute/12) + (hour*5)) * 6));
        System.out.println(getFormattedResult(Math.min(d,(360-d))));
      }
  }
}

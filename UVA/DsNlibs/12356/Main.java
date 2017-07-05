// 12356 - Army Buddies
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=278&page=show_problem&problem=3778

/*
  This solution gets a TLE possibly because of Scanner slow performance
  Same solution in c++ gets AC
*/

import java.util.*;

public class Main {

  class AB { // Army Buddies
    int leftSoldier[];
    int rightSoldier[];

    AB(int S) {
      leftSoldier = new int[S+1];
      rightSoldier = new int[S+1];
      for(int i=2; i<S; i++) {
        rightSoldier[i] = i+1;
        leftSoldier[i] = i-1;
      }

      rightSoldier[0] = -1;
      leftSoldier[0] = -1;

      if(S==1) {
        rightSoldier[1] = -1;
        leftSoldier[1] = -1;
      }
      else {
        rightSoldier[1] = 2;
        leftSoldier[1] = -1;
        rightSoldier[S] = -1;
        leftSoldier[S] = S-1;
      }
    }

    void markSoldierAsLost(int soldier) {
      if(soldier>=1 && soldier<=rightSoldier.length){
        rightSoldier[soldier] = -1;
        leftSoldier[soldier] = -1;
      }
    }

    String getStr(int i){
      if(i==-1)
        return new String("*");
      return new Integer(i).toString();
    }

    void pr(int lj, int rj, int start, int end) {
      StringBuffer sb = new StringBuffer();
      sb.append(getStr(lj));
      sb.append(" ");
      sb.append(getStr(rj));
      System.out.println(sb);
    }

    void prepareLossReport2(int start, int end) {
      int leftNode = leftSoldier[start];
      int rightNode =rightSoldier[end];

      if(leftNode >=1 && leftNode <= rightSoldier.length)
        rightSoldier[leftNode] = rightNode;
      if(rightNode>=1 && rightNode <=rightSoldier.length)
        leftSoldier[rightNode] = leftNode;

      markSoldierAsLost(start);
      markSoldierAsLost(end);
      int leftJoiner = leftNode;
      int rightJoiner = rightNode;
      pr(leftJoiner, rightJoiner, start, end);
    }

  }

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    while(true) {
      int S = sc.nextInt();
      int B = sc.nextInt();

      if(S==0 && B==0)
        break;

      AB ab = new Main(). new AB(S);
      for(int i=0; i<B;i++) {
        int L = sc.nextInt();
        int R = sc.nextInt();
        ab.prepareLossReport2(L, R);
      }
      System.out.println("-");
    }
  }
}

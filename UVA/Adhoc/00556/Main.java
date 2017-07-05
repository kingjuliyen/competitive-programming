// 556 - Amazing
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=497
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;

public class Main {

  class Amazing {
    int rows;
    int cols;
    int matrix[];
    int mc[];
    int forwardDirection;

    static final int NORTH = 2;
    static final int SOUTH = NORTH +1;
    static final int EAST = SOUTH + 1;
    static final int WEST = EAST +1;

    int curRow, curCol;

    Amazing(int r, int c) {
      rows = r;
      cols = c;
      matrix = new int[rows*cols];
      mc = new int[rows*cols];
      forwardDirection = EAST;
      curRow = rows-1;
      curCol = 0;
      for(int i=0; i<mc.length; i++){
        mc[i] = 0;
      }
    }

    void setCount(int r, int c, int v) {
      if(r<0|| r>=rows || c<0 || c>=cols)
        return;
      mc[(r*cols) + c] = v;
    }

    void incrCount(int r, int c) {
      setCount(r, c, (getCount(r,c)+1));
    }

    int getCount(int r, int c) {
      if(r<0|| r>=rows || c<0 || c>=cols)
        return -1;
      return mc[(r*cols) + c];
    }

    void set(int r, int c, int v) {
      if(r<0|| r>=rows || c<0 || c>=cols)
        return;
      matrix[(r*cols) + c] = v;
    }

    int get(int r, int c) {
      if(r<0|| r>=rows || c<0 || c>=cols)
        return -1;
      return matrix[(r*cols) + c];
    }

    void setPos(int r, int c) {
      incrCount(curRow, curCol);
      curRow = r;
      curCol = c;
    }

    void abortProgram() {
      int r = rows+1;
      int c = cols+1;
      matrix[(r*cols) + c] = 3;
    }

    void addRow(int r, String s) {
      for(int c=0; c<cols; c++){
        int v = -1;
        if(s.charAt(c) == '0')
          v = 0;
        else
          v = 1;
        set(r,c,v);
      }
    }

    void print(boolean showCurrentPosition) {
      for(int r=0; r<rows; r++) {
        StringBuffer sb = new StringBuffer();
        for(int c=0; c<cols; c++) {
          if(r == curRow && c == curCol) {
            sb.append("X"+" ");
            continue;
          }
          sb.append(get(r,c)+" ");
        }
        sb.append("                    #");
        System.out.println(sb);
      }
      System.out.println("                              #");
    }

    boolean isTerminated() {
      boolean b = (curRow == (rows-1) && curCol == 0);
      return b;
    }

    boolean isWithinMaze(int r, int c) {
      return !(r<0|| r>=rows || c<0 || c>=cols);
    }

    Vector<Integer> getNextPossibleMoveRowCol() {
      int r = curRow;
      int c = curCol;

      switch(forwardDirection) {
        case NORTH:
        r -= 1;
        c = curCol;
        break;

        case SOUTH:
        r += 1;
        c = curCol;
        break;

        case EAST:
        r = curRow;
        c += + 1;
        break;

        case WEST:
        r = curRow;
        c -= 1;
        break;
      }
      Vector<Integer>  vi = new Vector<Integer> ();
      vi.add(r);
      vi.add(c);
      return vi;
    }

    Vector<Integer> canMoveForward() {
      Vector<Integer>  vi = getNextPossibleMoveRowCol();
      int r = vi.elementAt(0);
      int c = vi.elementAt(1);

      if(!isWithinMaze(r,c))
        return null;
      if(get(r,c) == 1)
        return null;

      return vi;
    }

    void rotate() {
      switch(forwardDirection) {
        case NORTH:
        forwardDirection = WEST;
        break;
        case SOUTH:
        forwardDirection = EAST;
        break;
        case EAST:
        forwardDirection = NORTH;
        break;
        case WEST:
        forwardDirection = SOUTH;
        break;
      }
    }

    boolean isWallAtRight() {
      int r = curRow;
      int c = curCol;

      switch(forwardDirection) {
        case NORTH:
        c += 1;
        break;
        case SOUTH:
        c -= 1;
        break;
        case EAST:
        r += 1;
        break;
        case WEST:
        r -= 1;
        break;
      }

      if(!isWithinMaze(r, c))
        return true;
      if(get(r, c) == 1)
        return true;
      return false;
    }

    void turnRight() {
      switch(forwardDirection) {
        case NORTH:
        forwardDirection = EAST;
        break;
        case SOUTH:
        forwardDirection = WEST;
        break;
        case EAST:
        forwardDirection = SOUTH;
        break;
        case WEST:
        forwardDirection = NORTH;
        break;
      }
    }

    void oneStepForward() {
      if(isTerminated())
        return;
      Vector<Integer> vi = canMoveForward();
      if(vi != null) {
        setPos(vi.elementAt(0), vi.elementAt(1));
      }
    }

    void ensureWallAtRight() {
      if(isWallAtRight())
      return;

      turnRight();
      oneStepForward();
    }

    void moveRobot() {
      boolean moveDone = false;
      while(!moveDone) {
        Vector<Integer>  vi = canMoveForward();
        if(vi == null) {
          rotate();
        } else {
          setPos(vi.elementAt(0), vi.elementAt(1));
          ensureWallAtRight();
          moveDone = true;
        }
      }
    }

    String rightJustify(String s) {
      int len = s.length();
      int n = 3-len;
      StringBuffer sb = new StringBuffer();
      for(int i =0; i<n; i++) {
        sb.append(" ");
      }
      sb.append(s);
      return new String(sb);
    }

    void printResults() {
      int v[] = new int[5];
      for(int i=0; i<v.length; i++) { v[i] = 0; }

      for(int r=0; r<rows; r++) {
        StringBuffer sb1 = new StringBuffer();
        for(int c=0; c<cols; c++) {
          if(get(r,c)==0) {
            int x = getCount(r,c);
            if(x>=0 && x<=4)
              v[x]++;
          }
          sb1.append(getCount(r, c)+" ");
        }
      }

       StringBuffer sb = new StringBuffer();
       for(int i=0; i<v.length; i++) {
        String s1 = rightJustify(new Integer(v[i]).toString());
         sb.append(s1);
       }
       System.out.println(sb);
    }

    void simulate() {
      int count = 50;
      moveRobot();
      while(!isTerminated()) {
        moveRobot();
      }
      printResults();
    }
  } // class Amazing

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    while(true) {
      int r = sc.nextInt();
      int c = sc.nextInt();

      if(r==0 && c==0)
        break;

      Amazing a = new Main(). new Amazing(r, c);
      for(int i=0; i<r; i++) {
        String rs = sc.next();
        a.addRow(i, rs);
      }
      a.simulate();
    }
  }
}

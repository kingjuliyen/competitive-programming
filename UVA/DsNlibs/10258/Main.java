// 10258 - Contest Scoreboard
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_problem&problem=1199
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;

public class Main {
    class Submission {
      int teamId;
      int probId;
      int duration;
      int subType;

      Submission(int _teamId, int _probId, int _duration, int _subType) {
        teamId = _teamId;
        probId = _probId;
        duration = _duration;
        subType = _subType;
      }
      void print(){
        System.out.println(" teamId "+teamId+" probId "+probId+" duration "+duration+" subType "+subType);
      }
    } // class Submission


    public class Result implements Comparable<Result> {
      int teamId;
      int numSolved;
      int penalty;

      Result(int _teamId, int _numSolved, int _penalty){
        teamId = _teamId;
        numSolved = _numSolved;
        penalty = _penalty;
      }

      public int compareTo(Result r) {
        if(numSolved == r.numSolved) {
          if(penalty == r.penalty) {
            return Integer.compare(teamId, r.teamId);
          } else {
            return Integer.compare(penalty, r.penalty);
          }
        } else {
          return (-1) * Integer.compare(numSolved, r.numSolved);
        }
      }
      void print() {
        System.out.println(teamId+" "+numSolved+" "+penalty);
      }
    } // class


    class CSB {
      final static int maxTeam = 100;
      HashMap<Integer, Vector<Submission>> hm;
      Vector <Result> rs;

      CSB() {
        hm = new HashMap<Integer, Vector<Submission>>();
        rs = new Vector <Result>();
      }

      Vector<Submission> getSubmission(int teamId){
        if(hm.get(teamId) == null){
          hm.put(teamId, new Vector<Submission>());
        }
        return hm.get(teamId);
      }

      void addEntry(int teamId, int probId, int duration, int subType) {
        Vector<Submission> snv = getSubmission(teamId);
        Submission sn = new Submission(teamId, probId, duration, subType);
        snv.add(sn);
      }

      Vector<Integer> calcuatePenalty(int tId, int pbId){
        Vector<Submission> sn = getSubmission(tId);
        boolean submitOk = false;
        int penalty = 0;

        for(int i=0; i<sn.size(); i++){
          Submission s = sn.get(i);
           if(s.probId != pbId)
             continue;

           if(s.subType == 1) {
            submitOk = true;
            penalty += s.duration;
            break;
          }
          else if (s.subType == 0) {
            penalty += 20;
          }
        }

        Vector <Integer> vi = new Vector<Integer>();
        int isSolved = submitOk? 1 : 0;
        penalty = submitOk? penalty : 0;
        vi.add(new Integer(isSolved));
        vi.add(new Integer(penalty));
        return vi;
      }

      void calculatePenalties(int tId) { // teamId == tId
        Vector<Submission> sn = getSubmission(tId);
        HashMap<Integer, Integer> probs = new HashMap<Integer, Integer>();
        int numSolved = 0;

        for(int i=0; i<sn.size(); i++){
          Integer pbid = sn.elementAt(i).probId;
          if(probs.get(pbid)==null){
            probs.put(pbid, new Integer(1));
          }
        }

        Set<Integer> pbs = probs.keySet(); // pbs;
        int penalty = 0;
        for(Integer pbId: pbs){
          Vector<Integer> vi = calcuatePenalty(tId, pbId);
          numSolved += vi.elementAt(0);
          penalty += vi.elementAt(1);
        }
        Result r = new Result(tId, numSolved, penalty);
        rs.add(r);
      }

      void rankContestants () {
        Set<Integer> keys = hm.keySet();
        for(Integer k: keys) {
          calculatePenalties(k);
        }
        Collections.sort(rs);
        for(int i=0; i<rs.size(); i++){
          rs.get(i).print();
        }
      }
    } // class CSB

    static CSB readInput(Scanner sc) {
      CSB csb = new Main(). new CSB();

      while(sc.hasNextLine()) {
        String s = sc.nextLine();
        String[] args = s.split(" ");

        if(s.length()==0)
          break;

        int teamId = Integer.parseInt(args[0]);
        int probId = Integer.parseInt(args[1]);
        int duration = Integer.parseInt(args[2]);
        String subType = args[3];

        if(subType.equals("C")) {
          csb.addEntry(teamId, probId, duration, 1);
        }
        else if(subType.equals("I")) {
          csb.addEntry(teamId, probId, duration, 0);
        }
        else {
          csb.addEntry(teamId, probId, duration, -1);
        }

      }
      return csb;
    }


    public static void main(String args[]) {
      Scanner sc = new Scanner(System.in);
      String s = sc.nextLine();
      int T = Integer.parseInt(s);
      sc.nextLine();

      for(int i=0; i<T; i++) {
        CSB csb = readInput(sc);
        csb.rankContestants();
        if(i!=T-1)
          System.out.println();
      }
    }
}

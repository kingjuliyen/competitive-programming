// 00624 - CD
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=8&page=show_problem&problem=565
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

/*
   N - sum { OPTIMAL SUBSET } = minimum difference, which is (>=0 && <N)
   sum { OPTIMAL SUBSET } should be maximum
   FIND sum and { OPTIMAL SUBSET } -> this is a 0 1 knapsack problem solve by dp
   refer to http://cse.unl.edu/~goddard/Courses/CSCE310J/Lectures/Lecture8-DynamicProgramming.pdf
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template <typename T>
struct M2D  { // Matrix 2D
  int R, C;
  vector<T>  m;
  int SZ()                                      { return R*C; }
  M2D(int _R, int _C, T initval) : R(_R), C(_C) {  m = vector<T> (SZ(), initval); }
  M2D(int _R, int _C) : R(_R), C(_C)            {  m = vector<T> (SZ()); }
  ~M2D()                                        { }
  void set(int r, int c, T val)                 { m[r*C + c] = val; }
  T get(int r, int c)                           { return m[r*C + c]; }
  void print() {
    for(int r=0; r<R; r++) {
      for (int c=0; c<C; c++)
        printf("%10d\t", get(r, c));
      printf("\n");
    }
  }
};

class CD {
public:
  const int N, nt; vector<int> dtn; /* duration */ M2D<int> *B;
  CD(int _N, int _nt): N(_N), nt(_nt), B(new M2D<int>(nt+1, N+1, 0)) { dtn.push_back(-50000);  }
  ~CD()                                                              { delete B;}
  void addDuration(int m)                                            { dtn.push_back(m); }
  int weight(int x)                                                  { return dtn[x]; }
  int benefit(int x)                                                 { return dtn[x]; }

  #define wi (weight(i))
  #define bi (benefit(i))
  #define BG(x, y) (B->get(x, y))

  void doKnapSack() {
    const int W = N, I = nt;

    /*  FIND OPTIMAL ITEMS TO ADD IN KNAPSACK
    for w = 0 to W
        B[0,w] = 0
    for i = 1 to n
        B[i,0] = 0

    for i = 1 to n
        for w = 0 to W
            if wi <= w // item i can be part of the solution
                if bi + B[i-1,w-wi] > B[i-1,w]
                    B[i,w] = bi + B[i-1,w-wi]
                else
                    B[i,w] = B[i-1,w]
            else B[i,w] = B[i-1,w] // wi > w  */

    for(int i=1; i <= I; i++) {
      for(int w=0; w <= W; w++) {
        if(wi <= w) {
          if((bi + BG(i-1, w-wi)) > BG(i-1, w))
            B->set(i, w, bi + BG(i-1, w-wi));
          else
            B->set(i, w, BG(i-1, w));
        }
        else {
          B->set(i, w, BG(i-1, w));
        }
      }
    }

  } // void doKnapSack()

  void printKnapSackItems() {
    /* PRINT ITEMS FROM KNAPSACK
    i=n, k=W
    while i,k > 0
        if B[i,k] ≠ B[i−1,k] then
            mark the ith item as in the knapsack
            i = i−1, k = k-wi
        else
            i = i−1 */

    int i=nt, k=N; stack<int> s;
    while((i >0) && (k >0)) {
      if(B->get(i, k) != B->get(i-1, k) ) {
        s.push(wi);
        k = k-wi;
        i = i-1;
      }
      else
        i = i-1;
    }

    while(!s.empty()) {
      cout << s.top() << " ";
      s.pop();
    }
    cout << "sum:" << B->get(nt, N) << endl;
  }

  void solve() {
    doKnapSack();
    printKnapSackItems();
  }

}; // class CD

int main() {
  int N, nt, m;
  while(cin >> N) {
    cin >> nt;
    CD cd(N, nt);
    while(nt--) {
      cin >> m;
      cd.addDuration(m);
    }
    cd.solve();
  }
}

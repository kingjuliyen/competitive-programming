// 481 - What Goes Up
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=422
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;
typedef vector<int> vi_t;

struct WGU { // What Goes Up
  vi_t X; int N, L,lo, hi, newL, mid, k, *P, *M, *S;
  WGU() { }
  void add(int x) { X.push_back(x); }

  // algo from https://en.wikipedia.org/wiki/Longest_increasing_subsequence
  void algo() {
    for(int i=0; i<N; i++) {
      lo = 1; hi = L;
      while(lo <= hi) {
        mid = ceil((hi+lo)/2);
        if(X[M[mid]] < X[i])
          lo = mid+1;
        else
          hi = mid-1;
      }
      newL = lo;
      P[i] = M[newL - 1];
      M[newL] = i;
      if(newL > L)
        L = newL;
    }
  }

  void reconstruct() {
    S = new int[L];
    k = M[L];
    for(int i=L-1; i>=0; i--) {
      S[i] = X[k];
      k = P[k];
    }
  }

  void init() { N = X.size(); P = new int[N]; M = new int[N+1]; L = 0; }

  void solve() {
    init();
    algo();
    reconstruct();
  }

  void printResult() {
    cout << L << endl << "-" << endl;
    for(int i=0; i<L; i++)
      cout << S[i] << endl;
  }
};

int main() {
  int x;
  WGU wgu;
  while (cin >> x) { wgu.add(x); }
  wgu.solve();
  wgu.printResult();
}

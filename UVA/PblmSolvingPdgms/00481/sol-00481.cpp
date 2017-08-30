// 481 - What Goes Up
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=422
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <limits>
#include <cmath>

using namespace std;
typedef vector<int> vi_t;

struct WGU {
  vi_t X;
  int N, L,lo, hi, newL, mid,k        ,*P, *M, *S;
  WGU() { }
  void add(int x) { X.push_back(x); }
#if 0
P[N]; M[N+1];  L = 0;

for i in range 0 to N-1: // Binary search for the largest positive j ≤ Lsuch that X[M[j]] < X[i]
  lo = 1; hi = L
  while lo ≤ hi:
    mid = ceil((lo+hi)/2)
    if X[M[mid]] < X[i]:
      lo = mid+1
    else:
      hi = mid-1

  newL = lo // After searching, lo is 1 greater than the length of the longest prefix of X[i]
  P[i] = M[newL-1] // The predecessor of X[i] is the last index of the subsequence of length newL-1
  M[newL] = i

  if newL > L: // If we found a subsequence longer than any we've found yet, update L
    L = newL
// ============================================
// Reconstruct the longest increasing subsequence
S[L]
k = M[L]
for i in range L-1 to 0:
  S[i] = X[k]
  k = P[k]

#endif


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
      cout << " " << S[i];
      k = P[k];
    }
  }

  void solve() {
    N = X.size(); P = new int[N]; M = new int[N+1]; L = 0;
    algo();
    reconstruct();
  } // void solve()

  void printResult() {
  } // printResult()
};

int main() {
  int x;
  WGU wgu;
  while (cin >> x) { wgu.add(x); }
  wgu.solve();
  wgu.printResult();
}

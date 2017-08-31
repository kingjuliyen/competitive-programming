

// g++ lis.cpp -std=c++11

/*
  This algo is initially difficult to understand but actually easy once you get the basic idea behind this

  KEY IDEA:
  AT EACH STEP  KEEP BUILDING/ OVERWRITING INCREASING SUB SEQUENCES
  OF VARIOUS POSSIBLE LENGTHS ENSURING THE TAIL ELEMENT IS THE BEST POSSIBLE MINIMAL

  in a sequence 4, 5, 7, 2 -> "2" is the tail element since its the last element

  References:
  1) https://en.wikipedia.org/wiki/Longest_increasing_subsequence
  2) http://www.cdn.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n
  3) https://www.youtube.com/watch?v=S9oUiVYEq7E
  4) https://doi.org/10.1016%2F0012-365X%2875%2990103-X
*/

#include <iostream> 
#include <vector>
#include <cmath>

using namespace std;

vector<int>  X; int N, L, lo, hi, newL, mid, k, *P, *M, *S;
void init() { N = X.size(); P = new int[N]; M = new int[N + 1]; L = 0; }

void LIS() {
  for (int i = 0; i < N; i++) {
    lo = 1; hi = L;
    while (lo <= hi) {
      mid = ceil((hi + lo) / 2);
      if (X[M[mid]] < X[i])
        lo = mid + 1;
      else
        hi = mid - 1;
    }
    newL = lo;
    P[i] = M[newL - 1];
    M[newL] = i;
    if (newL > L)
      L = newL;
  }
}

void reconstruct() {
  S = new int[L]; k = M[L];
  for (int i = L - 1; i >= 0; i--) {
    S[i] = X[k];
    k = P[k];
  }
  for(int i=0; i<L; i++)
    cout << " " << S[i];
  cout << endl;
}

int main() {
  X = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
  init();
  LIS();
  reconstruct();
}

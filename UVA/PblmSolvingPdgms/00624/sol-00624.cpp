// 00624 - CD
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=8&page=show_problem&problem=565
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#if 0
http://cse.unl.edu/~goddard/Courses/CSCE310J/Lectures/Lecture8-DynamicProgramming.pdf

for w = 0 to W
  B[0,w] = 0
for i = 1 to n
  B[i,0] = 0

for i = 1 to n
    for w = 0 to W
        if (wi <= w && (bi + B[i-1, w-wi] > B[i-1,w]))
            B[i, w] = bi + B[i-1, w-wi]
            P[i, w] = -1 * (w-wi)
        else
            B[i, w] = B[i-1, w]
            P[i, w] = w

#endif

#include <iostream>
#include <vector>
using namespace std;

class CD {
public:
  int N, nt;
  vector<int> dtn; // duration
  CD(int _N, int _nt): N(_N), nt(_nt) { }
  void addDuration(int m) { dtn.push_back(m); }
};

int main() {
  int N, nt, m;
  while(cin >> N) {
    cin >> nt;
    CD cd(N, nt);
    while(nt--) {
      cin >> m;
      cd.addDuration(m);
    }
  }
}

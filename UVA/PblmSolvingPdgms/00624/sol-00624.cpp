// 00624 - CD
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=8&page=show_problem&problem=565
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

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

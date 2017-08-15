// 10567 - Helping Fill Bates
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=17&page=show_problem&problem=1508
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <vector>

using namespace std;

class HFB { // Helping Fill Bates
public:
  char * S;
  HFB(char * _S): S(_S) { }
  void solve(char *ss) {
  }
};

int main() {
  const int  sLen = 1000000 + 5, ssLen = 101 + 5;
  char *S = new char[sLen], *SS = new char[sLen];

  scanf("%s", S); // cout << S << endl;
  HFB hfb(S);

  int Q = -1;
  scanf("%d", &Q); // cout << Q << endl;

  while(Q--) {
    scanf("%s", SS); // cout << SS << endl;
    hfb.solve(SS);
  }
}

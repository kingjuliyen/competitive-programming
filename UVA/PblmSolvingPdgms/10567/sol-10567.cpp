// 10567 - Helping Fill Bates
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=17&page=show_problem&problem=1508
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <cstring>
#include <vector>
#include <set>

using namespace std;
typedef vector< set<int> > vsi_t; typedef  set<int> si_t;

class HFB { // Helping Fill Bates
public:
  char * S; size_t Slen; vsi_t charIndexMp;  int sp, ep;
  HFB(char * _S): S(_S), Slen(strlen(S)), charIndexMp(vsi_t ('z'+5) )  { recordCharPositions(); } 
  void addIndex(char c, int p) { si_t &s = charIndexMp[c]; s.insert(p); }
  void recordCharPositions() {
    int lc = Slen/4; // loopcount
    for(int i=0; i<lc; i++) {
      int d = i*4;
      addIndex(S[d+0], d+0); addIndex(S[d+1], d+1); addIndex(S[d+2], d+2); addIndex(S[d+3], d+3); 
    }
    for(int i=lc*4; i<Slen; i++)
      addIndex(S[i], i);
  }

  int find(char c, int msp ) { // msp == min start position
    si_t &s = charIndexMp[c];
    auto it = s.lower_bound(msp);
    return (it == s.end()) ? -1 : *it;
  }

  void solve(char *s) {
    int l = strlen(s), cp = 0;
    sp = -1, cp = 0, ep = -1;
    for(int i=0; i<l; i++, cp++) { // note cp++
      if((cp = find(s[i], cp)) == -1)
        break;
      if(i == 0)
        sp = cp;
      if(i == l-1)
        ep = cp;
    }
  } // solve(char *s)

  void printResult() {
    if(sp>=0 && ep != -1)
      cout << "Matched " << sp << " " << ep << endl;
    else
      cout << "Not matched" << endl;
  }
};

int main() {
  int  sLen = 1000000 + 5, ssLen = 101 + 5, Q = -1;
  char *S = new char[sLen], *SS = new char[sLen];
  scanf("%s", S);
  HFB hfb(S);
  scanf("%d", &Q); // cout << Q << endl;
  while(Q--) {
    scanf("%s", SS); // cout << SS << endl;
    hfb.solve(SS);
    hfb.printResult();
  }
}

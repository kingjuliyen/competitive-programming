// 11340 - Newspaper
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=25&page=show_problem&problem=2315
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class NS {
public:
  map<unsigned char, int> hm;
  vector<string> vs;
  unsigned long long cost;

  NS() {
    cost = 0;
    // System.out.println(" NS cost "+cost);
  }

  void addKey(string s, int v){
    hm[s[0]] = v;
  }

  void addLine(string s) {
    vs.push_back(s);
  }

  void countCost(string s) {
    for(int i=0; i<s.length(); i++) {
      int x = hm[s[i]];
      cost += x;
    }
  }

  void printResult() {
    double fc = cost;
    printf("%.2lf$\n",fc/100);
  }

  void solve() {
    for(int i=0; i<vs.size(); i++){
      countCost(vs[i]);
    }
    printResult();
  }
}; // class NS


int main() {
    int N = 0;
    cin >> N;
    for(int i=0; i<N; i++) {
      int K = 0;
      cin >> K;
      NS ns;
      for(int j=0; j<K; j++) {
        string s;
        cin >> s;
        int v = 0;
        cin >> v;
        ns.addKey(s, v);
      }
      int M = 0;
      cin >> M;
      cin.ignore();
      for(int j=0; j<M; j++) {
        string s0;
        getline(cin, s0);
        ns.addLine(s0);
      }
      ns.solve();
    }
}

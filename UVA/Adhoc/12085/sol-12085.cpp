// 12085 - Mobile Casanova
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=242&page=show_problem&problem=3237
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
typedef long long lli;
#define MAXSIZE_PN 100000

typedef struct record {
    int index;
    lli parent_phone_num;
    lli last_child;
    int length;
    record(int _index, lli ppn);
    void print();
} record;

record::record(int _index, lli ppn) {
  index = _index;
  parent_phone_num = ppn;
  last_child = ppn;
  length = 1;
}

string formatPhoneNum(string s) {

  int l = string("2000000000").length();
  int d = l - s.length();
  string ns(s);
  if(ns[0]!='0') {
    ns.insert(0,"0");
  }
  return ns;
}

void printRange(int p, int c) {
  stringstream ss1;
  ss1 << p;
  stringstream ss2;
  ss2 << c;

  string ps(ss1.str());
  string cs(ss2.str());
  vector<char> vc;

  if(ps.length() == cs.length()) {
    string s;
    int ls = 0;

    for(int i=0; i<cs.length(); i++) {
      if(cs[i] != ps[i]) {
        ls = i;
        break;
      }
    }
    for(int i=ls;i<cs.length();i++) {
      s.append(1, cs[i]);
    }
    cout << s;
  }
}

void printResult(record r) {
  stringstream ss;
  ss << r.parent_phone_num;
  string parent = formatPhoneNum(ss.str());
  cout << parent;
  if(r.length>1){
    cout << "-";
    printRange(r.parent_phone_num, r.last_child);
  }
  cout << "\n";
}

void printResult(vector<lli> &vpn, lli T, int cn) { // vector of phone number
  int count = 0;
  int curIndex = 0;
  vector<record> vr;

  record r0(0, vpn[0]);
  vr.push_back(r0);

  for(int i=1; i<T; i++) {
    lli prev = vpn[i-1];
    lli cur = vpn[i];
    lli d = cur - prev;
    int y = vr.size()-1;

    if((cur-prev) == 1) {
      vr[y].length++;
    }
    else {
      vr[y].last_child = vpn[i-1];
      record r(i, cur);
      vr.push_back(r);
    }
  }
  if(vr.size()==1) {
    int y = vpn.size()-1;
    vr[0].last_child = vpn[y];
  }

  if(vr.size()>1) {
    int y = vr.size()-1;
    if(vr[y].length > 1) {
      int index = vr[y].index + vr[y].length -1;
      vr[y].last_child = vpn[index];
    }
  }

  cout << "Case "<<cn<<":\n";
  for(int i=0; i<vr.size();i++) {
    printResult(vr[i]);
  }
}

int main() {
  lli T = -1;
  int caseNum = 1;

  while(true) {
    cin >> T;
    if(!T)
      break;

    vector<lli> vlli(T,-3);
    lli x = -1;

    for(int i=0; i<T; i++) {
      cin >> x;
      vlli[i] = x;
    }

    printResult(vlli, T, caseNum++);
    cout << "\n";
  }
}

// 11221 - Magic square palindromes
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2162
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class MSP { // magic square palindromes
public:
  char * cm;
  vector<string> ow;
  int limit;
  int row;
  int col;
  MSP(string s);
  void solve();
  char get(int r, int c);
  bool check_all_rows_forward();
  bool check_all_cols_forward();
  bool check_all_rows_backward();
  bool check_all_cols_backward();
};

void printResult(bool isPass, int K) {
  static int caseNo = 1;
  cout << "Case #" << caseNo++ << ":\n";
  if(!isPass) {
    cout << "No magic :(" << "\n";
    return;
  } else {
    cout << K << "\n";
  }
}

MSP::MSP(string s) : cm(0), limit(-1) {
  vector<char> vc;
  vector<char> clw; // clean words;
  const char * cp = s.c_str();
  for(int i=0; i < s.length(); i++) {
    char c = cp[i];
    if(c>='a' && c<='z')
      vc.push_back(c);
  }
  int len = vc.size();
  int sqtLen = sqrt(len);
  if((sqtLen * sqtLen) != len) {
    printResult(false, 0);
    return;
  }

  row = col = sqtLen;

  int limit = sqtLen * sqtLen;
  cm = new char[limit];
  for(int i=0; i<limit; i++){
    cm[i] = vc[i];
  }

  int x = 0;
  while(x<limit) {
    string ts;
    for(int i=x; i<x+col; i++) {
      ts.push_back(vc[i]);
    }
    ow.push_back(ts);
    x += col;
  }

}

char MSP::get(int r, int c) {
  if(r < 0 || r >= row)
    return -1;
  if(c < 0 || c >= col)
    return -1;

  return cm[(r*col) + c];
}

bool MSP::check_all_rows_forward() {
  for(int r=0; r < row; r++) {
    const char * cp = ow[r].c_str();
    for(int c=0; c < col; c++) {
      char ch = cp[c];
      if(get(r,c) != ch) {
        return false;
      }
    }
  }
  return true;
}

bool MSP::check_all_cols_forward() {
  for(int c=0; c < col; c++) {
    const char * cp = ow[c].c_str();
    for(int r=0; r < row; r++) {
      char ch = cp[r];
      if(get(r,c) != ch) {
        return false;
      }
    }
  }

  return true;
}

bool MSP::check_all_rows_backward() {
  for(int r = row-1; r >=0; r--) {
    const char * cp = ow[row-r-1].c_str();
    for(int c = col-1; c >=0; c--) {
      char ch = cp[col-c-1];
      if(get(r,c) != ch) {
        return false;
      }
    }
  }
  return true;
}

bool MSP::check_all_cols_backward() {
  for(int c = col-1; c >=0; c--) {
    const char * cp = ow[col-c-1].c_str();
    for(int r = row-1; r >=0; r--) {
      char ch = cp[row-r-1];
      if(get(r,c) != ch) {
        return false;
      }
    }
  }
  return true;
}

void MSP::solve() {
  if(!cm)
    return;

  if(!check_all_rows_forward()) {
    printResult(false, 0);
    return;
  }
  if(!check_all_cols_forward()) {
    printResult(false, 0);
    return;
  }
  if(!check_all_rows_backward()) {
    printResult(false, 0);
    return;
  }
  if(!check_all_cols_backward()) {
    printResult(false, 0);
    return;
  }
  printResult(true, row);
}

int main() {
  string s;
  int T=0;
  cin >> T;
  cin.ignore();
  for(int i=0; i<T; i++) {
    getline(cin, s);
    MSP msp(s);
    msp.solve();
  }
}

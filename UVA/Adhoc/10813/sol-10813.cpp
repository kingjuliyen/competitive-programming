// 10813 - Traditional BINGO
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=20&page=show_problem&problem=1754
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class BC { // BINGO CARD
public:
  BC();
  int * card;
  vector<int> vi;

  void readCard();
  void readBingoNumbers();
  void solve();
  void addRow(int v1, int v2, int v3, int v4, int v5, int _row);
  int get(int r, int c);
  void set(int r, int c, int val);
  bool checkWinner();
  bool insertNumber(int val);
  void print();

  int checkRow(int r);
  int checkCol(int r);
  bool checkRows() ;
  bool checkCols();
  bool checkDiag();
};

int limit() { return 5*5; }
BC::BC() {
  int l = limit();
  card = new int[l];
  for(int i=0; i<l; i++)
    card[i] = -2;
}

int BC::get(int r, int c) {
  if(r < 0 || r >=5 || c < 0 || c >=5)
    return -1;
  int offset = (r*5) + c;
  return card[offset];
}

void BC::set(int r, int c, int val) {
  if(r < 0 || r >= 5 || c < 0 || c >= 5)
    return;
  int offset = (r*5) + c;
  card[offset] = val;
}

void BC::addRow(int v1, int v2, int v3, int v4, int v5, int _row) {
  set(_row, 0, v1);
  set(_row, 1, v2);
  set(_row, 2, v3);
  set(_row, 3, v4);
  set(_row, 4, v5);
}

void BC::readCard() {
  for(int i=0; i<5;i++) {
    vector<int> vi2;
    string s;
    getline(cin, s);
    stringstream ss(s);
    int x;
    while(ss >> x) {
      vi2.push_back(x);
    }

    if(i==2) {
      addRow(vi2[0], vi2[1], -5 , vi2[2], vi2[3], i);
    }
    else{
      addRow(vi2[0], vi2[1], vi2[2], vi2[3], vi2[4], i);
    }
    vi2.clear();
  }
}

void BC::readBingoNumbers() {
  string s;
  while(getline(cin, s)) {
    stringstream ss(s);
    int x = 0;
    while(ss >> x) {
      vi.push_back(x);
      if(vi.size() == 75)
        return;
    }
  }
}

bool between(int val, int a, int b) {
  if(val >= a && val <= b)
    return true;
  return false;
}

int getCol(int val){
  if(between(val, 1 , 15))
    return 0;
  else if (between(val, 16, 30))
    return 1;
  else if (between(val, 31, 45))
    return 2;
  else if (between(val, 46, 60))
    return 3;
  else if(between(val, 61, 75))
    return 4;
  else
    return -1;
}

bool BC::insertNumber(int val) {
  int c = getCol(val);
  for(int r=0; r<5; r++) {
    if(get(r,c) == val) {
      set(r,c, -50);
      return true;
    }
  }
  return false;
}

int BC::checkRow(int r) {
  int v = 0;
  for(int c=0;c<5;c++) {
    if(get(r, c) == -50)
      v++;
  }
  return v;
}

bool BC::checkRows() {
  if(checkRow(2)==4)
      return true;

  if(checkRow(0)==5)
    return true;
  if(checkRow(1)==5)
      return true;
  if(checkRow(3)==5)
      return true;
  if(checkRow(4)==5)
        return true;
  return false;
}

int BC::checkCol(int c) {
  int v = 0;
  for(int r=0; r<5; r++){
    if(get(r,c) == -50)
      v++;
  }
  return v;
}

bool BC::checkCols() {
  if(checkCol(2)==4)
      return true;

  if(checkCol(0)==5)
    return true;
  if(checkCol(1)==5)
      return true;
  if(checkCol(3)==5)
      return true;
  if(checkCol(4)==5)
        return true;
  return false;
}

bool BC::checkDiag() {
  int v = 0;
  for(int i=0; i<5;i++){
    if(get(i,i) == -50)
      v++;
  }
  if(v>=4)
    return true;

  v = 0;

  for(int i=4;i>=0;i--){
    if(get(i, (4-i)) == -50)
      v++;
  }

  if(v>=4)
    return true;

  return false;
}

bool BC::checkWinner() {
  if(checkRows())
    return true;
  if(checkCols())
    return true;
  if(checkDiag())
    return true;
  return false;
}

void BC::print() {
    for(int r=0; r<5; r++) {
      for(int c=0; c<5; c++) {
        cout << " " << get(r,c);
      }
      cout << "\n";
    }
}

void BC::solve() {
  for(int i=0; i<vi.size();i++){
    insertNumber(vi[i]);
    if(checkWinner()) {
      cout << "BINGO after "<< (i+1) << " numbers announced" << "\n";
      return;
    }
  }
}

int readNumTests() {
  string s;
  getline(cin, s);
  stringstream ss(s);
  int x;
  while(ss >> x) { }
  return x;
}

int main() {
  int n = readNumTests();
  for(int i=1; i<=n; i++) {
    BC bc;
    bc.readCard();
    bc.readBingoNumbers();
    bc.solve();
  }
}

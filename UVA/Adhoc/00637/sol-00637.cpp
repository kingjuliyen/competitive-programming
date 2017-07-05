// 637 - Booklet Printing
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=8&page=show_problem&problem=578
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>

using namespace std;

class BP { // booklet printing
public:
  int totalPages;
  int curSheet;
  BP(int p);
  void solve();
  void isValid(int *fl, int *fr, int *bl, int *br );
  void print(int fl, int fr, int bl, int br);
  void print(int l, int r, bool isFront);
};

BP::BP(int p) : totalPages(p), curSheet(0) {
}

void BP::isValid(int *fl, int *fr, int *bl, int *br ) {
  int *ipa[4] = {fl, fr, bl, br};
  for(int i=0; i<4; i++) {
    int * x = ipa[i];
    if(*x > totalPages)
      *x = 0;
  }
}

void BP::print(int l, int r, bool isFront) {
  if(!l && !r)
    return;

  cout << "Sheet "<< curSheet <<", ";
  if(isFront)
    cout << "front: ";
  else
    cout << "back : ";

  if(l)
    cout << l << ", ";
  else
    cout << "Blank" << ", ";

  if(r)
      cout << r;
    else
      cout << "Blank";
  cout << "\n";
}

void BP::print(int fl, int fr, int bl, int br) {
  // cout << " fl " << fl << " fr " << fr << " bl " << bl << " br " << br << "\n";
  isValid(&fl, &fr, &bl, &br);
  print(fl, fr, true);
  print(bl, br, false);
}

void BP::solve() {
  int np = totalPages / 4;
  int rem = totalPages - (np * 4);
  // cout << " totalPages " << totalPages << " np " << np << " rem " << rem << "\n";
  if(rem>0)
    np += 1;

  int edge = np*4;
  int inner = 1;
  curSheet = 1;
  cout << "Printing order for "<< totalPages << " pages:" << "\n";
  for(int i=0; i<np; i++) {
    print(edge, inner, inner+1, edge-1);
    inner += 2;
    edge -= 2;
    curSheet++;
  }
}

int main() {
  while(true) {
    int i = 0;
    cin >> i;
    if(i==0)
      break;
    BP bp(i);
    bp.solve();
  }
}

// 00624 - CD
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=8&page=show_problem&problem=565
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com



#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct M2D  {
  int R, C;
  vector<T>  m;
  int SZ() { return R*C; }
  M2D(int _R, int _C, T initval) : R(_R), C(_C) {  m = vector<T> (SZ(), initval); }
  M2D(int _R, int _C) : R(_R), C(_C) {  m = vector<T> (SZ()); }
  ~M2D() { }
  void set(int r, int c, T val) { m[r*C + c] = val; }
  void setd(int r, int c, T val) { cout << " set r "<< r << " c " << c << " val " << val << endl; m[r*C + c] = val; }
  void set(int x, T val) { m[x] = val; }
  T getd(int r, int c) { cout << " get r "<< r << " c " << c << endl; return m[r*C + c]; }
  T get(int r, int c) { return m[r*C + c]; }
  void print() { for(int r=0; r<R; r++) { for (int c=0; c<C; c++)    printf("%10d ", get(r, c));     printf("\n");   }  }
  void test() { for(int i=0; i<SZ(); i++) { set(i, i+1);}  }
};

class CD {
public:
  const int N, nt;
  vector<int> dtn; // duration
  M2D<int> *B, *P;
  CD(int _N, int _nt): N(_N), nt(_nt), B(new M2D<int>(nt+1, N+1, 0)), P(new M2D<int>(nt+1, N+1, 0)) { dtn.push_back(-50000);  }
  ~CD() { /* delete B; delete P; */ }
  void addDuration(int m) { dtn.push_back(m); }
  int weight(int x) { return dtn[x]; }
  int benefit(int x) { return dtn[x]; }

#if 0
http://cse.unl.edu/~goddard/Courses/CSCE310J/Lectures/Lecture8-DynamicProgramming.pdf

for w = 0 to W
    B[0,w] = 0
for i = 1 to n
    B[i,0] = 0

for i = 1 to n
    for w = 0 to W
        if wi <= w // item i can be part of the solution
            if bi + B[i-1,w-wi] > B[i-1,w]
                B[i,w] = bi + B[i-1,w-wi]
            else
                B[i,w] = B[i-1,w]
        else B[i,w] = B[i-1,w] // wi > w
#endif

#define wi (weight(i))
#define bi (benefit(i))
#define BG(x, y) (B->get(x, y))

  void solve() {
    const int W = N, I = nt;

    for(int i=1; i <= I; i++) {
      for(int w=0; w <= W; w++) {
        cout << "\n\n i " << i << " w " << w << endl;
        cout << " wi " << wi << " w " << w << endl;
        if(wi <= w) {
          cout << " (wi <= w) wi " << endl;
          int nb = bi + BG(i-1, w-wi);
          cout << " nb " << nb << " BG(i-1, w) " << (BG(i-1, w)) << endl;
          if(nb > BG(i-1, w)) {
            cout << " nb > BG(i-1, w) \n";
            B->set(i, w, nb);
          }
          else {
            cout << " nb <= BG(i-1, w) \n";
            B->set(i, w, BG(i-1, w));
          }
        }
        else {
          cout << " ! (wi <= w) wi " << endl;
          B->set(i, w, BG(i-1, w));
        }
      }
      B->print();


    }
    B->print();
    cout << "########### " << B->get(I, W) << "\n";
    // cout << "###########\n";
  } // void solve()

}; // class CD {

int main() {
  int N, nt, m;
  while(cin >> N) {
    cin >> nt;
    CD cd(N, nt);
    while(nt--) {
      cin >> m;
      cd.addDuration(m);
    }
    cd.solve();
  }
}

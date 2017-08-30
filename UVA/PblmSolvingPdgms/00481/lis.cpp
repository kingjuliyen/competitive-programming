// 481 - What Goes Up
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=422
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef vector<int> vi_t;

struct WGU {
    vi_t X;
    int N, L,lo, hi, newL, mid,k        ,*P, *M, *S;
    WGU() { }
    void add(int x) { X.push_back(x); }

    void algo() {
        for(int i=0; i<N; i++) {
            cout << endl << " ============= i " << i  << endl;
            lo = 1; hi = L;
            while(lo <= hi) {
                cout << endl << " \tlo " << lo << " hi " << hi << endl;
                mid = ceil((hi+lo)/2);
                cout << " \tmid " << mid << " M[mid] " << M[mid] << " X[M[mid]] " << X[M[mid]] << " X[i] " << X[i];
                if(X[M[mid]] < X[i]) {
                    lo = mid+1;
                    cout << endl << " \tlo = mid+1 " << lo;
                }
                else {
                    hi = mid-1;
                    cout << endl <<" \thi = mid-1 " << hi;
                }
            }
            newL = lo;
            cout << endl << " \t\tnewL " << newL << " M[newL - 1] == " << M[newL - 1];
            P[i] = M[newL - 1];
            M[newL] = i;
            cout << endl << " \t\tM[newL] = i == " << M[newL] ;
            if(newL > L) {                
                L = newL;
                cout << endl << " \t\t(newL > L) L == " << L;
            } 
            else
                cout << " \t\t !(newL > L) L == " << L << endl;
        }
    }

    void reconstruct() {
        S = new int[L];
        k = M[L];
        for(int i=L-1; i>=0; i--) {
            S[i] = X[k];
            // cout << " " << S[i];
            k = P[k];
        }
    }
    
    void solve() {
        N = X.size(); P = new int[N]; M = new int[N+1]; L = 0;
        algo();
        reconstruct();
    } // void solve()
    
    void printResult() {
    } // printResult()
};

int main() {
    
    int vt[] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    int x;
    WGU wgu;
    for(int i=0; i<16; i++) { wgu.add(vt[i]); }
    wgu.solve();
    wgu.printResult();
}

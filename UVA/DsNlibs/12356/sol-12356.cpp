// 12356 - Army Buddies
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=278&page=show_problem&problem=3778
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>

using namespace std;

class AB {
public:
  int * leftSoldier;
  int * rightSoldier;
  int S;

  AB(int _S) {
    S = _S;

    leftSoldier = new int[S+1];
    rightSoldier = new int[S+1];
    for(int i=2; i<S; i++) {
      rightSoldier[i] = i+1;
      leftSoldier[i] = i-1;
    }

    rightSoldier[0] = -1;
    leftSoldier[0] = -1;

    if(S==1) {
      rightSoldier[1] = -1;
      leftSoldier[1] = -1;
    }
    else {
      rightSoldier[1] = 2;
      leftSoldier[1] = -1;
      rightSoldier[S] = -1;
      leftSoldier[S] = S-1;
    }
  }

  void markSoldierAsLost(int soldier) {
    if(soldier>=1 && soldier<=S){
      rightSoldier[soldier] = -1;
      leftSoldier[soldier] = -1;
    }
  }

  void printResult(int l, int r){
    if(l==-1)
      cout << "*";
    else
      cout << l;

    cout << " ";

    if(r==-1)
      cout << "*";
    else
      cout << r;
    cout << "\n";
  }

  void prepareLossReport2(int start, int end) {
    int leftNode = leftSoldier[start];
    int rightNode =rightSoldier[end];

    if(leftNode >=1 && leftNode <= S)
      rightSoldier[leftNode] = rightNode;
    if(rightNode>=1 && rightNode <= S)
      leftSoldier[rightNode] = leftNode;

    markSoldierAsLost(start);
    markSoldierAsLost(end);
    int leftJoiner = leftNode;
    int rightJoiner = rightNode;
    printResult(leftNode, rightNode);
  }
};

int main() {
  while(true) {
    int S = 0;
    int B = 0;
    cin >> S;
    cin >> B;

    if(S==0 && B==0)
      break;
    AB ab(S);
    for(int i=0; i<B;i++) {
      int L = -1;
      int R = -1;
      cin >> L;
      cin >> R;

      ab.prepareLossReport2(L, R);
    }
    cout << "-\n";

  }
}

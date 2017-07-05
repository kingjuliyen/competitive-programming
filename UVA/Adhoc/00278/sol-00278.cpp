// 00278	Chess
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=214
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
using namespace std;

int main() {
	int T = 0, R = 0, C = 0;

	cin >> T;
	while(T--) {
		char c = '-';
		cin >> c >> R >> C;
		switch(c) {
			case 'r': {
			int v = min(R, C);
			cout << v << "\n";				}
			break;

			case 'Q': {
			int v = min(R, C);
			cout << v << "\n";				}
			break;

			case 'k': {
			int v = ((R*C) + 1) /2;
			cout << v << "\n";				}
			break;

			case 'K': {
			int r = (int) (R+1)/2;
			int c = (int) (C+1)/2;
			int v = r * c;
			cout << v << "\n";				}
			break;
		}
	}
}

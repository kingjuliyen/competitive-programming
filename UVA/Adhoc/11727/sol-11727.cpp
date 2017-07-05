//  11727 - Cost Cutting
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=117&page=show_problem&problem=2827
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T = 0;
	cin >> T;
	for(int i=1; i<=T;i++) {
		vector<int> s(3);
		cin >> s[0] >> s[1] >> s[2];
		sort(s.begin(), s.end());
		printf("Case %d: %d\n",i, s[1]);
	}
}

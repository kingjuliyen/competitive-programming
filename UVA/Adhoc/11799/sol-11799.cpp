// 11799 - Horror Dash
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=117&page=show_problem&problem=2899
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T = -1, N = -1, c = -1;
	vector<int> vs;
	scanf("%d",&T);

	for(int i=1; i<=T; i++) {
		vs.clear();
		scanf("%d",&N);

		while(N--) {
			scanf("%d", &c);
			vs.push_back(c);
		}
		sort(vs.begin(), vs.end());
		printf("Case %d: %d\n", i, vs[vs.size()-1]);
	}

	return 0;
}

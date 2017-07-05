// 11559	Event Planning
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=27&page=show_problem&problem=2595
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N = -1, H = -1, W;
	float B = -1, ppw = -1;
	vector<float> prices;

	while(scanf("%d %f %d %d",&N, &B, &H, &W) != EOF) {
		prices.clear();
		for(int i =0; i<H; i++) {
			scanf("%f",&ppw);
			float val = N * ppw;
			int num_rooms = -1;
			for(int j=0; j<W; j++) {
				int r =	scanf("%d", &num_rooms);
				if(num_rooms >= N && (val <= B) ) {
					prices.push_back(val);
				}
			}
		}
		if(prices.size() > 0) {
			sort(prices.begin(), prices.end());
			printf("%d\n", (int)prices[0]);
		} else {
			printf("stay home\n");
		}
	}

	return 0;
}

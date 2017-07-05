// 11172 - Relop
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=23&page=show_problem&problem=2113
// author: Senthil Kumar Thangavelu

#include <cstdio>

void relop(int a, int b) {
	char c;
	if(a>b) {
		c = '>';
	}
	else if (a<b) {
		c = '<';
	}
	else
		c = '=';
	printf("%c\n",c);
}

int main() {
	int TC,a,b;
	scanf("%d",&TC);

	while(TC--) {
		scanf("%d %d",&a, &b);
		relop(a,b);
	}
	return 0;
}

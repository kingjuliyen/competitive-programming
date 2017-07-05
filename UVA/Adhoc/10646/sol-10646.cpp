// 10646 What is the Card?
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=18&page=show_problem&problem=1587
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getVal(string s) {
	char c = *s.c_str();

	if(c >= '2' && c <= '9') {
		return c - 48;
	}
	else
		return 10;
}

void simulate(int trialNum) {
	vector <string> cards;
	for(int i=0; i<52; i++) {
		string card;
		cin >> card;
		cards.push_back(card);
	}

	vector <string> cards2;
	int j = 0;
	for(int i = 27; i < 52; i++) {
		cards2.push_back(cards[i]);
	}

	int Y = 0;
	int T = 3;
	int top = 26;

	while(T--) {
		int X =	getVal(cards[top]);
		Y += X;
		int r = 10 - X;
		int tr = r + 1; // total removed
		top -= tr;
	}

	int start = top + 1;
	int limit = start+25;
	int k = 0;

	for(int i = start; i < limit; i++) {
		cards[i] = cards2[k];
		k++;
	}

	cout << "Case "<< trialNum << ": " << cards[Y-1] << "\n";
}

int main() {
	int T = 0;

	cin >> T;
	for(int i=1; i<=T; i++) {
		simulate(i);
	}
}

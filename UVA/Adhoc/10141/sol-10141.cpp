// 10141 - Request for Proposal
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1082
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <cstdio>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
	int nr = 0 , np = 0, reqmet = 0, high_req = 0;
	float price = -1, prev_low_price = 1E37;
	string b1;
	string prop;
	string m2;

	int rfp = 0;

	while(true) {
		cin >> nr >> np;

		if(!nr || !np)
			break;
		if(rfp>0)
			cout << "\n";

		cin.ignore();

		while(nr--) {
			getline(cin, b1);
		}

		high_req = 0;
		prev_low_price = 1E37;

		while(np--) {
			getline(cin, b1);
			m2 = string(b1);

			cin >> price >> reqmet;
			cin.ignore();

			if(reqmet > high_req) {
				prop = m2;
				high_req = reqmet;
				prev_low_price = price;
			}

			if((reqmet == high_req) &&
				price < prev_low_price) {
				prev_low_price = price;
				prop = m2;
			}

			for(int i=1; i<=reqmet; i++) {
				getline(cin, b1);
			}
		}
		cout << "RFP #" << (++rfp) << "\n";
		cout << prop << "\n";
	}
}

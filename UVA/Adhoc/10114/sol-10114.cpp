// 10114	Loansome Car Buyer
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1055
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <vector>

using namespace std;

void printAnswer(int ans) {
	if(ans==1)
	   	cout << ans << " month\n";
	else
		cout << ans << " months\n";
}

int main() {

	while (true) {
		int months = 0, m = 0, num_dep_recs = 0;
		double down_payment = 0, loan = 0,  dep = 0;

		cin >> months >> down_payment >> loan >> num_dep_recs;
		if(months < 0)
			break;

		double total_worth = loan + down_payment;
		double cur_worth = total_worth;
		vector <double> dv(months+1);

		for(int i=0; i <= months; i++) { dv[i] = -1; }

		for(int i=0; i<num_dep_recs; i++) {
			cin >> m >> dep;
			dv[m] = dep;
		}

		for (int i=1; i< months; i++) {
			if(dv[i] == -1) {
				dv[i] = dv[i-1];
			}
		}

		double paid = 0, owed = loan, d = 0;
		int ans = -1;

		float emi = loan/months;
		cur_worth = cur_worth * (1.0 - dv[0]);

		if(owed < cur_worth) {
			cout << "0 months\n";
			continue;
		}

		for(int i=1; i <= months; i++) {
			paid = i * emi;
			owed = loan - paid;

			cur_worth = cur_worth - cur_worth * dv[i];

	   		if(owed < cur_worth) {
	   			ans = i;
	   			break;
	   		} else
	   			ans = i;
		}

		printAnswer(ans);
	}

	return 0;
}

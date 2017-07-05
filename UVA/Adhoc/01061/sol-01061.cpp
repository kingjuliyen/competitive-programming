// 1061 - Consanguine Calculations
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=245&page=show_problem&problem=3502
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int caseCount;


class CC { // Consanguine Calculations
public:
	string par1, par2, chi;

	enum type {
		A = 1,
		B = 2,
		O = 3,
		AB = 4,
	};

	CC(string p1, string p2, string ch): par1(p1), par2(p2), chi(ch) {
	}

	void print() {
		cout << "|"<<par1 << "| |" << par2 << "| |" << chi << "|\n";
	}

	type getType(string s) {
		if(s.length()==3)
			return AB;
		switch(s[0]) {
			case 'A':
			return A;
			case 'B':
			return B;
			case 'O':
			return O;
		}
	}

	int getSignCombo(char a, char b) {
		if(a == '-' && b == '-')
			return 1;
		else
			return 2;
	}

	int getSignCombo(string s1, string s2) {
		char a = 'a';
		char b = 'c';
		if(s1.length() == 3)
			a = s1[2];
		else
			a = s1[1];

		if(s2.length() == 3)
			b = s2[2];
		else
			b = s2[1];
		return getSignCombo(a, b);
	}

	string getTypeStr(int t) {
		switch(t) {
			case A:
			return "A";
			case B:
			return "B";
			case O:
			return "O";
			case AB:
			return "AB";
		}
	}

	// generate children types
	vector<int> getComboPP(int t1, int t2) {
		vector<int> vi;
		if(t1 == A &&  t2 == A) { // A A => A | O
			vi.push_back(A); vi.push_back(O);
		}
		else if(t1 == A && t2 == B) { // A B => A | B | O | AB
			vi.push_back(A); vi.push_back(B); vi.push_back(O); vi.push_back(AB);
		}
		else if(t1 == A && t2 == O) { // A O => A | O
			vi.push_back(A); vi.push_back(O);
		}
		else if(t1 == A && t2 == AB) { // A AB => A | B | AB
			vi.push_back(A); vi.push_back(B); vi.push_back(AB);
		}
		else if(t1 == B && t2 == B) { // B B => B | O
			vi.push_back(B); vi.push_back(O);

		}
		else if(t1 == B && t2 == O) { // B O => B | O
			vi.push_back(B); vi.push_back(O);
		}
		else if(t1 == B && t2 == AB) { // B AB => A | B | AB
			vi.push_back(A); vi.push_back(B); vi.push_back(AB);
		}
		else if(t1 == O && t2 == AB) { // O AB => A | B
			vi.push_back(A); vi.push_back(B);
		}
		else if(t1 == O && t2 == O) { // O O => O
			vi.push_back(O);
		}
		else if(t1 == AB && t2 == AB) { // AB AB => AB | A | B
			vi.push_back(AB); vi.push_back(A); vi.push_back(B);
		}
		return vi;
	}

	void getChild(string p1, string p2) {
		int t1 = getType(p1);
		int t2 = getType(p2);
		vector<int> vi = getComboPP(min(t1, t2), max(t1, t2));
		printOutputPP(p1, p2, vi, getSignCombo(p1, p2));
	}

	bool isPossibleParent(int child, vector<int> vi) {
		for(int i=0; i<vi.size(); i++) {
			if(child == vi[i])
				return true;
		}
		return false;
	}

	void printOutputPP(string p1, string p2, vector<int> vi, int signCount) {
		cout << "Case " << caseCount++ <<": ";
		cout << p1 << " " << p2;

		if(vi.size()==0) {
			cout << " IMPOSSIBLE\n";
			return;
		}
		if(vi.size() == 1 && signCount == 1) {
			cout << " " <<getTypeStr(vi[0]) << "-\n";
			return;
		}
		sort(vi.begin(), vi.end(), cmp);

		cout << " {";
		for(int i=0; i<vi.size(); i++) {
			if(i>0)
				cout << ", ";
			cout << getTypeStr(vi[i]) << "-";
			if(signCount==2)
				cout << ", " <<getTypeStr(vi[i]) << "+";
		}
		cout << "}\n";
	}

	static bool cmp(int x, int y) {
		static int a[] = {-1,44,33,11,22};
		return a[x] < a[y];
	}

	void printOutputPPC(string p1, string chi, vector<int> pparents, map<int, int> m) {
		cout << "Case " << caseCount++ <<": ";
		if(pparents.size()==0) {
			cout << p1 << " IMPOSSIBLE " << chi << "\n";
			return;
		}
		sort(pparents.begin(), pparents.end(),cmp);

		cout << p1 << " {";
		for(int i=0; i<pparents.size(); i++) {
			if(i>0)
				cout << ", ";
			cout << getTypeStr(pparents[i]);
			if(m[pparents[i]]==-1)
				cout << "+";
			else
				cout << "-";
			if(m[pparents[i]]==2)
				cout << ", " <<getTypeStr(pparents[i]) << "+";
		}
		cout << "} " << chi << "\n";
	}

	int getSignComboPC(string s1, string s2) {
		char a = s1[s1.length()-1];
		char b = s2[s2.length()-1];
		if(a == '-' && b == '+')
			return -1;
		else
			return 2;
	}

	void getParent(string p, string child) {
		int t1 = getType(p);
		vector<int> v;
		vector<int> parents;
		map<int, int> m;

		v.push_back(A); v.push_back(B); v.push_back(O); v.push_back(AB);
		for(int i=0; i<v.size(); i++) {
			int t2 = v[i];
			vector<int> vi = getComboPP(min(t1, t2), max(t1, t2));
			bool b = isPossibleParent(getType(child), vi);
			if(b) {
				parents.push_back(t2);
				m[t2] = getSignComboPC(p, child);
			}
		}
		printOutputPPC(p, chi, parents, m);
	}

	void solve() {
		if(par1.find("?") != string::npos) {
			getParent(par2, chi);
		}
		if(par2.find("?") != string::npos) {
			getParent(par1, chi);
		}
		if(chi.find("?") != string::npos) {
			getChild(par1,  par2);
		}
	}

}; // class CC

vector<string> getArgs(string s) {
	stringstream ss(s);
	vector<string> vs;
	while(ss) {
		string x;
		ss >> x;
		vs.push_back(x);
	}
	return vs;
}

int main() {
	string s;
	caseCount = 1;
	while(getline(cin, s)) {
		if(s.size()==0)
			continue;
		if(s == "E N D")
			break;
		vector<string> vs = getArgs(s);
		CC cc(vs[0], vs[1], vs[2]);
		cc.solve();
	}
}

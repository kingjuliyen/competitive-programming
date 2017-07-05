// 00195 - Anagram
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=131
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

/*
  solved the problem using 2 methods, method 2) gets time limit exceeded method 1) gets AC
  1) Check solvingUsingStdInbuilt function which uses std c++ lib function next_permutation - this is very fast
  2) Check solveUsingCustomAlgo function which uses custom algorithm - this is slower(timeout) but optimization could be done on this
     idea:
      Recursively builds from base case of 2 char inputs
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class WG {
public:
	vector <char> vc;
	WG(string s);
	void solve();
	void printResults(vector<string> vsb);
	vector<string> baseCase(vector<char> cc);
	vector<char> getInputForLowerCombo(vector<char> cc);
	string insert(string baseStr,  int pos, char nc);
	vector<string> getNextHigherCombo(char c, vector<string> lowerCombo);
	vector<string> generateCombinations(vector<char> cc);
};

WG::WG(string s) {
	for(int i=0; i<s.size(); i++) {
		vc.push_back(s[i]);
	}
}

void WG::printResults(vector<string> vsb) {
	sort(vsb.begin(), vsb.end());
	map<string, bool> m;

	for(int i=0; i<vsb.size(); i++) {
		if(m.find(vsb[i]) == m.end()) {
			cout << vsb[i] << "\n";
			m[vsb[i]] = true;
		}
	}
}

vector<string> WG::baseCase(vector<char> cc){
   vector<string> combinations;
      if(cc.size()==1){
         string sb1(1,0);
         sb1[0] = cc[0];
         combinations.push_back(sb1);
       }
      if(cc.size()==2) {
         string sb1(2, 0);
         sb1[0] = cc[0];
         sb1[1] = cc[1];

         string sb2(2, 0);
         sb2[0] = cc[1];
		 sb2[1] = cc[0];

         combinations.push_back(sb1);
         combinations.push_back(sb2);
       }
      return combinations;
 }

vector<char> WG::getInputForLowerCombo(vector<char> cc) {
   vector<char> vsb;
   for(int i=1; i<cc.size(); i++){
     vsb.push_back(cc[i]);
   }
   return vsb;
}

string WG::insert(string baseStr,  int pos, char nc) {
	int len = baseStr.length()+1;
    string sb(len,0);
    int di = 0; // dest index
    int si = 0; // source index

    while(di<pos && si<baseStr.length()) {
        char c = baseStr[si++];
        sb[di++] = c;
    }
      sb[di++] = nc;

      while(di<len && si<baseStr.length()) {
      	char c = baseStr[si++];
        sb[di++] = c;
      }
      return sb;
}

int counter = 0;

vector<string> WG::getNextHigherCombo(char c, vector<string> lowerCombo){
	vector<string> vsb;
	int len = lowerCombo[0].length()+1;
    for(int i=0; i<len; i++) {
      for(int j=0; j<lowerCombo.size(); j++){
         if(counter>50) {
         	counter = 0;
         	return vsb;
         }
         string sb = insert(lowerCombo[j], i, c);
         vsb.push_back(sb);
       }
     }
     return vsb;
}

vector<string> WG::generateCombinations(vector<char> cc) {
	if(cc.size() <=2) {
		return baseCase(cc);
	}
	vector<char> lowerCombo = getInputForLowerCombo(cc);
	vector<string> lowerComboTemplate = generateCombinations(lowerCombo);
  vector<string> combinations = getNextHigherCombo(cc[0], lowerComboTemplate);
  return combinations;
}

void WG::solve() {
	vector<string> vsb = generateCombinations(vc);
	printResults(vsb);
}

inline int lowerDiff() {
	return 'a' - 'A';
}

inline bool isLower(char c1) {
	if(c1>='a' && c1<='z')
		return true;
	return false;
}

inline void toLower(char *c) {
	*c += lowerDiff();
}

bool compare(char c1, char c2) {
	bool c1b = isLower(c1);
	bool c2b = isLower(c2);

	if(c1b && c2b) {
		return c1 < c2;
	}
	else if(!c1b && !c2b) {
		return c1 < c2;
	}
	else if(c1b) {
		toLower(&c2);
		return c1 < c2;
	}
	else {
		toLower(&c1);
		return c1 <= c2;
	}
}

void solvingUsingStdInbuilt(string inputSet) {
  sort(inputSet.begin(), inputSet.end(), compare);
  do {
    cout << inputSet << "\n";
  } while(next_permutation(inputSet.begin(), inputSet.end(), compare));
}

void solveUsingCustomAlgo(string inputSet) {
    WG wg(inputSet);
    wg.solve();
}

int main() {
	int T = 0;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
    //solveUsingCustomAlgo(s);
    solvingUsingStdInbuilt(s);
	}
}

#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <process.h>
#include <algorithm>
using namespace std;
vector<pair<int, char>> S;
list<pair<char, char>> E;
vector<pair<int, char>> man;
int main() {
	int n;
	int i;
	char x;
	char y;
	ifstream f("date.txt");
	int p;
	f >> n;
	S.resize(n);
	man.resize(n);
	for (i = 0; i < n; i++) {
		f >> p;
		if (p > n - 1 || p < 0) {
			cout << "Nu";
			system("pause");
			return 0;
		}
		S[i] = make_pair(p, 'A' + i);
	}
	sort(S.begin(), S.end());
	for (i = 0; i < n; i++) {
		cout << S[i].first << " " << S[i].second << " ";
	}
	cout << "\n";
	while (S[n - 1].first > 0) {
		char et = S[n - 1].second;
		int d = S[n - 1].first;
		S.pop_back();
		n--;
		for (i = 1; i <= d; i++) {
			S[n - i].first--;
			E.push_back(make_pair(et, S[n - i].second));
			if (S[n - 1].first < 0) {
				cout << "Nu";
				system("pause");
				return 0;
			}
		}
		merge(S.begin(), S.begin() + n - d, S.begin() + n - d, S.end(), man.begin());
		for (i = 0; i < n; i++) {
			S[i] = man[i];
		}
	}
	cout << "\n...\n";
	for (auto p : E) {
		cout << p.first << " " << p.second << "\n";
	}
	system("pause");
	return 0;
}
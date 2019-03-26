#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <process.h>
#include <algorithm>
#include <queue>
using namespace std;
int n;
vector<int> S;
list<pair<char, char>> E;
ifstream f("date.txt");
queue<char> T;
queue<char> NT;
int main() {
	f >> n;
	S.resize(n);
	int sum = 0;
	int i;
	for (i = 0; i < n; i++) {
		f >> S[i];
		if (S[i] < 1) {
			cout << "Nu";
			system("pause");
			return 0;
		}
		sum += S[i];
		if (S[i] == 1) {
			T.push(i + 'A');
		}
		else {
			NT.push(i + 'A');
		}
	}
	while (!NT.empty()) {
		char x = T.front();
		T.pop();
		char y = NT.front();
		E.push_back(make_pair(x, y));
		S[y - 'A']--;
		if (S[y - 'A'] == 1) {
			NT.pop();
			T.push(y);
		}
	}
	char x = T.front();
	T.pop();
	char y = T.front();
	T.pop();
	E.push_back(make_pair(x, y));
	for (auto p : E) {
		cout << p.first << " " << p.second << "\n";
	}
	system("pause");
	return 0;
}
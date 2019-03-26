#include <iostream>
#include <fstream>
#include <process.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <list>
using namespace std;
int tata[100];
int d[100];
int viz[100];
int n;
int st;
void bfs(int st) {
	d[st] = 0;
	viz[st] = 1;
	queue<int> Q;
	Q.push(st);
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for (int y : L[x]) {
			if (!viz[y]) {
				d[y] = d[x] + 1;
				viz[y] = 1;
				tata[y] = x;
				Q.push(y);
			}
		}
	}
}
int main() {

	system("pause");
	return 0;
}
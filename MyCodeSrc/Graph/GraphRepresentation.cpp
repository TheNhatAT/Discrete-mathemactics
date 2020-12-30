#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <list>
using namespace std;
int n, m, k;
vector<list<int>> adjacentcyList;
vector<list<int>> adjacentcyListOpp;
vector<int> head;
list<int> arr;

void creat_graph() {
	int u, v;

	adjacentcyList.resize(n + 1);
	adjacentcyListOpp.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adjacentcyList[u].push_back(v);
		adjacentcyListOpp[v].push_back(u);
	}

	head.resize(n + 1);
	head[1] = 1;
	for (int i = 1; i < n; i++) {
		head[i + 1] = head[i] + adjacentcyList[i].size();
		if (adjacentcyList[i].empty()) head[i] = head[i + 1];
	}
	
}

void print() {
	cout << n << " " << m << endl;
	for (int i = 1; i <= n; i++) {
		cout << head[i] << " ";
	}
	cout << endl;

	for (int i = 1; i <= n; i++) {
		for (list<int>::iterator it = adjacentcyList[i].begin(); it != adjacentcyList[i].end(); ++it) {
			cout << *it << " ";
		}
	}
	cout << endl;

	for (int i = 1; i <= k; i++) {
		int x = arr.front(); arr.pop_front();
		if (adjacentcyListOpp[x].empty()) cout << endl;
		else {
			adjacentcyListOpp[x].sort();
			for (list<int>::iterator it = adjacentcyListOpp[x].begin(); it != adjacentcyListOpp[x].end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;
		}
	}
 }

int main() {
	cin >> n >> m >> k;
	creat_graph();
	int atp;
	for (int i = 0; i < k; i++) {
		cin >> atp;
		arr.push_back(atp);
	}
	print();
	return 0;
}
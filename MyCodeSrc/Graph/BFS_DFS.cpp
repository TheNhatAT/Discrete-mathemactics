#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

int n, m, i, j, Count = 0, countPath[100001] = { 0 }, countDic = 0;
vector<list<int>> graph;
bool visited[100001] = { false };
vector<int> sau;

void create_graph() {
	int u, v;
	graph.resize(n + 1);
	sau.resize(n + 1);
	for (int k = 0; k < m; k++) {
		cin >> u >> v;
		graph[u].push_back(v);
	}
	for (int k = 0; k < n; k++) {
	    graph[k].sort();
	}
}

void BFS(int s) {
	Count++;
	queue<int> Queue;
	visited[s] = true;
	Queue.push(s);
	while (!Queue.empty()) {
		int u = Queue.front();
		Queue.pop();
		if(u == j) return;
		for (int &v : graph[u]) {
			if (!visited[v]) {
				visited[v] = true;
				countPath[v] = countPath[u] + 1;
				Queue.push(v);
			}
		}
	}
}
void DFS(int s) {
	visited[s] = true;
	for (int& v : graph[s]) {
		if (!visited[v]) {
			sau[s] = v;
			DFS(v);
		}
	}
 }

int main() {
	cin >> n >> m;
	create_graph();
	cin >> i >> j;

	// bai do thi o bkict.org
	for (int k = 1; k <= n; k++) {
		if (!visited[k]) BFS(k);
	}
	cout << Count << endl;
	for (int k = 0; k <= n; k++) {
		countPath[k] = 0;
		visited[k] = false;
	}
	BFS(i);
	cout << countPath[j] + 1<< endl;

	for (int k = 0; k <= n; k++) {
		visited[k] = false;
	}
	DFS(i);
	int temp = i;
	while (true) {
		countDic++;
		if (temp == j) break;
		temp = sau[temp];
	}
	cout << countDic << endl;
	while (true) {
		cout << i << " ";
		if (i == j) break;
		i = sau[i];
	}
}
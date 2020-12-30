#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stack>
using namespace std;

typedef struct vertex {
	int edgeAdjacent[100001];
	int weight[100001];
}vertex;
vector<vertex> graph;
int n, m, u, v, c, s, t;
int d[100001], pre[100001];
bool T[100001] = { true };

void relax(int u, int v) {
	if (d[u] > d[v] + graph[v].weight[u]) {
		d[u] = d[v] + graph[v].weight[u];
		pre[u] = v;
	}
}

void create_graph() {
	int u, v;
	graph.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> c;
		graph[u].edgeAdjacent[v] = v;
		graph[u].weight[v] = c;
	}
}
void bellmanFord(int s, int t) {
	for (int i = 1; i <= n; i++) {
		d[i] = INT_MAX;
	}
	for (int i = 1; i <= n; i++) {
		if(graph[s].weight[i])	d[i] = graph[s].weight[i];
		pre[i] = s;
	}
	d[s] = 0; pre[s] = s;
	//cout << d[t] << endl;
	for (int k = 1; k <= n - 2; k++) {
		for (int v = 1; v <= n; v++) {
			if (v == s) continue;
			for (int u = 1; u <= n; u++) {
				if(graph[v].weight[u] != 0) relax(u, v);
			}
		}
	}
//	cout << d[t] << endl;
}
 
void dijkstra(int s, int t) {
	for (int i = 1; i <= n; i++) {
		d[i] = INT_MAX;
	}
	for (int i = 1; i <= n; i++) {
		if (graph[s].weight[i])	d[i] = graph[s].weight[i];
		pre[i] = s;
	}
	d[s] = 0; pre[s] = s;
	//T
}


int main() {
	cin >> n >> m;
	create_graph();
	cin >> s >> t;
	bellmanFord(s, t);
	cout << d[t] << endl;

	// print path
	vector<int> path;
	path.resize(n + 1);
	do {
		path.push_back(t);
		t = pre[t];
	} while (t != s);
	cout << s;
	for (int i = path.size() - 1; i >= 0; i--) {
		if (path[i]) cout << " " << path[i];
	}
	return 0;
}

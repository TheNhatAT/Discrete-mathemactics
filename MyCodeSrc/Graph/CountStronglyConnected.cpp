#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stack>

using namespace std;
int n, m, k, a, b, cnt = 0;
vector<list<int>> graph;
int Count = 0, disc[100001], low[100001];
stack<int> st;

void create_graph() {
	int u, v;
    graph.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
	}
}
void addEdge(int a, int b) {
    graph[a].push_back(b);
}
void countSCC(int u) {
    low[u] = disc[u] = ++cnt;
   // cout << "print disc[u]" << disc[u] << "}}";
    st.push(u);

    for (int v : graph[u])
        if (disc[v])
            low[u] = min(low[u], disc[v]);
        else {
                countSCC(v); // when v is visited
            low[u] = min(low[u], low[v]);
        }

    if (disc[u] == low[u]) {  // found one
        Count++;
        int v;
        do {
            v = st.top();
            st.pop();
            disc[v] = low[v] = INT_MAX;  // remove v from graph
        } while (v != u);
    }
}

void reset() {
    Count = 0; cnt = 0;
    for (int i = 0; i <= n; i++) {
        disc[i] = 0;
        low[i] = 0;
    }
}

int main() {
    cin >> n >> m >> k;
    create_graph();

    for (int i = 1; i <= n; i++)
        if (!disc[i]) countSCC(i);
    cout << Count << endl;

    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        addEdge(a, b);
        reset();
        for (int j = 1; j <= n; j++)
            if (!disc[j]) countSCC(j);
        cout << Count << endl;
    }
	return 0;
}
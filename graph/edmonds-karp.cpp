#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

template<size_t sz>
struct EdmondsKarp { // Edmonds-Karp algorithm, O(VE * E). O(V * E) for Bipartite-Graph.
	vector<vector<int>> flow, cap, adj;
	vector<int> par;
	int s, e; // source, sink

	EdmondsKarp() :
		flow(sz, vector<int>(sz)),
		cap(sz, vector<int>(sz)),
		adj(sz), par(sz),
		s(-1), e(-1) {}

	void SetSource(int t) { s = t; }
	void SetSink(int t) { e = t; }
	void AddEdge(int a, int b, int cap, bool directed = 1) {
		adj[a].push_back(b);
		adj[b].push_back(a);
		cap[a][b] += cap;
		if (!directed) cap[b][a] += cap;
	}

	int MaxFlow() {
		if (s == -1 || e == -1) return -1;
		queue<int> Q;
		int ret = 0;
		while (1) {
			fill(par.begin(), par.end(), -1);
			Q = {}; Q.push(s);
			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				for (auto nxt : adj[cur]) {
					if (par[nxt] == -1 && cap[cur][nxt] - flow[cur][nxt] > 0) {
						par[nxt] = cur; Q.push(nxt);
						if (nxt == e) break;
					}
				}
			}
			if (par[e] == -1) break;
			int cost = INF;
			for (int i = e; i ^ s; i = par[i])
				cost = min(cost, cap[par[i]][i] - flow[par[i]][i]);
			for (int i = e; i ^ s; i = par[i]) {
				flow[par[i]][i] += cost;
				flow[i][par[i]] -= cost;
			}
			ret += cost;
		}
		return ret;
	}
};

int main() {
    fastio;
}
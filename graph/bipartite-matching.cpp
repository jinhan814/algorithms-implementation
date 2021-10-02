#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

template<size_t sz>
struct BipartiteMatching { // Bipartite Match, O(VE).
	vector<vector<int>> adj;
	vector<int> par;
	bitset<sz> check;

	BipartiteMatching() :
		adj(sz), par(sz, -1) {}

	void AddEdge(int a, int b) { adj[a].push_back(b); }

	bool DFS(int cur) {
		for (auto nxt : adj[cur]) {
			if (check[nxt]) continue;
			check[nxt] = 1;
			if (par[nxt] == -1 || DFS(par[nxt])) {
				par[nxt] = cur; return 1;
			}
		}
		return 0;
	}

	int Match() {
		int ret = 0;
		for (int i = 0; i < sz; i++) {
			check.reset();
			ret += DFS(i);
		}
		return ret;
	}
};

int main() {
    fastio;
}
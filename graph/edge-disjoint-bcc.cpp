/*
 * BOJ 10806 (not full code)
 * https://www.acmicpc.net/problem/10806
 */

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

struct UnionFind { // -1 ver.
    vector<int> par;
    UnionFind(int n) : par(n, -1) {}
    int Find(int x) { return par[x] < 0 ? x : par[x] = Find(par[x]); }
    void Union(int a, int b) {
        a = Find(a), b = Find(b);
        if (a ^ b) par[a] += par[b], par[b] = a;
    }
};

struct BCC { // edge-disjoint bcc
	int n, dfs_cnt, edge_cnt;
    vector<int> dfs_order; UnionFind UF;
    vector<tuple<int, int, int>> bridge;
    vector<vector<pair<int, int>>> adj;

    BCC(int n) :
        n(n), adj(n + 1),
        dfs_order(n + 1), UF(n + 1),
        dfs_cnt(0), edge_cnt(0) {}

    void AddEdge(int a, int b, int idx = -1) {
        if (idx == -1) idx = edge_cnt++;
        adj[a].push_back({ b, idx });
        adj[b].push_back({ a, idx });
    }

    int DFS(int cur, int prv_idx = -1) {
        int ret = dfs_order[cur] = ++dfs_cnt;
        for (const auto& [nxt, idx] : adj[cur]) {
            if (idx == prv_idx) continue;
            if (!dfs_order[nxt]) {
                const int t = DFS(nxt, idx);
                if (t > dfs_order[cur]) bridge.push_back({ cur, nxt, idx });
                else UF.Union(cur, nxt);
                ret = min(ret, t);
            }
            else ret = min(ret, dfs_order[nxt]);
        }
        return ret;
    }

    void GetBCC(bool flag = 0) {
        for (int i = 1; i <= n; i++) if (!dfs_order[i]) DFS(i);

        if (flag) {
            cout << '\n' << "bridge :" << '\n';
            cout << bridge.size() << '\n';
            for (auto& [a, b, idx] : bridge) cout << a << ' ' << b << '\n';

            cout << '\n' << "color :" << '\n';
            for (int i = 1; i <= n; i++) cout << UF.Find(i) << ' ';
            cout << '\n' << '\n';
        }
    }
};

int main() {
	fastio;
	int n, m; cin >> n >> m; BCC B(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		B.AddEdge(a, b);
	}
	B.GetBCC(1);
}

/*
# in_1
9 10
1 2
2 3
2 3
3 4
4 5
4 6
3 6
6 7
6 8
8 9

# in_2
5 6
1 2
1 2
4 3
2 3
1 3
5 1
*/
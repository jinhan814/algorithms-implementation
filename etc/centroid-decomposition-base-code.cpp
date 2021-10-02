#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<pair<int, int>> adj[100001];
bitset<100001> visited;
int sz[100001];

int GetSize(int cur, int prev) {
	sz[cur] = 1;
	for (auto [nxt, ncost] : adj[cur]) {
		if (nxt == prev || visited[nxt]) continue;
		sz[cur] += GetSize(nxt, cur);
	}
	return sz[cur];
}

int GetCent(int cur, int prev, int lim) {
	for (auto [nxt, ncost] : adj[cur]) {
		if (nxt == prev || visited[nxt]) continue;
		if (sz[nxt] << 1 >= lim) return GetCent(nxt, cur, lim);
	}
	return cur;
}

int Calc(int cur, int prev, int dist, int dep) {
	int ret = 0;
	return ret;
}

void Update(int cur, int prev, int dist, int dep) {
	return;
}

int Sol(int cur) {
	int lim = GetSize(cur, -1);
	cur = GetCent(cur, -1, lim);
	int ret = 0; visited[cur] = 1;
	for (auto [nxt, ncost] : adj[cur]) {
		if (visited[nxt]) continue;
		ret += Calc(nxt, cur, ncost, 1);
		Update(nxt, cur, ncost, 1);
	}
	for (auto [nxt, ncost] : adj[cur]) {
		if (visited[nxt]) continue;
		ret += Sol(nxt);
	}
	return ret;
}

int main() {
	fastio;
}
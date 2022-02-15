/*
 * reference : https://nyaannyaan.github.io/library/graph/static-graph.hpp
 */

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

template<typename I> struct Edge {
	int u; I info;
	Edge() = default;
	Edge(const int& u, const I& info) : u(u), info(info) {}
};

template<> struct Edge<void> {
	int u;
	Edge() = default;
	Edge(const int& u) : u(u) {}
};

template<typename It> struct Edges {
	It st, en;
	It begin() const { return st; }
	It end() const { return en; }
	int size() const { return en - st; }
	decltype(auto) operator[] (int i) const { return st[i]; }
};

template<typename T = void> struct StaticGraph { // 1-based
public:
    using info_type      = T;
    using edge_type      = Edge<T>;
    using iterator       = Edges<typename vector<edge_type>::iterator>;
    using const_iterator = Edges<typename vector<edge_type>::const_iterator>;
    StaticGraph(int n, int m) : n(n), m(m), cnt(n + 2), e(m) { inp.reserve(m); }
    template<typename... Args>
    void AddEdge(int u, Args&&... args) {
        inp.emplace_back(u, edge_type{ forward<Args>(args)... });
        cnt[u]++;
        if (inp.size() == m) Init();
    }
    iterator operator[](int i) { return { e.begin() + cnt[i], e.begin() + cnt[i + 1] }; }
    const_iterator operator[](int i) const { return { e.begin() + cnt[i], e.begin() + cnt[i + 1] }; }
private:
    int n, m;
    vector<int> cnt;
    vector<pair<int, edge_type>> inp;
    vector<edge_type> e;
    void Init() {
        for (int i = 1; i < cnt.size(); i++) cnt[i] += cnt[i - 1];
        for (const auto& [u, info] : inp) e[--cnt[u]] = info;
    }
};

int main() {
	fastio;
}
#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

template<typename T = int64_t, size_t sz = 17, typename F = plus<T>>
struct SegTree {
	vector<T> tree; T t; F f{};
	SegTree(T t = T()) : tree(1 << sz + 1, t), t(t) {}
	explicit SegTree(T t, const F& f) : tree(1 << sz + 1, t), t(t), f(f) {}

	void Update(int i, T val) {
		--i |= 1 << sz; tree[i] = val;
		while (i >>= 1) tree[i] = f(tree[i << 1], tree[i << 1 | 1]);
	}
	T Query(int l, int r) {
		T L = t, R = t; --l |= 1 << sz, --r |= 1 << sz;
		while (l <= r) {
			if (l & 1) L = f(L, tree[l++]);
			if (~r & 1) R = f(tree[r--], R);
			l >>= 1, r >>= 1;
		}
		return f(L, R);
	}
};

int main() {
	fastio;
}
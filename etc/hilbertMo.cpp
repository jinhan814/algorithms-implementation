#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

using ll = long long;

class Query { // reference : https://www.acmicpc.net/source/27941653
public:
	int idx, st, en;
	Query(int idx, int st, int en) :
		idx(idx), st(st), en(en), pr(ConvHilbert(st, en)) {}
	bool operator< (const Query& i) const { return pr < i.pr; }

private:
	ll pr;
	static ll ConvHilbert(int x, int y) {
		ll ret = 0;
		for (int i = 17, cx, cy; ~i; i--) {
			cx = x >> i & 1, cy = y >> i & 1;
			ret = ret << 2 | cx << 1 | cx ^ cy;
			cy || (swap(x, y), cx) && (x = ~x, y = ~y);
		}
		return ret;
	}
};

int main() {
	fastio;
}
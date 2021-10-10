#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<pair<int, int>> Factorize(int n) { // must be n > 1
	vector<pair<int, int>> ret;
	for (int i = 2; i * i <= n; i++) {
		if (n % i) continue;
		int t = 0;
		while (n % i == 0) t++, n /= i;
		ret.push_back({ i, t });
	}
	if (n != 1) ret.push_back({ n, 1 });
	return ret;
}

int main() {
	fastio;
}
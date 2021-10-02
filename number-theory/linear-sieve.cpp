#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

constexpr int SZ = 1e5;
vector<int> p;
int sieve[SZ + 1]; // sieve[i] : IsPrime(i) ? 0 : smallest prime factor

void LinearSieve(int n = SZ) {
	for (int i = 2; i <= n; i++) {
		if (!sieve[i]) p.push_back(i);
		for (auto j : p) {
			if (i * j > n) break;
			sieve[i * j] = j;
			if (i % j == 0) break;
		}
	}
}

int main() {
	fastio;
}
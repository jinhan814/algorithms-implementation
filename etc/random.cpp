#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

struct Random {
	mt19937 rd;
	Random() : rd((unsigned)chrono::steady_clock::now().time_since_epoch().count()) {}
	Random(int seed) : rd(seed) {}
	template<typename T = int> T GetInt(T l = 0, T r = 32767) {
		return uniform_int_distribution<T>(l, r)(rd);
	}
	template<typename T = double> T GetDouble(T l = 0, T r = 1) {
		return uniform_real_distribution<T>(l, r)(rd);
	}
} Rand;

int main() {
	fastio;
}
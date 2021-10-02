#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

using ll = int64_t;
using ull = uint64_t;

struct Random {
	mt19937 rd;
	Random() : rd((unsigned)chrono::steady_clock::now().time_since_epoch().count()) {}
	Random(int seed) : rd(seed) {}
	template<typename T = int>
	T GetInt(T l = 0, T r = 32767) {
		return uniform_int_distribution<T>(l, r)(rd);
	}
	double GetDouble(double l = 0, double r = 1) {
		return uniform_real_distribution<double>(l, r)(rd);
	}
} Rand;

struct MillerRabin {
	ll Mul(ll x, ll y, ll MOD) {
		ll ret = x * y - MOD * ull(1.L / MOD * x * y);
		return ret + MOD * (ret < 0) - MOD * (ret >= (ll)MOD);
	}
	ll _pow(ll x, ll n, ll MOD) {
		ll ret = 1; x %= MOD;
		for (; n; n >>= 1) {
			if (n & 1) ret = Mul(ret, x, MOD);
			x = Mul(x, x, MOD);
		}
		return ret;
	}
	bool Check(ll x, ll p) {
		if (x % p == 0) return 0;
		for (ll d = x - 1; ; d >>= 1) {
			ll t = _pow(p, d, x);
			if (d & 1) return t != 1 && t != x - 1;
			if (t == x - 1) return 0;
		}
	}
	bool IsPrime(ll x) {
		if (x == 2 || x == 3 || x == 5 || x == 7) return 1;
		if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) return 0;
		if (x < 121) return x > 1;
		if (x < 1ULL << 32) for (auto& i : { 2, 7, 61 }) {
			if (x == i) return 1;
			if (x > i && Check(x, i)) return 0;
		}
		else for (auto& i : { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 }) {
			if (x == i) return 1;
			if (x > i && Check(x, i)) return 0;
		}
		return 1;
	}
};

int main() {
	fastio;
}
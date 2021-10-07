/*
 * BOJ 13976
 * https://www.acmicpc.net/problem/13976
 * reference : https://www.secmem.org/blog/2019/05/17/BerlekampMassey/, https://justicehui.github.io/hard-algorithm/2021/03/13/kitamasa/
 */

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

constexpr int MOD = 1e9 + 7;
using ll = long long;
using poly = vector<ll>;

ll Pow(ll x, ll n) {
	ll ret = 1;
	for (; n; n >>= 1) {
		if (n & 1) ret = ret * x % MOD;
		x = x * x % MOD;
	}
	return ret;
}

poly BerlekampMassey(const poly v) {
	poly ls, ret; ll lf, ld;
	for (ll i = 0, t = 0; i < v.size(); i++, t = 0) {
		for (ll j = 0; j < ret.size(); j++) t = (t + 1ll * v[i - j - 1] * ret[j]) % MOD;
		if ((t - v[i]) % MOD == 0) continue;
		if (ret.empty()) { ret.resize(i + 1), lf = i, ld = (t - v[i]) % MOD; continue; }
		const ll k = -(v[i] - t) * Pow(ld, MOD - 2) % MOD;
		poly cur(i - lf - 1);
		cur.push_back(k);
		for (const auto& j : ls) cur.push_back(-j * k % MOD);
		if (cur.size() < ret.size()) cur.resize(ret.size());
		for (ll j = 0; j < ret.size(); j++) cur[j] = (cur[j] + ret[j]) % MOD;
		if (i - lf + (ll)ls.size() >= (ll)ret.size()) tie(ls, lf, ld) = make_tuple(ret, i, (t - v[i]) % MOD);
		ret = cur;
	}
	for (auto& i : ret) i = (i % MOD + MOD) % MOD;
    reverse(ret.begin(), ret.end());
	return ret;
}

struct {
    static int Mod(ll x) {
        x %= MOD;
        return x < 0 ? x + MOD : x;
    }
    poly Mul(const poly& a, const poly& b) {
        poly ret(a.size() + b.size() - 1);
        for (int i = 0; i < a.size(); i++) for (int j = 0; j < b.size(); j++) {
            ret[i + j] = (ret[i + j] + a[i] * b[j]) % MOD;
        }
        return ret;
    }
    poly Div(const poly& a, const poly& b) {
        poly ret(a.begin(), a.end());
        for (int i = ret.size() - 1; i >= b.size() - 1; i--) for (int j = 0; j < b.size(); j++) {
            ret[i + j - b.size() + 1] = Mod(ret[i + j - b.size() + 1] - ret[i] * b[j]);
        }
        ret.resize(b.size() - 1);
        return ret;
    }
    ll operator() (poly rec, poly dp, ll n) {
        if (dp.size() > rec.size()) dp.resize(rec.size());
        poly d = { 1 }, xn = { 0, 1 };
        poly f(rec.size() + 1); f.back() = 1;
        for (int i = 0; i < rec.size(); i++) f[i] = Mod(-rec[i]);
        while (n) {
            if (n & 1) d = Div(Mul(d, xn), f);
            n >>= 1; xn = Div(Mul(xn, xn), f);
        }
        ll ret = 0;
        for (int i = 0; i < dp.size(); i++) ret = Mod(ret + dp[i] * d[i]);
        return ret;
    }
} Kitamasa;

int main() {
    fastio;
    poly dp = { 0, 3, 0, 11, 0, 41, 0, 153, 0, 571 };
    poly rec = BerlekampMassey(dp);
    ll n; cin >> n;
    cout << Kitamasa(rec, dp, n - 1) << '\n';
}
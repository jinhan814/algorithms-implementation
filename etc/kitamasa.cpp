/*
 * reference : https://justicehui.github.io/hard-algorithm/2021/03/13/kitamasa/
 */

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

constexpr int MOD = 1e9 + 7;
using ll = int64_t;
using poly = vector<ll>;

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
    ll operator() (poly& rec, poly& dp, ll n) {
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
} kitamasa;

int main() {
    fastio;
}
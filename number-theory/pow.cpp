#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

constexpr int MOD = 1e9 + 7;

int Pow(int x, int n, const int MOD) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = 1LL * ret * x % MOD;
        x = 1LL * x * x % MOD;
    }
    return ret;
}

int Pow(int x, int n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret *= x;
        x *= x;
    }
    return ret;
}

int main() {
    fastio;
}
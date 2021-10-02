#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int MOD = 1e9 + 7;

template<typename T = int>
T Pow(T x, T n, const T MOD) {
    T ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = 1LL * ret * x % MOD;
        x = 1LL * x * x % MOD;
    }
    return ret;
}

template<typename T = int>
T Pow(T x, T n) {
    T ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret *= x;
        x *= x;
    }
    return ret;
}

int main() {
    fastio;
}
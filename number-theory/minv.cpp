#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

constexpr int MOD = 1e9 + 7;

int minv(const int a, const int b = MOD) {
    if (a == 0 && b == 1) return 0;
    if (a == 1) return 1;
    return b - 1LL * minv(b % a, a) * b / a;
}

int main() {
    fastio;
}
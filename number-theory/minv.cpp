#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

template<typename T = int>
T minv(T a, T b) {
    if (a == 0 && b == 1) return 0;
    if (a == 1) return 1;
    return b - (long long)minv(b % a, a) * b / a;
}

int main() {
    fastio;
}
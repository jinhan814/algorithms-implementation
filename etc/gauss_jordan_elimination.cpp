/*
 * BOJ 9254
 * https://www.acmicpc.net/problem/9254
 */

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

template<typename T>
struct GaussElimination { // reference : https://blog.naver.com/jhnah917/222529605959
    using row = vector<T>;
    using matrix = vector<row>;

    template<enable_if_t<is_arithmetic_v<T>>* = nullptr>
    constexpr static bool IsZero(T val) {
        if constexpr (is_integral<T>::value) return val == 0;
        else return abs(val) < 1e-9;
    }

    template<bool IsSquare = 1>
    static tuple<matrix, T, T, matrix> Gauss(matrix v) { // return { rref, rank, det, inv }
        const int n = v.size(), m = v[0].size(); int rank = 0;
        matrix inv(n, row(m)); T det = 1;
        for (int i = 0; i < n; i++) if (IsSquare) inv[i][i] = 1;
        for (int j = 0; j < m && rank < n; j++) {
            if (IsZero(v[rank][j])) {
                T mx = 0; int idx = -1;
                for (int i = rank + 1; i < n; i++) if (mx < abs(v[i][j])) mx = abs(v[i][j]), idx = i;
                if (idx == -1 || IsZero(mx)) { det = 0; continue; }
                for (int k = 0; k < m; k++) {
                    v[rank][k] += v[idx][k];
                    if (IsSquare) inv[rank][k] += inv[idx][k];
                }
            }
            const T coeff = 1 / v[rank][j]; det *= v[rank][j];
            for (int k = 0; k < m; k++) {
                v[rank][k] *= coeff;
                if (IsSquare) inv[rank][k] *= coeff;
            }
            for (int i = 0; i < n; i++) {
                if (rank == i) continue;
                const T t = v[i][j];
                for (int k = 0; k < m; k++) {
                    v[i][k] -= v[rank][k] * t;
                    if (IsSquare) inv[i][k] -= inv[rank][k] * t;
                }
            }
            rank++;
        }
        return { v, rank, det, inv };
    }
};

using G = GaussElimination<double>;

int main() {
	fastio;
    int n; cin >> n;
    G::matrix v(n, G::row(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> v[i][j];
    auto [rref, rank, det, inv] = G::Gauss(v);
    if (G::IsZero(det)) cout << "no inverse" << '\n';
    else {
        cout << fixed << setprecision(10);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cout << inv[i][j] << ' ';
            cout << '\n';
        }
    }
}
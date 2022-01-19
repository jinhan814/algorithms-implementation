/*
 * reference : https://ioinformatics.org/journal/v9_2015_39_44.pdf
 */

/* =============================================================================================== */

/*
                                                                                                   *
                                                   *                       *           *     *  *   
                           *           *     *  *              *     *  *        *  *     *         
               *     *  *        *  *     *              *  *     *           *                     
         *  *     *           *                       *                                             
      *                                                                                             
----------------------------------------------------------------------------------------------------
   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32
*/

/*
                                                                                                   *
                                                   *                                                
                           *                          *  *     *           *                        
               *              *  *     *                    *     *  *        *  *     *            
         *        *  *              *     *  *                          *           *     *  *      
      *     *           *                       *                                               *   
----------------------------------------------------------------------------------------------------
   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32
*/

/* =============================================================================================== */

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

template<typename T, typename F, T ID>
struct Fenwick {
    int n; vector<T> v, FT1, FT2; F f{};
    Fenwick(int n) : n(n), v(n + 1, ID), FT1(n + 1, ID), FT2(n + 1, ID) {}
    explicit Fenwick(int n, const F& f) : n(n), v(n + 1, ID), FT1(n + 1, ID), FT2(n + 1, ID), f(f) {}
    void Update(int i, T val) {
        T t = v[i] = val;
        for (int j = i, l = i - 1, r = i + 1; j <= n; j += j & -j) {
            while (l > j - (j & -j)) t = f(FT1[l], t), l -= l & -l;
            while (r < j) t = f(t, FT2[r]), r += r & -r;
            FT1[j] = i ^ j ? f(t, v[j]) : t;
        }
        t = val;
        for (int j = i, l = i - 1, r = i + 1; j; j -= j & -j) {
            while (l > j) t = f(t, FT1[l]), l -= l & -l;
            while (r <= n && r < j + (j & -j)) t = f(FT2[r], t), r += r & -r;
            FT2[j] = i ^ j ? f(v[j], t) : t;
        }
    }
    T Query(int l, int r) {
        T L = ID, R = ID; int i;
        for (i = l; i + (i & -i) <= r; i += i & -i) L = f(L, FT2[i]);
        for (i = r; i - (i & -i) >= l; i -= i & -i) R = f(FT1[i], R);
        return f(f(L, v[i]), R);
    }
};

int main() {
	fastio;
}

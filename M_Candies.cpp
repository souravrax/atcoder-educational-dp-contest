/**
 *  author: souravrax
 *  created: 06.03.2021 11:26:30
**/

// #pragma GCC optimize("O3")
// #pragma GCC target ("avx2")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

namespace std {
#define ar array
#define len(x) static_cast<int>((x).size())
#define all(x) (x).begin(), (x).end()
#define str(x) to_string(x)

    //@y_combinator
    template <class F>
    struct y_combinator
    {
        F f;
        template <class... Args>
        decltype(auto) operator()(Args &&... args) const
        {
            // the lambda should take the first argument as `auto&& recurse` or similar.
            return f(*this, std::forward<Args>(args)...);
        }
    };
    template <class F>
    y_combinator<std::decay_t<F>> make_y_combinator(F &&f)
    {
        return {std::forward<F>(f)};
    }

#ifdef LOCAL
    //@Debugger
    template <typename T>
    ostream &operator<<(ostream &os, const vector<T> &v)
    {
        os << '{';
        string sep;
        for (const auto &x : v)
            os << sep << x, sep = ", ";
        return os << '}';
    }
    template <typename T, size_t size>
    ostream &operator<<(ostream &os, const array<T, size> &arr)
    {
        os << '{';
        string sep;
        for (const auto &x : arr)
            os << sep << x, sep = ", ";
        return os << '}';
    }
    template <typename A, typename B>
    ostream &operator<<(ostream &os, const pair<A, B> &p)
    {
        return os << '(' << p.first << "," << p.second << ')';
    }

    void flush_out() { cerr << endl; }
    template <typename H, typename... T>
    void flush_out(H h, T... t) { cerr << ' ' << h << " | "; flush_out(t...); }
#define log(...) cerr << "[ " << #__VA_ARGS__ << " ] :", flush_out(__VA_ARGS__)
#else
#define log(...) (void)0x30
#endif

    template <typename T> inline void mini(T &a, T b) { a = min(a, b); }
    template <typename T> inline void maxi(T &a, T b) { a = max(a, b); }
    template <class T>
    class Random {
        inline static T range(T &a, T &b) { return a + rand() % (b - a + 1); }
    };
    template <class K, class V>
    using table = __gnu_pbds::gp_hash_table<K, V>;
    template <typename K, typename V, typename Comp = std::less<K>>
    using ordered_map = __gnu_pbds::tree<
        K, V, Comp,
        __gnu_pbds::rb_tree_tag,
        __gnu_pbds::tree_order_statistics_node_update>;
    template <typename K, typename Comp = std::less<K>>
    using ordered_set = ordered_map<K, __gnu_pbds::null_type, Comp>;
}; // namespace std

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

const int mod = (int)1e9 + 7;
const ld PI = 3.141592653589793238f;

// overflows? index_of_of_bound? integer_overflows? read the problem?
void test_case(const int &test_no) {
    int N; cin >> N;
    int K; cin >> K;
    vector<int> a(N); for (int& i : a) cin >> i;
    
    vector<int> dp(K + 1);
    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        vector<int> ndp(K + 1);
        ndp[0] = 1;
        vector<int> prefix;

        int sum = 0;
        for (int k = 0; k <= K; k++) {
            sum = (sum + dp[k]) % mod;
            prefix.emplace_back(sum);
        }

        for (int j = 1; j <= K; j++) {
            int L = j - min(j, a[i - 1]);
            int R = j;
            // for (int k = 0; k <= min(j, a[i - 1]); k++) {
                // dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
            // }
            
            int interval = (prefix[R] - (L - 1 >= 0 ? prefix[L - 1] : 0) + mod) % mod;
            ndp[j] = ((ndp[j] + interval) % mod + mod) % mod;
        }
        dp = ndp;
    }
    cout << dp[K] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
#endif
    int T = 1; 
    for (int test_no = 1; test_no <= T; ++test_no) {
        test_case(test_no);
    }
#ifdef LOCAL
    cerr << "\nTime elapsed: " << ld(clock()) / CLOCKS_PER_SEC << "s.\n";
#endif
}


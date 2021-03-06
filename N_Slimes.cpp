/**
 *  author: souravrax
 *  created: 06.03.2021 12:31:23
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


ll N;
ll dp[500][500];
vector<ll> prefix;

inline ll cost(ll l, ll r) { return prefix[r] - (l - 1 >= 0 ? prefix[l - 1] : 0); }

ll solve(int l, int r) {
    if (l == r) return 0;
    assert(l < r);
    ll& ans = dp[l][r];
    if (~ans) return ans;
    ans = 2e18;
    log(l, r, cost(l, r));
    for (int mid = l; mid < r; mid++) {
        ans = min(ans, solve(l, mid) + solve(mid + 1, r) + cost(l, r));
    }
    return ans;
}

void test_case(const int &test_no) {
    prefix.clear();
    cin >> N;
    vector<ll> a(N);
    for (ll& i : a) cin >> i;
    partial_sum(all(a), back_inserter(prefix));
    log(prefix);
    for (int i = 0; i <= N; i++) for (int j = 0; j <= N; j++) dp[i][j] = -1;
    cout << solve(0, N - 1) << '\n';
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


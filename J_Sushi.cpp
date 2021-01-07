/**
 *  author: sourav rakshit
 *  created: 21.10.2020 12:15:42
**/
/* #pragma GCC optimize("O3") */
/* #pragma GCC target ("avx2") */
/* #pragma GCC optimize("unroll-loops") */
/* #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;

//@pbds
template<typename K, typename V, typename Comp = std::less<K>>
using ordered_map = __gnu_pbds::tree<
    K, V, Comp,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;
template <typename K, typename Comp = std::less<K>>
using ordered_set = ordered_map<K, __gnu_pbds::null_type, Comp>;

//@Macros
#define ar array
#define len(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define str(s) to_string(s)
#define hi_im_sourav main

//@Magic Lambdas
namespace std {
template<class Fun> class rec_result{
Fun fun_;
public:
template<class T>
explicit rec_result(T &&fun): fun_(std::forward<T>(fun)) {}
template<class ...Args>
decltype(auto) operator()(Args &&...args) {
return fun_(std::ref(*this), std::forward<Args>(args)...);}};
template<class Fun>decltype(auto) rec(Fun &&fun) {
return rec_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}} // namespace std

//@Debugger
#ifdef LOCAL
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v)
{ os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) 
{ os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) 
{ return os << '(' << p.first << "," << p.second << ')'; }

void flush_out() { cerr << endl; }
template<typename H, typename... T> void flush_out(H h, T... t) { cerr << ' ' << h << " | "; flush_out(t...); }
#define log(...) cerr << "[ " << #__VA_ARGS__ << " ] :", flush_out(__VA_ARGS__)
#else
#define log(...) (void)0x30
#endif

//@alias
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<ll>;

//@Utilities
template<typename T> inline void mini(T& a, T b) { a = min(a, b); }
template<typename T> inline void maxi(T& a, T b) { a = max(a, b); }
template<class T>class Random{ static T range(T&a, T&b){ return a+rand()%(b-a+1); }};

//*//---------------------------- Globals --------------------------//*//

const int mod = 1e9 + 7;
const ll INF = 1e18;
const int nax = 2000 * 2007;
const ld PI = 4*atan((ld)1);

//*//---------------------------- Code Begins Here --------------------------//*//

const int N = 305;

ld dp[N][N][N];

void _tc() {
    int n;
    cin >> n;
    dp[0][0][0] = 0;
    int cnt[4] = {0};

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }

    // p -> probability
    // dp[three][two][one] = 1 + p3 * dp[three - 1][two + 1][one] + p2 * dp[three][two - 1][one + 1] + p1 * dp[three][two][one - 1] + p0 * dp[three][two][one];
    // dp[three][two][one] - p0 * dp[three][two][one] = 1 + p3 * dp[three - 1][two + 1][one] + p2 * dp[three][two - 1][one + 1] + p1 * dp[three][two][one - 1];
    // dp[three][two][one] * (1 - p0) = 1 + p3 * dp[three - 1][two + 1][one] + p2 * dp[three][two - 1][one + 1] + p1 * dp[three][two][one - 1];
    // dp[three][two][one] = (1 + p3 * dp[three - 1][two + 1][one] + p2 * dp[three][two - 1][one + 1] + p1 * dp[three][two][one - 1]) / (1 - p0);

    dp[0][0][0] = 0.0f; // probability of taking 0 (3, 2, 1 and 0) is zero
    for (int three = 0; three <= n; three++) {
        for (int two = 0; two <= n; two++) {
            for (int one = 0; one <= n; one++) {
                if (one + two + three > n) continue;
                int zero = n - one - two - three;
                if (zero >= n) continue;
                
                ld val = 1.00f;

                ld p3 = ld(three) / n;
                ld p2 = ld(two) / n;
                ld p1 = ld(one) / n;
                ld p0 = ld(zero) / n;

                // take 3
                if (three > 0) {
                    val += p3 * dp[three - 1][two + 1][one];
                }
                // take 2
                if (two > 0) {
                    val += p2 * dp[three][two - 1][one + 1];
                }
                // take 1
                if (one > 0) {
                    val += p1 * dp[three][two][one - 1];
                }
                dp[three][two][one] = val / (1 - p0);
            }
        }
    }
    cout << setprecision(14);
    cout << fixed;
    cout << dp[cnt[3]][cnt[2]][cnt[1]] << '\n';
}

int hi_im_sourav() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _t = 1;
    for(int _=_t-1;~_;--_){
        _tc();
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
#endif
}

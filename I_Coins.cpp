/**
 *  author: sourav rakshit
 *  created: 30.08.2020 09:08:48
**/

/* #pragma GCC optimize("O3") */
/* #pragma GCC target ("avx2") */
/* #pragma GCC optimize("unroll-loops") */
/* #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template <typename T, typename cmp=less<T>>
using ordered_set=tree<T,null_type,cmp,rb_tree_tag,tree_order_statistics_node_update>;
template<typename K, typename V, typename cmp=less<K>>
using ordered_map=tree<K, V, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename cmp=less_equal<T>> // upper_bound works as lower bound
using ordered_multiset=tree<T, null_type,cmp,rb_tree_tag,tree_order_statistics_node_update>;

//@alias
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<ll>;

//@Macros
#define ar array
#define len(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define str(s) to_string(s);

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

//@Useful inlines
template<typename T> inline void mini(T& a, T b) { a = min(a, b); }
template<typename T> inline void maxi(T& a, T b) { a = max(a, b); }
template<typename T> inline int range(T& a, T& b) { return a+rand()%(b-a+1); }

//*//---------------------------- Globals --------------------------//*//

const int mod = 1e9+7;
const ll INF = 1e18;
const int nax = 2000 * 2007;
const ld PI = 4*atan((ld)1);

//*//---------------------------- Code Begins Here --------------------------//*//

double dp[3000][3000];

double solve(int n, const vector<double>& coins, int head, const int& size) {
    if(n == 0) {
        if(head > size / 2) return 1;
        else return 0;
    }
    double& ans = dp[n][head];
    if(ans != -1) return ans;
    return ans = solve(n-1, coins, head + 1, size) * coins[n-1] + solve(n-1, coins, head, size) * (1.00 - coins[n-1]);
}

inline void tc() {
    int n;
    cin >> n;
    vector<double> arr(n);
    for(double& i : arr) cin >> i;
    for(int i=0; i<3000; i++) {
        for(int j=0; j<3000; j++) dp[i][j] = -1.00;
    }

    cout << fixed << setprecision(10) << solve(n, arr, 0, n) << '\n';
}


int32_t main() {
    ios::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
#endif
    int tt = 1;
    /* cin >> tt; */
    for(int _=tt-1;~_;--_){
        tc();
    }
#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
#endif
}

//1. Check for integer overflow, array bounds
//2. Check for the lowest valid/invalid input
//3. Try special cases, set tle


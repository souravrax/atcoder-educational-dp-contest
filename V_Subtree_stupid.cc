/**
 *  author: souravrax
 *  created: 27.05.2021 15:25:57
**/
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define len(x) int((x).size())
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> 
ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "[ " << #__VA_ARGS__ << " ]:", dbg_out(__VA_ARGS__)
#else
#define dbg(...) (void)0x30
#endif
using ll = unsigned long long;

const int N = (int)1e5 + 5;
int M;
vector<int> tree[N];
ll dp[N];
int n;

void dfs1(int u, int p) {
    dp[u] = 1LL;
    for (int& v : tree[u]) {
        if (v == p) continue;
        dfs1(v, u);
        // dbg(u, v, dp[u], dp[v]);
        dp[u] = dp[u] * (dp[v] + 1);
        assert(dp[u] < LLONG_MAX);
    }
}

void dfs2(int u, int p) {
    dp[u] = (dp[p] / (dp[u] + 1) + 1) * dp[u];
    for (int& v : tree[u]) {
        if (v == p) continue;
        dfs2(v, u);
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> M;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs1(0, 0);
    dfs2(0, 0);
    for (int i = 0; i < n; i++) {
        dbg(dp[i]);
        dp[i] %= M;
        ll ans = (ll)dp[i];
        cout << ans << '\n';
    }
}


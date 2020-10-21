#pragma GCC optimize("O3")
/* #pragma GCC target ("avx2") */
/* #pragma GCC optimize("Ofast") */
/* #pragma GCC optimize("unroll-loops") */
/* #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T, typename cmp=less<T>>
using ordered_set=tree<T,null_type,cmp,rb_tree_tag,tree_order_statistics_node_update>;
template<typename K, typename V, typename cmp=less<K>>
using ordered_map=tree<K, V, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k) returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
using ll = long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax = 1000*1007;
#define ar array
#define len(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define tT template<typename T
#define tV typename V
#define ins inline string
#ifdef LOCAL
tT>ins to_string(T& t);
ins to_string(string s) {return '"' + s + '"';}
ins to_string(char c){string res="'";res.push_back(c);return res+"'";}
ins to_string(const char* s) {return to_string((string)s);}
ins to_string(char* s) {return to_string((string)s);}
template <size_t N>ins to_string(bitset<N> v) {string res="";for(size_t i = 0; i < N; i++){
res += static_cast<char>('0' + v[i]);}return res;}
ins to_string(bool b) {return (b ? "true" : "false");}
tT,tV>ins to_string(pair<T, V>& p){return "("+ to_string(p.first)+", "+to_string(p.second)+")";}
tT>ins to_string(T& v){string res="{";for(auto& i:v){res+=to_string(i)+',';} return res+'}';}
#define log(...) cerr<< "[" << #__VA_ARGS__ << " : "<< to_string(__VA_ARGS__) << "]"<<endl
#else
#define log(...) 0x30
#endif

vector<vector<int>> edges;
int dp[100001];

int solve(int i){
    if(edges[i].size() == 0) return 0;
    if(dp[i] != -1) return dp[i];
    for(auto edge : edges[i]){
        dp[i] = max(solve(edge)+1, dp[i]);
    }
    return dp[i];
}

inline void test_case(){
    memset(dp, -1, sizeof dp);
    int n, m;
    cin>>n>>m;
    edges.resize(n+1);
    for(int i=0; i<m; i++){
        int x;
        int y;
        cin>>x>>y;
        edges[x].push_back(y);
    }
    int mxm = INT_MIN;
    for(int i=1; i<=n; i++){
        mxm = max(mxm, solve(i));
    }
    /* for(int i=1; i<=n; i++){ */
    /*     log(dp[i]); */
    /* } */
    cout<<mxm<<'\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    test_case();
}   


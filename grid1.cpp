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

int dp[1001][1001];
const int mod = 1e9+7;

/* int solve(const vector<vector<char>>& grid, int n, int w){ */
/*     if(n < 1 || w < 1 ) return 0; */
/*     if(n==1 && w == 1) return 1; */
/*     if(dp[n][w] != -1) return dp[n][w]; */
/*     int a = 0; */
/*     int b = 0; */
/*     if(grid[n-1][w] != '#') a = solve(grid, n-1, w); */
/*     if(grid[n][w-1] != '#') b = solve(grid, n, w-1); */
/*     return dp[n][w] = (a%mod+b%mod)%mod; */
/* } */

int solve(const vector<vector<char>>& grid, int n, int w){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=w; j++){
            if(i== 1 ) dp[i][j] = 0;
            if(j==1) dp[i][j] = 0;
            if(i==1 && j == 1) dp[i][j] = 1;
        }
    }
    for(int i=2; i<=n; i++){
        for(int j=2; j<=w; j++){
            int a = 0;
            int b = 0;
            if(grid[i-1][j] != '#') a = dp[i-1][j];
            if(grid[i][j-1] != '#') b = dp[i][j-1];
            dp[i][j] = (a%mod+b%mod)%mod;
        }
    }
    return dp[n][w]%mod;
}

inline void test_case(){
    memset(dp, -1, sizeof dp);
    int h, w;
    cin>>h>>w;
    vector<vector<char>> grid(h+1, vector<char>(w+1));
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin>>grid[i][j];
        }
    }
    cout<<solve(grid, h, w)<<"\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    test_case();
}   


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

inline void solve(const string& s, const string& t, int& n, int& m){
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    /* log("reached"); */
    /* log(dp); */
    log(dp[n][m]);
    string res;
    while(n>0 && m>0){
        if(s[n-1] == t[m-1]){
            res.push_back(s[n-1]);
            --n, --m;
        }
        else{
            if(dp[n-1][m] >= dp[n][m-1]){
                n--;
            }
            else m--;
        }
        log(res);
    }
    reverse(all(res));
    cout<<res<<"\n";
}

inline void test_case(){
    string s;
    string t;
    cin>>s>>t;
    int n = s.size();
    int m = t.size();
    solve(s, t, n, m);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    test_case();
}   


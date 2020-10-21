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

vector<int> h;
int dp[100000+7];

int solve(int N){
    /* if(N==0) return; */
    if(N == 1) return 0;
    if(N == 2) return abs(h[0] - h[1]);
    if(dp[N] != -1) return dp[N];
    return dp[N] = min(abs(h[N-1]-h[N-2]) + solve(N-1), abs(h[N-1]-h[N-3])+solve(N-2));
}

int iter_solve(int N){
    dp[1] = 0;
    dp[2] = abs(h[0]-h[1]);
    for(int i=3; i<=N; i++){
        dp[i] = min(abs(h[i-1]-h[i-2]) + dp[i-1], abs(h[i-1]-h[i-3])+dp[i-2]);
    }
    return dp[N];
}

inline void test_case(){
    memset(dp, -1, sizeof dp);
    int N;
    cin>>N;
    h.resize(N);
    for(int& i : h) cin>>i;
    cout<<iter_solve(N)<<"\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt=  1;
    for(int qq=1; qq<=tt; qq++){
        /* cout<<"Case #"<<qq<<": "; */
        test_case();
    }
}   


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

#define int long long

/* class wtstore{ */
/*     private: */
/*     vector<int> part1(500000, -1); */
/*     vector<int> part2(500000, -1); */
/*     public: */
/*     int at(int indx){ */
/*         if(indx < 500000){ */
/*             return part1[indx]; */
/*         } */
/*         else return part2[indx-500000]; */
/*     } */
/*     int set(int indx, int value){ */
/*         if(indx < 500000){ */
/*             part1[indx] = value; */
/*         } */
/*         else par2[indx] = value; */
/*         return value; */
/*     } */
/* }; */

vector<int> wt;
vector<int> val;
vector<vector<int>> dp;

int solve(const int& n, const int& w, const int& value){
    for(int i=0; i<=n; i++){
        for(int v=0; v<=value; v++){
            if( i==0) dp[i][v] = INT_MAX-value;
            if(v == 0) dp[i][v] = 0;
        }
    }

    /* Finding the mimimum weight required to make a value */
    for(int i=1; i<=n; i++){
        for(int v=1; v<=value; v++){
            if(val[i-1] > v) dp[i][v] = dp[i-1][v];
            else dp[i][v] = min(dp[i-1][v-val[i-1]]+wt[i-1], dp[i-1][v]);
        }
    }

    /* vector<Pair<weight, value>> */
    vector<pair<int,int>> arr;
    for(int i=1; i<=value; i++){
        arr.emplace_back(dp[n][i], i);
    }

    int mxm = INT_MIN;
    for(auto i : arr){
        if( i.first <= w) mxm = max(mxm, i.second);
    }
    return mxm;

}

inline void test_case(){
    /* memset(dp, 0, sizeof dp); */
    int n;
    cin>>n;
    int w;
    cin>>w;
    wt.resize(n);
    val.resize(n);
    int value = 0;
    for(int i=0; i<n; i++){
        cin>>wt[i]>>val[i];
        value+=val[i];
    }
    dp.assign(n+10, vector<int>(value+10, 0));
    cout<<solve(n, w, value)<<'\n';
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    test_case();
}   


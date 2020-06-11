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

int dp[100000+7][3];
vector<array<int, 3>> arr;

/* int solve(const vector<array<int, 3>>& arr, int n, int dont){ */
/*     if( n == 1){ */
/*         if(dont == 0) return max(arr[n-1][1], arr[n-1][2]); */
/*         else if(dont == 1) return max(arr[n-1][0], arr[n-1][2]); */
/*         else return max(arr[n-1][0], arr[n-1][1]); */
/*     } */
/*     if(dp[n][dont]!=-1){ */
/*         log("found"); */
/*         return dp[n][dont]; */
/*     } */

/*     if(dont == 0){ */
/*         return dp[n][dont] = max(solve(arr, n-1, 1)+arr[n-1][1], solve(arr, n-1, 2)+arr[n-1][2]); */
/*     } */
/*     else if(dont == 1){ */
/*         return dp[n][dont] = max(solve(arr, n-1, 0)+ arr[n-1][0], solve(arr, n-1, 2) + arr[n-1][2]); */
/*     } */
/*     else return dp[n][dont] = max(solve(arr, n-1, 0) + arr[n-1][0], solve(arr, n-1, 1) + arr[n-1][1]); */
/* } */

int solve(int n, int dont){
    for(int i=1; i<=n; i++){
        for(int dn=0; dn<3; dn++){
            if(i == 1){
                if(dn == 0){
                    dp[i][dn] = max(arr[i-1][1], arr[i-1][2]);
                }
                else if(dn == 1){
                    dp[i][dn] = max(arr[i-1][0] , arr[i-1][2]);
                }
                else if(dn == 2){
                    dp[i][dn] = max(arr[i-1][0], arr[i-1][1]);
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int dn = 0; dn<3; dn++){
            if(dn == 0){
                dp[i][dn] = max(dp[i-1][1]+arr[i-1][1], dp[i-1][2] + arr[i-1][2]);
            }
            else if(dn == 1){
                dp[i][dn] = max(dp[i-1][0]+arr[i-1][0], dp[i-1][2] + arr[i-1][2]);
            }
            else if(dn == 2){
                dp[i][dn] = max(dp[i-1][0]+arr[i-1][0], dp[i-1][1] + arr[i-1][1]);
            }
        }
    }
    return dp[n][dont];
}


inline void test_case(){
    memset(dp, 0, sizeof dp);
    int n;
    cin>>n;
    arr.resize(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];
        }
    }
    cout<<max(max(solve(n, 0), solve(n, 1)), solve(n, 2))<<"\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    test_case();
}   


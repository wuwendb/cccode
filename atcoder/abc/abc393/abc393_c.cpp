// Problem: C - Make it Simple
// Contest: AtCoder - AtCoder Beginner Contest 393
// URL: https://atcoder.jp/contests/abc393/tasks/abc393_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= int(b); ++i)  
#define rev(i, a, b) for (int i = int(a); i >= (b); --i) 
#define all(a) begin(a),end(a)
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using namespace std;  

const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

void solve() {  
    int N,M;cin>>N>>M;
    unordered_set<i64> st;
    int ans = 0;
    rep(i,0,M-1){
    	int u,v;cin>>u>>v;u--,v--;
    	if(u>v) swap(u,v);
    	if(u==v) continue;
		st.insert((i64)u<<20|v);
    }
    cout<<M-st.size()<<endl;
}  
  
signed main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);  
    int t=1;  
    // cin >> t; 
    cout<<fixed<<setprecision(1); 
    while (t--) {  
        solve();  
    } 
    return 0;  
}

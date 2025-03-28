// Problem: F - Teleporting Takahashi 2
// Contest: AtCoder - UNIQUE VISION Programming Contest 2024 Autumn (AtCoder Beginner Contest 372)
// URL: https://atcoder.jp/contests/abc372/tasks/abc372_f
// Memory Limit: 1024 MB
// Time Limit: 3000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a)
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
//#define ll long long  
#define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

  
void solve() {  
    int n,m,k;cin>>n>>m>>k;
    vector<vector<int>> g(n);
    rep(i,0,n-2){
    	g[i].pb(i+1);
    }
    g[n-1].pb(0);
    rep(i,1,m){
    	int x,y;cin>>x>>y;x--,y--;
    	g[x].pb(y);
    }
    int ans = 0;
    auto dfs = [&](auto& self,int x,int cnt){
    	if(cnt==k){
    		ans=(ans+1)%MOD;
    		return;
    	}
    	
    };
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
    // cout<<pow(2,22)<<endl;  
    return 0;  
}

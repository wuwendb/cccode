// Problem: F - Dividing Game
// Contest: AtCoder - Hitachi Vantara Programming Contest 2024（AtCoder Beginner Contest 368）
// URL: https://atcoder.jp/contests/abc368/tasks/abc368_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

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
    int n;cin>>n;
    vector<int> a(n);
    rep(i,0,n-1) cin>>a[i];
    int m = ranges::max(a);
    vector<vector<int>> fac(m+1);
    rep(i,1,m){
    	for(int j =i*2;j<=m;j+=i){
    		fac[j].push_back(i);
    	}
    }
    vector<int> sg(m+1);
    rep(i,1,m){
    	int k = fac[i].size();
    	vector<int> vis(k+1);
    	for(auto x:fac[i]){
    		if(sg[x]<=k) vis[sg[x]]++;
    	}
    	while(vis[sg[i]]>0) sg[i]++;
    }
    int ans = 0;
    for(auto x:a){
    	ans^=sg[x];
    }
    cout<<(ans==0?"Bruno\n":"Anna\n");
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

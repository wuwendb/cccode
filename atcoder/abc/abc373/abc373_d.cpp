// Problem: D - Hidden Weights
// Contest: AtCoder - AtCoder Beginner Contest 373
// URL: https://atcoder.jp/contests/abc373/tasks/abc373_d
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
vector<pii> g[mx];
int ans[mx];
void solve() {  
    int n,m;cin>>n>>m;
    rep(i,1,m){
    	int u,v,w;
    	cin>>u>>v>>w;
    	g[u].pb({v,w});
    	g[v].pb({u,-w});
    }
    vector<int> vis(n+1,false);
    queue<int> q;
    for(int i = 1;i<n;i++){
    	if(!vis[i]){
    		q.push(i);
    		vis[i] = 1;
    		while(!q.empty()){
    			auto u = q.front();q.pop();
    			for(auto [v,w]:g[u]){
    				if(!vis[v]){
    					vis[v] = 1;
    					q.push(v);
    					ans[v] = ans[u]+w;
    				}
    			}
    		}
    	}
    }
    rep(i,1,n){
    	cout<<ans[i]<<" \n"[i==n];
    }
    
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

// Problem: E - Souvenir
// Contest: AtCoder - UL Systems Programming Contest 2023(AtCoder Beginner Contest 286)
// URL: https://atcoder.jp/contests/abc286/tasks/abc286_e
// Memory Limit: 1024 MB
// Time Limit: 3000 ms

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
    int n;cin>>n;
    vector<int> weight(n);
    rep(i,0,n-1) cin>>weight[i];
    vector<vector<pair<int,i64>>> g(n,vector<pair<int,i64>>(n));
    rep(i,0,n-1){
    	rep(j,0,n-1){
    		char c;cin>>c;
    		if(c=='Y'){
    			g[i][j] = {1,weight[i]};
    		}else{
    			g[i][j] = {INT_MAX/3,0};
    		}
    	}
    }
    rep(k,0,n-1){
    	rep(i,0,n-1){
    		rep(j,0,n-1){
    			auto nd = g[i][k].first + g[k][j].first;
    			auto nw = g[i][k].second + g[k][j].second;
    			if(nd<g[i][j].first||nd==g[i][j].first &&nw>g[i][j].second){
    				g[i][j] = {nd,nw};
    			}
    		}
    	}
    }
    int q;cin>>q;
    rep(i,0,q-1){
    	int u,v;cin>>u>>v;u--,v--;
    	auto res = g[u][v];
    	if(res.first==INT_MAX/3){
    		cout<<"Impossible"<<endl;
    	}else{		
	    	cout<<res.first<<" "<<res.second+weight[v]<<endl;
    	}
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
    return 0;  
}

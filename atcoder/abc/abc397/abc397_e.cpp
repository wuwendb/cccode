// Problem: E - Path Decomposition of a Tree
// Contest: AtCoder - OMRON Corporation Programming Contest 2025 (AtCoder Beginner Contest 397)
// URL: https://atcoder.jp/contests/abc397/tasks/abc397_e
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
    int n,k;cin>>n>>k;
    vector<vector<int>> adj(n*k);
    rep(i,0,n*k-2){
    	int u,v;cin>>u>>v;
    	u--,v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    auto dfs = [&](auto &&self, int x, int p=-1)->int{
    	int sum = 0, cnt= 0;
    	for(auto y:adj[x]){
    		if(y==p){
    			continue;
    		}
    		int t = self(self, y, x);
    		if(t==-1){
    			return -1;
    		}
    		if(t>0){
    			cnt++;
    			sum+=t;
    		}
    	}
    	if(cnt>2){
    		return -1;
    	}
    	if(sum == k-1){
    		return 0;
    	}else if(cnt == 2){
    		return -1;
    	}else{
    		return sum+1;
    	}
    };
    if(dfs(dfs,0)==0){
    	cout<<"Yes"<<endl;
    }else{
    	cout<<"No"<<endl;
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

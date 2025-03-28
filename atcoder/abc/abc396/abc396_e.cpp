// Problem: E - Min of Restricted Sum
// Contest: AtCoder - AtCoder Beginner Contest 396
// URL: https://atcoder.jp/contests/abc396/tasks/abc396_e
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
    int N,M;cin>>N>>M;
    vector<vector<array<int,2>>> adj(N);
    rep(i,0,M-1){
    	int X,Y,Z;cin>>X>>Y>>Z;
    	X--,Y--;
    	adj[X].pb({Y,Z});
    	adj[Y].pb({X,Z});
    }
    vector<int> A(N,-1);
    rep(x,0, N-1){
    	if(A[x] != -1){
    		continue;
    	}
    	vector<int> idx{x};
    	A[x] = 0;
    	int cnt[30]{};
    	for(int i=0;i<idx.size();i++){
    		int u = idx[i];
    		rep(j,0,29){
    			cnt[j] += A[u] >> j & 1;
    		}
    		for(auto [v,w]:adj[u]){
    			if(A[v] == -1){
    				A[v] = A[u]^w;
    				idx.pb(v);
    			}else if(A[v]!= (A[u]^w	)){
    				cout<<-1<<endl;
    				return;
    			}
    		}
    	}
    	int mask = 0;
    	rep(i,0,29){
    		if(cnt[i] > idx.size()-cnt[i]){
    			mask ^= 1<<i;
    		}
    	}
    	for(auto i:idx){
    		A[i] ^= mask;
    	}
    }
    rep(i,0,N-1){
    	cout<<A[i]<<" \n"[i==N-1];
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

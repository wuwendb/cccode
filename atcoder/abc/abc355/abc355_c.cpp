// Problem: C - Bingo 2
// Contest: AtCoder - Tokio Marine & Nichido Fire Insurance Programming Contest 2024（AtCoder Beginner Contest 355)
// URL: https://atcoder.jp/contests/abc355/tasks/abc355_c
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
    int n,t;cin>>n>>t;
    vector<vector<int>> g(n,vector<int>(n,0));
    auto check = [&](int i,int j){
    	g[i][j]=1;
    	rep(x,0,n-1){
    		if(g[x][j]==0){
    			break;
    		}
    		if(x==n-1) return true;
    	}
    	rep(y,0,n-1){
    		if(g[i][y]==0){
    			break;
    		}
    		if(y==n-1) return true;
    	}
    	rep(x,0,n-1){
    		if(g[x][x]==0){
    			break;
    		}
    		if(x==n-1) return true;
    	}
    	rep(x,0,n-1){
    		if(g[x][n-1-x]==0){
    			break;
    		}
    		if(x==n-1) return true;
    	}
    	return false;
    };
    rep(i,1,t){
    	int x;cin>>x;x--;
    	if(check(x/n,x%n)){
    		cout<<i<<endl;
    		return;
    	}
    }
    cout<<-1<<endl;
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

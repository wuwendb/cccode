// Problem: 16进制世界
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/89237/C
// Memory Limit: 1048576 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a) 
//#define ll long long  
#define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
int dp[mx][16];
void solve() {  
    int n,m;cin>>n>>m;
    vector<pair<int,int>> a;
    rep(i,1,n){
    	int v,w;cin>>v>>w;
    	a.emplace_back(v,w%16);
    }
    rep(i,0,m){
    	rep(j,1,15){
    		dp[i][j] = LLONG_MIN;
    	}
    }
    rep(i,0,n-1){
    	rev(j,m,a[i].first){
    		rep(k,0,15){
    			dp[j][k] = max(dp[j-a[i].first][(16+k-a[i].second)%16]+1,dp[j][k]);				
    		}
    	}
    }
    int ans = 0;
    rep(i,0,m){
    	ans = max(ans,dp[i][0]);
    }
    cout<<ans<<endl;
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

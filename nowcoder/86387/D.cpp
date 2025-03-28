// Problem: 小红组比赛
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/86387/D
// Memory Limit: 524288 MB
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
int a[110][30];
int n,m,target;
void solve() {  
    cin>>n>>m;
    int maxx = 0;
    rep(i,0,n-1){
    	int ma= 0;
    	rep(j,0,m-1){
    		cin>>a[i][j];
    		ma = max(ma,a[i][j]);
    	}
    	maxx += ma;
    }
    cin>>target;
    
    vector<vector<bool>> f(n+1,vector<bool>(maxx+1,false));
    f[0][0]=true;
    for(int i=0;i<n;i++){
    	for(int j = 0;j<=maxx;j++){
    		for(int k = 0;k<m;k++){
    			if(j-a[i][k]>=0) f[i+1][j] = f[i+1][j] || f[i][j-a[i][k]];
    		}
    	}
    }
    int ans = LLONG_MAX;
    rep(i,0,maxx){
    	if(f[n][i]) ans = min(ans,abs(i-target));
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

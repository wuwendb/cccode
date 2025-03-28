// Problem: D - Laser Marking
// Contest: AtCoder - KEYENCE Programming Contest 2024（AtCoder Beginner Contest 374）
// URL: https://atcoder.jp/contests/abc374/tasks/abc374_d
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
    int n,s,t;cin>>n>>s>>t;
    vector<int> a(n),b(n),c(n),d(n),vis(n);
    rep(i,0,n-1) cin>>a[i]>>b[i]>>c[i]>>d[i];
    double ans = INFINITY;
    auto dfs = [&](auto& self,int x,int y,double sum,int cnt){
    	if(cnt == n){
    		ans = min(ans,sum);return;
    	}
    	rep(i,0,n-1){
    		if(!vis[i]){
    			auto d1 = hypot(x-a[i],y-b[i]);
    			auto d2 = hypot(x-c[i],y-d[i]);
    			auto w = hypot(a[i]-c[i],b[i]-d[i]);
    			vis[i]=1;
    			self(self,a[i],b[i],sum+d2/s+w/t,cnt+1);
    			self(self,c[i],d[i],sum+d1/s+w/t,cnt+1);
    			vis[i]=0;
    		}
    	}
    };
    dfs(dfs,0,0,0.0,0);
    cout<<ans<<endl;
}  
  
signed main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);  
    int t=1;  
    // cin >> t; 
    cout<<fixed<<setprecision(20); 
    while (t--) {  
        solve();  
    }  
    // cout<<pow(2,22)<<endl;  
    return 0;  
}

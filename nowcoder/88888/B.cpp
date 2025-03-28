// Problem: 小红的树切割
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/88888/B
// Memory Limit: 524288 MB
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
int w[mx];
  
void solve() {  
    int n;cin>>n;
    rep(i,1,n){
    	char c;cin>>c;
    	if(c=='R') w[i]=1;
    }
    int ans = 0;
    rep(i,1,n-1){
    	int u,v;cin>>u>>v;
    	if(w[u]==w[v]) ans++;
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

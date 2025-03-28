// Problem: 等公交车
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/89237/G
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

  
void solve() {  
    int n,m;cin>>n>>m;
    vector<int> d(n),ct(m);
    rep(i,1,n){
    	cin>>d[i-1];
    }
    rep(i,1,m){
    	cin>>ct[i-1];
    }
    int q;cin>>q;
    rep(i,1,q){
    	int t,x;cin>>t>>x;
    	int dis = d[x-1];
		auto ans = lower_bound(all(ct),t-dis);
		if(ans == ct.end()) cout<<"TNT"<<endl;
		else cout<<*ans-(t-dis)<<endl;
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

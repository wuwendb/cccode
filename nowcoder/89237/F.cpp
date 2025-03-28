// Problem: 追寻光的方向
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/89237/F
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
    int n;cin>>n;
    vector<int> l(n);	
    rep(i,0,n-1) cin>>l[i];
    stack<int> stk;
    int ans = 0;
    rev(i,n-1,1){
    	if(stk.empty()||l[i]>=stk.top()){
    		if(!stk.empty()) ans++;
    		stk.push(l[i]);
    	}
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

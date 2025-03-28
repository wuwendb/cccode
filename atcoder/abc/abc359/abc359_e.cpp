// Problem: E - Water Tank
// Contest: AtCoder - UNIQUE VISION Programming Contest 2024 Summer (AtCoder Beginner Contest 359)
// URL: https://atcoder.jp/contests/abc359/tasks/abc359_e
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
    int n;cin>>n;
    vector<int> h(n+1,1e9+10);
    rep(i,1,n) cin>>h[i];
    vector<i64> ans(n+1,1);
    stack<pii> stk;
    stk.push({h[0],0});
    rep(i,1,n){
    	while(stk.top().first<h[i]){
			stk.pop();
		}
    	if(h[i]<=h[i-1]){
			ans[i] = ans[i-1]+h[i];
    	}else{
    		auto po = stk.top().second;
    		ans[i] = ans[po]+1LL*(i-po)*h[i];
    	}
    	stk.push({h[i],i});
    }
    rep(i,1,n) cout<<ans[i]<<" \n"[i==n];
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

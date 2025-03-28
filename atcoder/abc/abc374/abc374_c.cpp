// Problem: C - Separated Lunch
// Contest: AtCoder - KEYENCE Programming Contest 2024（AtCoder Beginner Contest 374）
// URL: https://atcoder.jp/contests/abc374/tasks/abc374_c
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
    int n;cin>>n;
    vector<int> a(n);rep(i,0,n-1) cin>>a[i];
    int sum = accumulate(all(a),0LL);
    int ans = sum;
    vector<int> g(1<<n);
    rep(i,0,(1<<n)-1){
    	if(i){
    		int j = __builtin_ctz(i);
    		g[i] = a[j]+g[i^(1<<j)];
    	}
    	ans = min(ans,max(g[i],sum-g[i]));
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

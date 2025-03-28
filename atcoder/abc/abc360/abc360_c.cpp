// Problem: C - Move It
// Contest: AtCoder - AtCoder Beginner Contest 360
// URL: https://atcoder.jp/contests/abc360/tasks/abc360_c
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
    vector<int> a(n),w(n);
    vector<int> ma(n+1,0);
    rep(i,1,n) cin>>a[i-1];
    rep(i,1,n) cin>>w[i-1];
    rep(i,0,n-1) {
    	ma[a[i]] = max(ma[a[i]],w[i]);
    }
    cout<<accumulate(w.begin(),w.end(),0)-accumulate(ma.begin(),ma.end(),0)<<endl;
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

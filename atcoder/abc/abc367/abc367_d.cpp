// Problem: D - Pedometer
// Contest: AtCoder - AtCoder Beginner Contest 367
// URL: https://atcoder.jp/contests/abc367/tasks/abc367_d
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
    int n,m;cin>>n>>m;
    vector<int> a(2*n);
    rep(i,0,n-1){
    	cin>>a[i];
    	a[n+i] = a[i];
    }
    vector<int> pre(2*n+1);
    rep(i,1,2*n){
    	pre[i] = (pre[i-1]+a[i%n])%m;
    }
    int ans = 0;
    unordered_map<int,int> mp;
    rep(i,0,n-1){
    	mp[pre[i]]++;
    }
    rep(i,n,2*n-1){
    	mp[pre[i-n]]--;
    	ans+=mp[pre[i]];
    	mp[pre[i]]++;
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
    return 0;  
}

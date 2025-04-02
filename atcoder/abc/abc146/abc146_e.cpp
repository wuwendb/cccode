// Problem: E - Rem of Sum is Num
// Contest: AtCoder - AtCoder Beginner Contest 146
// URL: https://atcoder.jp/contests/abc146/tasks/abc146_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= int(b); ++i)  
#define rev(i, a, b) for (int i = int(a); i >= (b); --i) 
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
    int n,k;cin>>n>>k;
    vector<i64> a(n);
    rep(i,0,n-1) cin>>a[i];
    vector<i64> pre(n+1);
    rep(i,0,n-1){
    	pre[i+1] = (pre[i]+a[i]-1)%k;
    }
    map<int, int> mp;
    i64 ans = 0;
    rep(i,0,n){
    	ans += mp[pre[i]]++;
    	if(i>=k-1){
    		mp[pre[i-k+1]]--;
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
    return 0;  
}

// Problem: E - Xor Sigma Problem
// Contest: AtCoder - Toyota Programming Contest 2024#8（AtCoder Beginner Contest 365）
// URL: https://atcoder.jp/contests/abc365/tasks/abc365_e
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
    vector<int> a(n);
    rep(i,0,n-1) cin>>a[i];
    i64 ans = 0;
    rep(i,0,30){
    	i64 res= 0;
    	i64 pre= 0;
    	vector<int> cnt(2,0);
    	rep(j,0,n-1){
    		pre^=(a[j]>>i)&1;
			res+=cnt[pre^1];
    		cnt[pre^((a[j]>>i)&1)]++;
    	}
    	ans+=res*(1<<i);
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

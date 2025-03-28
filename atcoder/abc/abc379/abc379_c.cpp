// Problem: C - Sowing Stones
// Contest: AtCoder - Toyota Programming Contest 2024#11（AtCoder Beginner Contest 379）
// URL: https://atcoder.jp/contests/abc379/tasks/abc379_c
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
    i64 n,m;cin>>n>>m;
    vector<pair<i64,i64>> a(m);
    i64 sum = 0;
    rep(i,0,m-1) cin>>a[i].first;
    rep(i,0,m-1) {
    	cin>>a[i].second;
    	sum += a[i].second;
    }
    ranges::sort(a);
    i64 ans = 0;
    i64 end = n;
    if(sum!=n){
    	cout<<-1<<endl;
    	return;
    }
    rev(i,m-1,0){
    	u64 nx = max(a[i].first-1,end-a[i].second)+1;
    	ans += (nx+end)*(end-nx+1)/2 - (end-nx+1)*a[i].first;
    	end = nx-1;
    }
    if(end == 0) cout<<ans<<endl;
    else cout<<-1<<endl;
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

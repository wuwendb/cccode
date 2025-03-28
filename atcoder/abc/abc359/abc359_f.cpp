// Problem: F - Tree Degree Optimization
// Contest: AtCoder - UNIQUE VISION Programming Contest 2024 Summer (AtCoder Beginner Contest 359)
// URL: https://atcoder.jp/contests/abc359/tasks/abc359_f
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
    vector<i64> a(n);
    priority_queue<pair<i64,int>,vector<pair<i64,int>>,greater<>> pq;
    rep(i,0,n-1){
    	cin>>a[i];
    	pq.push({a[i]*3,2});
    } 
    i64 ans = accumulate(a.begin(),a.end(),0LL);
    rep(i,1,n-2){
    	auto [x,t] = pq.top();pq.pop();
    	ans += x;
    	x/=(t*2-1);
    	x*=(t*2+1);
    	pq.push({x,t+1});
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

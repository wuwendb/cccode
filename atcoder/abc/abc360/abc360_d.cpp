// Problem: D - Ghost Ants
// Contest: AtCoder - AtCoder Beginner Contest 360
// URL: https://atcoder.jp/contests/abc360/tasks/abc360_d
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
    i64 n,t;cin>>n>>t;
    string s;cin>>s;
    vector<i64> l,r;
    rep(i,0,n-1){
    	i64 x;cin>>x;
    	if(s[i]=='1'){
    		r.pb(x);
    	}else{
    		l.pb(x);
    	}
    }
    ranges::sort(r);
    i64 ans=0;
    for(auto x:l){
    	i64 lo = x-2*t;
    	i64 hi = x;
    	ans += ranges::lower_bound(r,hi)-ranges::lower_bound(r,lo);
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

// Problem: D - Patisserie ABC
// Contest: AtCoder - AtCoder Beginner Contest 100
// URL: https://atcoder.jp/contests/abc100/tasks/abc100_d
// Memory Limit: 976 MB
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
    int n,m;cin>>n>>m;
    vector<array<i64,3>> a(n);
    rep(i,0,n-1){
    	cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    array<int,2> sym{1,-1};
    i64 sum = 0,ans=0;
    rep(i,0,7){
    	i64 x = sym[(i>>2)&1];
    	i64 y = sym[(i>>1)&1];
    	i64 z = sym[(i>>0)&1];
    	ranges::sort(a,ranges::greater{},[&](array<i64,3>& num){
    		return x*num[0]+y*num[1]+z*num[2];
    	});
    	sum = 0;
    	rep(i,0,m-1){
    		auto num = a[i];
    		sum += x*num[0]+y*num[1]+z*num[2];
    	}
    	ans = max(ans, sum);
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

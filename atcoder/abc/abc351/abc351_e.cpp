// Problem: E - Jump Distance Sum
// Contest: AtCoder - AtCoder Beginner Contest 351
// URL: https://atcoder.jp/contests/abc351/tasks/abc351_e
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
    int n;cin>>n;
    array<vector<int>,4> point;
    rep(i,1,n){
    	int x,y;cin>>x>>y;
    	point[(x+y)%2].pb(x+y);
    	point[2+(x+y)%2].pb(x-y);
    }
    auto cal = [&](vector<int>& v){
    	ranges::sort(v);
    	i64 pre = 0;
    	i64 res = 0;
    	int n = v.size();
    	rep(i,0,n-1){
    		res += 1LL*i*v[i]-pre;
    		pre += v[i];
    	}
    	return res;
    };
    cout<<(cal(point[0])+cal(point[1])+cal(point[2])+cal(point[3]))/2<<endl;
    
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

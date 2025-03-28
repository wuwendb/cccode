// Problem: C - Avoid Knight Attack
// Contest: AtCoder - TOYOTA SYSTEMS Programming Contest 2024（AtCoder Beginner Contest 377)
// URL: https://atcoder.jp/contests/abc377/tasks/abc377_c
// Memory Limit: 1024 MB
// Time Limit: 4000 ms

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

const int dx[8]{2,1,-1,-2,-2,-1,1,2};
const int dy[8]{1,2,2,1,-1,-2,-2,-1};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

  
void solve() {  
    int n,m;cin>>n>>m;
    set<i64> st;
    rep(i,1,m){
    	i64 a,b;cin>>a>>b;
    	st.insert(a<<30|b);
    	rep(j,0,7){
    		i64 x=a+dx[j];
    		i64 y=b+dy[j];
    		if(x<=0||y<=0||x>n||y>n) continue;
    		st.insert(x<<30|y);
    		
    	}
    }
    cout<<(i64)n*n-st.size()<<endl;
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

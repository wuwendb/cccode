// Problem: C - Popcorn
// Contest: AtCoder - AtCoder Beginner Contest 358
// URL: https://atcoder.jp/contests/abc358/tasks/abc358_c
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
    vector<int> a(n);
    rep(i,0,n-1){
    	string s;cin>>s;
    	int t = s[0]=='o'?1:0;
    	rep(i,1,m-1){
    		t *= 2;
    		t += s[i]=='o'?1:0;
    	}
    	a[i] = t;
    } 
    int ans = n;
    rep(i,0,(1<<n)-1){
    	int tmp = 0;
    	rep(j,0,n-1){
    		if((i>>j)&1){
    			tmp|=a[j];
    		}
    	}
    	if(tmp==(1<<m)-1){
    		ans = min(ans,__builtin_popcount(i));
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

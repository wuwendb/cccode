// Problem: B - A..B..C
// Contest: AtCoder - AtCoder Beginner Contest 393
// URL: https://atcoder.jp/contests/abc393/tasks/abc393_b
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
    string s;cin>>s;
    int n = s.size();
    int ans = 0;
    rep(i,0,n-1){
    	if(s[i]!='A') continue;
    	rep(j,i+1,n-1){
    		if(s[j]!='B') continue;
    		rep(k,j+1,n-1){
				if(s[k]=='C'&&k-j==j-i) ans++;
			}
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

// Problem: D - Swap to Gather
// Contest: AtCoder - AtCoder Beginner Contest 393
// URL: https://atcoder.jp/contests/abc393/tasks/abc393_d
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
    string s;cin>>s;
    i64 ans = 0;
	vector<int> cnt(n);
	int ones = 0;
	rep(i,0,n-1){
		if(s[i]=='1') ones++;
		else cnt[i] = ones;
	}
	rep(i,0,n-1){
		if(s[i]=='0'){
			ans += min(cnt[i],ones-cnt[i]);
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

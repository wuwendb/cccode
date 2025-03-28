// Problem: D - Bonfire
// Contest: AtCoder - UNIQUE VISION Programming Contest 2025 Spring (AtCoder Beginner Contest 398)
// URL: https://atcoder.jp/contests/abc398/tasks/abc398_d
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
    int n,r,c;cin>>n>>r>>c;
    string s;cin>>s;
    set<pii> st1;
    int R=0,C=0;
    st1.insert(make_pair(R,C));
	rep(i,0,n-1){
		if(s[i]=='N'){
			r++,R++;
		}else if(s[i]=='W'){
			c++,C++;
		}else if(s[i]=='S'){
			r--,R--;
		}else{
			c--,C--;
		}
		st1.insert(make_pair(R,C));
		if(st1.contains(make_pair(r,c))){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	cout<<endl;
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

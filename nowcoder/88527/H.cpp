// Problem: 区间问题2
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/88527/H
// Memory Limit: 524288 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a)
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
//#define ll long long  
#define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 1e6+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
int lg[mx];
void initLg(int n){
	rep(i,2,n) lg[i] = lg[i>>1]+1;
}
int st[mx][22];

int query(int l, int r) {
	int lt = r - l + 1;
	int q = lg[lt];
	return max(st[l][q], st[r - (1 << q) + 1][q]);
}
  
void solve() {
	int n;cin>>n; 
    initLg(n);
    int len = n, l1 = lg[len] + 1;
	for (int i = 0; i < len; ++i) {
	  	cin>>st[i][0];
	}
	for (int j = 1; j < l1; ++j) {
	  int pj = (1 << (j - 1));
	  for (int i = 0; i + pj < len; ++i) {
	    st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	  }
	}
    int q;cin>>q;
    rep(i,1,q){
    	int l,r;cin>>l>>r;l--,r--;
    	cout<<query(l,r)<<endl;
    }
} 
  
signed main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);  
    int t=1;  
    // cin >> t; 
//     cout<<fixed<<setprecision(1); 
    while (t--) {  
        solve();  
    }  
    // cout<<pow(2,22)<<endl;  
    return 0;  
}

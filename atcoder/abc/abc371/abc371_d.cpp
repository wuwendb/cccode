// Problem: D - 1D Country
// Contest: AtCoder - AtCoder Beginner Contest 371
// URL: https://atcoder.jp/contests/abc371/tasks/abc371_d
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
//#define ll long long  
#define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
  
void solve() {  
    int n;cin>>n;
    vector<pii> g(n);
    vector<int> h(n);
    rep(i,1,n) cin>>g[i-1].first,h[i-1]=g[i-1].first;
    rep(i,1,n) cin>>g[i-1].second;
    ranges::sort(g);
    ranges::sort(h);
    // h.pb(1e10);
    vector<int> pre(n+1);
    rep(i,0,n-1){
    	pre[i+1] = pre[i]+g[i].second;
    }
    int q;cin>>q;
    rep(i,1,q){
    	int l,r;cin>>l>>r;
    	if(r<g[0].first||l>g[n-1].first){
    		cout<<0<<endl;
    		continue;
    	}
    	auto left = ranges::lower_bound(h,l)-h.begin();
    	auto right = ranges::upper_bound(h,r)-h.begin();
    	cout<<pre[right]-pre[left]<<endl;
    }
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
    // cout<<pow(2,22)<<endl;  
    return 0;  
}

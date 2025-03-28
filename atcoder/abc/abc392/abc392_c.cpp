// Problem: C - Bib
// Contest: AtCoder - Japan Registry Services (JPRS) Programming Contest 2025#1 (AtCoder Beginner Contest 392)
// URL: https://atcoder.jp/contests/abc392/tasks/abc392_c
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
// 记录 兜和人  人和看的人 人和兜三个map
  
void solve() {  
    unordered_map<int,int> b2p,p2p,p2b;
    int n;cin>>n;
    rep(i,1,n){
    	int p;cin>>p;
    	p2p[i]=p;
    }
    rep(i,1,n){
    	int q;cin>>q;
    	p2b[i] = q;
    	b2p[q] = i;
    }
    rep(i,1,n){
    	cout<<p2b[p2p[b2p[i]]]<<" \n"[i==n];
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
    return 0;  
}

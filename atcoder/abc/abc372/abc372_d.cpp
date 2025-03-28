// Problem: D - Buildings
// Contest: AtCoder - UNIQUE VISION Programming Contest 2024 Autumn (AtCoder Beginner Contest 372)
// URL: https://atcoder.jp/contests/abc372/tasks/abc372_d
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
    vector<int> a(n);rep(i,0,n-1) cin>>a[i];
    priority_queue<int,vector<int>,greater<>> pq;
    vector<int> ans(n);
    rev(i,n-2,0){
    	while(!pq.empty()&&pq.top()<a[i+1]){
    		pq.pop();
    	}
    	pq.push(a[i+1]);
    	ans[i] = pq.size();
    }
    rep(i,0,n-1) cout<<ans[i]<<" \n"[i==n-1];
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

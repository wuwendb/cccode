// Problem: B - Traveling Takahashi Problem
// Contest: AtCoder - Panasonic Programming Contest 2024（AtCoder Beginner Contest 375）
// URL: https://atcoder.jp/contests/abc375/tasks/abc375_b
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
    vector<pair<double,double>> a(n);
    rep(i,1,n){
    	cin>>a[i-1].first>>a[i-1].second;
    }
    a.pb({0,0});
    double x=0,y=0;
    double ans = 0;
    for(auto [i,j]:a){
    	ans += hypot(i-x,j-y);
    	x=i;y=j;
    }
    cout<<ans<<endl;
}  
  
signed main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);  
    int t=1;  
    // cin >> t; 
    cout<<fixed<<setprecision(20); 
    while (t--) {  
        solve();  
    }  
    // cout<<pow(2,22)<<endl;  
    return 0;  
}

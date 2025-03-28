// Problem: B - Right Triangle
// Contest: AtCoder - Toyota Programming Contest 2024#7（AtCoder Beginner Contest 362）
// URL: https://atcoder.jp/contests/abc362/tasks/abc362_b
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
    int xa,xb,xc,ya,yb,yc;
    cin>>xa>>ya>>xb>>yb>>xc>>yc;
    vector<int> a;
	a.pb((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
	a.pb((xa-xc)*(xa-xc)+(ya-yc)*(ya-yc));
	a.pb((xc-xb)*(xc-xb)+(yc-yb)*(yc-yb));
	ranges::sort(a);
	if(a[0]+a[1]==a[2]) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
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

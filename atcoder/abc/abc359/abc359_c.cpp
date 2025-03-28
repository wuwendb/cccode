// Problem: C - Tile Distance 2
// Contest: AtCoder - UNIQUE VISION Programming Contest 2024 Summer (AtCoder Beginner Contest 359)
// URL: https://atcoder.jp/contests/abc359/tasks/abc359_c
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
    i64 sx,sy,tx,ty,left,right;
    cin>>sx>>sy>>tx>>ty;
    if((sx+sy)%2) sx--;
    if((tx+ty)%2) tx--;
    if(sx<tx) {
    	swap(sx,tx);
    	swap(sy,ty);
    }
    i64 ydif = abs(ty-sy);
    auto xmin = sx-ydif;
    if(xmin<=tx){
    	cout<<ydif<<endl;
    }else{
    	cout<<ydif+(xmin-tx)/2<<endl;
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

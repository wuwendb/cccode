// Problem: 异或故事
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/88392/C
// Memory Limit: 524288 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a) 
//#define ll long long  
// #define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9;  
const int MOD = 998244353;  
//---------------------------------------------------------  

// ^优先级低于<=
void solve() {  
    int a;cin>>a;
    rep(i,1,1000000000){
        int b = a^i;
        if((a^i)<=1000000000&&(a^i)>=1){
            cout<<i<<" "<<(a^i)<<endl;
            return;
        }
    }
}  
  
signed main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);  
    int t=1;  
    cin >> t; 
    cout<<fixed<<setprecision(1); 
    while (t--) {  
        solve();  
    }  
    // cout<<pow(2,22)<<endl;  
    return 0;  
}

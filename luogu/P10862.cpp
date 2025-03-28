// Problem: P10862 [HBCPC2024] Spicy or Grilled?
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P10862
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i)  
//#define ll long long  
#define int long long  
using namespace std;  
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

  
void solve() {  
    int n,x,a,b;
    cin>>n>>x>>a>>b;
    cout<<x*b+(n-x)*a<<endl;
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
//    cout<<pow(2,22)<<endl;  
    return 0;  
}

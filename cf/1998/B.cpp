// Problem: B. Minimize Equal Sum Subarrays
// Contest: Codeforces - Codeforces Round 965 (Div. 2)
// URL: https://codeforces.com/contest/1998/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms

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
    int n;cin>>n;
    int f;cin>>f;
    rep(i,1,n-1){
    	int x;cin>>x;cout<<x<<" ";
    }
    cout<<f<<endl;
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

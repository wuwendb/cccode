// Problem: 小红的字符串
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/87656/A
// Memory Limit: 1048576 MB
// Time Limit: 2000 ms

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
    char c1,c2,c3;cin>>c1>>c2>>c3;
    if(c1==c2&&c1==c3){
    	cout<<0<<endl;
    }else if(c1==c2||c1==c3||c2==c3){
    	cout<<1<<endl;
    }else{
    	cout<<2<<endl;
    }
    
}  
  
signed main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);  
    int t=1;  
//    cin >> t; 
    cout<<fixed<<setprecision(1); 
    while (t--) {  
        solve();  
    }  
//    cout<<pow(2,22)<<endl;  
    return 0;  
}

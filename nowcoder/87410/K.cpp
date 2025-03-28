// Problem: 鸽桥
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/87410/K
// Memory Limit: 524288 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) (a).begin(),(a).end() 
#define ll long long  
// #define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

  
void solve() {  
    int n; cin>>n;
    bool f=true; 
    int t=0;
    rep(i,1,n)
    {
        rep(j,1,t) cout<<" ";
        cout<<"鸽";
        cout<<'\n';
        t+=f?1:-1;
        if(t==-1){
            f=true;
            t=1;
        }
        else if(t==27){
            f=false;
            t=25;
        }
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

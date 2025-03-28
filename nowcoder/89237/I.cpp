// Problem: 正义从不打背身
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/89237/I
// Memory Limit: 1048576 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a) 
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
    int n,m;cin>>n>>m;
    vector<int> g(n);
    rep(i,1,n){
    	char c;cin>>c;
    	if(c=='P') g[i-1] = 1;
    	else g[i-1] =0;
    }
    for(int i = m;i>0;i-=2){
        if((m-i+1)%2==0){
            cout<<g[i-1]<<" ";
        }else{
            cout<<(g[i-1]^1)<<" ";
        }
    }
    for(int i = 1+(m&1);i<m;i+=2){
        if((m-i+1)%2==0){
            cout<<g[i-1]<<" ";
        }else{
            cout<<(g[i-1]^1)<<" ";
        }
    }
    rep(i,m,n-1){
    	cout<<g[i]<<" ";
    }
    cout<<endl;
    
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

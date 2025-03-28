// Problem: ACM中的M题
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/88878/C
// Memory Limit: 524288 MB
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
    rep(i,1,n){
    	int x;cin>>x;
    }
    map<int,int> b;
    rep(i,1,n){
    	int x;cin>>x;
    	b[x]++;
    }
    int ans = 0;
    for(auto [k,v]:b){
    	if(v==1){
    		cout<<-1<<endl;return;
    	}
    	if(v&1) {
    		ans+=v/2+1;
    	}else{
    		ans+=v/2;
    	}
    }
    cout<<ans<<endl;
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

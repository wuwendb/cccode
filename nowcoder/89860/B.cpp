// Problem: 你好，这里是牛客竞赛
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/89860/B
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
    string s;cin>>s;
    if(s.starts_with("www.nowcoder.com")||s.starts_with("https:\/\/www.nowcoder.com")){
    	cout<<"Nowcoder"<<endl;
    }else if(s.starts_with("https:\/\/ac.nowcoder.com")||s.starts_with("ac.nowcoder.com")){
    	cout<<"Ac"<<endl;
    }else{
    	cout<<"No"<<endl;
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

// Problem: T511483 【入门赛】B 重聚
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T511483?contestId=197857
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a)
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
//#define ll long long  
// #define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

  
void solve() {  
    int t,d,t1,d1,t2,d2;
    cin>>t>>d>>t1>>d1>>t2>>d2;
    if(d>d1&&d>d2){
    	cout<<-1<<endl;
    }else{
    	int res = INT_MAX;
    	if(d<=d1){
    		res = min(res,max(0,t1-t));
    	}
    	if(d<=d2){
    		res = min(res,max(0,t2-t));
    	}
    	cout<<res<<endl;
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

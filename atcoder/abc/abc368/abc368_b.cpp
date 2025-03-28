// Problem: B - Decrease 2 max elements
// Contest: AtCoder - Hitachi Vantara Programming Contest 2024（AtCoder Beginner Contest 368）
// URL: https://atcoder.jp/contests/abc368/tasks/abc368_b
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
    priority_queue<int> pq;
    int n;cin>>n;
    rep(i,1,n){
    	int x;cin>>x;pq.push(x);
    }
    int t=0;
    while(pq.size()>1){
    	auto t1 = pq.top();pq.pop();
    	auto t2 = pq.top();pq.pop();
    	t1--;t2--;
    	if(t1>0) pq.push(t1);
    	if(t2>0) pq.push(t2);
    	t++;
    }
    cout<<t<<endl;
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
